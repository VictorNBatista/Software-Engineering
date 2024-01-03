#include<stdio.h>
#include<math.h>
#include<locale.h>

void tempo(int hri, int mini, int hrf, int minf);

main()
{
	setlocale(LC_ALL,"Portuguese");
	int hr_i,min_i, hr_f, min_f;
	printf("Digite o horário em que começou o jogo");
	printf("\nHora: ");
	scanf("%i",&hr_i);
	printf("Minuto: ");
	scanf("%i", &min_i);
	printf("\nDigite o horário em que terminou o jogo");
	printf("\nHora: ");
	scanf("%i",&hr_f);
	printf("Minuto: ");
	scanf("%i", &min_f);
	tempo(hr_i,min_i,hr_f,min_f);
}

void tempo(int hri, int mini, int hrf, int minf){
	int inicio,fim,duracao;
	inicio = (hri*60) + mini;
	fim = (hrf*60) + minf;
	
	duracao = fim - inicio;
	
	printf("A duração total do jogo em minutos foi: %i", duracao);
}

