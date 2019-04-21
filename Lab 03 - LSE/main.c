/*

   O crit�rio para inser��o � o seguinte: se o n�mero for positivo e par, inserir no in�cio da lista; se o
n�mero positivo e impar, inserir no final da lista; e se o n�mero for negativo, inserir no meio da
lista. A fun��o recebe como entrada um ponteiro para o in�cio da lista, ptLista, e o n�mero
inteiro que deve ser inserido. Aten��o, note que para inserir um elemento exatamente no meio da
lista, voc� deve percorrer toda a lista para saber quantos elementos a lista possui, pois na lista
encadeada temos apenas busca sequencial. Se a lista possuir um n�mero par de elementos, inserir
exatamente no meio. Se a lista possuir um n�mero �mpar de elementos, inserir antes do elemento
central. Se o usu�rio informar o valor zero, n�o fazer nada.
Passos para testar o laborat�rio (conte�do do main):
	a) Inserir os elementos na lista.
	b) Exibe a lista.
	c) Destr�i a lista.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoNo ptLSE;
struct tipoNo{
	int numero;
	ptLSE *prox;
};

ptLSE *inserir(int numero, ptLSE *ptLista);
void exibe(ptLSE *ptLista);
ptLSE *destroi(ptLSE *ptLista);

void inicializaLista(ptLSE *ptLista);
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

	return 0;
}

ptLSE *inserir(int numero, ptLSE *ptLista){
	ptLSE *novo;
	novo = (ptLSE*) malloc(sizeof(ptLSE));
	novo->numero = numero;

	if (ptLista == NULL){
        ptLista = novo;
		ptLista->prox = NULL;

	} else {
		if (numero >= 0){
	        	if ( (numero % 2) == 0){
        	        	novo->prox = ptLista;
		                ptLista = novo;
        	    	}
			else {
				novo->prox = NULL;
				retornaUltimoNo(ptLista)->prox = novo;
        		}
        	}
		else {
			ptLSE *aux;
            aux = retornaNoMeio(ptLista);
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}

	return ptLista;
}

void exibe(ptLSE *ptLista){
	ptLSE *aux;
	aux = ptLista;

	printf("----- LISTA -----\n");
	while (aux != NULL){
		printf("%d\n", aux->numero);
		aux = aux->prox;
	}
	printf("----- FIM DA LISTA -----\n");
	system("PAUSE");
}

ptLSE *destroi(ptLSE *ptLista){
    ptLSE *aux;

    while (ptLista != NULL){
            aux = ptLista->prox;
            free(ptLista);
            ptLista = aux;
    }

    return ptLista;
}



// Funcoes auxiliares
void inicializaLista(ptLSE *ptLista){
	ptLista = (ptLSE *) malloc(sizeof(ptLSE));
}

ptLSE * retornaUltimoNo(ptLSE *ptLista){
	ptLSE *aux;
       	aux = ptLista;

	while (aux->prox != NULL){
		aux = aux->prox;
	}

	return aux;
}

ptLSE* retornaNoMeio(ptLSE *ptLista){
	ptLSE *aux;
	aux = ptLista;

	while ( (aux->prox != NULL) && ((aux->prox->numero % 2) == 0) ){
		aux = aux->prox;
	}

	return aux;
}
