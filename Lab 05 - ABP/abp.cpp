/*
 * Arquivo:   abp.cpp
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 * Trechos do c�digo foram criados pela Prof.� Dr.� Renata Galante
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
     /* Caso a �rvore seja nula - isto �, esteja vazia -, adiciona novo elemento como raiz
     e indica que n�o existem elementos filhos */
     if (a == NULL) {
            a =  (pNodoA*) malloc(sizeof(pNodoA));
            a->info = ch;
            a->esq = NULL;
            a->dir = NULL;
            return a;
     } else {
         /* Caso a �rvore n�o esteja vazia */
         /* Verifica se o valor � menor do que o da sub�rvore atual */
         if (ch < a->info){
            /* Caso seja menor, o insere na esquerda da sub�rvore */
            a->esq = InsereArvore(a->esq,ch);
         }
        else if (ch > a->info){
            /* Caso seja maior, o insere na direita da sub�rvore */
            a->dir = InsereArvore(a->dir,ch);
        }
     }
     return a;
}

/** \brief Busca caminho entre o valor 1 at� o valor 2 entrados e imprime o mesmo
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param valor1 - inteiro do tipo tipoinfo que sera o valor inicial do caminho
 * \param valor2 - inteiro do tipo tipoinfo que sera o valor final do caminho
 *
 */
void caminho(pNodoA *a, tipoinfo valor1, tipoinfo valor2){
    // Indica de onde o caminho ser� tra�ado
    printf("Caminho entre o %d-%d:\n", valor1, valor2);

    /* Verifica se a �rvore est� vazia */
    if ( a == NULL ){
        printf("A arvore esta vazia\n");
    } else{
        /* Se a �rvore n�o estiver vazia */
        /* Busca se existe o valor1 na �rvore entrada e se o valor2 � descendente do valor1 */
        pNodoA *nodoValor1;
        nodoValor1 = consultaABP(a, valor1);
        if (consultaABP(nodoValor1, valor2) == NULL){
                printf("Nao foi possivel estabelecer o caminho entre os dois nodos\n");
        } else {
            /* Caso valor2 for descendente do valor1, percorre imprimindo caminho entre eles */
            pNodoA *aux = nodoValor1;
            printf("-> %d\n", aux->info);   // imprime o valor1
            int nivel = 2;                  // variavel auxiliar para fazer uma interface bonitinha que demonstra os niveis

            /* Percorre a sub�rvore do valor1 at� encontrar o valor2 */
            while ( (aux != NULL) && (aux->info != valor2) ){
                // se o valor2 for menor que a subarvore atual, desloca para a para a subarvore filha da esquerda
                if (aux->info > valor2){
                    aux = aux->esq;
                }
                // se o valor2 for maior que a subarvore atual, desloca para a para a subarvore filha da direita
                else {
                    aux = aux->dir;
                }

                for (int i = 0; i < nivel; i++){    // essa parte � da interface que mostra os niveis
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
 * \return Retorna valor de nodo da arvore mais proximo do valor entrado. Retorna -1 caso a �rvore estiver vazia
 *
 */
tipoinfo valorMaisProximo(pNodoA *a, tipoinfo valor){
    /* Verifica se a �rvore est� vazia */
    if ( a == NULL ){
        printf("A arvore esta vazia");
        return -1;
    } else{
        /* Caso n�o esteja, percorre �rvore */
        while(a != NULL){

            if (valor == a->info){
                /* caso o valor entrado seja igual ao do nodo atual, retorna esse valor */
                return a->info;
            } else if (valor < a->info){
                /* caso o valor seja menor ao do nodo atual */
                if (a->esq == NULL){
                        /* Caso n�o exista mais filhos � esquerda do nodo atual, retorna o valor desse nodo */
                        return a->info;
                } else {
                    /* Caso exista um filho � esquerda, compara a diferen�a do valor com o valor do nodo atual
                    com a diferen�a do valor com o valor do filho � esquerda */
                    if ( abs(valor - (a->info)) < abs(valor - (a->esq->info)) ){
                        /* Caso o valor seja mais pr�ximo do nodo atual, retorna esse nodo */
                        return a->info;
                    } else {
                        /* Caso o valor seja mais pr�ximo do filho � esquerda, poda �rvore para o descendente esquerdo */
                        a = a->esq;
                    }
                }
            } else if (valor > a->info){
                /* caso o valor seja maior ao do nodo atual */
                if (a->dir == NULL){
                        /* Caso n�o exista mais filhos � direita do nodo atual, retorna o valor desse nodo */
                        return a->info;
                } else {
                    /* Caso exista um filho � direita, compara a diferen�a do valor com o valor do nodo atual
                    com a diferen�a do valor com o valor do filho � direita */
                    if ( abs(valor - (a->info)) < abs(valor - (a->dir->info)) ){
                        /* Caso o valor seja mais pr�ximo do nodo atual, retorna esse nodo */
                        return a->info;
                    } else {
                        /* Caso o valor seja mais pr�ximo do filho � direita, poda �rvore para o descendente direito */
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
    /* Percorre at� chegar ao fim da �rvore */
    while (a!=NULL){
        //se o valor da raiz da sub�rvore atual for igual ao procurado
        if (a->info == chave){
            return a; //achou ent�o retorna o ponteiro para o nodo
        } else {
            //se n�o, verifica se o valor procurado � maior ou menor que o valor da sub�rvore atual
            if (a->info > chave){
                // se for valor procurado (chave) for menor, poda para a subarvore filha da esquerda
                a = a->esq;
            } else {
               // se for valor procurado (chave) for maior, poda para a subarvore filha da direita
               a = a->dir;
            }
          }
    }
    return NULL; //se n�o achou
}
