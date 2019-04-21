/*
 * Arquivo:   tad.c
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 23 de Março de 2019, 21:47
 */

#include "tad.h"
#include <string.h>
#include <stdio.h>


/*
 *  Esse método lê os dados de um sócio a partir da entrada no console
 *  e os armazena na lista de sócios.
 *
 *   ENTRADA:
 *   *sócios - Lista do tipo estruturado SOCIO onde serão armazenados os dados dos sócios.
 *   *inicio - Ponteiro que aponta para o valor que indica o início da lista.
 *   *fim - Ponteiro que aponta para o valor que indica o fim da lista.
 *   max - Valor que indica a quantidade de elementos possíveis de serem armazenados na lista de sócios.
*/
void atribui_dados(SOCIO *socios, int *inicio, int *fim, int max){
    /* VARIAVEIS DE ENTRADA DE SOCIO */
    // Matrícula auto-incrementada, por isso, usou-se a variável como estática.
    // Assim, toda a vez o método for executado um novo número de matrícula será gerado.
    static int matricula = 1;
    char nome[100];
    int idade;
    int grau_instrucao;
    int turno;
    int atividade;
    int frequencia;

    // variável que armazena resultado de cada uma das validações, r é do tipo inteiro, mas é usado como uma variável booleana
    int r;

    /* ENTRADA DE DADOS DO USUÁRIO */
    printf("---- SOCIO: %d -----\n", matricula);

    printf("Nome: ");
    scanf("%s", nome);

    printf("Idade: ");
    scanf("%d", &idade);

    /* Enquanto o usuário digitar uma opcao fora de escopo, mostra que a opção é indisponível
    e pede a entrada do dado novamente. */
    r = 0;
    while(!r){
        printf("\n");        printf("Grau de Instrucao: ");
        printf("\n%d - Ensino Fundamental", FUNDAMENTAL);
        printf("\n%d - Ensino Medio", MEDIO);
        printf("\n%d - Ensino Superior", SUPERIOR);
        printf("\n");
        scanf("%d", &grau_instrucao);

        r = valida(grau_instrucao, GRAU_INSTRUCAO);

        if (!r){
            printf("Essa opcao nao eh possivel. Digite novamente!\n");
        }
    }

    /* Segue a mesma lógica da entrada acima */
    r = 0;
    while(!r){
        printf("\n");
        printf("Turno: ");
        printf("\n%d - Manha", MANHA);
        printf("\n%d - Tarde", TARDE);
        printf("\n%d - Noite", NOITE);
        printf("\n");
        scanf("%d", &turno);

        r = valida(turno, TURNO);

        if (!r){
            printf("Essa opcao nao eh possivel. Digite novamente!\n");
        }
    }

    /* Idem */
    r = 0;
    while(!r){
        printf("\n");        printf("Atividade: ");
        printf("\n%d - Natacao", NATACAO);
        printf("\n%d - Hidroginastica", HIDROGINASTICA);
        printf("\n%d - Danca", DANCA);
        printf("\n%d - Kung-Fu", KUNG_FU);
        printf("\n%d - Violao", VIOLAO);
        printf("\n%d - Futebol", FUTEBOL);
        printf("\n%d - Volei", VOLEI);
        printf("\n");
        scanf("%d", &atividade);

        r = valida(atividade, ATIVIDADE);

        if (!r){
            printf("Essa opcao nao eh possivel. Digite novamente!\n");
        }
    }

    printf("\n");
    printf("Frequencia (em %): ");
    scanf("%d", &frequencia);
    printf("\n");

    /* A partir dos dados inseridos, cria-se uma variável do tipo socio */
    SOCIO socio = { matricula, "", idade, grau_instrucao, turno, atividade, frequencia};
    strcpy(socio.nome, nome);

    /*
    *   CONTROLE DE LISTA LINEAR
    *   Caso a lista não tenha sido populada ainda, a popula e indica onde esta inicia e termina.
    *   Caso já tenha sido populada, mas não esteja cheia, insere dados após a última posicao
    * inserida, e atualiza as informações de início e fim da lista linear.
    *   Caso esteja cheia, indica que esta encontra-se cheia.
    */
    if ( (*inicio) == -1){
        socios[0] = socio;

        *inicio = 0;
        *fim = 0;

    } else if ( ((*inicio) > -1) && ((*fim) < max) ){
        socios[(*fim)+1 ] = socio;
        (*fim)++;
    } else if ( (*fim) >= max){
        printf("Lista esta cheia");
    }

    //Incrementa variavel estática de número de matrícula
    matricula++;
}


