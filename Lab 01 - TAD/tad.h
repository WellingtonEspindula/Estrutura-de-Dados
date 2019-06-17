/*
 * Arquivo:   tad.h
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 23 de Março de 2019, 21:45
 */

/* CONSTANTES DE GRAU DE INSTRUÇÃO*/
#define FUNDAMENTAL 1
#define MEDIO 2
#define SUPERIOR 3

/* CONSTANTES DE TURNO*/
#define MANHA 1
#define TARDE 2
#define NOITE 3

/* CONSTANTES DE ATIVIDADE*/
#define NATACAO 1
#define HIDROGINASTICA 2
#define DANCA 3
#define KUNG_FU 4
#define VIOLAO 5
#define FUTEBOL 6
#define VOLEI 7

/* CONSTANTES UTILIZADAS PARA DEFINIR A ENTRADA DE DADOS
PARA SER UZADA NO MÉTODO DE VALIDAÇÃO DE DADOS */
#define GRAU_INSTRUCAO 0
#define TURNO 1
#define ATIVIDADE 2


/* Tipo de dados do tipo Socio */
typedef struct {
    int matricula;
    char nome[100];
    int idade;
    int grau_instrucao;
    int turno;
    int atividade;
    int frequencia;
} SOCIO;


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
void atribui_dados(SOCIO *socios, int *inicio, int *fim, int max);


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
void calcula_estatisticas(SOCIO *socios, int max);


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
SOCIO socio_nota_10(SOCIO *socio, int max);


/*
 *  Esse método, a partir do tipo de entrada declarado nas constantes desse arquivo - Grau de Instrução, Turno e Atividade -,
 *  verifica se a entrada de dados para esse campo foi válida.
 *
 *  ENTRADA:
 *  entrada - Entrada de dados realizada pelo usuário para o campo em questão.
 *  opcao_validacao - Campo em que será realizada a operação de validação de dados.
 *
 *  SAÍDA: A função retornará 0 caso a entrada de dados do usuário final não tenha sido válida; 1, caso tenha sido válida.
*/
int valida(int entrada, int opcao_validacao);
