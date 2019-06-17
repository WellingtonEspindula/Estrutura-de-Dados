/*

HEADER

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "DataStructs/tweet.h"

void initializeOperations(FILE *operationsFile);
void readEntryFile(FILE *entryFile);


int LIMIT_OP_A = -1;
int LIMIT_OP_B = -1;
int LIMIT_OP_C = -1;
int LIMIT_OP_D = -1;
int LIMIT_OP_E = -1;
int LIMIT_OP_F = -1;
char HASHTAG_OP_G[280];


int main(int argc, char **argv){
    /* Tenta abrir os arquivos de entrada de dados, de operacoes e de saida */
    FILE *entry = fopen(argv[1], "r");
    if (entry == NULL){
        printf("Arquivo %s nao encontrado!\n", argv[1]);
    }

    FILE *operations = fopen(argv[2], "r");
    if (operations == NULL){
        printf("Arquivo %s nao encontrado!\n", argv[2]);
    }

    FILE *output = fopen(argv[3], "w");
    if (output == NULL){
        printf("Arquivo %s nao encontrado!\n", argv[3]);
    }
    

    initializeOperations(operations);
    readEntryFile(entry);


    // printf("Operations:\n");
    // printf("A: %d\n", LIMIT_OP_A);
    // printf("B: %d\n", LIMIT_OP_B);
    // printf("C: %d\n", LIMIT_OP_C);
    // printf("D: %d\n", LIMIT_OP_D);
    // printf("E: %d\n", LIMIT_OP_E);
    // printf("F: %d\n", LIMIT_OP_F);
    // printf("G: %s\n", HASHTAG_OP_G);


    // char texto[75] = "@MrsPaulocarlos1;#QueroUFRGS Relações Internacionais @ufrgsnoticias;3;9";
    // Tweet tt1 = leTwitte(texto);
    // printf("Nome: %s\n",  tt1.user);
    // printf("Texto: %s\n", tt1.text);
    // printf("RTs: %d\n",   tt1.rtCount);
    // printf("Favs: %d\n",  tt1.favCount);

}



/** \brief Conforme as informacoes contidas no arquivo de operacoes, verifica
 * quais operacoes serao realizadas, habilitando-as e definindo a entrada dessas 
 * operacoes 
 */
void initializeOperations(FILE *operationsFile){
    char operation[282];
    while (fgets(operation, 280, operationsFile) != NULL) {

        char op[1];
        strcpy(op, strtok(operation, ";"));

        if (op[0] == 'g'){
            strcpy(HASHTAG_OP_G, strtok(NULL, ";"));

        } else{
            char limit[2];
            strcpy(limit, strtok(NULL, ";"));
            switch (op[0]){
                case 'a': 
                    LIMIT_OP_A = atoi(limit);
                    break;
                case 'b':
                    LIMIT_OP_B = atoi(limit);
                    break;
                case 'c':
                    LIMIT_OP_C = atoi(limit);
                    break;
                case 'd':
                    LIMIT_OP_D = atoi(limit);
                    break;
                case 'e':
                    LIMIT_OP_E = atoi(limit);
                    break;
                case 'f':
                    LIMIT_OP_F = atoi(limit);
                    break;
            }
        }
    }
}


void readEntryFile(FILE *entryFile){
    char line[500];
    while (fgets(line, 280, entryFile) != NULL) {
        Tweet tt = readTwitte(line);
        printf("Nome: %s\n",  tt.user);
        printf("Texto: %s\n", tt.text);
        printf("RTs: %d\n",   tt.rtCount);
        printf("Favs: %d\n\n",  tt.favCount);
    }

}