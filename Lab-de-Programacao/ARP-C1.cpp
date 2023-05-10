#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

void Cadastro(int idade[100], char sexo[100], float salario[100], char bairro[100][30], int moradores[100], int n);
void Mostrar_dados(int idade[100], char sexo[100], float salario[100], char bairro[100][30], int moradores[100], int n);

/*typedef struct P{
	int idade; 
	char sexo;
	float salario;
	char bairro;
	int moradores;
};*/

main()
{
 setlocale(LC_ALL, "Portuguese");
	//P teste[100];
	int i;
	int idade[100], moradores[100],n;
	float salario[100];
	char bairro[100][30], sexo[100];
	//stdcpy(teste[i].bairro,"marancana");
	
	
	printf("Quantos pacientes?\n");
	scanf("%i",&n);
	
	printf("Cadastrando pacientes...\n");
	Cadastro(idade,sexo,salario,bairro,moradores,n);
	
	printf("\n");
	printf("Mostrando pacientes cadastrados...\n");
	Mostrar_dados(idade,sexo,salario,bairro,moradores,n);
}

void Cadastro(int idade[100], char sexo[100], float salario[100], char bairro[100][30], int moradores[100], int n){
	for(int i=0;i<n;i++){
		printf("\nDigite os dados do %iº paciente\n",i+1);
		printf("Idade: ");
		scanf("%i",&idade[i]);
		printf("Sexo (M/F): ");
		scanf(" %c",&sexo[i]);
		printf("Renda Salarial: ");
		scanf("%f",&salario[i]);
		printf("Bairro de moradia: ");
		scanf(" %[^\n]",&bairro[i]);
		printf("Número de moradores na residência: ");
		scanf("%i",&moradores[i]);		
}
}

void Mostrar_dados(int idade[100], char sexo[100], float salario[100], char bairro[100][30], int moradores[100], int n){
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
