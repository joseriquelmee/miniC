#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;
extern int yyparse();
extern int errores;

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("Uso %s fichero\n", argv[0]);
        exit(1);
    }   
    yyin = fopen(argv[1], "r");
    if(yyin == NULL){
        printf("no se puede abrir %s\n", argv[1]);
        exit(2);
    }
    yyparse();
  
    printf("Errores: %d\n", errores);
    
}
