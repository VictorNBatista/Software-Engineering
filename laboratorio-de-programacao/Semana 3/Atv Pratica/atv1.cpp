#include<stdio.h>
#include<math.h>
#include<locale.h>

void n(int x);

main()
{
setlocale(LC_ALL, "Portuguese");
	int a;
	float s,soma;
	printf("Insira a quantidade de parcelas que deseja realizar: ");
	scanf("%i",&a);
	n(a);
	}

void n(int x){
	int i;
	float conta,s=0;
	for(i=1;i<=x;i++){
		conta = ((pow(i,2) + 1) / (i + 3));
		s = s + conta;		
}
printf("\nO resultado da soma é: %.2f",s);
}