/*
 *  Esse método percorre a lista de sócios a fim de calcular e imprimir seguintes estatísticas sobre os sócios:
 *       -> total	de	sócios	do	turno	da	manhã;
 *       -> total	de	sócios	do	turno	da	tarde;
 *       -> total	de	sócios	do	turno	da	noite;
 *       -> média	de	idade	dos	sócios	com	grau	de	instrução	igual	a	ensino	superior;
 *       -> total	de	sócios	que	praticam	natação;
 *       -> sócio	mais	idoso que	pratica	Kung Fu;
 *       -> sócio	mais	idoso que	pratica	Futebol;
 *
 *   ENTRADA:
 *   *sócios - Lista do tipo estruturado SOCIO onde estão armazenados os dados dos sócios.
 *   max - Valor que indica a quantidade de elementos possíveis de serem armazenados na lista de sócios.
*/
void calcula_estatisticas(SOCIO *socios, int max){
    // Variáveis de contagem de socios por turno
    int num_soc_manha = 0;
    int num_soc_tarde = 0;
    int num_soc_noite = 0;

    // Média de idade dos sócios com ensino superior
    int soma_idade_soc_ensino_sup = 0;
    int num_soc_ensino_sup = 0;
    float media_idade_soc_ensino_sup = 0;

    // Contagem de sócios que fazem natação
    int num_soc_natacao = 0;

    // Guara a posicao dos socios mais idosos que praticam, respectivamente,
    // kung-fu e futebol.
    SOCIO soc_mais_idoso_kungfu = {0, "", 0, 0, 0, 0, 0};
    SOCIO soc_mais_idoso_futebol = {0, "", 0, 0, 0, 0, 0};

    for (int i = 0; i < max; i++){
        SOCIO socio = socios[i];

        // Percorre os socios buscando o número de sócios em cada turno
        if (socio.turno == MANHA){
            num_soc_manha++;
        } else if (socio.turno == TARDE){
            num_soc_tarde++;
        } else if (socio.turno == NOITE){
            num_soc_noite++;
        }

        // Percorre os socios somando o total da idade do sócios com ensino superior e o número de sócios, também, com ensino superior.
        // Este método possibilita o cálculo da média logo após o laço.
        if (socio.grau_instrucao == SUPERIOR){
            soma_idade_soc_ensino_sup += socio.idade;
            num_soc_ensino_sup++;
        }

        // Percorre os socios buscando o número de sócios que fazem natação
        if (socio.atividade == NATACAO){
            num_soc_natacao++;
        }

        // Percorre os socios buscando o sócio mais idoso que pratica Kung Fu
        if ( (socio.atividade == KUNG_FU) &&
        (socio.idade > soc_mais_idoso_kungfu.idade)){
            soc_mais_idoso_kungfu = socio;
        }

        // Percorre os socios buscando o sócio mais idoso que joga Futebol
        if ( (socio.atividade == FUTEBOL) &&
        (socio.idade > soc_mais_idoso_futebol.idade)){
            soc_mais_idoso_futebol = socio;
        }
    }

    //Calcula a média de idade dos sócios com ensino superior.
    media_idade_soc_ensino_sup = (float) soma_idade_soc_ensino_sup / (float) num_soc_ensino_sup;

    /* Imprime as estatísticas calculadas sobre os sócios */
    printf("O numero de socios do turno da manha eh %i\n", num_soc_manha);
    printf("O numero de socios do turno da tarde eh %i\n", num_soc_tarde);
    printf("O numero de socios do turno da noite eh %i\n", num_soc_noite);
    printf("A media de idade dos socios com ensino superior eh %.2f \n", media_idade_soc_ensino_sup);
    printf("O numero de socios que fazem natacao eh %i\n", num_soc_natacao);
    printf("O socio mais idoso que faz kung-fu eh (%i) %s\n", soc_mais_idoso_kungfu.matricula,
           soc_mais_idoso_kungfu.nome);
    printf("O socio mais idoso que joga futebol eh (%i) %s\n", soc_mais_idoso_futebol.matricula,
           soc_mais_idoso_futebol.nome);
}

/*
 *  Esse método percorre a lista de sócios para encontrar o sócio nota 10 do clube.
 *  O sócio nota 10 é selecionado usando o critério de frequência. Assim, o sócio com maior frequência será o sócio nota 10.
 *  Entretanto, caso sócios empatem, usou-se como primeiro critério de desempate o grau de instrução.
 *  Como segundo - e último - critério de desempate, foi usada a idade dos sócios.
 *
 *  ENTRADA:
 *  *sócios - Lista do tipo estruturado SOCIO onde estão armazenados os dados dos sócios.
 *  max - Valor que indica a quantidade de elementos possíveis de serem armazenados na lista de sócios.
 *
 *  SAÍDA: A função tem retorno do tipo SOCIO, na qual o sócio retornado será o sócio nota 10.
*/
SOCIO socio_nota_10(SOCIO *socios, int max){
    SOCIO socio_nota_10 = {0, "", 0, 0, 0, 0, 0};

    for (int i = 0; i < max; i++){
        if (socios[i].frequencia > socio_nota_10.frequencia){
            socio_nota_10 = socios[i];
        } else if (socios[i].frequencia == socio_nota_10.frequencia){
            if (socios[i].grau_instrucao > socio_nota_10.grau_instrucao){
                socio_nota_10 = socios[i];
            } else if (socios[i].grau_instrucao == socio_nota_10.grau_instrucao){
                if (socios[i].idade > socio_nota_10.idade){
                    socio_nota_10 = socios[i];
                }
            }
        }
    }

    return socio_nota_10;
}

/*
 *  Esse método, a partir do tipo de entrada declarado nas constantes desse arquivo - Grau de Instrução, Turno e Atividade -,
 *  verifica se a entrada de dados para esse campo foi válida.
 *
 *  ENTRADA:
 *  entrada - Entrada de dados realizada pelo usuário para o campo em questão.
 *  opcao_validacao - Campo em que será realizada a operação de validação de dados.
 *
 *  SAÍDA: A função retornará 0 caso a entrada de dados do usuário final não tenha sido válida; e 1, caso tenha sido válida.
*/
int valida(int entrada, int opcao_validacao){
    switch (opcao_validacao){
    case GRAU_INSTRUCAO:
        return ((entrada >= 1) && (entrada <= 3));
        break;
    case TURNO:
        return ((entrada >= 1) && (entrada <= 3));
        break;
    case ATIVIDADE:
        return ((entrada >= 1) && (entrada <= 7));
        break;
    default:
        return 0;
        break;
    }
}
