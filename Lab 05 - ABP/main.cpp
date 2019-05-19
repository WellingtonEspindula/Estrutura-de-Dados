#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"

int main()
{
   pNodoA *arv = NULL;
   pNodoA *vazia = NULL;

   arv = InsereArvore(arv,30);
   arv = InsereArvore(arv,45);
   arv = InsereArvore(arv,25);
   arv = InsereArvore(arv,90);
   arv = InsereArvore(arv,80);
   arv = InsereArvore(arv,95);

   system("pause");

   caminho(arv, 45, 95);
   caminho(arv, 30, 25);
   caminho(arv, 30, 80);
   caminho(arv, 95, 45);
   caminho(arv, 25, 80);
   caminho(arv, 45, 100);
   caminho(vazia, 40, 50);


   printf("O valor mais proximo de %d na arvore e %d\n", 44, valorMaisProximo(arv, 44));
   printf("O valor mais proximo de %d na arvore e %d\n", 26, valorMaisProximo(arv, 26));
   printf("O valor mais proximo de %d na arvore e %d\n", 31, valorMaisProximo(arv, 31));
   printf("O valor mais proximo de %d na arvore e %d\n", 92, valorMaisProximo(arv, 92));
   printf("O valor mais proximo de %d na arvore e %d\n", 100, valorMaisProximo(arv, 100));
   printf("O valor mais proximo de %d na arvore e %d\n", 82, valorMaisProximo(arv, 82));


}


