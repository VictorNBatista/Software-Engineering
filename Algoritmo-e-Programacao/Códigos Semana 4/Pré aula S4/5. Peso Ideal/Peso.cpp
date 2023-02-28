#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
	
float a,s;
printf("Digite sua altura: ");
scanf("%f", &a);
printf("Digite seu sexo - Home (1) ou Mulher(2): ");
scanf("%f", &s);

if(s == 1)
{
	printf("\n\t O peso ideal é: %.3f", ((72.7 * a)-58));
}
else 
{
	printf("\n\t O peso ideal é: %.3f", ((62.1 * a)-44.7));
}
}

