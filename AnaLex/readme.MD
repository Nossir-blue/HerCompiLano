# AnaLex
Aqui está o Lexer.
Para uma primeira versão, ele só pega tokens numéricos mas o objectivo é fazer a tokenização de outros lexemas
## Overview
O objectivo do Lexer como vocês já sabem, é de pegar input de fora, transformar a linguagem introduzida em HLL Puro, armazenar tudo em uma tabema de símbolos e passar os Tokens ao Parser.

# Possíveis Dúvidas
## Estás a programar em C, qual linguagem é essa que estás a usar que tem .h?
Na verdade, tanto .c quanto .h são apenas extensões da linguagem C, pensa da seguinte forma, da mesma maneira que tem .js e jsr para javascript e ficheiros react, o .c e o .h são a mesma coisa mas para fins diferente
- .c é onde fica o código fonte, basicamente é onde programas lá e fazes as coisas acontecerem.
- .h são header files, eles são blocos de código que têm como função, serem importados, estás a ver os #include <stdio.h>? Yá, stdio.h na verdade é um header file com código importado. É como se estivesses a importar classes em Java.
## E esse Makefile é o quê?
Makefile é apenas um ficheiro que serve para escrever scripts para o terminal do ubuntu (Sim, estou a programar no Ubuntu e não no Windos). O que gera outra questão.
## Orroh? Do nada mesmo trocaste Windows para usar Linux? Porquê?
Porque eu simplesmente quis, o código funciona de qualquer jeito, o que muda seria a plataforma alvo mas isso seria na parte do backend, então yá, Baixa só o código no teu Windows e usa, vai funcionar de qualquer jeito

# Um pouco sobre os ficheiro que estão aqui
## Scan.c
Aqui acontece o scan dos lexemas introduzidos
## defs.h
Aqui eu estou a fazer as estruturas das árvores sintáticas e tokens
## tree.c
Aqui estou a construir árvores sintáticas abstratas (ASA) e a fazer alguns nós, é aquela cena de LFA QUE NINGUÉM QUER ESTUDAR PARA E AJUDAR, PORRA PELO AMOR DE DEUS NÉH T-T
## data.h
Nada de especial, são só apenas dados para ser exportados ao scan.c
## main.c
Acho que é auto-explicativo néh, é aqui onde fica o código principal, depois explico como ele funciona e a relação com outros c-files e header-files porque estou sem tempo e preciso terminar meu trabalho de base de dados e estudar para a prova de amanhã... tá fodido


# Palavras-Chaves usadas neste README.MD
Lexer - Analisador Léxico
Parser - Analisador Sintático
Tokenização - Extrair o significado dos Lexemas
Lexema - Tudo que é declarado que precisa ser analisado
HLL Puro - High Level Language (Linguagem de alto nível)
Header file - ficheiro header, o .h
c-file - ficheiro C, o .c