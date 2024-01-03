#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

void n(int x, float *s);

main()
{
 setlocale(LC_ALL, "Portuguese");
 setlocale(LC_ALL, "Portuguese");
    int a;
    float s, soma;
    printf("Insira a quantidade de parcelas que deseja realizar: ");
    scanf("%i", &a);
    n(a, &s);
    printf("\nO resultado da soma é: %.2f", s);
}

void n(int x, float *s)
{
    int i;
    float conta;
    *s = 0;
    for (i = 1; i <= x; i++)
    {
        conta = ((pow(i, 2) + 1) / (i + 3));
        *s = *s + conta;
    }
}
