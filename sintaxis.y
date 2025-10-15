%{
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "listaSimbolos.h"
    #include "listaCodigo.h"

    // Funciones necesarias para analisis sintactico    
    extern int yylex();
    void yyerror(const char *msg);
    // Variables externas
    extern int yylineno;
    extern int errores; 
    // Registros 
    int regs[10];
    void iniciar_regs();
    char *obtener_reg(); // $tX
    void liberar_reg(char *reg);
    char *concatenar(char *arg1, char *arg2);
    void imprimirCodigo(ListaC codigo);
    void imprimirSimbolos();
    char *obtener_etiqueta();
    // Lista de símbolos
    Lista l;
    // Tipo del identificador
    Tipo tipo_decl;
    int menos;
    int contador_cadenas = 0;
    int contadorEtiquetas = 1;
%}

// Esto va a parar a .tab.h para el analizador léxico
%code requires{
        #include "listaCodigo.h"
    }

/* Tipos de dato de tokens y no terminales */
%union{
    char *cadena;
    ListaC codigo;
}

/* Tipo de dato vinculado a no terminales */
%type <codigo> expression statement statement_list read_list print_item print_list identifier_list asig program declarations inicio

/* Tokens de la gramatica */
%token PLUSOP  "+"
%token MINUSOP "-"
%token MULTOP  "*"
%token BARRA  "/"
%token LPAREN "("
%token RPAREN ")"
%token LCORCH  "{"
%token RCORCH  "}"
%token FIN  ";"
%token COMMA  ","
%token <cadena> INTLIT "numero"
%token <cadena> STR "string"
%token ASIGN "="
%token PRINT "print"
%token READ  "read"
%token VOID  "void"
%token <cadena> ID    "id"
%token VAR   "var"
%token CONST "const"
%token IF   "if"
%token ELSE "else"
%token WHILE "while"

/* Simbolo inicial */
%start program

/* Mensajes de error más precisos */
%define parse.error verbose

%left "+" "-"
%left "*" "/"
%precedence UMINUS

/* Depuracion */
%define parse.trace

%expect 1

%%

/* Reglas de producción */

program         : inicio VOID ID "(" ")" "{" declarations statement_list "}"
                    {
                        if(errores == 0){
                            $$ = creaLC();
                            concatenaLC($$, $7);
                            concatenaLC($$, $8);
                            liberaLC($7);
                            liberaLC($8);
                            Operacion o;
                            o.op = "jr";
                            o.res = "$ra";
                            o.arg1 = NULL;
                            o.arg2 = NULL;
                            insertaLC($$, finalLC($$), o);
                            imprimirSimbolos();
                            imprimirCodigo($$);
                            liberaLS(l);
                            liberaLC($$);
                        }
                    }
                ;       
inicio          :   %empty      {
                        l = creaLS(); 
                        memset(regs, 0, 10);
                }
                ;
declarations    : declarations VAR { tipo_decl = VARIABLE; } identifier_list ";"                      {
                    if(errores == 0){
                        $$ = creaLC();
                        concatenaLC($$, $1);
                        concatenaLC($$, $4);
                        liberaLC($1);
                        liberaLC($4);
                    }
                }
                | declarations CONST { tipo_decl = CONSTANTE; } identifier_list ";"                   {
                    if(errores == 0){
                        $$ = creaLC();
                        concatenaLC($$, $1);
                        concatenaLC($$, $4);
                        liberaLC($1);
                        liberaLC($4);
                    }
                }
                | %empty    { 
                    if(errores == 0){
                        $$ = creaLC();
                    }
                }
                ;

identifier_list : asig                         {
                    if(errores == 0){
                        $$ = $1;
                    }
                }
                | identifier_list "," asig     {
                    if(errores == 0){
                        $$ = creaLC();
                        concatenaLC($$, $1);
                        concatenaLC($$, $3);
                        liberaLC($1);
                        liberaLC($3);
                    }
		        }
                ;
        
asig            : ID {   
                    PosicionLista p = buscaLS(l,$1);
                    if (p == finalLS(l)) {
                        Simbolo aux;
                        aux.nombre = $1;
                        aux.tipo = tipo_decl;
                        insertaLS(l,finalLS(l),aux);
                        if(errores == 0){
                            $$ = creaLC();
                        }   
                    } else {
                        printf("Error: identificador %s redeclarado en linea %d\n", $1, yylineno);
                        errores++;
                    }                                                  
                                                       
                }
                | ID "=" expression {
                    PosicionLista p = buscaLS(l,$1);
                    if (p == finalLS(l)) {
                        Simbolo aux;
                        aux.nombre = $1;
                        aux.tipo = tipo_decl;
                        insertaLS(l,finalLS(l),aux);  
                        if(errores == 0){
                            $$ = $3;
                            Operacion oper;
                            oper.op = "sw";
                            oper.res = recuperaResLC($3);
                            char *d;
                            asprintf(&d, "_%s", $1);
                            oper.arg1 = d;
                            oper.arg2 = NULL;
                            insertaLC($$, finalLC($$), oper);
                            liberar_reg(oper.res);
                        }  
                    } else {
                        printf("Error: identificador %s redeclarado en linea %d\n", $1, yylineno);
                        errores++;
                    }  
                }
                ;

