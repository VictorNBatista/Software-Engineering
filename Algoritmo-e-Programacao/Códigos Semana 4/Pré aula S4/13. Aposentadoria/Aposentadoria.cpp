#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 int id,ts;
 printf("Digite sua idade: ");
 scanf("%i", &id);
 printf("Digite seu tempo de servi�o: ");
 scanf("%i", &ts);
 
 if(id >= 65 || ts >= 30 || id >= 60 && ts >= 25)
 printf("\n\t Voc� pode se aposentar");
 else
 printf("\n\t Voc� n�o pode se aposentar");
}

