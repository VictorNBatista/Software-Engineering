#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
	int y = 5;
	int *yPtr;
	
	yPtr = &y;
	
	printf("O valor de y é: %i\n",y);
	printf("O valor de yPtr é: %i\n",yPtr);
	printf("O valor armazenado em y que yPtr referencia: %i\n",*yPtr);
}
