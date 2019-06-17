#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tweet.h"

/** \brief A partir de uma linha de um arquivo CSV, transfere as informacoes
 * para uma variavel do tipo Tweet
  */
Tweet readTwitte(char *linha){
    Tweet twitte;
    strcpy(twitte.user, strtok(linha, ";"));
    strcpy(twitte.text, strtok(NULL, ";"));
    
    char rtCountStr[5];
    char favCountStr[5];

    strcpy(rtCountStr, strtok(NULL, ";"));
    strcpy(favCountStr, strtok(NULL, ";"));
    
    twitte.rtCount = atoi(rtCountStr);
    twitte.favCount = atoi(favCountStr);

    return twitte;
}