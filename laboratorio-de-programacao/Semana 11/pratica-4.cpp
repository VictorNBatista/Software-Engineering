#include <stdio.h>
#include <math.h>
#include <locale.h>

#define LIN 10
#define COL 3

void receber_notas(float notas[LIN][COL]);
void menor_nota(float notas[LIN][COL]);
void contar_menor_nota(float notas[LIN][COL]);

main()
{
    setlocale(LC_ALL, "Portuguese");
    float notas[LIN][COL];

    printf("Recebendo notas...\n");
    receber_notas(notas);
    menor_nota(notas);
    contar_menor_nota(notas);

}

void receber_notas(float notas[LIN][COL])
{
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("Digite a nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &notas[i][j]);
        }
    }
}

void menor_nota(float notas[LIN][COL])
{
    float menor;
    int aux;
    for (int i = 0; i < LIN; i++)
    {
        menor = 100;
        for (int j = 0; j < COL; j++)
        {
            if (notas[i][j] < menor)
            {
                menor = notas[i][j];
                aux = j + 1;
            }
        }
        printf("\nMenor nota do aluno %d foi na prova %i: %.2f", i + 1, aux, menor);
    }
}

void contar_menor_nota(float notas[LIN][COL])
{
    int contp1 = 0, contp2 = 0, contp3 = 0;

    for (int i = 0; i < LIN; i++)
    {
        float menor_p1 = notas[i][0], menor_p2 = notas[i][1], menor_p3 = notas[i][2];

        for (int j = 0; j < COL; j++)
        {
            if (notas[i][j] < menor_p1)
            {
                menor_p1 = notas[i][j];
            }
            if (notas[i][j] < menor_p2)
            {
                menor_p2 = notas[i][j];
            }
            if (notas[i][j] < menor_p3)
            {
                menor_p3 = notas[i][j];
            }
        }

        if (notas[i][0] == menor_p1)
        {
            contp1++;
        }
        if (notas[i][1] == menor_p2)
        {
            contp2++;
        }
        if (notas[i][2] == menor_p3)
        {
            contp3++;
        }
    }

    printf("\nAlunos com a menor nota na prova 1: %d", contp1);
    printf("\nAlunos com a menor nota na prova 2: %d", contp2);
    printf("\nAlunos com a menor nota na prova 3: %d\n", contp3);
}

