#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

void receber(int a, int b, char simb);
int operacao(int a, int b, char simb);

main()
{
 setlocale(LC_ALL, "Portuguese");
 int a,b,resp;
 char simb;
 printf("Digite o 1º valor: ");
 scanf("%i",&a);
 printf("Digite o 1º valor: ");
 scanf("%i",&b);
 
 receber(a,b,simb);
 resp = operacao(a,b,simb);
 
 printf("O resultado da operação é: %i",resp);
}

void receber(int a, int b, char simb){
	printf("Valores recebidos\nA: %i \nB: %i\n",a,b);
}

int operacao(int a, int b, char simb){
	printf("Qual operação deseja realizar? (+/*)\n");
	scanf(" %c",&simb);
	if(simb == '+')
	return a+b;
	else if(simb == '*')
	return a*b;
}
