/* Estrutura base para a lista duplamente encadeada circular usada para encontrar as
hashtags mais citadas  */
struct HashtagTopList {
        char hashtag[280];
        int count;
        struct HashtagTopList *prev;
        struct HashtagTopList *next;
};
typedef struct HashtagTopList HashtagTL;

/* Funcoes */


/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
HashtagTL *initialize(HashtagTL *ptHashtag);


/* TODO  */
HashtagTL *select(HashtagTL *ptHashtag, char *hashtag);

/* TODO  */
HashtagTL *hashtagOcurrence(HashtagTL *ptHashtag, char *hashtag);

/** \brief Método que insere elementos na LDEC
 * \param *ptHashtag - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \param *hashtag - string da hashtag que sera inserida na lista
 * \return Retorna lista com elementos inseridos
*/
HashtagTL *insert(HashtagTL *ptHashtag, char *hashtag){

/* TODO */
HashtagTL *remove(HashtagTL *ptHashtag, char *hashtag);

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDEC
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
HashtagTL *destroy(HashtagTL *ptLista);


/* Auxiliares */

/** \brief Método que exibe a lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
void show(HashtagTL *ptLista);
