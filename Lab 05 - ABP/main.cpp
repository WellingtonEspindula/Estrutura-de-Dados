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
   arv = InsereArvore(arv,30);
   arv = InsereArvore(arv,45);
   arv = InsereArvore(arv,25);
   arv = InsereArvore(arv,90);
   arv = InsereArvore(arv,80);
   arv = InsereArvore(arv,95);
   system("pause");

   // Testa o método caminho
   caminho(arv, 45, 95);
   caminho(arv, 30, 25);
   caminho(arv, 30, 80);
   caminho(arv, 95, 45);
   caminho(arv, 25, 80);
   caminho(arv, 45, 100);
   caminho(vazia, 40, 50);
   system("pause");

    // Testa o método valorMaisProximo
   printf("O valor mais proximo de %d na arvore e %d\n", 44, valorMaisProximo(arv, 44));
   printf("O valor mais proximo de %d na arvore e %d\n", 26, valorMaisProximo(arv, 26));
   printf("O valor mais proximo de %d na arvore e %d\n", 31, valorMaisProximo(arv, 31));
   printf("O valor mais proximo de %d na arvore e %d\n", 92, valorMaisProximo(arv, 92));
   printf("O valor mais proximo de %d na arvore e %d\n", 100, valorMaisProximo(arv, 100));
   printf("O valor mais proximo de %d na arvore e %d\n", 82, valorMaisProximo(arv, 82));
}
