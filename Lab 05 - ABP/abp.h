/*
 * Arquivo:   abp.h
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 * Trechos do código foram criados pela Prof.ª Dr.ª Renata Galante
 *
 * Criado em 19 de Maio de 2019, 18:50
*/


typedef int tipoinfo;

/* Estrutura base para as árvores */
struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;



/** \brief Insere novo novo em uma dada arvore
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param ch - valor inteiro do tipo tipoinfo que sera acrescido na arvore na posicao correspondente ao seu valor
 * \return ponteiro para a raiz da arvore modificada com o novo valor inserido
 *
 */
pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);


/** \brief Busca caminho entre o valor 1 até o valor 2 entrados e imprime o mesmo
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param valor1 - inteiro do tipo tipoinfo que sera o valor inicial do caminho
 * \param valor2 - inteiro do tipo tipoinfo que sera o valor final do caminho
 *
 */
void caminho(pNodoA *a, tipoinfo valor1, tipoinfo valor2);


/** \brief Busca na arvore entrada, o nodo com o valor mais proximo do valor entrado
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param valor - Inteiro do tipo tipoinfo que sera usado de parametro para a busca do valor mais proximo
 * \return Retorna valor de nodo da arvore mais proximo do valor entrado. Retorna -1 caso a árvore estiver vazia
 *
 */
tipoinfo valorMaisProximo(pNodoA *a, tipoinfo valor);


/** \brief Consulta uma arvore binaria de pesquisa se existe o valor entrado
 *
 * \param *a - Ponteiro do tipo pNodo para a raiz da arvore
 * \param chave - inteiro do tipo tipoinfo que sera buscado na arvore
 * \return Retorna ponteiro para o nodo com o valor entrado
 *
 */
pNodoA* consultaABP(pNodoA *a, tipoinfo chave);
