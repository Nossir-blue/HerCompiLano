# Para os colegas de TAC
Está aqui o repositório actualizado com o analisador léxico feito em java

## Do que ele consiste?

Consiste de apenas 3 classes, a classe principal, a classe do lexer e a classe dos tokens
## Main

Esta classe apenas contém o código que executa o analisador léxico com um simples programa
## Lexer

Esta classe é onde está a lógica do Analisador Léxico
Nela eu usei a biblioteca específica para gerar Expressões Regulares (Tirei do Livro de Java que meti no grupo); Usei arraylists porque é meio difícil trabalhar com vectores pelo simples motivo de darem erro "out of bounds" e causar uns erros nada haver com os Tokens; Usei StringBuilder, que é uma biblioteca java que basicamente serve para copiar o conteúdo de uma variável e concatenar mais coisas já que Strings não imutáveis.

## Token

Nesta classe apenas contém enumerações de tokens para poder fazer a sua estrutura.

## Orientação

À partir daqui já temos a base do compilador. O que é será depois daqui?

# Equipa de testes

Por favor, baixem este repositório e testem o analisador léxico de todas as formas, o objectivo é ver como ele funciona, onde não funciona e as partes que estão com problemas

Para contexto, só usei 4 palavras chaves que são: "if", "else", "return" e "while"

Para mais informações, é só lerem o código na classe "Token"

Toda e qualquer descoberta, façam em um documento e mandem no grupo

# Equipa de programação
A minha parte está tecnicamente feita, só estou a depender da equipa de testes

O dev encarregado de fazer a análise sintática irá fazer a análise sintática e a árvore sintática, a árvore sintática é uma estrutura de dados indispensável na criação de parsers pois ela é que irá fazer a estrutura da gramática do nosso compilador e eu irei dar o máximo para ajudar ele

O dev encarregado da análise semântica possivelmente é o que está a lidar com coisa pesada porque é essa parte que lida com contexto e para isso entra a próxima secção

# Equipa de Optimização

Avaliem o meu código e ao mesmo tempo quero que vocês ajudem o dev encarregado da Análise Semântica
##### Não espero muito que façam a optimização do analisador léxico agora pelo simples facto de o código ainda não ter sido modularizado por completo então a prioridade seria ajudarem no Context e também começarem os estudos de ASSEMBLY

# Equipa da Documentação

Este README.md contém algumas informações que podem vir a ser documentadas, os conteúdos usados estão logo à baixo
##### Sobre as dificuldades (Já que é o que será documentado)

Fazer o Analisador Léxico (por favor, entendam que eu chamo isso de LEXER, é muito tempo só para escrever Analisador Léxico) foi um processo Pesado porque eu tive que estudar uma cadeira que eu tenho dificuldades, ao mesmo tempo com estudos de compiladores que nunca tive enquanto tive que relembrar a sintáxe de java e aprender novas funções que ajudaram no processo de criação.

Uma das maiores dificuldade que enfrentei foi me adaptar ao paradigma funcional que a nova versão do java implementou na sua linguagem em certas bibliotecas e funções, exemplo são as funções anónimas aonde eu pude usar uma função sem nome com a palavra chave "static", que me permite criar um bloco de código sem precisar deixar explícito que é uma função com algum tipo de retorno

Outra dificuldade foi implementar a biblioteca de Expressões regulares (REGEX), antes de saber a sua existência, eu tive que me forçar a aprender o básico de Autômatos finitos (Não determinísticos e determinísticos) e expressões regulares da cadeira de Linguagens Formais e Autômatos, foi difícil porque não tenho tempo para praticar o que estou a aprender então sempre que eu tinha um entendimento básico, eu aplicava logo, o que resultou em um monte de Fluxos de Controlo, o que deixou o código enorme e confuso na hora de detectar erros. Após ler o Livro sobre java 17 (embora eu esteja a usar o 21) descobri que Java tem bibliotecas que lidam com expressões regulares, a sua sintáxe é meio confusa de se entender no princípio mas com um pouco de esforço, o que eram mais de 90 linhas de código reduziram para 50.

# Para a Gestora de projecto

O Cronograma de desenvolvimento da minha parte foi basicamente 24/7, desde o dia que defendemos até hoje que terminei, eu tenho dedicado este tempo todo somente à compiladores
#### Sexta (dia 17) - Dia gasto com lendo livros de compiladores
#### Sábado (Dia 18) - Dia gasto vendo aulas de design de compiladores e LFA
#### Domingo (dia 19) - Dia gasto tentando refazer o lexer já que eu tinha feito em C a primeira vez e houve a reunião do grupo as 19h30
#### Segunda (Dia 20) - Adoeci, não pude fazer nada por estar insconsciente
#### Terça (Dia 21) - Dia gasto lendo livro de java enquanto tentava fazer a correspondência com os tokens e os seus valores
#### Quarta (dia 22 - hoje) dia gasto fazendo o Lexer e terminei as 15h20

# Conteúdos usados
#### O Livro que o Rui mandou no Grupo
#### Construindo Compiladores (Livro que mandei no Grupo)
#### Dragon Book (Outro Livro de compiladores, acho que mandei no grupo)
#### Wikipedia: Analisador Léxico (Sim, usei wikipedia) - https://pt.wikipedia.org/wiki/An%C3%A1lise_l%C3%A9xica
#### Neso Academy (Canal do youtube para entender design de compiladores) - https://www.youtube.com/playlist?list=PLBlnK6fEyqRjT3oJxFXRgjPNzeS-LFY-q
#### Pixeled (Canal do youtube com a playlist "Lets make a compiler") - https://www.youtube.com/playlist?list=PLUDlas_Zy_qC7c5tCgTMYq2idyyT241q

