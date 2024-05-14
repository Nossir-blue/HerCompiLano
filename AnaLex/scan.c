#include "defs.h"
#include "data.h"
#include <locale.h>
/**
* Aqui o scan fica com as funções do lexer
* Vai ler um char por vez doo input file mas tem vezes que 
* vou ter que devolver um char se eu ler muito à frente 
* da stream.
* também tem essa de querer saber qual é a llinha que estou
* para poder printar o num da linha nas mensagens de debug
*/

static int next(void){
    int c;

    if(devolve){
        c = devolve; // usa o char put
        devolve = 0; // volta se tiver um lá
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
    devolve = c;
}

static int skip(void){
    // Yá, Rui... essa função aqui pula os espaços em branco
    // do tipo, espaços em branco, trocas de linha e blá blá
    // e depois retorn o primeiro char que vou ter que lidar com ele
    int c;

    c = next();
    while(' ' == d||'\n' == c || '\n' == c || '\r' == c || '\f' == c){
        c = next();
    }
    return (c);
}
/***
*   É aqui que a vaca começa tossir
*   Mô primeiro lexer scanner
*/
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
            break;
    }
    printf("O character introduzido '%c' na linha %i não é reconhecido\n",c,Linha);
    return (1); // encontrei um token
}

static int scanint(int c){
    int k, val = 0;

    while((k = chrpos("0123456789",c)) >= 0){
        val = val * 10 + k;
        c = next();
    }
    devolve(c);
    return val;
}