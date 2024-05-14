#include "defs.h"
#define extern_
#include "data.h"
// #include <stdio.h>
// #include <stdlib.h>
#undef extern_

char *tokenStream[] = {"+","-","*","/","intlit"};

static void scanfile(){
    struct token T;

    while(scan(&T)){
        printf("Token %s", tokenStream[T.token]);
        if(T.token == T_INTLIT)
            printf(", valor %d", T.intvalue);
        printf("\n");
    }
}

void main(int argc, char *argv[]){

    init();

    Infile = fopen(argv[1], "r");

    scanfile();
    exit(0);
}
