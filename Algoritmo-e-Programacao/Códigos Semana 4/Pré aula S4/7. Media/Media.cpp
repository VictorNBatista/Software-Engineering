#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
setlocale(LC_ALL,"Portuguese");
float a, b, c, media;
printf("Digite a primeira nota: ");
scanf("%f", &a);
printf("Digite a segunda nota: ");
scanf("%f", &b);
printf("Digite a terceira nota: ");
scanf("%f", &c);

media = ((a+b+(c*2))/3);
printf("\n\t Sua m�dia � de: %.1f", media);

if (media <= 60)
{
	printf("\n\t Voc� est� reprovado '-'");
}
else
{
	printf("\n\t Voc� est�  aprovado :)");
}
}

