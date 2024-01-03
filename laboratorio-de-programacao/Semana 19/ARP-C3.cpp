#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct {
    int idade;
    char sexo;
    float salario;
    char bairro[30];
    int moradores;
} Paciente;

void Cadastro(Paciente *pacientes, int n);
void Mostrar_dados(Paciente *pacientes, int n);
void armazenamento(Paciente *pacientes, int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i, n;
    Paciente pacientes[100];

    printf("Quantos pacientes?\n");
    scanf("%i", &n);

    printf("Cadastrando pacientes...\n");
    Cadastro(pacientes, n);

    system("cls");
    printf("Mostrando pacientes cadastrados...\n");
    Mostrar_dados(pacientes, n);
    getch();
    
    system("cls");
    printf("Passando dados dos pacientes cadastrados para o arquivo...\n\n");
    armazenamento(pacientes, n);
    printf("------------------------------\n");
    printf("Dados passados com sucesso!!\n");
    printf("------------------------------\n");

    return 0;
}

void Cadastro(Paciente *pacientes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite os dados do %iº paciente\n", i + 1);
        printf("Idade: ");
        scanf("%i", &(pacientes[i].idade));
        printf("Sexo (M/F): ");
        scanf(" %c", &(pacientes[i].sexo));
        printf("Renda Salarial: ");
        scanf("%f", &(pacientes[i].salario));
        printf("Bairro de moradia: ");
        scanf(" %[^\n]", pacientes[i].bairro);
        printf("Número de moradores na residência: ");
        scanf("%i", &(pacientes[i].moradores));
    }
}

void Mostrar_dados(Paciente *pacientes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nDados do %iº Paciente", i + 1);
        printf("\nIdade: %i", pacientes[i].idade);
        printf("\nSexo: %c", pacientes[i].sexo);
        printf("\nRenda Salarial: R$%.2f", pacientes[i].salario);
        printf("\nBairro de moradia: %s", pacientes[i].bairro);
        printf("\nNúmero de moradores na residência: %i", pacientes[i].moradores);
        printf("\n");
    }
}

void armazenamento(Paciente *pacientes, int n){
	FILE *arq;
	arq = fopen("Pacientes.txt", "a+");
	if (arq == NULL) {
        printf("Erro na abertura do arquivo");
    }
    else{
	for(int i=0; i<n; i++){
		fprintf(arq,"\nDados do %iº Paciente", i + 1);
        fprintf(arq,"\nIdade: %i", pacientes[i].idade);
        fprintf(arq,"\nSexo: %c", pacientes[i].sexo);
        fprintf(arq,"\nRenda Salarial: R$%.2f", pacientes[i].salario);
        fprintf(arq,"\nBairro de moradia: %s", pacientes[i].bairro);
        fprintf(arq,"\nNúmero de moradores na residência: %i", pacientes[i].moradores);
        fprintf(arq,"\n");
	}
	}
	fclose(arq);
}
