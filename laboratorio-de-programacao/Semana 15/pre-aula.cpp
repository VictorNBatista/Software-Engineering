#include <stdio.h>
#include <locale.h>

typedef struct{
	char nome[50];
	int idade;
	char CPF[11];
	char endereco[100];
	char celular[20];
	char sexo;
} Cliente;

main(){
	setlocale(LC_ALL,"Portuguese");
	Cliente cliente;
	
	printf("Recebendo dados do cliente...\n\n");
	printf("Nome: ");
	scanf(" %s",&cliente.nome);
	printf("Idade: ");
	scanf(" %i",&cliente.idade);
	printf("CPF: ");
	scanf(" %s",&cliente.CPF);
	printf("Endereço: ");
	scanf(" %s",&cliente.endereco);
	printf("Celular: ");
	scanf(" %s",&cliente.celular);
	printf("Sexo (M/F): ");
	scanf(" %c",&cliente.sexo);
	
	printf("Mostrando dados cadastrados...\n\n");
	printf("\nNome: %s",cliente.nome);
	printf("\nIdade: %i",cliente.idade);
	printf("\nCPF: %s",cliente.CPF);
	printf("\nEndereço: %s",cliente.endereco);
	printf("\nCelular: %s",cliente.celular);
	printf("\nSexo (M/F): %c",cliente.sexo);
}