statement_list  : statement_list statement {
                    if (errores == 0) {
                        $$ = $1;
                        concatenaLC($$, $2);
                        liberaLC($2);
                    }
                }
                | %empty { 
                    if(errores == 0){ $$ = creaLC(); }
                }
                ;

statement       : ID "=" expression ";" {
                    PosicionLista p = buscaLS(l,$1);
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", $1, yylineno);
                        errores++;
                    }else{
                        Simbolo sim = recuperaLS(l, p);
                        if (sim.tipo == CONSTANTE){
                            printf("Error en linea %d: identificador %s es constante\n", yylineno, $1);
                            errores++;  
                        }
                    }
                    if (errores == 0) {
                        $$ = $3;
                        Operacion oper;
                        oper.op = "sw";
                        oper.res = recuperaResLC($3);
                        char *d;
                        asprintf(&d, "_%s", $1);
                        oper.arg1 = d;
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        liberar_reg(oper.res);
                    }
                }
                | "{" statement_list "}" {
                    if (errores == 0){
                        $$ = $2;
                    }
			    }
                | IF "(" expression ")" statement ELSE statement   {
                    if (errores == 0){
                        $$ = $3;
                        Operacion o;
                        o.op = "beqz";
                        o.res = recuperaResLC($3);
                        char *etiqueta1 = obtener_etiqueta();
                        o.arg1 = etiqueta1;
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        concatenaLC($$, $5);
                        liberar_reg(o.res);
                        Operacion o1;
                        o1.op = "b";
                        char *etiqueta2 = obtener_etiqueta();
                        o1.res = etiqueta2;
                        o1.arg1 = NULL;
                        o1.arg2 = NULL;
                        insertaLC($$, finalLC($$), o1);
                        Operacion o2;
                        o2.op = "etiq";
                        o2.res = etiqueta1;
                        o2.arg1 = NULL;
                        o2.arg2 = NULL;
                        insertaLC($$, finalLC($$), o2);
                        concatenaLC($$, $7);
                        Operacion o3;
                        o3.op = "etiq";
                        o3.res = etiqueta2;
                        o3.arg1 = NULL;
                        o3.arg2 = NULL;
                        insertaLC($$, finalLC($$), o3);
                        liberaLC($5);
                        liberaLC($7);
                    }
			    }
                | IF "(" expression ")" statement                           {
                    if (errores == 0){
                        $$ = $3;
                        char *etiqueta1 = obtener_etiqueta();
                        Operacion o;
                        o.op = "beqz";
                        o.res = recuperaResLC($3);
                        o.arg1 = etiqueta1;
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        concatenaLC($$, $5);
                        liberar_reg(o.res);
                        liberaLC($5);
                        Operacion o1;
                        o1.op = "etiq";
                        o1.res = etiqueta1;
                        o1.arg1 = NULL;
                        o1.arg2 = NULL;
                        insertaLC($$, finalLC($$), o1);
                    }

				}
                | WHILE "(" expression ")" statement                        {
                    if (errores == 0){
                        $$ = creaLC();
                        char * etiqueta1 = obtener_etiqueta();
                        Operacion o;
                        o.op = "etiq";
                        o.res = etiqueta1;
                        o.arg1 = NULL;
                        o.arg2 = NULL;
                        insertaLC($$, finalLC($$), o);
                        concatenaLC($$, $3);
                        Operacion o1;
                        o1.op = "beqz";
                        o1.res = recuperaResLC($3);
                        char *etiqueta2 = obtener_etiqueta();
                        o1.arg1 = etiqueta2;
                        o1.arg2 = NULL;
                        insertaLC($$, finalLC($$), o1);
                        concatenaLC($$, $5);
                        Operacion o2;
                        o2.op = "b";
                        o2.res = etiqueta1;
                        o2.arg1 = NULL;
                        o2.arg2 = NULL;
                        insertaLC($$, finalLC($$), o2);
                        Operacion o3;
                        o3.op = "etiq";
                        o3.res = etiqueta2;
                        o3.arg1 = NULL;
                        o3.arg2 = NULL;
                        insertaLC($$, finalLC($$), o3);
                        liberaLC($3);
                        liberaLC($5);
                        liberar_reg(o1.res);
                    }
				}
                | PRINT print_list ";" { 
			        if (errores == 0){
				        $$ = $2;
				    }
			    }
                | READ read_list ";" { 
			        if (errores == 0){
				        $$ = $2;
				    } 
                }
                | error ";" { $$ = creaLC(); }
                ;

