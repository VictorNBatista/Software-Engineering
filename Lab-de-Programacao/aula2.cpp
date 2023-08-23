#include<stdio.h>


main(){
	
	
	int x, y, *pont;
	
	x = 2;
	y = 5;
	pont = &x;
	
	printf("x = %i.\n",x);
	printf("y = %i.\n",y);
	printf("Endereco de x = %i.\n",&x);
	printf("Endereco de y = %i.\n",&y);
	
	printf("Ponteiro = %i.\n",pont);
	printf("Endereco do ponteiro = %i.\n",&pont);
	printf("Conteudo do ponteiro: %i.\n\n",*pont);
	
	x = 10;
	printf("Conteudo do ponteiro = %i.\n",*pont);
}
