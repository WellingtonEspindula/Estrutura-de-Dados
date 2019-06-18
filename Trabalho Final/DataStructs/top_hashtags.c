#include "top_hashtags.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada
*/
HashtagTL* initializeHTL(HashtagTL *ptHashtag){
  ptHashtag = (HashtagTL *) malloc(sizeof(HashtagTL));
  return ptHashtag;
}


HashtagTL* selectHTL(HashtagTL *ptHashtag, char *hashtag){
  if (ptHashtag != NULL){
    HashtagTL *aux = ptHashtag;
    
    do {
      if (strcmp(aux->hashtag, hashtag) == 0){
        return aux;
      }  
      aux = aux->next;
    } while (aux != ptHashtag);
  }

  return NULL;
  
}

HashtagTL* hashtagOcurrence(HashtagTL *ptHashtag, char *hashtag){
  HashtagTL *selectedHashtag = selectHTL(ptHashtag, hashtag);
  if (selectedHashtag != NULL){

    selectedHashtag->count++;
    HashtagTL *aux = selectedHashtag;

    if (selectedHashtag == ptHashtag){
      return ptHashtag;
    }
    if (selectedHashtag->count > ptHashtag->count){
        selectedHashtag->prev->next = selectedHashtag->next;
        selectedHashtag->next->prev = selectedHashtag->prev;

        ptHashtag->prev->next = selectedHashtag;
        selectedHashtag->prev = ptHashtag->prev;
        selectedHashtag->next = ptHashtag;
        return selectedHashtag;

    } else {
      do{
        aux = aux->prev;

        if (strcmp(aux->hashtag, hashtag) > 0){      // Caso a hashtag a ser inserida seja "maior" que a hashtag atual
            if (strcmp(aux->prev->hashtag, hashtag) < 0){   // Caso a hashtag a ser inserida seja "menor" que a hashtag anterior
              /* Achou a posicao */
              
              /* Retira a hashtag selecionada da sua posicao original*/
              selectedHashtag->prev->next = selectedHashtag->next;
              selectedHashtag->next->prev = selectedHashtag->prev;

              /* Insere no meio da hashtag "maior" e hashtag "menor" */
              selectedHashtag->next = aux->next;                        
              selectedHashtag->prev = aux;                              
              aux->next->prev = selectedHashtag;                        
              aux->next = selectedHashtag;  
              return ptHashtag;                 

                //               aux = aux->prev;
                // new->next = aux->next;                        
                // new->prev = aux;                              
                // aux->next->prev = new;                        
                // aux->next = new;             
            }
          }          
      } while ((aux->count <= selectedHashtag->count) && 
      (aux != selectedHashtag));
    }
    

  } else {
    return insertHTL(ptHashtag, hashtag);
  }
}


HashtagTL* insertHTL(HashtagTL *ptHashtag, char *hashtag){
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
        HashtagTL *aux = ptHashtag->prev;
        while ( (aux->count <= 1) && (aux != ptHashtag) ) 
        {
          if (strcmp(aux->hashtag, hashtag) == 0){            // Caso a hashtag ja tenha sido inserida
            return ptHashtag;                                 // retorna a lista sem alteracoes
          } else if (strcmp(aux->hashtag, hashtag) > 0){      // Caso a hashtag a ser inserida seja "maior" que a hashtag atual
              if (strcmp(aux->prev->hashtag, hashtag) < 0){   // Caso a hashtag a ser inserida seja "menor" que a hashtag anterior
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
        ptHashtag->prev->next = new;
        new->prev = ptHashtag->prev;
        ptHashtag->prev = new;
        new->next = ptHashtag;
        return ptHashtag;     
    }
    return NULL;
}


HashtagTL* removeHTL(HashtagTL *ptHashtag, char *hashtag){
  /* TODO */
  return NULL;
}


/* TODO improves*/
HashtagTL* destroyHTL(HashtagTL *ptLista){
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
void showHTL(HashtagTL *ptLista){
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

    getchar(); //Similar ao system("PAUSE");
}

