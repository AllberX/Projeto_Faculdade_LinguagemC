#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, j, k, n;
    int valor = 0, numIng = 0;
    char cpeca[50];  // Espaço suficiente para o nome do arquivo
    char pLinha[5] = {'A', 'B', 'C', 'D', 'E'};
    int pColuna[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    FILE *banco;

    // Usando dois laços para criar os arquivos
    for (k = 1; k <= 2; k++) {  // k vai de 1 a 2
        for (n = 1; n <= 7; n++) {  // n vai de 1 a 7
            // Formar o nome do arquivo usando snprintf
            snprintf(cpeca, sizeof(cpeca), "%d%dBancoDados.txt", k, n);

            // Abrindo o arquivo para escrita
            banco = fopen(cpeca, "w");
            if (banco == NULL) {
                printf("Erro ao abrir o arquivo %s\n", cpeca);
                return 1;  // Retorna erro caso não consiga abrir o arquivo
            }

            // Escrever as informações no arquivo
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 8; j++) {
                    fprintf(banco, "%c%d ", pLinha[i], pColuna[j]);
                }
                fprintf(banco, "\n");  // Para organizar a impressão na próxima linha
            }

            // Escreve os valores finais
            fprintf(banco, "%d %d\n", valor, numIng);

            // Fechar o arquivo
            fclose(banco);
        }
    }

    return 0;
}
