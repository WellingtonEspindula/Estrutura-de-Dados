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


#define TRUE 1
#define FALSE 0


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

/** \brief Busca caminho entre o valor 1 ate o valor 2 entrados e imprime o mesmo
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
        /* Busca se existe o valor1 na arvore entrada e se o valor2 eh descendente do valor1 */
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
pNodoA *consultaABP(pNodoA *a, tipoinfo chave) {
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


/** \brief Dada uma árvore/subarvore determinada pelo ponteiro entrado, retorna a altura de dado nodo em um ABP
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz/subraiz da arvore
 * \return Retorna a altura do nodo
 *
 */
int altura(pNodoA *a) {
    int Alt_Esq, Alt_Dir;

    if (a == NULL){
        return 0;
    } else {
        Alt_Esq = altura(a->esq);
        Alt_Dir = altura(a->dir);

        if (Alt_Esq > Alt_Dir){
            return (1 + Alt_Esq);
        } else {
            return (1 + Alt_Dir);
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
int fatorNodo(pNodoA *a, tipoinfo chave) {
    /* Percorre at� chegar ao fim da �rvore */
    while (a!=NULL){
        //se o valor da raiz da sub�rvore atual for igual ao procurado
        if (a->info == chave){
            return (altura(a->esq) - altura(a->dir)); //achou, então retorna a diferença entre a altura do filho esquerdo e o filho direito
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


/** \brief Retorna se a arvore eh uma AVL
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \return Retorna 1 se a arvore for AVL; 0 caso a arvore nao seja AVL
 *
 */
int ehArvoreAVL(pNodoA *a) {
    static int ehAVL = TRUE;    // variavel estatica que servira como flag para saber se a arvore eh AVL

    if (a == NULL){             // se o nodo for nulo
        return ehAVL;           // retorna o valor atual de ehAVL
    } else {                    // se o nodo não for nulo
        ehAVL = ehArvoreAVL(a->esq);    // verifica se o filho da esquerda eh AVL
        ehAVL = ehArvoreAVL(a->dir);    // verifica se o flho da direita eh AVL

        int fatorA = altura(a->esq) - altura(a->dir);   // calcula o fator da subarvore atual
        if ( (fatorA > 1) || (fatorA < -1) ){           // se a subarvore exceda o fator 1
            return FALSE;                               // retorna falso
        }
    }

    int aux = ehAVL;    // guarda em uma auxiliar se a arvore eh AVL
    ehAVL = TRUE;       // restaura o estado da variavel estatica para a proxima utilizacao do metodo
    return aux;         // retorna o estado de ehAVL
}


/** \brief Retorna se a arvore eh Rubro-Negra
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \return Retorna 1 se a arvore for rubro-negra; 0 caso a arvore nao seja RN
 *
 */
int ehArvoreRN(pNodoA *a) {
    static int ehRN = TRUE;    // variavel estatica que servira como flag para saber se a arvore eh RN

    if (a == NULL){             // se o nodo for nulo
        return ehRN;           // retorna o valor atual de ehRN
    } else {                    // se o nodo não for nulo
        ehRN = ehArvoreRN(a->esq);    // verifica se o filho da esquerda eh RN
        ehRN = ehArvoreRN(a->dir);    // verifica se o flho da direita eh RN

        /* VALIDACOES PARA A ARVORE NAO SER RUBRO-NEGRA */
        if ( (altura(a->esq) - altura(a->dir)) > 1 ) {          // Verifica se o fator da subarvore eh maior que 1 e verifica se o ramo com maior altura eh o esquerdo)
            if ( (altura(a->esq) > 2*altura(a->dir)) ){         // Verifica se a altura da subarvore esquerda (ramo maior) eh maior que o dobro da altura da subarvore direita (ramo menor)
                return FALSE;                                   // retorna falso
            }
        } else if ( (altura(a->dir) - altura(a->esq)) > 1 ) {   // Verifica se o fator da subarvore eh maior que 1 e verifica se o ramo com maior altura eh o direito)
            if ( (altura(a->dir) > 2*altura(a->esq)) ){         // Verifica se a altura da subarvore direita (ramo maior) eh maior que o dobro da altura da subarvore esquerda (ramo menor)
                return FALSE;                               // retorna falso
            }
        }
    }

    int aux = ehRN;    // guarda em uma auxiliar se a arvore eh RN
    ehRN = TRUE;       // restaura o estado da variavel estatica para a proxima utilizacao do metodo
    return aux;         // retorna o estado de ehRN
}
