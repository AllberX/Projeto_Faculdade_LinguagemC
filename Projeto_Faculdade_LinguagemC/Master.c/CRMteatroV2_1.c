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
    
    // Declaração das variáveis
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
    // Menu inicial
    printf("|----------=Bem vindo ao teatro SJC!!!=----------|\n");
    printf("| -Pecas em cartaz:           |-Dias Disponiveis: |\n");
    printf("| 1 - Shakespeare           |(Todos os dias)       |\n");
    printf("| 2 - Musical da Broadway   |(Todos os dias)       |\n");
    printf("Digite o número referente à peça desejada: ");
    scanf("%d", &peca);
    system("cls");

    if (peca == 1) nomePeca = "Shakespeare ";
    else if (peca == 2) nomePeca = "Musical da Broadway";
    else {
        printf("Escolha inválida!\n");
        exit(1);
    }
    
    // Escolha do dia
    diasem:
    printf("Escolha um dia da semana (1 a 7): ");
    scanf("%d", &sem);
    char *dias[] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
    if (sem < 1 || sem > 7) {
        printf("Dia inválido!\n");
        exit(1);
    }
    semana = dias[sem - 1];
    system("cls");
    printf("Dia escolhido: %s\n", semana);
    
    // Manipulação de arquivos
    sprintf(caminho, "%d%d%s", peca, sem, arquivo);
    arquivoDados = fopen(caminho, "r");
    if (!arquivoDados) {
        printf("Arquivo não encontrado!\n");
        exit(1);
    }
    for (j = 0; j < 40; j++) {
        fscanf(arquivoDados, "%s", pArq[j]);
    }
    fscanf(arquivoDados, "%d %d", &valor, &numIng);
    fclose(arquivoDados);
    
    if (numIng >= 40) {
        printf("Ingressos esgotados para esta data!\n");
        goto diasem;
    }
    
    // Escolha de poltrona
    inicioPoltrona:
    printf("Escolha uma poltrona: ");
    scanf("%s", poltEsc);
    int disponivel = 0;
    for (j = 0; j < 40; j++) {
        if (strcmp(strupr(poltEsc), pArq[j]) == 0) {
            disponivel = 1;
            strcpy(pArq[j], "xx");
            break;
        }
    }
    if (!disponivel) {
        printf("Poltrona indisponível!\n");
        goto inicioPoltrona;
    }
    system("cls");
    printf("Poltrona escolhida: %s\n", poltEsc);
    
    // Pagamento
    printf("Tem direito a desconto? (S/N): ");
    scanf(" %c", &desconto);
    valorIngresso = (toupper(desconto) == 'S') ? 50 : 100;
    
    printf("Valor do ingresso: R$ %d,00\n", valorIngresso);
    printf("Confirmar compra? (S/N): ");
    scanf(" %c", &compra);
    
    if (toupper(compra) == 'S') {
        arquivoDados = fopen(caminho, "w");
        for (j = 0; j < 40; j++) {
            fprintf(arquivoDados, "%s ", pArq[j]);
        }
        fprintf(arquivoDados, " %d %d", valorIngresso + valor, ++numIng);
        fclose(arquivoDados);
    
        system("cls");
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Compra cancelada!\n");
    }
    
    printf("Nova compra? (S/N): ");
    scanf(" %c", &novaCompra);
    if (toupper(novaCompra) == 'S') {
        goto compra;
    }
    
    return 0;
}
