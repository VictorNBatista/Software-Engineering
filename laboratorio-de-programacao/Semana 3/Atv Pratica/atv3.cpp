#include<stdio.h>
#include<math.h>
#include<locale.h> 	
#include<stdlib.h>
#define n 30

void numeros(int numero[], int A[], int B[]){
	int pos=0,neg=0;
	
	for (int i=0;i<n;i++) {
        A[i] = 0;
        B[i] = 0;
    }
	
	for(int i=0;i<n;i++){
		if(numero[i]>0){
			A[pos] = numero[i];
			pos++;
		}else{
			B[neg] = numero[i];
			neg++;
		}
	}
}


main()
{
 setlocale(LC_ALL, "Portuguese");
 int numero[n], A[n], B[n], i;
 
 	printf("Digite os números do vetor\n");
 	for(i=0;i<n;i++){
 	printf("%iº Número: ",i+1);
	scanf("%i",&numero[i]);
 	}
 	
 	numeros(numero,A,B);
 	
 	printf("Vetor A (maiores que zero):\n");
 	for(i=0;i<n;i++){
 		if(A[i]>0)
 		printf("%i  ",A[i]);
	}
	printf("\n");
	
	printf("Vetor B (menores que zero):\n");
	for(i=0;i<n;i++){
		if(B[i]<=0)
		printf("%i  ",B[i]);
	}
	printf("\n");
	
}
