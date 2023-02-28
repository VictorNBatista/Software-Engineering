#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int a,b,sm,resp,i,acertos=0;
 srand(time(0));
 for(i=0;i<5;i++)
{
 a = (rand()%100);
 b = (rand()%100);
 sm = a+b;
 resp = sm;
 
 printf("Qual a soma de %i + %i ? ", a,b);
 scanf("%i",&resp);
 
 if(resp != sm)
 printf("\n Resposta errada, a resposta certa é: %i \n", sm);
 else
 acertos ++;
}
printf("Você acertou em: %d alternativas", acertos);
}

