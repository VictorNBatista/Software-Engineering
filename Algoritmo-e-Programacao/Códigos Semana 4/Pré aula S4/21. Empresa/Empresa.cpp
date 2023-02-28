#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
 setlocale(LC_ALL, "Portuguese");
 float salario,s1,s2,s3,s4,s5,res;
 int tempo;
 printf("Digite o valor do seu salário: ");
 scanf("%f",&salario);
 printf("Há quanto tempo está na empresa \nMenos de 1 ano (1) \nDe 1 a 3 anos (2) \nDe 4 e 6 anos (3) \nDe 7 a 10 anos (4) \nMais de 10 anos (5) \n");
 scanf("%i",&tempo);
 
 s1= (salario + (salario*0.25));
 s2= (salario + (salario*0.20));
 s3= (salario + (salario*0.15));
 s4= (salario + (salario*0.10));
 s5= salario;
 
 switch (tempo)
 {
 	case 1:
 	if(salario<=500)
	 res=s1;
	else if(salario<=1000)
	 res=s2;
	else if(salario<=1500)
	 res=s3;
	else if(salario<=2000)
	 res=s4;
	else
	 res=s5;
	
	printf("\n\tO seu novo salário é: R$%.2f",res);
	break;
	
	case 2:
	if(salario<=500)
	 res=s1;
	else if(salario<=1000)
	 res=s2;
	else if(salario<=1500)
	 res=s3;
	else if(salario<=2000)
	 res=s4;
	else
	 res=s5;
	
	printf("\n\tO seu novo salário é: R$%.2f",res+100);
	break;
	
	case 3:
	if(salario<=500)
	 res=s1;
	else if(salario<=1000)
	 res=s2;
	else if(salario<=1500)
	 res=s3;
	else if(salario<=2000)
	 res=s4;
	else
	 res=s5;
	
	printf("\n\tO seu novo salário é: R$%.2f",res+200);
	break;
	
	case 4:
	if(salario<=500)
	 res=s1;
	else if(salario<=1000)
	 res=s2;
	else if(salario<=1500)
	 res=s3;
	else if(salario<=2000)
	 res=s4;
	else
	 res=s5;
	
	printf("\n\tO seu novo salário é: R$%.2f",res+300);
	break;
	
	case 5:
	if(salario<=500)
	 res=s1;
	else if(salario<=1000)
	 res=s2;
	else if(salario<=1500)
	 res=s3;
	else if(salario<=2000)
	 res=s4;
	else
	 res=s5;
	
	printf("\n\tO seu novo salário é: R$%.2f",res+500);
	break;     
 }
}

