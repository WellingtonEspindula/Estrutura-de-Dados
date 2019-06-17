#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "top_hashtags.h"

/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
HashtagTL *initialize(HashtagTL *ptHashtag){
  ptHashtag = (HashtagTL *) malloc(sizeof(HashtagTL));
  return ptHashtag;
}


HashtagTL *select(HashtagTL *ptHashtag, char *hashtag){
  while (ptHashtag != NULL)
  {
    if (strcmp(ptHashtag->hashtag, hashtag) == 0){
      return ptHashtag;
    }  
    ptHashtag = ptHashtag->next;
  }

  return NULL;
  
}

HashtagTL *hashtagOcurrence(HashtagTL *ptHashtag, char *hashtag){
  if (select(ptHashtag, hashtag) != NULL){
    
  } else {
    return insert(ptHashtag, hashtag);
  }
}


HashtagTL *insert(HashtagTL *ptHashtag, char *hashtag){
    // Novo elemento que será inserido na lista
    HashtagTL *new;
    // aloca memória para o elemento
    new = (HashtagTL*) malloc(sizeof(HashtagTL));
    // adiciona as informacoes na estrutura apontada pelo ponteiro
    strcpy(new->hashtag, hashtag);
    new->count = 1;
  
    /* Caso a lista esteja vazia, indica que a lista será composta
    unicamente pelo elemento criado acima e aponta para uma próxima posição nula */
    if (ptHashtag == NULL)
    {
        ptHashtag = new;
        ptHashtag->prev = ptHashtag;
        ptHashtag->next = ptHashtag;
        return ptHashtag;
    }
    else
    {
        /* Caso a lista não esteja vazia, procura a posicao na qual a hashtag se enquada (ordem alfabetica) */
        HashtagTL *aux = ptHashtag;
        while ( (aux->count < 1) || (aux->prev == ptHashtag) ) 
        {
          if (strcmp(aux->hashtag, hashtag) == 0){            // Caso a hashtag ja tenha sido inserida
            return ptHashtag;                                 // retorna a lista sem alteracoes
          } else if (strcmp(aux->hashtag, hashtag) < 0){      // Caso a hashtag a ser inserida seja "maior" que a hashtag atual
              if (strcmp(aux->prev->hashtag, hashtag) > 0){   // Caso a hashtag a ser inserida seja "menor" que a hashtag anterior
                /* Aqui devera ser inserida a hashtag */
                
                /* Insere no meio da hashtag "maior" e hashtag "menor" */
                aux = aux->prev;
                new->next = aux->next;                        
                new->prev = aux;                              
                aux->next->prev = new;                        
                aux->next = new;  
                return ptHashtag;                            
              }
          }
          aux = aux->prev;
        }     
    }
}


HashtagTL *remove(HashtagTL *ptHashtag, char *hashtag){

}


HashtagTL *destroy(HashtagTL *ptLista){
    if (ptLista != NULL)             // Verifica se a lista é nula para evitar erros
    {
        HashtagTL *aux1 = ptLista;   // auxiliar que recebe a primeira posição da lista
        HashtagTL *aux2;

        do                          // enquanto não chegar ao fim da lista
        {
            aux2 = aux1;            // utiliza 2 auxiliares para guardar a informação da próxima posição e da posição atual da lista
            aux1 = aux1->next;
            free(aux2);             // e liberar a memória da posição atual
        }
        while (aux1 != ptLista);
    }

    return NULL;                    // retorna a lista como nula
}


/* Auxiliares */
void show(HashtagTL *ptLista){
    HashtagTL *aux;
    aux = ptLista;

    printf("\n----- LISTA -----\n");
    /* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
    if (ptLista != NULL)            // Verifica se a lista é nula para evitar erros
    {
        do
        {
            printf("%s: %d\n", aux->hashtag, aux->count);
            aux = aux->next;
        }
        while (aux != ptLista);
    }
    printf("----- FIM DA LISTA -----\n");

    getchar(); //gambiarra para limpar o buffer e pausar a execução do programa em ambiente linux e windows.
    getchar(); //Similar ao system("PAUSE");
}