print_list      : print_item { 
                    if (errores == 0){
                        $$ = $1; 
                    }
		        }
                | print_list "," print_item {
                    if (errores == 0) { 
                        $$ = $1;
                        concatenaLC($$, $3);
                        liberaLC($3); 
                    }
                }                                 
                ;

print_item      : expression     { 
		            if (errores == 0 ){                                           
                        $$ = $1;
                        Operacion oper;
                        oper.op = "move";
                        oper.res = "$a0";
                        oper.arg1 = recuperaResLC($1);
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        liberar_reg(oper.arg1);
                        Operacion oper1;
                        oper1.op = "li";
                        oper1.res = "$v0";
                        oper1.arg1 = "1";
                        oper1.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper1);
                        Operacion oper2;
                        oper2.op = "syscall";
                        oper2.arg1 = NULL;
                        oper2.arg2 = NULL;
                        oper2.res = NULL;
                        insertaLC($$, finalLC($$), oper2);
		            }
		        }
                | STR {
                    if (errores == 0){
                        Simbolo aux;
                        aux.nombre = $1;
                        aux.tipo = CADENA;
                        aux.valor = contador_cadenas;
                        insertaLS(l, finalLS(l), aux);
                        $$ = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "4";
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        oper.op = "la";
                        oper.res = "$a0";
                        char *s;
                        asprintf(&s, "$str%d", contador_cadenas++);
                        oper.arg1 = s;
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        oper.op = "syscall";
                        oper.res = oper.arg1 = oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                    }
		        }
                ;

read_list       : ID {
                    PosicionLista p = buscaLS(l,$1);
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", $1, yylineno);
                        errores++;
                    }else{

                        Simbolo sim = recuperaLS(l, p);
                        if (sim.tipo == CONSTANTE){
                            printf("Error: identificador %s es constanteen linea %d\n",$1, yylineno);
                            errores++;  
                        }
                    }
                    if (errores == 0){
                        $$ = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "5";
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        Operacion oper1;
                        oper1.op = "syscall";
                        oper1.res = NULL;
                        oper1.arg1 =NULL;
                        oper1.arg2  =NULL;
                        insertaLC($$, finalLC($$), oper1);
                        Operacion oper2;
                        oper2.op = "sw";
                        oper2.res = "$v0";
                        char *dir;
                        asprintf(&dir, "_%s", $1);
                        oper2.arg1 = dir;
                        oper2.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper2);			
                    }  
                    
                }
                | read_list "," ID {
                    PosicionLista p = buscaLS(l,$3);
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", $3, yylineno);
                        errores++;
                    }else{
			            Simbolo sim = recuperaLS(l, p);
			            if (sim.tipo == CONSTANTE){
			                printf("Error en linea %d: identificador %s es constante\n", yylineno, $3);
                            errores++;  
				        }
			        }
                    if (errores == 0){
                        $$ = $1;
                        Operacion oper;
                        oper.op = "li";
                        oper.res = "$v0";
                        oper.arg1 = "5";
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                        Operacion oper1;
                        oper1.op = "syscall";
                        oper1.res = NULL;
                        oper1.arg1 =NULL;
                        oper1.arg2  =NULL;
                        insertaLC($$, finalLC($$), oper1);
                        Operacion oper2;
                        oper2.op = "sw";
                        oper2.res = "$v0";
                        char *dir;
                        asprintf(&dir, "_%s", $3);
                        oper2.arg1 = dir;
                        oper2.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper2);			
                    }  
                }
                ;

