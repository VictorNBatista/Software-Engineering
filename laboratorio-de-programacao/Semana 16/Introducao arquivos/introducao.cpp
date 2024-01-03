#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	FILE *fp;
	
	char nome[100];
	int i;
	
	fp = fopen("MeuPrimeiroArquivo.txt", "w");
	
	if(!fp){
		printf("ERRO na Abertura do Arquivo: ");
		exit(1);
	}
	printf("Entre com o nome do usuário a ser gravado no arquivo: ");
	gets(nome);
	for(i=0; nome[i]; i++){
		putc(nome[i], fp);
	}
	fclose(fp);
}
