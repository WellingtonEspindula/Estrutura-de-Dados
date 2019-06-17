/*
 *  O presente programa foi realizado para a disciplina de Estrutura de Dados,
 * ministrada pela Prof.ª Dr.ª Renata Galante, da Universidade Federal do Rio Grande do Sul.
 * Assim, o trabalho tem como finalidade a implementação de um TAD (Tipo Abstrato de Dados)
 * em uma lista linear utilizando Array em C.
 *  Dessa forma, o programa simula um clube, realizando a incrição de sócios, cálculo de
 * estatísticas sobre os sócios e seleção do sócio nota 10 - através de três critérios.
 *
 */

/*
 * Arquivo:   main.c
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 23 de Março de 2019, 21:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

 /* CONSTANTE QUE INDICA O TAMANHO DA LISTA DE SÓCIOS*/
#define MAX 5

/* Protótipos de funcoes da main */
void inicializa(SOCIO *socios, int *inicio, int *fim);


int main() {
    /* Lista linear de sócios usando arrays */
    SOCIO socios[MAX];
    int inicio, fim;

    // inicializa vetor e variáveis de controle da lista linear
    inicializa(socios, &inicio, &fim);

    /* Itera o tamanho da lista, chamando o método de atribuição de dados, que, por conseguinte, irá ler dados dos sócios
    da entrada do console e preencher a lista de sócios */
    for (int i = 0; i < MAX; i++) {
        atribui_dados(socios, &inicio, &fim, MAX);
    }

    /* Calcula e imprime as estatísticas sobre os sócios do clube */
    calcula_estatisticas(socios, MAX);

    /* Encontra o sócio nota 10 e imprime na tela */
    SOCIO socio_n10 = socio_nota_10(socios, MAX);
    printf("O socio nota 10 do clube eh (%d) %s!!!", socio_n10.matricula, socio_n10.nome);

    return 0;
}


/* Com a entrada da lista de sócios, inicializa a lista e inicializa as variáveis de início e fim da lista */
void inicializa(SOCIO *socios, int *inicio, int *fim){
    for (int i = 0; i < MAX; i++){
        socios[i].matricula = 0;
        strcpy(socios[i].nome, "");
        socios[i].idade = 0;
        socios[i].grau_instrucao = 0;
        socios[i].turno = 0;
        socios[i].atividade = 0;
        socios[i].frequencia = 0;
    }

    *inicio = -1;
    *fim = 0;
}

/* Imprime todos os sócios cadastrados na lista */
void lista_socios(SOCIO *socios){
    for (int i = 0; i < MAX; i++){
        printf("SOCIO %d: %d, %s, %d, %d, %d, %d, %d \n", i,
           socios[i].matricula, socios[i].nome, socios[i].idade,
           socios[i].grau_instrucao, socios[i].turno,
           socios[i].atividade, socios[i].frequencia);
    }
}
