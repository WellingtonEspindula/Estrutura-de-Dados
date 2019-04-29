/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.ª Dr.ª Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementação de uma LSE (Lista Simplesmente Encadeada)
 * utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma lista de uma estrutura dada, e o programa deverá:
 *      1) Inserir os elementos na lista.
 *	2) Exibir a lista.
 *	3) Destruir a lista.
 *  Para a inserção, o programa receberá como entrada um ponteiro e um número.
 * Se o número for positivo e par, o programa deve inseri-lo no início da lista;
 * se o número for positivo e impar, inserir no final da lista; e se o número for negativo, inserir
 * no meio da lista.
 */

/*
 * Arquivo:   main.c
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 29 de Abril de 2019, 18:50
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct tipoNo ptLSE;
struct tipoNo{
	int numero;
	ptLSE *ant;
	ptLSE *prox;
};

//PROTÓTIPOS
ptLSE *inserir(int numero, ptLSE *ptLista);
void exibe(ptLSE *ptLista);
ptLSE *destroi(ptLSE *ptLista);

ptLSE *inicializaLista(ptLSE *ptLista);
ptLSE *retornaUltimoNo(ptLSE *ptLista);
ptLSE *retornaNoMeio(ptLSE *ptLista);
void clear_screen();


int main(){
	ptLSE *ptLista = NULL;

	int entrada;
	do{
        clear_screen();
		printf("Digite:\n");
		printf("0 - Sair\n");
		printf("1 - Inserir\n");
		printf("2 - Exibir lista\n");
		printf("3 - Destruir lista\n");
		scanf("%d", &entrada);
		int valor;

		switch (entrada){
			case 1:
				printf("Digite o valor:\n");
				scanf("%d", &valor);
				ptLista = inserir(valor, ptLista);
				break;
			case 2:
				exibe(ptLista);
				break;
			case 3:
				ptLista = destroi(ptLista);
				break;
		}
	} while (entrada != 0);

	destroi(ptLista);   //Destrói lista antes de terminar o programa

	return 0;
}


/** \brief Método que insere elementos na LSE
 * \param numero - Numero inteiro que sera inserido na lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return Retorna lista com elementos inseridos
*/
ptLSE *inserir(int numero, ptLSE *ptLista){
	// Novo elemento que será inserido na lista
	ptLSE *novo;
	// aloca memória para o elemento
	novo = (ptLSE*) malloc(sizeof(ptLSE));
	// adiciona o número na estrutura apontada pelo ponteiro
	novo->numero = numero;

	/* Caso a lista esteja vazia, indica que a lista será composta
	unicamente pelo elemento criado acima e aponta para uma próxima posição nula*/

	if (ptLista == NULL){
        ptLista = novo;
        ptLista->ant = ptLista;
		ptLista->prox = ptLista;

	} else {

	/* Caso a lista não esteja vazia */

		if (numero >= 0){
	        	if ( (numero % 2) == 0){

                        /* Se o número for positivo e par, insere no topo da lista.
	                        Ou seja, indica que a primeira posição será o novo elemento,
        	                e a próxima do novo elemento apontará pra lista já criada */

                        novo->ant = ptLista->ant;
        	        	novo->prox = ptLista;
		                ptLista = novo;
        	    	}
			else {

                    /* Se o número for positivo e ímpar, o novo ocupará a última posição da lista.
		                E o próximo elemento do novo apontará para uma próxima posição nula */

                                                    // Novo elemento será o novo fim
                    ptLista->ant->prox = novo;      // O antigo fim terá como próxima posição o novo elemento
                    novo->ant = ptLista->ant;       // O novo elemento terá como posição anterior o antigo fim
                    novo->prox = ptLista;           // O novo elemento terá como próxima posição o início da lista
                    ptLista->ant = novo;            // A posição anterior do início da lista será o novo fim

        		}
        	}
		else {

			/* Caso o número for negativo, insere no meio da lista.
        		Assim, pega o nó do meio da lista, e usando um ponteiro auxiliar, o põe no meio */

			ptLSE *aux;
            aux = retornaNoMeio(ptLista);          // aux assumirá a posição (memória) do elemento do meio da lista
			novo->prox = aux->prox;                // o próximo elemento do novo elemento será o próximo do elemento do meio
			novo->ant = aux;                       // o elemento anterior do novo elemento será o próximo elemnto do meio
			aux->prox = novo;                      // o próximo elemento do meio será o novo elemento
		}
	}

	// Retorna a lista com os valor inserido!! xD
	return ptLista;
}

/** \brief Método que exibe a lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
*/
void exibe(ptLSE *ptLista){
	ptLSE *aux;
	aux = ptLista;

	printf("\n----- LISTA -----\n");
	/* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
	do{
		printf("%d\n", aux->numero);
		aux = aux->prox;
	} while (aux != ptLista);

	printf("----- FIM DA LISTA -----\n");

    getchar(); //gambiarra para limpar o buffer e pausar a execução do programa em ambiente linux e windows.
    getchar(); //Similar ao system("PAUSE");

}

// FIXME HERE
/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LSE
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
ptLSE *destroi(ptLSE *ptLista){
    ptLSE *aux;

    while (ptLista != NULL){
            aux = ptLista->prox;
            free(ptLista);
            ptLista = aux;
    }

    return ptLista;
}



/* Funcoes auxiliares */

/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
*/
ptLSE *inicializaLista(ptLSE *ptLista){
	ptLista = (ptLSE *) malloc(sizeof(ptLSE));
	return ptLista;
}

/** OBSOLETO (DEPRECATED)
 * \brief Metodo que retorna o ultimo no da lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return retorna o ponteiro para a posicao de memoria do ultimo no da lista
*/
ptLSE *retornaUltimoNo(ptLSE *ptLista){
	return ptLista->ant;     // retorna a posição de memória do último nó da lista
}

/** \brief Metodo que retorna o Nó que está no meio da lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return retorna o ponteiro para a posicao que ocupa o meio da lista
*/
ptLSE *retornaNoMeio(ptLSE *ptLista){
	ptLSE *aux;         // Ponteiro auxiliar que serve para iterar a lista
	aux = ptLista;      // Ponteiro auxiliar assume o valor do ponteiro para a LSE
	int numNos = 0;     // variável que armazenará o número de nós
	int indiceNo = 0;   // variável que armazenará o índice (quantas iterações que deverão ser feitas para encontrar) do nó do meio

	/* Aqui encontra o número de nós da lista */
	do {
		aux = aux->prox;
		numNos++;
	} while ( aux != ptLista );

	/* Aqui faz o cálculo de quantas iterações deverão ser feitas para encontrar o nó do meio.
        Usa-se o floor para, caso a lista tenha um número ímpares de elementos, encontrar o nó do elemento anterior ao elemento central  */
	indiceNo = (int) floor(numNos / 2);
	aux = ptLista;      // o auxiliar assume novamente o valor do ponteiro para o primeiro elemento da lista, para, assim, iterá-lo até encontrar o nó do meio

	for (int i = 0; i < (indiceNo - 1); i++){
		aux = aux->prox;
	}

	return aux;         // retorna a posição de memória do nó do meio
}

/** \brief Limpa o console em linux e windows */
void clear_screen()
{
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}
