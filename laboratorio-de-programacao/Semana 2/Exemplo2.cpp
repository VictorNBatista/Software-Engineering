#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

void numAleatorio(int qtde);

main()
{
 setlocale(LC_ALL,"Portuguese");
 int num;
 printf("Digite a Qtde de Valores Aleatório que gostaria de gerar: ");
 scanf("%d",&num);
 //Fazendo a chamado do procedimento(função) numAleatorio(int qtde)
 printf("\n");
 numAleatorio(num);
 
}
//************************************************
void numAleatorio(int qtde){
	int i;
	for(i=1;i<=qtde;i++){
		printf("%10d", 1+rand()%6);
		if(i%5 == 0)
		printf("\n");
	}
}

