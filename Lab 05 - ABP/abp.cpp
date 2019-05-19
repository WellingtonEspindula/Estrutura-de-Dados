#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "abp.h"



pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     if (a == NULL) {
            a =  (pNodoA*) malloc(sizeof(pNodoA));
            a->info = ch;
            a->esq = NULL;
            a->dir = NULL;
            return a;
     } else {
         if (ch < a->info){
            a->esq = InsereArvore(a->esq,ch);
         }
        else if (ch > a->info){
            a->dir = InsereArvore(a->dir,ch);
        }
     }
     return a;
}


void caminho(pNodoA *a, tipoinfo valor1, tipoinfo valor2){
    printf("Caminho entre o %d-%d:\n", valor1, valor2);

    if ( a == NULL ){       // Verifica se a árvore está vazia
        printf("A arvore esta vazia\n");
    } else{                 // Se a árvore não estiver vazia
        pNodoA *nodoValor1;
        nodoValor1 = consultaABP(a, valor1);
        if (consultaABP(nodoValor1, valor2) == NULL){
                printf("Nao foi possivel estabelecer o caminho entre os dois nodos\n");
        } else {
            pNodoA *aux = nodoValor1;
            printf("-> %d\n", aux->info);
            int nivel = 2;

            while ( (aux != NULL) && (aux->info != valor2) ){
                if (aux->info > valor2){
                    aux = aux->esq;
                }
                else {
                    aux = aux->dir;
                }

                for (int i = 0; i < nivel; i++){
                    printf("-");
                }
                printf("> %d\n", aux->info);
                nivel++;
            }
        }
    }
    printf("\n");
}

/** \brief Busca na arvore entrada, o nodo com o valor mais proximo do valor entrado
 *
 * \param
 * \param
 * \return Retorna valor de nodo da arvore mais proximo do valor entrado. Retorna -1 caso a árvore estiver vazia
 *
 */
tipoinfo valorMaisProximo(pNodoA *a, tipoinfo valor){
    if ( a == NULL ){       // Verifica se a árvore está vazia
        printf("A arvore esta vazia");
        return -1;
    } else{
        while(a != NULL){
            if (valor == a->info){
                return a->info;
            } else if (valor < a->info){
                if (a->esq == NULL){
                        return a->info;
                } else {
                    if ( abs(valor - (a->info)) < abs(valor - (a->esq->info)) ){
                        return a->info;
                    } else {
                        a = a->esq;
                    }
                }
            } else if (valor > a->info){
                if (a->dir == NULL){
                        return a->info;
                } else {
                    if ( abs(valor - (a->info)) < abs(valor - (a->dir->info)) ){
                        return a->info;
                    } else {
                        a = a->dir;
                    }
                }
            }
        }
    }
}

pNodoA* consultaABP(pNodoA *a, tipoinfo chave) {

    while (a!=NULL){
          if (a->info == chave )
             return a; //achou então retorna o ponteiro para o nodo
          else
            if (a->info > chave)
               a = a->esq;
            else
               a = a->dir;
    }
    return NULL; //se não achou
}
