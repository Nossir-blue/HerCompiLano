#include <locale.h>

struct ASTnode *makeASTNode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue){
    setlocale(LC_ALL,"Portuguese");
    struct ASTnode *n;

    n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
    if(n == NULL){
        fprintf(stderr, "Impossível fazer alocação de memória em makeASTNode()\n");
        exit(1);
    }
    n->op = op;
    n->esquerda = esquerda;
    n->direita = direita;
    n->intvalue = intvalue;
    return (n);
}
