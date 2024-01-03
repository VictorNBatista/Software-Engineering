#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

typedef struct{
	char sexo;
	float altura;
	int idade;
	char olhos;
} Habitante;

void registro(Habitante *h, int n);
void mostrar(Habitante *h, int n);
void media_idade(Habitante *h, int n);
void maior_idade(Habitante *h, int n);
void qtd_mulheres(Habitante *h, int n);
void percent_homem(Habitante *h, int n);

main(){
	setlocale(LC_ALL,"Portuguese");
	Habitante h[50];
	int n;
	
	printf("Digite o número de habitantes que serão registrados: ");
	scanf("%i",&n);
	
	printf("\nRegistrando habitantes...\n");
	registro(h, n);
	
	printf("\nDados registrados...\n\n");
	mostrar(h, n);
	
	printf("\nResultados obtidos...\n");
	media_idade(h, n);
	maior_idade(h, n);
	qtd_mulheres(h, n);
	percent_homem(h, n);
}

void registro(Habitante *h, int n){
	for(int i=0; i<n; i++){
		printf("\n*Paciente %i*", i+1);
		printf("\nSexo (M/F): ");
		scanf(" %c",&h[i].sexo);
		printf("Altura: ");
		scanf("%f",&h[i].altura);
		printf("Idade: ");
		scanf("%i",&h[i].idade);
		printf("Cor dos olhos (A-azuis; V-verdes; C-castanhos): ");
		scanf(" %c",&h[i].olhos);
	}
}

void mostrar(Habitante *h, int n){
	for(int i=0; i<n; i++){
		printf("*Paciente %i*", i+1);
		printf("\nSexo: %c",h[i].sexo);
		printf("\nAltura: %.2f",h[i].altura);
		printf("\nIdade: %i",h[i].idade);
		printf("\nCor dos olhos: %c\n\n",h[i].olhos);
	}
}

void media_idade(Habitante *h, int n){
	float soma=0, cont=0;
	for(int i=0; i<n; i++){
		if(h[i].olhos == 'C' && h[i].altura > 1.60){
			soma+= h[i].idade;
			cont++;
		}
	}
	printf("A média da idade dos habitantes com olhos castanhos e maiores que 1,60 é: %.2f", soma/cont);
}

void maior_idade(Habitante *h, int n){
	int maior=0;
	for(int i=0; i<n; i++){
		if(h[i].idade > maior)
		maior = h[i].idade;
	}
	printf("\nA maior idade entre os habitantes é: %i", maior);
}

void qtd_mulheres(Habitante *h, int n){
	int soma=0;
	for(int i=0; i<n; i++){
		if(h[i].sexo == 'F' && h[i].idade >= 20 && h[i].idade <= 45 || h[i].sexo == 'F' && h[i].olhos == 'V' && h[i].altura < 1.70){
			soma++;
		}
	}
	printf("\nO número de mulheres com idade entre 20 e 45 anos\nou de olhos verdes e menor que 1.70 é: %i",soma);
}

void percent_homem(Habitante *h, int n){
	float p,cont,percent;
	p = n;
	
	for(int i=0; i<n; i++){
		if(h[i].sexo == 'M')
			cont++;
		else
			continue;	
	}
	
	percent = (cont/p) * 100;
	printf("\nO percentual de homens entre os habitantes é de: %.2f%",percent);
}
