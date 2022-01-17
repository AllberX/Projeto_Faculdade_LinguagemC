#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i, j, k, n, valor, numIng;
	char cpeca[30], csem[3];
	char arquivo[25] = "BancoDados.txt";
	char pLinha[5] = {'A', 'B', 'C', 'D', 'E'};
	int pColuna[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	FILE *banco;
	
	valor = 0;
	numIng = 0;
	k = 1;
	n = 2;
	
	for (k=1; k<3; k++)
	{
		for (n=1; n<8; n++)
		{
			sprintf(cpeca, "%d", k);
			sprintf(csem, "%d", n);
			
			strcat(cpeca, csem);
			strcat(cpeca, arquivo);
	
			banco = fopen(cpeca, "w");
			
			for(i=0; i<5; i++)
			{
				for(j=0; j<8; j++)
				{
					fprintf(banco, "%c%d ",pLinha[i], pColuna[j]);
				}
			}
			fprintf(banco, "%d ",valor);
			fprintf(banco, "%d ",numIng);
		
			fclose(banco);
		
		}
	}
	
	return 0;
}
