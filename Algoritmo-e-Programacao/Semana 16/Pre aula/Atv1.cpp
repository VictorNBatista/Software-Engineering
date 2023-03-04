#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int num[8], numNeg[8], numPos[8], positivos=0, negativos=0, i;
 printf("Digite 8 números inteiros: ");
 for(i=0;i<=7;i++){
 	scanf("%d",&num[i]);
 	if(num[i]>=0){
 		numPos[positivos] = num[i];
 		positivos++;
	 } else if(num[i]<0){
	 	numNeg[negativos] = num[i];
	 	negativos++;
	 }
 }
 
 printf("\nO vetor digitado foi: ");
 for(i=0;i<=7;i++){
 	printf("%d ",num[i]);
 }
 
 printf("\nVetor dos números positivos: ");
 for(i=0;i<positivos;i++){
 	printf("%d ",numPos[i]);
 }
 
 printf("\nVetor dos números negativos: ");
 for(i=0;i<negativos;i++){
 	printf("%d ",numNeg[i]);
 } 
}

