#include<stdio.h>
#include<math.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	int c=0;
	
	while(c<=1000000)
	{
		printf("\n%i",c);
		c= c+5;
	}
	
}


