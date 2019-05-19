typedef int tipoinfo;

struct TNodoA{
        tipoinfo info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA *a, tipoinfo ch);
void caminho(pNodoA *a, tipoinfo valor1, tipoinfo valor2);
tipoinfo valorMaisProximo(pNodoA *a, tipoinfo valor);
pNodoA* consultaABP(pNodoA *a, tipoinfo chave);

