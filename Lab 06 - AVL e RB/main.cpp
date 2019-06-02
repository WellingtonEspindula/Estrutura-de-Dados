/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.ª Dr.ª Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementação de uma ABP (Árvore Binária de Pesquisa)
 * utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma lista de uma estrutura dada, e o programa deverá:
 *      1. Função para inserção de nodos em uma ABP que armazene números inteiros.
 *      2. Função que recebe como parâmetro	uma	árvore (arv1) gerada pela função do
 *  exercício 1 e dois valores (valor1 e valor2) e exiba os valores dos nodos do
 *  caminho para se chegar do nodo com o valor1 ate o nodo com o valor2. Se não
 *  existir	caminho, exibir essa informação para o usuário.
 *      3. Função que recebe como parâmetro a árvore gerada no exercício 1 e um	 valor
 *  retorna o valor do nó da árvore que tenha o	valor mais próximo do valor
 *  procurado.
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

int main()
{
   pNodoA *arv = NULL;
   pNodoA *vazia = NULL;


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
   system("pause");

//    Testa o método ehRN
    printf("A arvore eh RN? %d\n\n", ehArvoreRN(arv));

    // Testa o método InsereArvore
    pNodoA *arv1 = NULL;
    arv1 = InsereArvore(arv1,10);
    arv1 = InsereArvore(arv1,5);
    arv1 = InsereArvore(arv1,3);
    arv1 = InsereArvore(arv1,6);
    arv1 = InsereArvore(arv1,11);

   // Testa o método ehRN
    printf("A arvore 1 eh RN? %d\n\n", ehArvoreRN(arv1));


   // Testa o método FatorNodo
//   printf("A fator do nodo %d eh %d\n", 2, fatorNodo(arv, 2));
//   printf("A fator do nodo %d eh %d\n", 71, fatorNodo(arv, 71));
//   printf("A fator do nodo %d eh %d\n", 35, fatorNodo(arv, 35));

//    // Testa o método ehAVL
//    printf("A arvore eh AVL? %d\n", ehArvoreAVL(arv));
//
//    pNodoA *arv1 = NULL;
//    arv1 = InsereArvore(arv1,42);
//    arv1 = InsereArvore(arv1,15);
//    arv1 = InsereArvore(arv1,27);
//    arv1 = InsereArvore(arv1,20);
//    arv1 = InsereArvore(arv1,88);
//    arv1 = InsereArvore(arv1,63);
//    arv1 = InsereArvore(arv1,57);
//    arv1 = InsereArvore(arv1,71);
//
//    // Testa o método ehAVL
//    printf("A arvore 1 eh AVL? %d\n", ehArvoreAVL(arv1));
//
//    // TESTA O METODO ehAVL com uma arvore AVL
//    pNodoA *arv2 = NULL;
//    arv2 = InsereArvore(arv2,42);
//    arv2 = InsereArvore(arv2,15);
//    arv2 = InsereArvore(arv2,6);
//    arv2 = InsereArvore(arv2,27);
//    arv2 = InsereArvore(arv2,20);
//    arv2 = InsereArvore(arv2,88);
//    arv2 = InsereArvore(arv2,63);
//    arv2 = InsereArvore(arv2,94);
//    arv2 = InsereArvore(arv2,57);
//    arv2 = InsereArvore(arv2,71);
//
//    // Testa o método ehAVL
//    printf("A arvore 2 eh AVL? %d\n", ehArvoreAVL(arv2));

   // Testa o método caminho
   // caminho(arv, 45, 95);
   // caminho(arv, 30, 25);
   // caminho(arv, 30, 80);
   // caminho(arv, 95, 45);
   // caminho(arv, 25, 80);
   // caminho(arv, 45, 100);
   // caminho(vazia, 40, 50);
   // system("pause");

    // Testa o método valorMaisProximo
   // printf("O valor mais proximo de %d na arvore e %d\n", 44, valorMaisProximo(arv, 44));
   // printf("O valor mais proximo de %d na arvore e %d\n", 26, valorMaisProximo(arv, 26));
   // printf("O valor mais proximo de %d na arvore e %d\n", 31, valorMaisProximo(arv, 31));
   // printf("O valor mais proximo de %d na arvore e %d\n", 92, valorMaisProximo(arv, 92));
   // printf("O valor mais proximo de %d na arvore e %d\n", 100, valorMaisProximo(arv, 100));
   // printf("O valor mais proximo de %d na arvore e %d\n", 82, valorMaisProximo(arv, 82));
}
