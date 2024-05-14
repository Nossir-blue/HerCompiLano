#include "defs.h"
#include "data.h"
#include <locale.h>
#include <string.h>
/**
* Aqui o scan fica com as funções do lexer
* Vai ler um char por vez doo input file mas tem vezes que 
* vou ter que devolver um char se eu ler muito à frente 
* da stream.
* também tem essa de querer saber qual é a llinha que estou
* para poder printar o num da linha nas mensagens de debug
*/

static int chrpos(char *s, int c){
    char *p;
    
    p = strchr(s, c);
    return (p ? p - s : -1);
}

static int next(void){
    int c;

    if(Devolve){
        c = Devolve; // usa o char put
        Devolve = 0; // volta se tiver um lá
        return c;
    }

    c = fgetc(Infile); //aqui ele lê do input file
    if('\n' == c)
        Linha++; // incrementa o contador da linha
    return c;
}

static void devolve(int c){
    // função que devolve um character indesejado... filho indesejado
    // HAHAHAHAHAHAHAH... ok...
    Devolve = c;
}

static int skip(void){
    // Yá, Rui... essa função aqui pula os espaços em branco
    // do tipo, espaços em branco, trocas de linha e blá blá
    // e depois retorn o primeiro char que vou ter que lidar com ele
    int c;

    c = next();
    while(' ' == c||'\n' == c || '\n' == c || '\r' == c || '\f' == c){
        c = next();
    }
    return (c);
}
/***
*   É aqui que a vaca começa tossir
*   Mô primeiro lexer scanner
*/

static int scanint(int c){
    int k, val = 0;

    while((k = chrpos("0123456789", c)) >= 0){
        val = val * 10 + k;
        c = next();
    }
    devolve(c);
    return val;
}

int scan(struct token *t){
    setlocale(LC_ALL,"Portuguese");
    int c;

    c = skip();

    switch(c){
        case EOF:
            return (0);
        case '+':
            t->token = T_MAIS;
            break;
        case '-':
            t->token = T_MENOS;
            break;
        case '*':
            t->token = T_ASTERISCO;
            break;
        case '/':
            t->token = T_BARRA;
            break;
        default:
            // se for número, faz scan do valor do intlit (IS LIT lmaooooooo)
            t->intvalue = scanint(c);
            t->token = T_INTLIT;
            break;
    }
    printf("O character introduzido '%c' na linha %i não é reconhecido\n",c,Linha);
    return (1); // encontrei um token
}