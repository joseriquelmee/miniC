miniC: lex.yy.c main.c sintaxis.tab.c listaSimbolos.c listaSimbolos.h listaCodigo.c
	gcc -g main.c lex.yy.c sintaxis.tab.c listaSimbolos.c listaCodigo.c -ll -o miniC

lex.yy.c: lexico3.l sintaxis.tab.h
	flex lexico3.l

sintaxis.tab.h sintaxis.tab.c: sintaxis.y listaSimbolos.h listaCodigo.h
	bison -d -v sintaxis.y 

limpia: 
	rm -f miniC lex.yy.c sintaxis.tab.c sintaxis.tab.h

