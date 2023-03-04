#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int m[10][10], i,j,aux,sla;
 printf("Digite os elementos da matriz: ");
 for(i=0;i<=9;i++){
 	printf("\nLINHA %d\n",i+1);
 	for(j=0;j<=9;j++){
 		printf("COLUNA %d: ",j+1);
 		scanf("%d",&m[i][j]);
	}
 }
 system("cls");
 
 printf("MATRIZ");
 for(i=0;i<=9;i++){
 	printf("\n");
 	for(j=0;j<=9;j++){
 		printf("\t%d",m[i][j]);
	}
 }
 
 printf("\n\nMATRIZ TROCADA");
 //Trocar linha 2 com linha 8
 for(i=0;i<=9;i++){
 	aux = m[1][i];
 	m[1][i] = m[7][i];
 	m[7][i] = aux;
 }
 
 //Trocar coluna 4 com coluna 10
 for(j=0;j<=9;j++){
 	aux = m[j][3];
 	m[j][3] = m[j][9];
 	m[j][9] = aux;
 }
 
 //Trocar diagonal principal com diagonal secundária
 for(i=0;i<=9;i++){
 	aux = m[i][i];
 	m[i][i] = m[i][9-i];
 	m[i][9-i] = aux;
 }
 
 //trocar linha 5 com coluna 10
 for(i=0;i<=9;i++){
 	for(j=0;j<=9;j++){
 		aux = m[4][j];
 		m[4][j] = m[9-i][9];
 		m[9-i][9] = aux;
	}
 }
 
 for(i=0;i<=9;i++){
 	printf("\n");
 	for(j=0;j<=9;j++){
 		printf("\t%d",m[i][j]);
	}
 }
}

