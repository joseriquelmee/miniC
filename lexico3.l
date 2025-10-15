%{
#include <string.h>
#include <stdio.h>
#include "sintaxis.tab.h"
#include <math.h>
void error_lexico();

int comienzo_comentario = 0;
int errores = 0;
long limite = pow(2,31);
%}
digito	[0-9]
letra	[a-zA-Z]
entero	{digito}+
mod_panico [^ \n\t\ra-zA-Z_0-9+\-+*/;,(){}=]

%x commulti
%option yylineno

%%

[ \n\t]+				;
"//".*					;
<commulti>"/*"				{ comienzo_comentario = yylineno;
								BEGIN(commulti); }
<commulti>"*/"				{ BEGIN(INITIAL); }					
<commulti>(.|\n) 			;

<commulti><<EOF>>			{ printf("Comentario sin cerrar iniciado en línea %d\n", comienzo_comentario);
								errores++;
					  			return 0;
							}


"void"				return VOID;
"var"				return VAR;
"const"				return CONST;
"if"				return IF;
"else"				return ELSE;
"while"				return WHILE;
"print"				return PRINT;
"read"				return READ;


";"					return FIN;
","					return COMMA;
"+"					return PLUSOP;
"-"					return MINUSOP;
"*"					return MULTOP;
"/"					return BARRA;
"="					return ASIGN;
"("					return LPAREN;
")"					return RPAREN;
"{"					return LCORCH;
"}"					return RCORCH;


({letra}|_|$)({letra}|{digito}|_|$)*	{ 	
											long i = atol(yytext);
											if(i > 16){
												printf("Error: identificador demasiado largo.\n");
												errores++;
											}
											yylval.cadena = strdup(yytext);
					  						return ID; 
										}

	

{entero}								{ 	long i = atol(yytext);
					  						if((i>limite-1)||(i<-limite)){
					  							printf("Error: entero demasiado grande o demasiado pequeño.\n");
					  							errores++;
					   						}
					   						yylval.cadena = strdup(yytext);
					   						return INTLIT; 
										}



\"([^"\n]|\\\")+\"						{
											yylval.cadena = strdup(yytext);
											return STR;
										}

\"([^"\n]|\\\")+						{
											printf("Error en la linea %d: cadena mal cerrar\n", yylineno);
											errores++;
										}

{mod_panico}							{
											printf("\nError en la línea %d, simbolo no reconocido %s\n",yylineno, yytext);
											errores++;
										}
%%





