#include <stdio.h>
#include <stdlib.h>
int i,j,soma,vetorA,vetorB,somatotal;

void somatoria(int vetor1[5],int  vetor2[5]){
    int soma = 0;
	for (i=0;i<5;i++)
	{
    	soma =  vetor1[i] + vetor2[i] + soma;
	}
	somatotal = soma;
	printf("O valor da soma é de: %d", somatotal);
}

int main (){
    int vetorA[5], vetorB[5];
    for (i=0;i<5;i++) {
        printf("Digite o %dº número do vetor A: \n",i+1);
        scanf("%d",&vetorA[i]);
    }
    for (j=0;j<5;j++) {
        printf("Digite o %dº número do vetor B: \n",j+1);
        scanf("%d",&vetorB[j]);
    }
	somatoria(&vetorA[5],&vetorB[5]);
}
