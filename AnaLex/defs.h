// extrutura do token
struct token{
    int token, intvalue;
};

// Os tokens
enum{
    T_MAIS, T_MENOS, T_ASTERISCO, T_BARRA, T_INTLIT
    /*
    *   INTLIT -> IntegerLiteral
    *   Quando o token é um integer literal, o intvalue vai
    *   guardar esse número
    */
};

enum{
    A_ADICIONAR, A_SUBTRAIR, A_MULTIPLICAR, A_DIVIDIR, A_INTLIT
};

struct ASTnode{
    int op;
    struct ASTnode *esquerda;
    struct ASTnode *direita;
    int intvalue;
}
