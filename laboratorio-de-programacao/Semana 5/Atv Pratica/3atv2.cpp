#include <stdio.h>
#include <math.h>
#include <locale.h>
#define n 15

void cadastro(int *idades, char *sexos, float *salarios, int *filhos)
{
    for (int i = 0; i < n; i++)
    {
        printf("Dados do %iº habitante\n", i + 1);
        printf("Idade: ");
        scanf("%i", idades + i);
        printf("Sexo M/F: ");
        scanf(" %c", sexos + i);
        printf("Salário: ");
        scanf("%f", salarios + i);
        printf("Número de filhos: ");
        scanf("%i", filhos + i);
        printf("\n");
    }
}

float media_salario(float *salarios)
{
    float soma = 0, media;
    for (int i = 0; i < n; i++)
    {
        soma += *(salarios + i);
    }
    return soma / n;
}

int menor_idade(int *idades)
{
    int menor = *idades;
    for (int i = 1; i < n; i++)
    {
        if (*(idades + i) < menor)
            menor = *(idades + i);
    }

    return menor;
}

int maior_idade(int *idades)
{
    int maior = *idades;
    for (int i = 1; i < n; i++)
    {
        if (*(idades + i) > maior)
            maior = *(idades + i);
    }
    return maior;
}

int mulheres_filhos_500(float *salarios, char *sexos, int *filhos)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(sexos + i) == 'F' && *(filhos + i) == 3 && *(salarios + i) <= 500)
            cont++;
    }
    return cont;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idades[n], filhos[n];
    char sexos[n];
    float salarios[n];

    cadastro(idades, sexos, salarios, filhos);

    printf("Média salarial: R$%.2f\n", media_salario(salarios));
    printf("Menor idade: %i\n", menor_idade(idades));
    printf("Maior idade: %i\n", maior_idade(idades));
    printf("Mulheres com 3 filhos e salário de até R$500,00: %i", mulheres_filhos_500(salarios, sexos, filhos));

    return 0;
}

