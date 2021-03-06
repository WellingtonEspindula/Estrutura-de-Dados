/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.� Dr.� Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementa��o de uma LDEC (Lista Duplamente Encadeada Circular)
 * utilizando ponteiros em C.
 *  Dessa forma, o programa tem uma lista de uma estrutura dada, e o programa dever�:
 *  1) Inserir os elementos na lista.
 *	2) Exibir a lista.
 *  3) Exibir a lista inversa a partir da posi��o de um n�mero dado pelo usu�rio
 *	4) Destruir a lista.
 *  Para a inser��o, o programa receber� como entrada um ponteiro e um n�mero.
 * Se o n�mero for positivo e par, o programa deve inseri-lo no in�cio da lista;
 * se o n�mero for positivo e impar, inserir no final da lista; e se o n�mero for negativo, inserir
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
struct tipoNo
{
    int numero;
    ptLDEC *ant;
    ptLDEC *prox;
};

//PROT�TIPOS
ptLDEC *inserir(int numero, ptLDEC *ptLista);
void exibe(ptLDEC *ptLista);
void exibeInversoNum(ptLDEC *ptLista, int num);
ptLDEC *destroi(ptLDEC *ptLista);

ptLDEC *inicializaLista(ptLDEC *ptLista);
ptLDEC *retornaUltimoNo(ptLDEC *ptLista);
ptLDEC *retornaNoMeio(ptLDEC *ptLista);
void clear_screen();


int main()
{
    ptLDEC *ptLista = NULL;

    int entrada;
    do
    {
        clear_screen();
        printf("Digite:\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Exibir lista\n");
        printf("3 - Exibir lista inversa a partir de um numero\n");
        printf("4 - Destruir lista\n");
        scanf("%d", &entrada);
        int valor;

        switch (entrada)
        {
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
    }
    while (entrada != 0);

    destroi(ptLista);   //Destr�i lista antes de terminar o programa

    return 0;
}


/** \brief M�todo que insere elementos na LDEC
 * \param numero - Numero inteiro que sera inserido na lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return Retorna lista com elementos inseridos
*/
ptLDEC *inserir(int numero, ptLDEC *ptLista)
{
    // Novo elemento que ser� inserido na lista
    ptLDEC *novo;
    // aloca mem�ria para o elemento
    novo = (ptLDEC*) malloc(sizeof(ptLDEC));
    // adiciona o n�mero na estrutura apontada pelo ponteiro
    novo->numero = numero;

    /* Caso a lista esteja vazia, indica que a lista ser� composta
    unicamente pelo elemento criado acima e aponta para uma pr�xima posi��o nula*/

    if (ptLista == NULL)
    {
        ptLista = novo;
        ptLista->ant = ptLista;
        ptLista->prox = ptLista;

    }
    else
    {

        /* Caso a lista n�o esteja vazia */

        if (numero >= 0)
        {
            if ( (numero % 2) == 0)
            {

                /* Se o n�mero for positivo e par, insere no topo da lista.
                    Ou seja, indica que a primeira posi��o ser� o novo elemento,
                    e a pr�xima do novo elemento apontar� pra lista j� criada */

                // O novo elemento ser� o novo topo ou novo in�cio da lista
                ptLista->ant->prox = novo;      // O �ltimo elemento da lista ter� como seu pr�ximo elemento o novo in�cio
                novo->ant = ptLista->ant;       // o anterior do novo in�cio ser� o anterior do antigo in�cio da lista
                novo->prox = ptLista;           // o novo in�cio ter� como sucessor o antigo in�cio
                ptLista->ant = novo;            // o antigo in�cio ter� como seu antecessor o novo in�cio
                ptLista = novo;                 // o ptLista apontar� para o novo in�cio

            }
            else
            {

                /* Se o n�mero for positivo e �mpar, o novo ocupar� a �ltima posi��o da lista.
                    E o pr�ximo elemento do novo apontar� para uma pr�xima posi��o nula */

                // Novo elemento ser� o novo fim
                ptLista->ant->prox = novo;      // O antigo fim ter� como pr�xima posi��o o novo elemento
                novo->ant = ptLista->ant;       // O novo elemento ter� como posi��o anterior o antigo fim
                novo->prox = ptLista;           // O novo elemento ter� como pr�xima posi��o o in�cio da lista
                ptLista->ant = novo;            // A posi��o anterior do in�cio da lista ser� o novo fim

            }
        }
        else
        {

            /* Caso o n�mero for negativo, insere no meio da lista.
            	Assim, pega o n� do meio da lista, e usando um ponteiro auxiliar, o p�e no meio */

            ptLDEC *aux;
            aux = retornaNoMeio(ptLista);          // aux assumir� a posi��o (mem�ria) do elemento do meio da lista
            novo->prox = aux->prox;                // o pr�ximo elemento do novo elemento ser� o pr�ximo do elemento do meio
            novo->ant = aux;                       // o elemento anterior do novo elemento ser� o pr�ximo elemnto do meio
            aux->prox->ant = novo;                 // o elemento sucessor do elemento do meio ter� como anterior o novo elemento
            aux->prox = novo;                      // o pr�ximo elemento do meio ser� o novo elemento
        }
    }

    // Retorna a lista com os valor inserido!! xD
    return ptLista;
}

/** \brief M�todo que exibe a lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
void exibe(ptLDEC *ptLista)
{
    ptLDEC *aux;
    aux = ptLista;

    printf("\n----- LISTA -----\n");
    /* Itera a lista, usando um ponteiro auxiliar, e exibe cada n� da lista */
    if (ptLista != NULL)            // Verifica se a lista � nula para evitar erros
    {
        do
        {
            printf("%d\n", aux->numero);
            aux = aux->prox;
        }
        while (aux != ptLista);
    }
    printf("----- FIM DA LISTA -----\n");

    getchar(); //gambiarra para limpar o buffer e pausar a execu��o do programa em ambiente linux e windows.
    getchar(); //Similar ao system("PAUSE");

}

