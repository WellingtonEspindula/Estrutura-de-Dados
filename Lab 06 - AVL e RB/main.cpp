/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.ª Dr.ª Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementação de uma ABP (Árvore Binária de Pesquisa)
 * usando conceitos de AVLs e Árvores Rubro-Negras utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma estrutura dada, e o programa deverá realizar:
 *      1. Inserção de nodos em uma ABP que armazene números inteiros.
 *      2. Retornar o fator de um nodo da arvore dado o valor do novo;
 *      3. Verificar se a árvore é uma AVL.
 *      4. Verificar se a árvore é uma Árvore Rubro-Negra.
 *
*/


/*
 * Arquivo:   main.cpp
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 * Trechos do código foram criados pela Prof.ª Dr.ª Renata Galante
 *
 * Criado em 19 de Maio de 2019, 18:50
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"


/* MÉTODOS LOCAIS */
void entrada_manual();
void testes();
void clear_screen();


int main(){
    int entrada;

    do {
        /* MENU INICIAL */
        clear_screen();
        printf("Digite:\n");
        printf("0 - Sair\n");
        printf("1 - Executar testes internos\n");
        printf("2 - Testar manualmente\n");
        scanf("%d", &entrada);
        int valor;

        switch (entrada)
        {
        case 1:
            testes();
            break;
        case 2:
            entrada_manual();
            break;
        }
    }
    while (entrada != 0);

    return 0;
}

/* Opcao de teste por entrada manual */
void entrada_manual(){
    pNodoA *arv = NULL;
    int entrada = 0;

    clear_screen();
    do {
        printf("Entre com um valor a ser adicionado na arvore.\nDigite 0 para parar\n");
        scanf("%d", &entrada);
        printf("\n");

        if (entrada != 0) {
            // Testa o método InsereArvore
            arv = InsereArvore(arv, entrada);
        }
    } while (entrada != 0);

    // Testa o método FatorNodo
    int nodo = 0;
    printf("Digite o valor do nodo que quer encontrar o fator:\n");
    scanf("%d", &nodo);
    printf("A fator do nodo %d eh %d\n", nodo, fatorNodo(arv, nodo));

    // Testa o método ehAVL
    if (ehArvoreAVL(arv)){
        printf("A arvore eh AVL\n");
    } else {
        printf("A arvore nao eh AVL\n");
    }

    // Testa o método ehRN
    if (ehArvoreRN(arv)){
        printf("A arvore eh RN\n");
    } else {
        printf("A arvore nao eh RN\n");
    }

    getchar();
    getchar();
}


/* Opcao de testes pre programados */
void testes(){
    clear_screen();

    pNodoA *arv = NULL;

    // Testa o método InsereArvore
    arv = InsereArvore(arv,35);
    arv = InsereArvore(arv,02);
    arv = InsereArvore(arv,06);
    arv = InsereArvore(arv,28);
    arv = InsereArvore(arv,71);
    arv = InsereArvore(arv,73);
    arv = InsereArvore(arv,49);
    arv = InsereArvore(arv,44);
    arv = InsereArvore(arv,50);

    // Testa o método FatorNodo
    printf("A fator do nodo %d eh %d\n", 2, fatorNodo(arv, 2));
    printf("A fator do nodo %d eh %d\n", 71, fatorNodo(arv, 71));
    printf("A fator do nodo %d eh %d\n", 35, fatorNodo(arv, 35));

    // Testa o método ehAVL
    if (ehArvoreAVL(arv)){
        printf("A arvore eh AVL\n");
    } else {
        printf("A arvore nao eh AVL\n");
    }

    // Testa o método ehRN
    if (ehArvoreRN(arv)){
        printf("A arvore eh RN\n");
    } else {
        printf("A arvore nao eh RN\n");
    }

    getchar();
    getchar();
}


/** \brief Limpa o console em linux e windows */
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}
