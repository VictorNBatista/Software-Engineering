#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	int n,mult;
	
	printf("Digite um número para realizar sua tabuada: ");
	scanf("%i",&n);
	for(int c=1;c<=10;c++)
	{
		mult = n * c;
		printf("%i x %i = %i\n",n,c,mult); 
	}
}


