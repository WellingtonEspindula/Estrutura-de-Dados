/*
 * Arquivo:   tad.c
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 23 de Mar�o de 2019, 21:47
 */

#include "tad.h"
#include <string.h>
#include <stdio.h>


/*
 *  Esse m�todo l� os dados de um s�cio a partir da entrada no console
 *  e os armazena na lista de s�cios.
 *
 *   ENTRADA:
 *   *s�cios - Lista do tipo estruturado SOCIO onde ser�o armazenados os dados dos s�cios.
 *   *inicio - Ponteiro que aponta para o valor que indica o in�cio da lista.
 *   *fim - Ponteiro que aponta para o valor que indica o fim da lista.
 *   max - Valor que indica a quantidade de elementos poss�veis de serem armazenados na lista de s�cios.
*/
void atribui_dados(SOCIO *socios, int *inicio, int *fim, int max){
    /* VARIAVEIS DE ENTRADA DE SOCIO */
    // Matr�cula auto-incrementada, por isso, usou-se a vari�vel como est�tica.
    // Assim, toda a vez o m�todo for executado um novo n�mero de matr�cula ser� gerado.
    static int matricula = 1;
    char nome[100];
    int idade;
    int grau_instrucao;
    int turno;
    int atividade;
    int frequencia;

    // vari�vel que armazena resultado de cada uma das valida��es, r � do tipo inteiro, mas � usado como uma vari�vel booleana
    int r;

    /* ENTRADA DE DADOS DO USU�RIO */
    printf("---- SOCIO: %d -----\n", matricula);

    printf("Nome: ");
    scanf("%s", nome);

    printf("Idade: ");
    scanf("%d", &idade);

    /* Enquanto o usu�rio digitar uma opcao fora de escopo, mostra que a op��o � indispon�vel
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

    /* Segue a mesma l�gica da entrada acima */
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

    /* A partir dos dados inseridos, cria-se uma vari�vel do tipo socio */
    SOCIO socio = { matricula, "", idade, grau_instrucao, turno, atividade, frequencia};
    strcpy(socio.nome, nome);

    /*
    *   CONTROLE DE LISTA LINEAR
    *   Caso a lista n�o tenha sido populada ainda, a popula e indica onde esta inicia e termina.
    *   Caso j� tenha sido populada, mas n�o esteja cheia, insere dados ap�s a �ltima posicao
    * inserida, e atualiza as informa��es de in�cio e fim da lista linear.
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

    //Incrementa variavel est�tica de n�mero de matr�cula
    matricula++;
}


/*
 *  Esse m�todo percorre a lista de s�cios a fim de calcular e imprimir seguintes estat�sticas sobre os s�cios:
 *       -> total	de	s�cios	do	turno	da	manh�;
 *       -> total	de	s�cios	do	turno	da	tarde;
 *       -> total	de	s�cios	do	turno	da	noite;
 *       -> m�dia	de	idade	dos	s�cios	com	grau	de	instru��o	igual	a	ensino	superior;
 *       -> total	de	s�cios	que	praticam	nata��o;
 *       -> s�cio	mais	idoso que	pratica	Kung Fu;
 *       -> s�cio	mais	idoso que	pratica	Futebol;
 *
 *   ENTRADA:
 *   *s�cios - Lista do tipo estruturado SOCIO onde est�o armazenados os dados dos s�cios.
 *   max - Valor que indica a quantidade de elementos poss�veis de serem armazenados na lista de s�cios.
*/
void calcula_estatisticas(SOCIO *socios, int max){
    // Vari�veis de contagem de socios por turno
    int num_soc_manha = 0;
    int num_soc_tarde = 0;
    int num_soc_noite = 0;

    // M�dia de idade dos s�cios com ensino superior
    int soma_idade_soc_ensino_sup = 0;
    int num_soc_ensino_sup = 0;
    float media_idade_soc_ensino_sup = 0;

    // Contagem de s�cios que fazem nata��o
    int num_soc_natacao = 0;

    // Guara a posicao dos socios mais idosos que praticam, respectivamente,
    // kung-fu e futebol.
    SOCIO soc_mais_idoso_kungfu = {0, "", 0, 0, 0, 0, 0};
    SOCIO soc_mais_idoso_futebol = {0, "", 0, 0, 0, 0, 0};

    for (int i = 0; i < max; i++){
        SOCIO socio = socios[i];

        // Percorre os socios buscando o n�mero de s�cios em cada turno
        if (socio.turno == MANHA){
            num_soc_manha++;
        } else if (socio.turno == TARDE){
            num_soc_tarde++;
        } else if (socio.turno == NOITE){
            num_soc_noite++;
        }

        // Percorre os socios somando o total da idade do s�cios com ensino superior e o n�mero de s�cios, tamb�m, com ensino superior.
        // Este m�todo possibilita o c�lculo da m�dia logo ap�s o la�o.
        if (socio.grau_instrucao == SUPERIOR){
            soma_idade_soc_ensino_sup += socio.idade;
            num_soc_ensino_sup++;
        }

        // Percorre os socios buscando o n�mero de s�cios que fazem nata��o
        if (socio.atividade == NATACAO){
            num_soc_natacao++;
        }

        // Percorre os socios buscando o s�cio mais idoso que pratica Kung Fu
        if ( (socio.atividade == KUNG_FU) &&
        (socio.idade > soc_mais_idoso_kungfu.idade)){
            soc_mais_idoso_kungfu = socio;
        }

        // Percorre os socios buscando o s�cio mais idoso que joga Futebol
        if ( (socio.atividade == FUTEBOL) &&
        (socio.idade > soc_mais_idoso_futebol.idade)){
            soc_mais_idoso_futebol = socio;
        }
    }

    //Calcula a m�dia de idade dos s�cios com ensino superior.
    media_idade_soc_ensino_sup = (float) soma_idade_soc_ensino_sup / (float) num_soc_ensino_sup;

    /* Imprime as estat�sticas calculadas sobre os s�cios */
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
 *  Esse m�todo percorre a lista de s�cios para encontrar o s�cio nota 10 do clube.
 *  O s�cio nota 10 � selecionado usando o crit�rio de frequ�ncia. Assim, o s�cio com maior frequ�ncia ser� o s�cio nota 10.
 *  Entretanto, caso s�cios empatem, usou-se como primeiro crit�rio de desempate o grau de instru��o.
 *  Como segundo - e �ltimo - crit�rio de desempate, foi usada a idade dos s�cios.
 *
 *  ENTRADA:
 *  *s�cios - Lista do tipo estruturado SOCIO onde est�o armazenados os dados dos s�cios.
 *  max - Valor que indica a quantidade de elementos poss�veis de serem armazenados na lista de s�cios.
 *
 *  SA�DA: A fun��o tem retorno do tipo SOCIO, na qual o s�cio retornado ser� o s�cio nota 10.
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
 *  Esse m�todo, a partir do tipo de entrada declarado nas constantes desse arquivo - Grau de Instru��o, Turno e Atividade -,
 *  verifica se a entrada de dados para esse campo foi v�lida.
 *
 *  ENTRADA:
 *  entrada - Entrada de dados realizada pelo usu�rio para o campo em quest�o.
 *  opcao_validacao - Campo em que ser� realizada a opera��o de valida��o de dados.
 *
 *  SA�DA: A fun��o retornar� 0 caso a entrada de dados do usu�rio final n�o tenha sido v�lida; e 1, caso tenha sido v�lida.
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
