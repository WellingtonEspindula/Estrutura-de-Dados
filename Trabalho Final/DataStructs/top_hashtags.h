/* Estrutura base para a árvore splay usada para encontrar as
hashtags mais citadas  */
struct HashtagsSplayTree {
        char hashtag[280];
        int count;
        struct HashtagsSplayTree *esq;
        struct HashtagsSplayTree *dir;
};
typedef struct HashtagsSplayTree PtrHashtagST;

/* Funcoes */
PtrHashtagST* New(char *hashtag, int count, PtrHashtagST* esq, PtrHashtagST* dir);
PtrHashtagST* Insert(char *hashtag, PtrHashtagST* t);
PtrHashtagST* Splay(PtrHashtagST* t, char *hashtag);
PtrHashtagST* Select(PtrHashtagST* t, char *hashtag);
PtrHashtagST* Remove(PtrHashtagST* t, char *hashtag);
void Destroy(PtrHashtagST* t);

/* Funcoes Auxiliares */
PtrHashtagST* RotEsq(PtrHashtagST* t);
PtrHashtagST* RotDir(PtrHashtagST* t);
// void Desenha(PtNodo* t , int nivel);
PtrHashtagST* ConsultaSplay(PtrHashtagST* t, char *hashtag);
