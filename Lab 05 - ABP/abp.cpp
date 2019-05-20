/*
 * Arquivo:   abp.cpp
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 * Trechos do código foram criados pela Prof.ª Dr.ª Renata Galante
 *
 * Criado em 19 de Maio de 2019, 18:50
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "abp.h"


/** \brief Insere novo novo em uma dada arvore
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param ch - valor inteiro do tipo tipoinfo que sera acrescido na arvore na posicao correspondente ao seu valor
 * \return ponteiro para a raiz da arvore modificada com o novo valor inserido
 *
 */
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     /* Caso a árvore seja nula - isto é, esteja vazia -, adiciona novo elemento como raiz
     e indica que não existem elementos filhos */
     if (a == NULL) {
            a =  (pNodoA*) malloc(sizeof(pNodoA));
            a->info = ch;
            a->esq = NULL;
            a->dir = NULL;
            return a;
     } else {
         /* Caso a árvore não esteja vazia */
         /* Verifica se o valor é menor do que o da subárvore atual */
         if (ch < a->info){
            /* Caso seja menor, o insere na esquerda da subárvore */
            a->esq = InsereArvore(a->esq,ch);
         }
        else if (ch > a->info){
            /* Caso seja maior, o insere na direita da subárvore */
            a->dir = InsereArvore(a->dir,ch);
        }
     }
     return a;
}

/** \brief Busca caminho entre o valor 1 até o valor 2 entrados e imprime o mesmo
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param valor1 - inteiro do tipo tipoinfo que sera o valor inicial do caminho
 * \param valor2 - inteiro do tipo tipoinfo que sera o valor final do caminho
 *
 */
void caminho(pNodoA *a, tipoinfo valor1, tipoinfo valor2){
    // Indica de onde o caminho será traçado
    printf("Caminho entre o %d-%d:\n", valor1, valor2);

    /* Verifica se a árvore está vazia */
    if ( a == NULL ){
        printf("A arvore esta vazia\n");
    } else{
        /* Se a árvore não estiver vazia */
        /* Busca se existe o valor1 na árvore entrada e se o valor2 é descendente do valor1 */
        pNodoA *nodoValor1;
        nodoValor1 = consultaABP(a, valor1);
        if (consultaABP(nodoValor1, valor2) == NULL){
                printf("Nao foi possivel estabelecer o caminho entre os dois nodos\n");
        } else {
            /* Caso valor2 for descendente do valor1, percorre imprimindo caminho entre eles */
            pNodoA *aux = nodoValor1;
            printf("-> %d\n", aux->info);   // imprime o valor1
            int nivel = 2;                  // variavel auxiliar para fazer uma interface bonitinha que demonstra os niveis

            /* Percorre a subárvore do valor1 até encontrar o valor2 */
            while ( (aux != NULL) && (aux->info != valor2) ){
                // se o valor2 for menor que a subarvore atual, desloca para a para a subarvore filha da esquerda
                if (aux->info > valor2){
                    aux = aux->esq;
                }
                // se o valor2 for maior que a subarvore atual, desloca para a para a subarvore filha da direita
                else {
                    aux = aux->dir;
                }

                for (int i = 0; i < nivel; i++){    // essa parte é da interface que mostra os niveis
                    printf("-");
                }
                printf("> %d\n", aux->info);        // imprime o valor do nivel do caminho
                nivel++;
            }
        }
    }
    printf("\n");
}

/** \brief Busca na arvore entrada, o nodo com o valor mais proximo do valor entrado
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param valor - Inteiro do tipo tipoinfo que sera usado de parametro para a busca do valor mais proximo
 * \return Retorna valor de nodo da arvore mais proximo do valor entrado. Retorna -1 caso a árvore estiver vazia
 *
 */
tipoinfo valorMaisProximo(pNodoA *a, tipoinfo valor){
    /* Verifica se a árvore está vazia */
    if ( a == NULL ){
        printf("A arvore esta vazia");
        return -1;
    } else{
        /* Caso não esteja, percorre árvore */
        while(a != NULL){

            if (valor == a->info){
                /* caso o valor entrado seja igual ao do nodo atual, retorna esse valor */
                return a->info;
            } else if (valor < a->info){
                /* caso o valor seja menor ao do nodo atual */
                if (a->esq == NULL){
                        /* Caso não exista mais filhos à esquerda do nodo atual, retorna o valor desse nodo */
                        return a->info;
                } else {
                    /* Caso exista um filho à esquerda, compara a diferença do valor com o valor do nodo atual
                    com a diferença do valor com o valor do filho à esquerda */
                    if ( abs(valor - (a->info)) < abs(valor - (a->esq->info)) ){
                        /* Caso o valor seja mais próximo do nodo atual, retorna esse nodo */
                        return a->info;
                    } else {
                        /* Caso o valor seja mais próximo do filho à esquerda, poda árvore para o descendente esquerdo */
                        a = a->esq;
                    }
                }
            } else if (valor > a->info){
                /* caso o valor seja maior ao do nodo atual */
                if (a->dir == NULL){
                        /* Caso não exista mais filhos à direita do nodo atual, retorna o valor desse nodo */
                        return a->info;
                } else {
                    /* Caso exista um filho à direita, compara a diferença do valor com o valor do nodo atual
                    com a diferença do valor com o valor do filho à direita */
                    if ( abs(valor - (a->info)) < abs(valor - (a->dir->info)) ){
                        /* Caso o valor seja mais próximo do nodo atual, retorna esse nodo */
                        return a->info;
                    } else {
                        /* Caso o valor seja mais próximo do filho à direita, poda árvore para o descendente direito */
                        a = a->dir;
                    }
                }
            }
        }
    }
}


/** \brief Consulta uma arvore binaria de pesquisa se existe o valor entrado
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param chave - inteiro do tipo tipoinfo que sera buscado na arvore
 * \return Retorna ponteiro para o nodo com o valor entrado
 *
 */
pNodoA* consultaABP(pNodoA *a, tipoinfo chave) {
    /* Percorre até chegar ao fim da árvore */
    while (a!=NULL){
        //se o valor da raiz da subárvore atual for igual ao procurado
        if (a->info == chave){
            return a; //achou então retorna o ponteiro para o nodo
        } else {
            //se não, verifica se o valor procurado é maior ou menor que o valor da subárvore atual
            if (a->info > chave){
                // se for valor procurado (chave) for menor, poda para a subarvore filha da esquerda
                a = a->esq;
            } else {
               // se for valor procurado (chave) for maior, poda para a subarvore filha da direita
               a = a->dir;
            }
          }
    }
    return NULL; //se não achou
}