/** \brief M�todo que exibe a lista de forma inversa iniciando a exibi��o pela posicao na lista de dado um numero
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \param num - Numero inteiro que sera buscado na lista e sera o pivo da exibicao da lista
*/
void exibeInversoNum(ptLDEC *ptLista, int num)
{
    if (ptLista != NULL)
    {
        ptLDEC *aux = ptLista;          // auiliar que apontar� para o in�cio da lista
        ptLDEC *ptPosNum = NULL;        // ponteiro para a posi��o de mem�ria ocupada pelo n�mero na lista

        do                              // enquanto a lista n�o chegou ao fim ou o elemento n�o foi encontrado
        {
            if (aux->numero == num)     // verifica se o n�mero da lista iterada � igual ao n�mero entrado
            {
                ptPosNum = aux;         // caso sim, o ptPosNum assume a posi��o de mem�ria
            }
            aux = aux->prox;            // itera para o pr�ximo elemento da lista
        }
        while ((aux != ptLista) || (ptPosNum == NULL));

        if (ptPosNum == NULL)           // caso n�o tenha sido encontrado o n�mero na lista, informa o usu�rio
        {
            printf("Numero nao encontrado na lista");
        }
        else                            // caso sim, exibe a lista do n�mero at� o sucessor do n�mero em ordem inversa
        {
            aux = ptPosNum;             // aux aqui receber� a fun��o de apontar para a posi��o do n�mero na mem�ria

            printf("\n----- LISTA -----\n");
            /* Itera a lista, usando um ponteiro auxiliar, e exibe cada n� da lista */
            do                          // realiza opera��es de exibi��o enquanto n�o percorrer toda a lista (do ptPosNum at� o sucessor do ptPosNum)
            {
                printf("%d\n", aux->numero);
                aux = aux->ant;
            }
            while (aux != ptPosNum);
            printf("----- FIM DA LISTA -----\n");


        }
        getchar();
        getchar();
    }
}

/** \brief M�todo que destroi a lista e libera endere�os de memoria alocados para a LDEC
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return Retorna um ponteiro para a lista com todos os la�os destruidos e os elementos liberados da mem�ria
*/
ptLDEC *destroi(ptLDEC *ptLista)
{
    if (ptLista != NULL)             // Verifica se a lista � nula para evitar erros
    {
        ptLDEC *aux1 = ptLista;      // auxiliar que recebe a primeira posi��o da lista
        ptLDEC *aux2;

        do                          // enquanto n�o chegar ao fim da lista
        {
            aux2 = aux1;            // utiliza 2 auxiliares para guardar a informa��o da pr�xima posi��o e da posi��o atual da lista
            aux1 = aux1->prox;
            free(aux2);             // e liberar a mem�ria da posi��o atual
        }
        while (aux1 != ptLista);
    }

    return NULL;                    // retorna a lista como nula
}



/* Funcoes auxiliares */

/** \brief Metodo que inicializa a lista alocando endere�o de mem�ria
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
*/
ptLDEC *inicializaLista(ptLDEC *ptLista)
{
    ptLista = (ptLDEC *) malloc(sizeof(ptLDEC));
    return ptLista;
}

/** OBSOLETO (DEPRECATED)
 * \brief Metodo que retorna o ultimo no da lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return retorna o ponteiro para a posicao de memoria do ultimo no da lista
*/
ptLDEC *retornaUltimoNo(ptLDEC *ptLista)
{
    return ptLista->ant;     // retorna a posi��o de mem�ria do �ltimo n� da lista
}

/** \brief Metodo que retorna o N� que est� no meio da lista
 * \param *ptLista - Ponteiro para a primeira posicao da Lista Duplamente Encadeada Circular
 * \return retorna o ponteiro para a posicao que ocupa o meio da lista
*/
ptLDEC *retornaNoMeio(ptLDEC *ptLista)
{
    ptLDEC *aux;         // Ponteiro auxiliar que serve para iterar a lista
    aux = ptLista;      // Ponteiro auxiliar assume o valor do ponteiro para a LDEC
    int numNos = 0;     // vari�vel que armazenar� o n�mero de n�s
    int indiceNo = 0;   // vari�vel que armazenar� o �ndice (quantas itera��es que dever�o ser feitas para encontrar) do n� do meio

    /* Aqui encontra o n�mero de n�s da lista */
    do
    {
        aux = aux->prox;
        numNos++;
    }
    while ( aux != ptLista );

    /* Aqui faz o c�lculo de quantas itera��es dever�o ser feitas para encontrar o n� do meio.
        Usa-se o floor para, caso a lista tenha um n�mero �mpares de elementos, encontrar o n� do elemento anterior ao elemento central  */
    indiceNo = (int) floor(numNos / 2);
    aux = ptLista;      // o auxiliar assume novamente o valor do ponteiro para o primeiro elemento da lista, para, assim, iter�-lo at� encontrar o n� do meio

    for (int i = 0; i < (indiceNo - 1); i++)
    {
        aux = aux->prox;
    }

    return aux;         // retorna a posi��o de mem�ria do n� do meio
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
