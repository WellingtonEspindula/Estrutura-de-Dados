/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.ª Dr.ª Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementação de uma LDEC (Lista Duplamente Encadeada Circular)
 * utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma lista de uma estrutura dada, e o programa deverá:
 *  1) Inserir os elementos na lista.
 *	2) Exibir a lista.
 *  3) Exibir a lista inversa a partir da posição de um número dado pelo usuário
 *	4) Destruir a lista.
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

typedef struct tipoNo ptLDEC;
struct tipoNo{
	int numero;
	ptLDEC *ant;
	ptLDEC *prox;
};

//PROTÓTIPOS
ptLDEC *inserir(int numero, ptLDEC *ptLista);
void exibe(ptLDEC *ptLista);
void exibeInversoNum(ptLDEC *ptLista, int num);
ptLDEC *destroi(ptLDEC *ptLista);

ptLDEC *inicializaLista(ptLDEC *ptLista);
ptLDEC *retornaUltimoNo(ptLDEC *ptLista);
ptLDEC *retornaNoMeio(ptLDEC *ptLista);
void clear_screen();


int main(){
	ptLDEC *ptLista = NULL;

	int entrada;
	do{
        clear_screen();
		printf("Digite:\n");
		printf("0 - Sair\n");
		printf("1 - Inserir\n");
		printf("2 - Exibir lista\n");
		printf("3 - Exibir lista inversa a partir de um numero\n");
		printf("4 - Destruir lista\n");
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
			    printf("Digite o numero:\n");
				scanf("%d", &valor);
				exibeInversoNum(ptLista, valor);
				break;
			case 4:
				ptLista = destroi(ptLista);
				break;
		}
	} while (entrada != 0);

	destroi(ptLista);   //Destrói lista antes de terminar o programa

	return 0;
}


/** \brief Método que insere elementos na LDEC
 * \param numero - Numero inteiro que sera inserido na lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return Retorna lista com elementos inseridos
*/
ptLDEC *inserir(int numero, ptLDEC *ptLista){
	// Novo elemento que será inserido na lista
	ptLDEC *novo;
	// aloca memória para o elemento
	novo = (ptLDEC*) malloc(sizeof(ptLDEC));
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

                                                        // O novo elemento será o novo topo ou novo início da lista
                        ptLista->ant->prox = novo;      // O último elemento da lista terá como seu próximo elemento o novo início
                        novo->ant = ptLista->ant;       // o anterior do novo início será o anterior do antigo início da lista
        	        	novo->prox = ptLista;           // o novo início terá como sucessor o antigo início
                        ptLista->ant = novo;            // o antigo início terá como seu antecessor o novo início
		                ptLista = novo;                 // o ptLista apontará para o novo início

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

			ptLDEC *aux;
            aux = retornaNoMeio(ptLista);          // aux assumirá a posição (memória) do elemento do meio da lista
			novo->prox = aux->prox;                // o próximo elemento do novo elemento será o próximo do elemento do meio
			novo->ant = aux;                       // o elemento anterior do novo elemento será o próximo elemnto do meio
			aux->prox->ant = novo;                 // o elemento sucessor do elemento do meio terá como anterior o novo elemento
			aux->prox = novo;                      // o próximo elemento do meio será o novo elemento
		}
	}

	// Retorna a lista com os valor inserido!! xD
	return ptLista;
}

/** \brief Método que exibe a lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
void exibe(ptLDEC *ptLista){
	ptLDEC *aux;
	aux = ptLista;

	printf("\n----- LISTA -----\n");
	/* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
	if (ptLista != NULL){           // Verifica se a lista é nula para evitar erros
        do{
            printf("%d\n", aux->numero);
            aux = aux->prox;
        } while (aux != ptLista);
	}
	printf("----- FIM DA LISTA -----\n");

    getchar(); //gambiarra para limpar o buffer e pausar a execução do programa em ambiente linux e windows.
    getchar(); //Similar ao system("PAUSE");

}

/** \brief Método que exibe a lista de forma inversa iniciando a exibição pela posicao na lista de dado um numero
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \param num - Numero inteiro que sera buscado na lista e sera o pivo da exibicao da lista
*/
void exibeInversoNum(ptLDEC *ptLista, int num){
    if (ptLista != NULL){
        ptLDEC *aux = ptLista;          // auiliar que apontará para o início da lista
        ptLDEC *ptPosNum = NULL;        // ponteiro para a posição de memória ocupada pelo número na lista

        do{                             // enquanto a lista não chegou ao fim ou o elemento não foi encontrado
            if (aux->numero == num){    // verifica se o número da lista iterada é igual ao número entrado
                ptPosNum = aux;         // caso sim, o ptPosNum assume a posição de memória
            }
            aux = aux->prox;            // itera para o próximo elemento da lista
        } while ((aux != ptLista) || (ptPosNum == NULL));

        if (ptPosNum == NULL){          // caso não tenha sido encontrado o número na lista, informa o usuário
            printf("Numero nao encontrado na lista");
        } else{                         // caso sim, exibe a lista do número até o sucessor do número em ordem inversa
            aux = ptPosNum;             // aux aqui receberá a função de apontar para a posição do número na memória

            printf("\n----- LISTA -----\n");
            /* Itera a lista, usando um ponteiro auxiliar, e exibe cada nó da lista */
            do {                        // realiza operações de exibição enquanto não percorrer toda a lista (do ptPosNum até o sucessor do ptPosNum)
                printf("%d\n", aux->numero);
                aux = aux->ant;
            } while (aux != ptPosNum);
            printf("----- FIM DA LISTA -----\n");


        }
        getchar();
        getchar();
    }
}

/** \brief Método que destroi a lista e libera endereços de memoria alocados para a LDEC
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return Retorna um ponteiro para a lista com todos os laços destruidos e os elementos liberados da memória
*/
ptLDEC *destroi(ptLDEC *ptLista){
    if (ptLista != NULL){            // Verifica se a lista é nula para evitar erros
        ptLDEC *aux1 = ptLista;      // auxiliar que recebe a primeira posição da lista
        ptLDEC *aux2;

        do{                         // enquanto não chegar ao fim da lista
            aux2 = aux1;            // utiliza 2 auxiliares para guardar a informação da próxima posição e da posição atual da lista
            aux1 = aux1->prox;
            free(aux2);             // e liberar a memória da posição atual
        } while (aux1 != ptLista);
    }

    return NULL;                    // retorna a lista como nula
}



/* Funcoes auxiliares */

/** \brief Metodo que inicializa a lista alocando endereço de memória
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
ptLDEC *inicializaLista(ptLDEC *ptLista){
	ptLista = (ptLDEC *) malloc(sizeof(ptLDEC));
	return ptLista;
}

/** OBSOLETO (DEPRECATED)
 * \brief Metodo que retorna o ultimo no da lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return retorna o ponteiro para a posicao de memoria do ultimo no da lista
*/
ptLDEC *retornaUltimoNo(ptLDEC *ptLista){
	return ptLista->ant;     // retorna a posição de memória do último nó da lista
}

/** \brief Metodo que retorna o Nó que está no meio da lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return retorna o ponteiro para a posicao que ocupa o meio da lista
*/
ptLDEC *retornaNoMeio(ptLDEC *ptLista){
	ptLDEC *aux;         // Ponteiro auxiliar que serve para iterar a lista
	aux = ptLista;      // Ponteiro auxiliar assume o valor do ponteiro para a LDEC
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
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}
