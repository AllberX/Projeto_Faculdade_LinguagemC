#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

/*
* Projeto para venda de ingressos de teatro 
* Análise e desenvolvimento de sistemas
*/

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	//Declaração das variáveis'																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
	int j, peca, sem, valor, numIng, valorIngresso, i, menu;
	char desconto, compra, novaCompra;
	char cpeca[3], csem[3];
	char *semana, *nomePeca;
	char caminho[30];
	char arquivo[25] = "BancoDados.txt";
	char pArq[40][10];
	char poltEsc[2];
	FILE *arquivoDados;
	
	
	compra:
	system("cls");
	//Boas vindas e escolha da peça
    printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|----------=Bem vindo ao teatro SJC!!!=----------|\n");
	printf("|________________________________________________|\n\n\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| -Pecas em cartaz:           |-Dias Disponiveis:     |\n");
	printf("|_____________________________|_______________________|\n");
	printf("| 19h - Shakespeare           |(Todos os dias)        |\n");
	printf("|                             |                       |\n");
	printf("| 21h - Musical da Broadway   |(Todos os dias)        |\n");
	printf("|_____________________________|_______________________|\n\n\n");
	printf("-Digite o número referente à peca que deseja assistir...\n\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1 - Shakespeare           |\n| 2 - Musical da Broadway   |\n");
	printf("|___________________________|\n");
	scanf("%d", &peca);
	system("cls");

	//Verificar a peça escolhida
	if (peca==1)
	{
		printf("Você escolheu -- Shakespeare --\n\n");
		nomePeca = "Shakespeare às 19h";
	}
	else if (peca==2)
	{
		printf("Você escolheu -- Musical da Broadway --\n\n");
		nomePeca = "Musical da Broadway às 21h";
	}
	else
	{
		printf("Escolha uma das opções de peça válida!\n");
		exit(1);
	}
	
	//Selecionar dia da semana
	diasem:
	printf("-Digite o número referente ao dia da semana que deseja comprar\n\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| 1 - Domingo    02-Dez-2018 |\n| 2 - Segunda    03-Dez-2018 |\n| 3 - Terça      04-Dez-2018 |\n| 4 - Quarta     05-Dez-2018 |\n| 5 - Quinta     06-Dez-2018 |\n| 6 - Sexta      07-Dez-2018 |\n| 7 - Sábado     08-Dez-2018 |\n");
	printf("|____________________________|\n");
	scanf("%d", &sem);
	
	switch(sem)
	{
		case 1: semana = "Domingo, 02-Dez-2018";break;
		case 2: semana = "Segunda-feira, 03-Dez-2018";break;
		case 3: semana = "Terça-feira, 04-Dez-2018";break;
		case 4: semana = "Quarta-feira, 05-Dez-2018";break;
		case 5: semana = "Quinta-feira, 06-Dez-2018";break;
		case 6: semana = "Sexta-feira, 07-Dez-2018";break;
		case 7: semana = "Sábado, 08-Dez-2018";break;
		default:printf("Escolha um dia da semana válido!"); exit(1);
	}
	system("cls");
	printf("O dia escolhido foi | %s |\n\n", semana);
	
	
	//Buscar dados do banco referente às escolhas
	sprintf(cpeca, "%d", peca);
	sprintf(csem, "%d", sem);
	
	strcat(caminho, cpeca);
	strcat(caminho, csem);
	strcat(caminho, arquivo);
	
	arquivoDados = fopen(caminho, "r");
	if(arquivoDados == NULL)
	{
		printf("O arquivo não foi encontrado!\n");
		exit(1);
	}
	
	for(j=0; j<40; j++)
	{
		fscanf(arquivoDados, "%s", pArq[j]);
	}
	fscanf(arquivoDados, "%d", &valor);
	fscanf(arquivoDados, "%d", &numIng);
	
	//Verificar se ainda tem ingressos disponíveis para essa data
	if(numIng>=40)
	{
		printf("Ingressos esgotados para esta data!\n");
		goto diasem;
		exit(1);
	}
	
	//Processar a poltrona escolhida e substiruir por xx
	inicioPoltrona:
	i = 0;
	printf("|~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|Escolha a poltrona:  |\n");
	printf("|_____________________|\n\n");
	for(j=0; j<40; j++)
	{
		fprintf(arquivoDados, "%s ", pArq[j]);
	}
	
	printf("---------Palco---------\n");
	for(j=0; j<40; j++)
	{
		printf("%s ", pArq[j]);
		if((j+1)%8==0) printf("\n");
	}
	printf("\n");
	scanf("%s", &poltEsc);
	
	//Verificar se a poltrona está disponível
	for(j=0; j<40; j++)
	{
		if(strcmp(strupr(poltEsc),pArq[j])==0)
		{
			i = 1;
			break;
		}            
	}
	
	if(i==0)
	{
		printf("Favor escolher uma poltrona disponível\n\n");
		goto inicioPoltrona;
	}
	system("cls");
	//Se a poltrona escolhida for válida
	printf("\nA poltrona escolhida foi: %s\n", strupr(poltEsc));
	
	for(j=0; j<40; j++)
	{
		if(strcmp(strupr(poltEsc),pArq[j])==0)
		{
			strcpy(pArq[j], "xx");
			printf("\n");
		}            
	}
	
	//Verificar condições de pagamento
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|...................Pagamento...................|\n");
	printf("|_______________________________________________|\n\n");
	if(sem==3)
	{
		printf("É aluno da rede pública de ensino? \nS = Sim, N = Não\n");
		scanf(" %c", &desconto);
		if(toupper(desconto)=='S')
		{
			system("cls");
			printf("-Você tem 100%% de desconto!!!\n\n");
			valorIngresso = 0;
			goto valor;
		}
		else system("cls");
		{
			printf("Tem de 2 a 12 anos, acima de 60 anos ou é professor/n da rede pública de ensino?\nS = Sim, N = Não\n");
			scanf(" %c", &desconto);
			if(toupper(desconto)=='S')
			{
				system("cls");
				printf("-Você tem 50%% de desconto!!!\n\n");
				valorIngresso = 50;
			}
			else
			{
				system("cls");
				valorIngresso = 100;
			}
		}
	}
	else
	{
		printf("Tem de 2 a 12 anos, acima de 60 anos ou é professor da rede pública de ensino?\nS = Sim, N = Não\n");
		scanf(" %c", &desconto);
		if(toupper(desconto)=='S')
		{
			system("cls");
			printf("-Você tem 50%% de desconto!!!\n\n");
			valorIngresso = 50;
		}
		else 
		{
			system("cls");
			valorIngresso = 100;
		}
	}
	fclose(arquivoDados);
	
	valor:
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("| O valor do ingresso é: R$ %d,00\n", valorIngresso);
	printf("|__________________________________|\n\n");
	
	printf("Pode processar sua compra? \nS = Sim, N = Não\n");
	scanf(" %c", &compra);
	
	if(toupper(compra)=='S')
	{
		//Atualizar banco de dados com os dados da compra
		arquivoDados = fopen(caminho, "w");
		for(j=0; j<40; j++)
		{
			fprintf(arquivoDados, "%s ", pArq[j]);
		}
		fprintf(arquivoDados, " %d", valorIngresso + valor);
		fprintf(arquivoDados, " %d", ++numIng);
		
		fclose(arquivoDados);
		
		system("cls");
		
		//Dados da compra para impressão
		printf("\n***************** Dados da compra *****************\n");
		printf("**\n");
		printf("**  Peça e horário: %s \n", nomePeca);
		printf("**  Dia da semana: %s\n", semana);
		printf("**  Poltrona reservada: %s\n", strupr(poltEsc));
		printf("**\n");
		printf("***************************************************\n\n\n");
	}
		
	else printf("Compra cancelada!\n\n");
	
	//Se desejar realizar uma nova compra o programa reinicia
	printf("\nDeseja realizar uma nova compra? \nS = Sim, N = Não\n");
	scanf(" %c", &novaCompra);
	
	if (toupper(novaCompra)== 'S')
	{
		system("cls");
		system("Pim4_TeatroSJC.exe");
	}
	
	return 0;
}
