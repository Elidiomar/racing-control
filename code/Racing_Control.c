/*
@title - CONTROL PROGRAM OF PARTICIPANTS OF STREET RACES
@author - ELIDIOMAR RODRIGUES
@email - ELIDIOMAR.RODRIGUES@GMAIL.COM
@language - PT-BR
@version - 1.0
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//CRIA A ESTRUTURA PARA CADASTRO DE CORREDORES
typedef struct{
	long int id, idade, batimentoRepouso, batimentoExercicio, idCorridas;
	char nome[81], dataNascimento[11], cpf[12], endereco[151], nomeContato[81], sexo[2], pressaoArterial[6], telefone[12], tempoProva[16], dataInsercaoDados[11];
	float colesterol, triglicerideos, glicose, peso, altura, imc;
}corredores;

//CRIA A ESTRUTURA PARA CADASTRO DAS PROVAS
typedef struct{
	int id;
	char nome[21], horaInicio[5], horaTermino[5], dataRealizacao[11];
	float percursoMetros;
}provas;

//PROTOTIPO DAS FUNCOES
void cadastro_Corredor();
void cadastro_Prova();
void pre_Prova();
void pos_Prova();
void relatorio();
void limparBuffer();

//DECLARA AS VARIAVEIS
corredores corredor[15];
provas prova[10];
int i = 1, cont = 1, x = 1, y = 1, z = 1, totalCorredores = -1, totalProvas = -1;
char anoAtual[5], temp[91], escolha[3], converte[91];

int main()
{
 	// INICIALIZA AS VARIAVEIS
    for (i=0; i<=14; i++)
	{
		// CORREDORES
		strcpy(corredor[i].nome,"");
		strcpy(corredor[i].dataNascimento,"");
		strcpy(corredor[i].cpf,"");
		strcpy(corredor[i].endereco,"");
		strcpy(corredor[i].nomeContato,"");
		strcpy(corredor[i].sexo,"");
		strcpy(corredor[i].pressaoArterial,"");
		strcpy(corredor[i].telefone,"");
		strcpy(corredor[i].tempoProva,"");
		strcpy(corredor[i].dataInsercaoDados,"");
		corredor[i].id = 0;
		corredor[i].idade = 0;
		corredor[i].batimentoRepouso = 0;
		corredor[i].batimentoExercicio = 0;
		corredor[i].idCorridas = 0;
		corredor[i].colesterol = 0;
		corredor[i].triglicerideos = 0;
		corredor[i].glicose = 0;
		corredor[i].peso = 0;
		corredor[i].altura = 0;
		corredor[i].imc = 0;
			
		//PROVAS
		strcpy(prova[i].nome,"");
		strcpy(prova[i].horaInicio,"");
		strcpy(prova[i].horaTermino,"");
		strcpy(prova[i].dataRealizacao,"");
		prova[i].id = 0;
		prova[i].percursoMetros = 0;
	}

	// HABILITA ACENTUACAO DO IDIOMA LOCAL
	setlocale(LC_ALL, "Portuguese");

	// MENSAGEM INICIAL E INFORMACOES
	system("CLS");
	system("COLOR E");
	printf("\a");

	printf("\n =================================================================================");
	printf("\n                 CONTROLE PARTICIPANTES CORRIDA DE RUA");
	printf("\n =================================================================================");
	printf("\n\n SEJA BEM VINDO,");
	printf("\n COM ESSA FERRAMENTA VOCE PODERA ACOMPANHAR MELHOR OS DADOS DOS CORREDORES");
	printf("\n A FIM DE VERIFICAR MELHORA NAS CONDIÇÕES DE SAÚDE DE CADA UM.");
	printf("\n NELA VOCE ENTRARA COM OS DADOS PARA POSTERIOR CONTROLE E PODERA ACOMPANHAR ");
	printf("\n O DESEMPENHO DOS COMPETIDORES.");
	printf("\n\n OBSERVACAO: COMPETIDORES COM MENOS DE 35 ANOS NÃO PRECISAM DE SER CADASTRADOS.");
	printf("\n\n Pressione a tecla [ENTER] para inicia o cadastro...\n\n  ");

 	temp[0]=getch();

	i = 1;
	while (i != 0)
	{
		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR A");
		printf("\n  SELECIONE UM DAS OPÇÕES ABAIXO:\n");
		printf("\n  1 - CADASTRAR COMPETIDOR");
		printf("\n  2 - CADASTRAR CORRIDA");
		printf("\n  3 - INSERIR DADOS PRE PROVA");
		printf("\n  4 - INSERIR DADOS POS PROVA");
		printf("\n  5 - EXIBIR RELATORIOS");
		printf("\n  0 - SAIR\n\n");

		strcpy(escolha,"");
		escolha[0]=getch();
		i = atoi(escolha);

		if (i >5)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
			system ("PAUSE>NUL");
		}
		else
		{
			
			if (i > 0)
			{
				// CHAMA FUNCAO DE CADASTRO DE CORREDORES
				if (i == 1) cadastro_Corredor();
					
				// CHAMA FUNCAO DE CADASTRO DE PROVAS
				if ( i == 2) cadastro_Prova();
						
				// CHAMA FUNCAO PARA INSERIR DADOS ANTES DA PROVA (UMA SEMANA ANTES)
				if ( i == 3) pre_Prova();

				// CHAMA FUNCAO PARA INSERIR DADOS DEPOIS DA PROVA
				if ( i == 4) pos_Prova();

				// CHAMA FUNCAO DE RELATORIOS
				if ( i == 5) relatorio();
    		}
		}
	}
}


// FUNCAO PARA CADASTRO DOS CORREDORES
void cadastro_Corredor()
{
	x = 1;
	while (x != 0)
	{

		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR B");
		
		totalCorredores = -1;
		for (cont = 0; cont <= 15; cont++) if (corredor[cont -1].id > 0) totalCorredores ++;

		printf("\n  SELECIONE UM DAS OPÇÕES ABAIXO:\n");
		printf("\n  1 - CADASTRAR NOVO CORREDOR");
		printf("\n  2 - EXIBIR LISTA DE CORREDORES");
		printf("\n  0 - VOLTAR PARA MENU\n\n");

		strcpy(escolha,"");
		escolha[0]=getch();
		x = atoi(escolha);
		
		if (x > 2)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
			system ("PAUSE>NUL");
		}
		else
		{

			if (x > 0)
			{
				// CADASTRO DE CORREDORES
				if (x == 1)
				{
					
					//ARMAZENA ID DO CORREDOR
					totalCorredores ++;
					corredor[totalCorredores].id = totalCorredores +1;
					system("CLS");
					system("COLOR E");
					
					//ARMAZENA NOME DO CORREDOR
					printf("\n   NOME DO CORREDOR: ");
					gets (temp);
	 				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].nome,temp);

					//ARMAZENA DATA DE NASCIMENTO
					printf("\n   DATA DE NASCIMENTO: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].dataNascimento,temp);
					
					//ARMAZENA IDADE
					printf("\n   IDADE: ");
					gets (temp);
	  				setbuf(stdin, NULL);
					corredor[totalCorredores].idade = atoi(temp);

					//ARMAZENA CPF
					printf("\n   NUMERO CPF: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].cpf, temp);
					
					//ARMAZENA ENDERECO
					printf("\n   ENDEREÇO: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].endereco, temp);
					
					//ARMAZENA SEXO
					printf("\n   SEXO: ");
					gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].sexo, temp);
					
					//ARMAZENA TELEFONE
					printf("\n   TELEFONE: ");
					gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(corredor[totalCorredores].telefone, temp);
					
					//ARMAZENA NOME CONTATO
					printf("\n   NOME PARA CONTATO: ");
	 				gets (temp);
					strcpy(corredor[totalCorredores].nomeContato, temp);

					system("COLOR B");
					printf ("\n\n   [CADASTRADO COM SUCESSO] ...\n   ");
				
				}
				

				// LISTA DE CORREDORES
				if (x == 2)
				{
					system("CLS");
					if (totalCorredores == -1)
						printf ("\n    NENHUM COMPETIDOR CADASTRADO.");
					else
					{
						printf("\n  LISTA DE CORREDORES:\n");
						for (cont = 0; cont <= 15; cont++)
							if (corredor[cont].id > 0)
								printf ("\n    %i - %s.", corredor[cont].id, corredor[cont].nome);
					}
					printf ("\n\n\n    PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE CADASTRO...\n   ");
					

				}
				
				system ("PAUSE>NUL");
			}
		}
	}
}


// FUNCAO PARA CADASTRO DAS PROVAS
void cadastro_Prova()
{
	x = 1;
	while (x != 0)
	{

		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR F");

		totalProvas = -1;
		for (cont = 0; cont <= 15; cont++) if (corredor[cont -1].id > 0) totalProvas ++;

		printf("\n  SELECIONE UM DAS OPÇÕES ABAIXO:\n");
		printf("\n  1 - CADASTRAR PROVA");
		printf("\n  2 - EXIBIR LISTA DE PROVAS");
		printf("\n  0 - VOLTAR PARA MENU\n\n");

		strcpy(escolha,"");
		escolha[0]=getch();
		x = atoi(escolha);
		if (x > 2)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
			system ("PAUSE>NUL");
		}
		else
		{

			if (x > 0)
			{
				// CADASTRO DE CORRIDAS
				if (x == 1)
				{

					//ARMAZENA ID DA PROVA
					totalProvas ++;
					prova[totalProvas].id = totalProvas +1;
					system("CLS");
					system("COLOR E");

					//ARMAZENA NOME DA PROVA
					printf("\n   NOME DA PROVA: ");
					gets (temp);
	 				setbuf(stdin, NULL);
					strcpy(prova[totalProvas].nome,temp);

					//ARMAZENA DATA DA REALIZAÇÃO DA PROVA
					printf("\n   DATA DA REALIZAÇÃO DA PROVA: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(prova[totalProvas].dataRealizacao,temp);

					//ARMAZENA HORARIO DE INICIO
					printf("\n   HORARIO DE INICIO DA PROVA: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(prova[totalProvas].horaInicio,temp);

					//ARMAZENA HORARIO DE TERMINO
					printf("\n   HORARIO DE TERMINO DA PROVA: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					strcpy(prova[totalProvas].horaTermino,temp);

					//ARMAZENA PERCURSO DA PROVA
					printf("\n   PERCURSO DA PROVA EM METROS: ");
	 				gets (temp);
	  				setbuf(stdin, NULL);
					prova[totalProvas].percursoMetros = atof(temp);

					system("COLOR F");
					printf ("\n\n   [CADASTRADO COM SUCESSO] ...\n   ");

				}


				// LISTA DAS CORRIDAS
				if (x == 2)
				{
					system("CLS");
					if (totalProvas == -1)
						printf ("\n    NENHUMA CORRIDA CADASTRADA.");
					else
					{
						printf("\n  LISTA DAS CORRIDAS:\n");
						for (cont = 0; cont <= 15; cont++)
							if (prova[cont].id > 0)
								printf ("\n    %i - %s - %s - %s.", prova[cont].id, prova[cont].dataRealizacao, prova[cont].horaInicio, prova[cont].nome);
					}
					printf ("\n\n\n    PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE CADASTRO...\n   ");

				}

				system ("PAUSE>NUL");
			}
		}
	}
}


// FUNCAO PARA CADASTRAR DADOS ANTES DAS PROVAS
void pre_Prova()
{
	x = 1;
	while (x != 0)
	{
		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR E");
		
		if (totalCorredores == -1)
			printf ("\n    NENHUM COMPETIDOR CADASTRADO.");
		else
		{
			printf("\n  SELECIONE UM DOS CORREDORES PARA CADASTRO DOS DADOS:");
			printf("\n  SD = SEM DADOS DE COLETA\n  DC = DADOS COLETADOS\n");
			totalCorredores = 0;
			for (cont = 0; cont <= 15; cont++)
			{
				if (corredor[cont].id > 0)
				{
					totalCorredores ++;
					if (corredor[cont].batimentoRepouso > 0)
						printf ("\n    %i - DC - %s.", corredor[cont].id, corredor[cont].nome);
					else
						printf ("\n    %i - SD - %s.", corredor[cont].id, corredor[cont].nome);
				}
			}
		}
		printf ("\n    0 - VOLTAR PARA MENU\n\n");
		strcpy(escolha,"");
		escolha[0]=getch();
		x = atoi(escolha);
		
		if ((x > totalCorredores) && x != 0)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
			system ("PAUSE>NUL");
		}
		else
		{

			if (x > 0)
			{
				system("CLS");
				system("COLOR B");
				printf("\n\n   CORREDOR SELECIONADO: %s.", corredor[x -1].nome);
				printf("\n   IDADE: %i ANOS.", corredor[x -1].idade);
				printf("\n   CPF: %s.", corredor[x -1].cpf);
				printf("\n   ID: %i.\n\n", corredor[x -1].id);

				//ARMAZENA BATIMENTO CARDIACO EM REPOUSO
				printf("\n   +=======================================================================+");
				printf("\n   + PREENCHA OS CAMPOS ABAIXO COM AS INFORMAÇÕES DO CORREDOR SELECIONADO. +");
				printf("\n   +=======================================================================+\n");
				printf("\n\n   BATIMENTO CARDIACO EM REPOUSO: ");
 				gets (temp);
	 			setbuf(stdin, NULL);
				corredor[x -1].batimentoRepouso = atof(temp);
				
				//ARMAZENA PRESSAO ARTERIAL
				printf("\n   PRESSÃO ARTERIAL: ");
 				gets (temp);
	 			setbuf(stdin, NULL);
				strcpy(corredor[x -1].pressaoArterial, temp);
				
				//ARMAZENA  COLESTEROL
				printf("\n   COLESTEROL: ");
 				gets (temp);
	 			setbuf(stdin, NULL);
				corredor[x -1].colesterol = atof(temp);

				//ARMAZENA TRIGLICERÍDEOS
				printf("\n   TRIGLICERÍDEOS: ");
 				gets (temp);
	 			setbuf(stdin, NULL);
				corredor[x -1].triglicerideos = atof(temp);

				//ARMAZENA GLICOSE
				printf("\n   GLICOSE: ");
 				gets (temp);
	 			setbuf(stdin, NULL);
				corredor[x -1].glicose = atof(temp);

				//ARMAZENA PESO
				printf("\n   PESO: ");
				gets (temp);
	  			setbuf(stdin, NULL);
				corredor[x -1].peso = atof(temp);

				//ARMAZENA ALTURA
				printf("\n   ALTURA: ");
				gets (temp);
	  			setbuf(stdin, NULL);
				corredor[x -1].altura = atof(temp);
				
				//DATA DE INSERÇÃO DOS DADOS
				strcpy(corredor[x -1].dataInsercaoDados, __DATE__);

				system("COLOR F");
				printf ("\n\n   [CADASTRADO COM SUCESSO] ...\n   ");
				system ("PAUSE>NUL");
			}
		}
	}
}


// FUNCAO PARA CADASTRAR DADOS DEPOIS DAS PROVAS
void pos_Prova()
{
	x = 1;
	while (x != 0)
	{
		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR E");
		if (totalCorredores == -1)
			printf ("\n    NENHUM COMPETIDOR CADASTRADO.");
		else
		{
			printf("\n  SELECIONE UM DOS CORREDORES PARA CADASTRO DOS DADOS:");
			printf("\n  SD = SEM DADOS DE COLETA\n  DC = DADOS COLETADOS\n");
			totalCorredores = 0;
			for (cont = 0; cont <= 15; cont++)
			{
				if (corredor[cont].id > 0)
				{
					totalCorredores ++;
					if (corredor[cont].batimentoExercicio > 0)
						printf ("\n    %i - DC - %s", corredor[cont].id, corredor[cont].nome);
					else
						printf ("\n    %i - SD - %s", corredor[cont].id, corredor[cont].nome);
				}
			}
		}
		
		printf ("\n    0 - VOLTAR PARA MENU\n\n");
		
		strcpy(stdin,"");
		strcpy(escolha,"");
		escolha[0]=getch();
		x=atoi(escolha);

		if ((x > totalCorredores) && x != 0)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
		    system ("PAUSE>NUL");
		}
		else
		{

			if (x > 0)
			{
				system("CLS");
				system("COLOR E");

				// LISTA NA OS DADOS DO CORREDOR SELECIONADO
				printf("\n\n   CORREDOR SELECIONADO: %s.", corredor[x -1].nome);
				printf("\n   IDADE: %i ANOS.", corredor[x -1].idade);
				printf("\n   CPF: %s.", corredor[x -1].cpf);
				printf("\n   ID: %i.\n\n", corredor[x -1].id);

				printf("\n   +=======================================================================+");
				printf("\n   + PREENCHA OS CAMPOS ABAIXO COM AS INFORMAÇÕES DO CORREDOR SELECIONADO. +");
				printf("\n   +=======================================================================+\n");

				// VERIFICA SE O CORREDOR CONCLUIU A PROVA
				printf("\n\n   O COMPETIDOR CONCLUIU A PROVA?");
				printf("\n   1 - SIM");
				printf("\n   2 - NÃO\n   ");

				strcpy(escolha,"");
				escolha[0]=getch();
				z = atoi(escolha);
				strcpy(stdin,"");
				strcpy(escolha,"");
				
				if (z == 1)
				{
					//ARMAZENA TEMPO DE PROVA
					printf("\n   DIGITE TEMPO CONCLUSAO DA PROVA EM MINUTOS: ");
	 				gets (temp);
	  				strcpy(stdin,"");
					strcpy(corredor[x -1].tempoProva, temp);
				}
				else
					strcpy(corredor[x -1].tempoProva, "NAO CONCLUIDO");

				//ARMAZENA BATIMENTO CARDIACO POS EXERCICIO
				printf("\n   BATIMENTO CARDIACO POS EXERCICIO: ");
 				gets (temp);
 				strcpy(stdin,"");
				corredor[x -1].batimentoExercicio = atoi(temp);

				system("COLOR F");
				printf ("\n\n   [CADASTRADO COM SUCESSO] ...\n   ");
				system ("PAUSE>NUL");
			}
		}
	}
}


// FUNCAO PARA RELATORIOS
void relatorio()
{
	x = 1;
	while (x != 0)
	{
		//EXIBE NA TELA AS OPCOES DE ESCOLHAS
		system("CLS");
		system("COLOR B");
		printf("\n  SELECIONE UM DAS OPÇÕES ABAIXO:\n");
		printf("\n  1 - SOBREPESO");
		printf("\n  2 - HIPERLIPIDEMIA");
		printf("\n  3 - HIPERGLICEMIA");
		printf("\n  4 - INDIVIDUAL");
		printf("\n  0 - VOLTAR PARA MENU\n\n");

		escolha[0]=getch();
		x = atoi(escolha);
		if (x > 4)
		{
			system("CLS");
   			system("COLOR C");
			printf("\n VOCE ESCOLHEU UMA OPCAO INEXISTENTE!");
 			printf("\n PRESSIONE QUALQUER TECLA PARA ESCOLHER NOVAMENTE...\n");
			system ("PAUSE>NUL");
		}
		else
		{

			if (x > 0)
			{
				totalCorredores = 0;
				for (cont = 0; cont <= 15; cont++) if (corredor[cont -1].id > 0) totalCorredores ++;

				system("CLS");
				if (totalCorredores == 0)
				{
					printf ("\n  NENHUM COMPETIDOR CADASTRADO.");
					printf ("\n\n  PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE RELATORIOS...\n   ");
					temp[0]=getch();
				}
				else
				{
					// EXIBE RELATORIO DE SOBREPESOS
					if (x == 1)
					{
						y = 0;
						for (cont = 0; cont <= 15; cont++)
						{
							if (corredor[cont -1].id > 0)
							{
								corredor[cont -1].imc = corredor[cont -1].peso / (corredor[cont -1].altura * corredor[cont -1].altura);
								if (corredor[cont -1].imc >= 30.00) y ++;
							}
						}
						
						if (y > 0)
						{
							printf ("\n\n  +----------------------------------------------------------------------------------+");
							printf ("\n  |                       RELATORIO DE CORREDORES COM SOBREPESO                      |");
							printf ("\n  +----------------------------------------------------------------------------------+");
							printf ("\n  | ID | NOME                                   | IDADE | BAT. EXERCICIO |    IMC    |");
							printf ("\n  +----------------------------------------------------------------------------------+");
							for (cont = 0; cont <= 15; cont++)
							{
								if (corredor[cont -1].imc >= 30.00)
								{

									printf ("\n  | %i", corredor[cont -1].id);
									sprintf(converte,"%i",corredor[cont -1].id);
									for (z = 0; z <= (2 - strlen(converte)); z++) printf (" ");

									printf ("| %s", corredor[cont -1].nome);
									for (z = 0; z <= (38 - strlen(corredor[cont -1].nome)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].idade);
									sprintf(converte,"%i",corredor[cont -1].idade);
									for (z = 0; z <= (5 - strlen(converte)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].batimentoExercicio);
									sprintf(converte,"%i",corredor[cont -1].batimentoExercicio);
									for (z = 0; z <= (14 - strlen(converte)); z++) printf (" ");

									printf ("| %.2f", corredor[cont -1].imc);
									sprintf(converte,"%.2f",corredor[cont -1].imc);
									for (z = 0; z <= (9 - strlen(converte)); z++) printf (" ");
									printf ("|");


								}
       						}
							printf ("\n  +----------------------------------------------------------------------------------+\n");
						}
						else printf ("\n  NENHUM CORREDOR COM SOBREPESO.");

						printf ("\n  PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE RELATORIOS...\n   ");
						temp[0]=getch();

					}


					// EXIBE RELATORIO DE HIPERLIPIDEMIA (COLESTEROL ALTO > 240 MG/DL)
					if (x == 2)
					{
						y = 0;
						for (cont = 0; cont <= 15; cont++) if (corredor[cont -1].colesterol >= 240) y ++;

						if (y > 0)
						{
							printf ("\n\n  +-----------------------------------------------------------------------------------+");
							printf ("\n  |                    RELATORIO DE CORREDORES COM HIPERLIPIDEMIA                     |");
							printf ("\n  +-----------------------------------------------------------------------------------+");
							printf ("\n  | ID | NOME                                   | IDADE | BAT. EXERCICIO | COLESTEROL |");
							printf ("\n  +-----------------------------------------------------------------------------------+");
							for (cont = 0; cont <= 15; cont++)
							{
								if (corredor[cont -1].colesterol >= 240)
								{

									printf ("\n  | %i", corredor[cont -1].id);
									sprintf(converte,"%i",corredor[cont -1].id);
									for (z = 0; z <= (2 - strlen(converte)); z++) printf (" ");

									printf ("| %s", corredor[cont -1].nome);
									for (z = 0; z <= (38 - strlen(corredor[cont -1].nome)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].idade);
									sprintf(converte,"%i",corredor[cont -1].idade);
									for (z = 0; z <= (5 - strlen(converte)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].batimentoExercicio);
									sprintf(converte,"%i",corredor[cont -1].batimentoExercicio);
									for (z = 0; z <= (14 - strlen(converte)); z++) printf (" ");

									printf ("| %.2f", corredor[cont -1].colesterol);
									sprintf(converte,"%.2f",corredor[cont -1].colesterol);
									for (z = 0; z <= (10 - strlen(converte)); z++) printf (" ");
									printf ("|");
									
								}
       						}
							printf ("\n  +-----------------------------------------------------------------------------------+\n");
						}
						else printf ("\n  NENHUM CORREDOR COM HIPERLIPIDEMIA (COLESTEROL ALTO).");

						printf ("\n  PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE RELATORIOS...\n   ");
						temp[0]=getch();

					}


					// EXIBE RELATORIO DE HIPERGLICEMIA > 125
					if (x == 3)
					{
						y = 0;
						for (cont = 0; cont <= 15; cont++) if (corredor[cont -1].glicose > 125) y ++;

						if (y > 0)
						{
							printf ("\n\n  +----------------------------------------------------------------------------------+");
							printf ("\n  |                    RELATORIO DE CORREDORES COM HIPERGLICEMIA                     |");
							printf ("\n  +----------------------------------------------------------------------------------+");
							printf ("\n  | ID | NOME                                   | IDADE | BAT. EXERCICIO |  GLICOSE  |");
							printf ("\n  +----------------------------------------------------------------------------------+");
							for (cont = 0; cont <= 15; cont++)
							{
								if (corredor[cont -1].glicose > 125)
								{
									printf ("\n  | %i", corredor[cont -1].id);
									sprintf(converte,"%i",corredor[cont -1].id);
									for (z = 0; z <= (2 - strlen(converte)); z++) printf (" ");

									printf ("| %s", corredor[cont -1].nome);
									for (z = 0; z <= (38 - strlen(corredor[cont -1].nome)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].idade);
									sprintf(converte,"%i",corredor[cont -1].idade);
									for (z = 0; z <= (5 - strlen(converte)); z++) printf (" ");

									printf ("| %i", corredor[cont -1].batimentoExercicio);
									sprintf(converte,"%i",corredor[cont -1].batimentoExercicio);
									for (z = 0; z <= (14 - strlen(converte)); z++) printf (" ");

									printf ("| %.2f", corredor[cont -1].glicose);
									sprintf(converte,"%.2f",corredor[cont -1].glicose);
									for (z = 0; z <= (9 - strlen(converte)); z++) printf (" ");
									printf ("|");
									
								}
       						}
							printf ("\n  +----------------------------------------------------------------------------------+\n");
						}
						else printf ("\n  NENHUM CORREDOR COM HIPERGLICEMIA.");

						printf ("\n  PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE RELATORIOS...\n   ");
						temp[0]=getch();
					}

					// EXIBE RELATORIO INDIVIDUAL
					if (x == 4)
					{
						printf ("\n\n  +----------------------------------------------------------------------------------+");
						printf ("\n  |                       RELATORIO DE CORREDORES - INDIVIDUAL                       |");
						printf ("\n  +----------------------------------------------------------------------------------+");
						printf ("\n  | ID | NOME                                   | IDADE | BAT. EXERCICIO | GLICOSE   |");
						printf ("\n  +----------------------------------------------------------------------------------+");

						for (cont = 0; cont <= 15; cont++)
						{
							if (corredor[cont -1].id > 0)
							{
								printf ("\n  | %i", corredor[cont -1].id);
								sprintf(converte,"%i",corredor[cont -1].id);
								for (z = 0; z <= (2 - strlen(converte)); z++) printf (" ");
								
								printf ("| %s", corredor[cont -1].nome);
								for (z = 0; z <= (38 - strlen(corredor[cont -1].nome)); z++) printf (" ");
								
								printf ("| %i", corredor[cont -1].idade);
								sprintf(converte,"%i",corredor[cont -1].idade);
								for (z = 0; z <= (5 - strlen(converte)); z++) printf (" ");
								
								printf ("| %i", corredor[cont -1].batimentoExercicio);
								sprintf(converte,"%i",corredor[cont -1].batimentoExercicio);
								for (z = 0; z <= (14 - strlen(converte)); z++) printf (" ");
								
								printf ("| %.2f", corredor[cont -1].glicose);
								sprintf(converte,"%.2f",corredor[cont -1].glicose);
								for (z = 0; z <= (9 - strlen(converte)); z++) printf (" ");
								printf ("|");
							}
						}
						
						printf ("\n  +----------------------------------------------------------------------------------+");
						printf ("\n\n  PRESSIONE QUALQUER TECLA PARA RETORNAR AS OPÇÕES DE RELATORIOS...\n   ");
						temp[0]=getch();
					}
				}
			}
			
		}
	}
}


// FUNCAO PARA LIMPAR BUFFER (JA QUE A SETBUF NAO FUNCIONA EM ALGUNS CASOS!)
void limparBuffer()
{
    int c;
    while( (c = fgetc(stdin)) != EOF && (c = fgetc(stdin)) != '\n' );
}
