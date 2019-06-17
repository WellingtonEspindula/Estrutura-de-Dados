#include <string.h>
#include "top_hashtags.h"


PtrHashtagST* New(char *hashtag, int count, PtrHashtagST* esq, PtrHashtagST* dir)
{ 
  PtrHashtagST* x = (PtrHashtagST*) malloc(sizeof(PtrHashtagST));
  strcpy(x->hashtag, hashtag); 
  x->count = count;
  x->esq = esq; 
  x->dir = dir;
  return x;
};

PtrHashtagST* Insert(char *hashtag, PtrHashtagST* t)
{ 
  return Splay(t,hashtag);
};

PtrHashtagST* Select(PtrHashtagST* t, char *hashtag)
{
 if (t == NULL) return NULL;
 t = ConsultaSplay(t, hashtag);
 return t;
};

PtrHashtagST* Remove(PtrHashtagST* t, char *hashtag){
       PtrHashtagST* x;
       if (t == NULL) {
           return NULL;
       }
       t = Consulta(t,hashtag);
       if (strcmp(hashtag, t->hashtag) == 0) {               /* achou */
          if (t->esq == NULL) {
	           x = t->dir;
          } else {
	        x = Consulta(t->esq, hashtag);
	        x->dir = t->dir;
	        }
	        free(t);
	        return x;
       }
       return t;                         /* It wasn't there */
};

void Destroy(PtrHashtagST* t)
{
 if(t->esq != NULL) Destroi(t->esq);
 if(t->dir != NULL) Destroi(t->dir);
 free(t);
};

PtrHashtagST* Splay(PtrHashtagST* t, char *hashtag)
{ 
  if (t == NULL) {
      return Novo(hashtag, NULL, NULL);  
  }
  if (strcmp(hashtag, t->hashtag) < 0) 
  { 
    if (t->esq == NULL) {
        return New(hashtag, 1, NULL, t);
    }
    if (strcmp(hashtag, t->esq->hashtag)) { 
      t->esq->esq = Splay(t->esq->esq, hashtag);
      t = RotDir(t);
    }
    else { 
        t->esq->dir = Splay(t->esq->dir, hashtag);
        t->esq = RotEsq(t->esq);
    }
    return RotDir(t); 
  }
  else
  { 
    if (t->dir == NULL) {
        return New(hashtag, 1, t, NULL);
    }
    if (strcmp(t->dir->hashtag, hashtag) < 0) { 
        t->dir->dir = Splay(t->dir->dir, hashtag);
        t = RotEsq(t);
    }
    else { 
        t->dir->esq = Splay(t->dir->esq, hashtag);
        t->dir = RotDir(t->dir);
    }
    return RotEsq(t);
  }
};

PtNodo* ConsultaSplay(PtNodo* t, int key)
{
 if (t == NULL) return NULL;
 if (key < t->key) {
    if (t->esq == NULL) return t;
	  if (key < t->esq->key) {
       t->esq->esq = ConsultaSplay(t->esq->esq, key);
	     t = RotDir(t);
	     if (t->esq == NULL) return t;
	     else return RotDir(t);
    } else if (t->esq->key , key) {
              t->esq->dir = ConsultaSplay(t->esq->dir, key);
	            if (t->esq->dir != NULL) t->esq = RotEsq(t->esq);
	            return RotDir(t);
           } else return RotDir(t);
 } else if(t->key < key) {
	         if (t->dir == NULL) return t;
	         if (t->dir->key < key) {
	            t->dir->dir = ConsultaSplay(t->dir->dir, key);
	            t = RotEsq(t);
	            if (t->dir == NULL) return t;
	            else return RotEsq(t);
           } else if (key < t->dir->key) {
	                   t->dir->esq = ConsultaSplay(t->dir->esq, key);
                     if (t->dir->esq != NULL) t->dir = RotDir(t->dir);
	                   return RotEsq(t);
                     } else return RotEsq(t);
        } else
 return t;
};

PtNodo* RotDir(PtNodo* t)
{ 
  PtNodo* x = t->esq;
  t->esq = x->dir;
  x->dir = t;
  return x; 
};

PtNodo* RotEsq(PtNodo* t)
{ 
  PtNodo* x = t->dir;
  t->dir = x->esq;
  x->esq = t;
  return x;
};

// void Desenha(PtNodo* t, int nivel)
// {
// int x;
//  if (t !=NULL)
//  {
//    for (x=1; x<=nivel; x++)
//       printf("=");
//    printf("%d \n", t->key);
//    if (t->esq != NULL) Desenha(t->esq, (nivel+1));
//    if (t->dir != NULL) Desenha(t->dir, (nivel+1));
//  }
//  else printf("Arvore Vazia");
// };
