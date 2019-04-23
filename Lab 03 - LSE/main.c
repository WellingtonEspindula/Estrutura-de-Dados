/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.� Dr.� Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementa��o de uma LSE (Lista Simplesmente Encadeada)
 * utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma lista de uma estrutura dada, e o programa dever�:
 *      1) Inserir os elementos na lista.
 *	2) Exibir a lista.
 *	3) Destruir a lista.
 *  Para a inser��o, o programa receber� como entrada um ponteiro e um n�mero.
 * Se o n�mero for positivo e par, o programa deve inseri-lo no in�cio da lista;
 * se o n�mero for positivo e impar, inserir no final da lista; e se o n�mero for negativo, inserir
 * no meio da lista.
 */

/*
 * Arquivo:   main.c
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 22 de Abril de 2019, 20:50
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct tipoNo ptLSE;
struct tipoNo{
	int numero;
	ptLSE *prox;
};

//PROT�TIPOS
ptLSE *inserir(int numero, ptLSE *ptLista);
void exibe(ptLSE *ptLista);
ptLSE *destroi(ptLSE *ptLista);

ptLSE * inicializaLista(ptLSE *ptLista);
ptLSE * retornaUltimoNo(ptLSE *ptLista);
ptLSE* retornaNoMeio(ptLSE *ptLista);


int main(){
	ptLSE *ptLista = NULL;

	int entrada;
	do{
		system("cls");
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

	destroi(ptLista);   //Destr�i lista antes de terminar o programa

	return 0;
}


/** \brief M�todo que insere elementos na LSE
 * \param numero - Numero inteiro que sera inserido na lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return Retorna lista com elementos inseridos
*/
ptLSE *inserir(int numero, ptLSE *ptLista){
	// Novo elemento que ser� inserido na lista
	ptLSE *novo;
	// aloca mem�ria para o elemento
	novo = (ptLSE*) malloc(sizeof(ptLSE));
	// adiciona o n�mero na estrutura apontada pelo ponteiro
	novo->numero = numero;

	/* Caso a lista esteja vazia, indica que a lista ser� composta
	unicamente pelo elemento criado acima e aponta para uma pr�xima posi��o nula*/
	if (ptLista == NULL){
        ptLista = novo;
		ptLista->prox = NULL;

	} else {
        /* Caso a lista n�o esteja vazia */
		if (numero >= 0){
	        	if ( (numero % 2) == 0){
                        /* Se o n�mero for positivo e par, insere no topo da lista.
                        Ou seja, indica que a primeira posi��o ser� o novo elemento,
                        e a pr�xima do novo elemento apontar� pra lista j� criada */
        	        	novo->prox = ptLista;
		                ptLista = novo;
        	    	}
			else {
                /* Se o n�mero for positivo e �mpar, o novo ocupar� a �ltima posi��o da lista.
                E o pr�ximo elemento do novo apontar� para uma pr�xima posi��o nula */
				novo->prox = NULL;
				retornaUltimoNo(ptLista)->prox = novo;
        		}
        	}
		else {
            /* Caso o n�mero for negativo, insere no meio da lista.
            Assim, pega o n� do meio da lista, e usando um ponteiro auxiliar, o p�e no meio */
			ptLSE *aux;
            aux = retornaNoMeio(ptLista);
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}

	// Retorna a lista com os valor inserido!! xD
	return ptLista;
}

/** \brief M�todo que exibe a lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
*/
void exibe(ptLSE *ptLista){
	ptLSE *aux;
	aux = ptLista;

	printf("\n----- LISTA -----\n");
	/* Itera a lista, usando um ponteiro auxiliar, e exibe cada n� da lista */
	while (aux != NULL){
		printf("%d\n", aux->numero);
		aux = aux->prox;
	}
	printf("----- FIM DA LISTA -----\n");
	system("PAUSE");
}


/** \brief M�todo que destroi a lista e libera endere�os de memoria alocados para a LSE
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return Retorna um ponteiro para a lista com todos os la�os destruidos e os elementos liberados da mem�ria
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

/** \brief Metodo que inicializa a lista alocando endere�o de mem�ria
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
*/
ptLSE * inicializaLista(ptLSE *ptLista){
	ptLista = (ptLSE *) malloc(sizeof(ptLSE));
	return ptLista;
}

/** \brief Metodo que retorna o ultimo no da lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return retorna o ponteiro para a posicao de memoria do ultimo no da lista
*/
ptLSE * retornaUltimoNo(ptLSE *ptLista){
	ptLSE *aux;
    aux = ptLista;

    /* Itera a lista, usando um ponteiro auxiliar, at� chegar ao �ltimo n� da lista*/
	while (aux->prox != NULL){
		aux = aux->prox;
	}

	return aux;     // retorna a posi��o de mem�ria do �ltimo n� da lista
}

/** \brief Metodo que retorna o N� que est� no meio da lista
 * \param *ptLista - Ponteiro para a primeira posicao da lista simplesmente encadeada
 * \return retorna o ponteiro para a posicao que ocupa o meio da lista
*/
ptLSE* retornaNoMeio(ptLSE *ptLista){
	ptLSE *aux;         // Ponteiro auxiliar que serve para iterar a lista
	aux = ptLista;      // Ponteiro auxiliar assume o valor do ponteiro para a LSE
	int numNos = 0;     // vari�vel que armazenar� o n�mero de n�s
	int indiceNo = 0;   // vari�vel que armazenar� o �ndice (quantas itera��es que dever�o ser feitas para encontrar) do n� do meio

	/* Aqui encontra o n�mero de n�s da lista */
	while ( aux != NULL ){
		aux = aux->prox;
		numNos++;
	}

	/* Aqui faz o c�lculo de quantas itera��es dever�o ser feitas para encontrar o n� do meio.
        Usa-se o floor para, caso a lista tenha um n�mero �mpares de elementos, encontrar o n� do elemento anterior ao elemento central  */
	indiceNo = (int) floor(numNos / 2);
	aux = ptLista;      // o auxiliar assume novamente o valor do ponteiro para o primeiro elemento da lista, para, assim, iter�-lo at� encontrar o n� do meio

	for (int i = 1; i < indiceNo; i++){
		aux = aux->prox;
	}

	return aux;         // retorna a posi��o de mem�ria do n� do meio
}
