#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int n,i,j;
 float e=1.0, fatorial=1;
 printf("Quantidade de termo que serão fatorados: ");
 scanf("%d", &n);

for( i =1; i<= n ; i++)
{
    fatorial*=i;
    e = e + (1.0/ fatorial);
    printf("\nValor do %iº termo é: %.3f",i,e);
}

printf("\nO valor de E é: %.3f", e);
}