expression      : expression "+" expression                                 {
                    if (errores == 0){
                        $$ = $1;
                        concatenaLC($$,$3);
                        Operacion oper;
                        oper.op = "add";
                        oper.res = recuperaResLC($1);
                        oper.arg1 = recuperaResLC($1);
                        oper.arg2 = recuperaResLC($3);
                        insertaLC($$, finalLC($$), oper);
                        liberaLC($3);
                        liberar_reg(oper.arg2);
                    }
                }
                | expression "-" expression                                 {
                    if (errores == 0){
                        $$ = $1;
                        concatenaLC($$,$3);
                        Operacion oper;
                        oper.op = "sub";
                        oper.res = recuperaResLC($1);
                        oper.arg1 = recuperaResLC($1);
                        oper.arg2 = recuperaResLC($3);
                        insertaLC($$, finalLC($$), oper);
                        liberaLC($3);
                        liberar_reg(oper.arg2);
                    }
                }
                | expression "*" expression                                 {
                    if (errores == 0){
                        $$ = $1;
                        concatenaLC($$,$3);
                        Operacion oper;
                        oper.op = "mul";
                        oper.res = recuperaResLC($1);
                        oper.arg1 = recuperaResLC($1);
                        oper.arg2 = recuperaResLC($3);
                        insertaLC($$, finalLC($$), oper);
                        liberaLC($3);
                        liberar_reg(oper.arg2);
                    }
                }
                | expression "/" expression                                 {
                    if (errores == 0){
                        $$ = $1;
                        concatenaLC($$,$3);
                        Operacion oper;
                        oper.op = "div";
                        oper.res = recuperaResLC($1);
                        oper.arg1 = recuperaResLC($1);
                        oper.arg2 = recuperaResLC($3);
                        insertaLC($$, finalLC($$), oper);
                        liberaLC($3);
                        liberar_reg(oper.arg2);
                    }
                }
                | "-" expression %prec UMINUS  { 
                    if (errores == 0) {
                        $$ = $2;
                        Operacion oper;
                        oper.op = "neg";
                        oper.res = recuperaResLC($2);
                        oper.arg1 = recuperaResLC($2);
                        oper.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper);
                    
                    }
		        }
                | "(" expression ")"            {
                    if (errores == 0){
                        $$ = $2;
                    }
		        }
                | ID {
                    PosicionLista p = buscaLS(l,$1);
                    if (p == finalLS(l)){
                        printf("Error: identificador %s no declarado en linea %d\n", $1, yylineno);
                        errores++;
                    }
                    // Generación de código
                    if (errores == 0) {
                        $$ = creaLC();
                        Operacion oper;
                        oper.op = "lw";
                        oper.res = obtener_reg();
                        char *dir;
                        asprintf(&dir, "_%s", $1);
                        oper.arg1 = dir;
                        oper.arg2 = NULL;
                        insertaLC($$,finalLC($$), oper);
                        guardaResLC($$, oper.res);
                    }
		        }
                | INTLIT  {
                    if (errores == 0){
                        $$ = creaLC();
                        Operacion oper;
                        oper.op = "li";
                        oper.res = obtener_reg();
                        oper.arg1 = $1;
                        oper.arg2 = NULL;
                        insertaLC($$,finalLC($$), oper);
                        guardaResLC($$, oper.res);
                    }
		        }
                ;
%%

void yyerror(const char *msg) {
    errores++;
    printf("Error en linea %d: %s\n", yylineno, msg);    
}

char *obtener_reg(){
    char reg[4]; // $tX
    for(int i = 0; i <10; i++){
        if(regs[i] == 0){
            sprintf(reg, "$t%d",i);
            regs[i] = 1;
            return strdup(reg);
        }
    }
    printf("Error: no quedan registros libres\n");
    exit(1);
}

void liberar_reg(char *reg){
    // reg == $tX
    int i = reg[2] - '0';
    regs[i] = 0;
}

char *concatenar(char *arg1, char *arg2){
    int l = strlen(arg1) + strlen(arg2);
    char *res = (char *) malloc(l);
    sprintf(res, "%s%s",arg1,arg2);
    return res;
}

void imprimirCodigo(ListaC codigo){
    PosicionListaC p = inicioLC(codigo);
    Operacion oper;
    while(p != finalLC(codigo)){
        oper = recuperaLC(codigo,p);
        if(!strcmp(oper.op, "etiq")){
                printf("%s:\n", oper.res);
        }else{
            printf("    %s",oper.op);
            if (oper.res) printf(" %s",oper.res);
            if (oper.arg1) printf(",%s",oper.arg1);
            if (oper.arg2) printf(",%s",oper.arg2);
            printf("\n");     
        }
         p = siguienteLC(codigo,p);
    }
}

void imprimirSimbolos(){
    PosicionLista p = inicioLS(l);
    printf(".data\n");
    while(p != finalLS(l)){
        Simbolo aux = recuperaLS(l, p);
        if(aux.tipo == CADENA){
            printf("$str%d:\n   .asciiz %s\n", aux.valor, aux.nombre);
        }else{
            printf("_%s:\n      .word 0\n", aux.nombre);
        }
        p = siguienteLS(l,p);
    }
    printf(".text\n.globl main\nmain:\n");
}

char * obtener_etiqueta(){
	char etiq[32];
	sprintf(etiq, "$l%d", contadorEtiquetas++);
        return strdup(etiq);

}
