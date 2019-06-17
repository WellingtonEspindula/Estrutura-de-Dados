/*
 * Arquivo:   tad.h
 * Autores: Wellington Espindula (00302367) e Rafael Trevisan (00301922)
 *
 * Criado em 23 de Mar�o de 2019, 21:45
 */

/* CONSTANTES DE GRAU DE INSTRU��O*/
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
PARA SER UZADA NO M�TODO DE VALIDA��O DE DADOS */
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
 *  Esse m�todo l� os dados de um s�cio a partir da entrada no console
 *  e os armazena na lista de s�cios.
 *
 *   ENTRADA:
 *   *s�cios - Lista do tipo estruturado SOCIO onde ser�o armazenados os dados dos s�cios.
 *   *inicio - Ponteiro que aponta para o valor que indica o in�cio da lista.
 *   *fim - Ponteiro que aponta para o valor que indica o fim da lista.
 *   max - Valor que indica a quantidade de elementos poss�veis de serem armazenados na lista de s�cios.
*/
void atribui_dados(SOCIO *socios, int *inicio, int *fim, int max);


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
void calcula_estatisticas(SOCIO *socios, int max);


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
SOCIO socio_nota_10(SOCIO *socio, int max);


/*
 *  Esse m�todo, a partir do tipo de entrada declarado nas constantes desse arquivo - Grau de Instru��o, Turno e Atividade -,
 *  verifica se a entrada de dados para esse campo foi v�lida.
 *
 *  ENTRADA:
 *  entrada - Entrada de dados realizada pelo usu�rio para o campo em quest�o.
 *  opcao_validacao - Campo em que ser� realizada a opera��o de valida��o de dados.
 *
 *  SA�DA: A fun��o retornar� 0 caso a entrada de dados do usu�rio final n�o tenha sido v�lida; 1, caso tenha sido v�lida.
*/
int valida(int entrada, int opcao_validacao);
