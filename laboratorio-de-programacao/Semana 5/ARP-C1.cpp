#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

void cIdade(int idade[], int n);
void cSexo(char sexo[], int n);
void cSalario(float salario[], int n);
void cBairro(char bairro[][30], int n);
void cMoradores(int moradores[], int n);

main()
{
 setlocale(LC_ALL, "Portuguese");
	int idade[100], moradores[100],n;
	float salario[100];
	char bairro[100][30], sexo[100];
	
	printf("Quantos pacientes?\n");
	scanf("%i",&n);
	
	for(int i=0;i<n;i++){
		printf("\nDigite os dados do %iº paciente\n",i+1);
		printf("Idade: ");
		scanf("%i",&idade[i]);
		printf("Sexo (M/F): ");
		scanf(" %c",&sexo[i]);
		printf("Renda Salarial: ");
		scanf("%f",&salario[i]);
		printf("Bairro de moradia: ");
		scanf(" %[^\n]",bairro[i]);
		printf("Número de moradores na residência: ");
		scanf("%i",&moradores[i]);	
		
}
	cIdade(idade,n);

		printf("\n");

	for(int i=0;i<n;i++){
		printf("\nDados do %iº Paciente",i+1);
		printf("\nIdade: %i",idade[i]);
		printf("\nSexo: %c",sexo[i]);
		printf("\nRenda Salarial: R$%.2f",salario[i]);
		printf("\nBairro de moradia: %s",bairro[i]); 
		printf("\nNúmero de moradores na residência: %i",moradores[i]);
		printf("\n");
	}
}

void cIdade(int idade[], int n){
	for(int i=0;i<n;i++){
		scanf("%i",idade[i]);	
	}
}
	
void cSexo(char sexo[], int n){
	for(int i=0;i<n;i++){
		scanf("%i",sexo[i]);	
	}	
}

void cSalario(float salario[], int n){
	for(int i=0;i<n;i++){
		scanf("%i",salario[i]);	
	}	
}

void cBairro(char bairro[][30], int n){
	for(int i=0;i<n;i++){
		scanf("%i",bairro[i]);	
	}	
}

void cMoradores(int moradores[], int n){
	for(int i=0;i<n;i++){
		scanf("%i",moradores[i]);	
	}
}	

