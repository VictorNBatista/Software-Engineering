#include<stdio.h>
#include<math.h>
#include<locale.h>

main()
{
  setlocale(LC_ALL, "Portuguese");
  
  float id;
  printf("Digite a sua idade: ");
  scanf("%f",&id);
  
  if(id >= 18)
  {
  	printf("\n\t Você é maior de idade");
  }
  else
  {
  	printf("\n\t Você é menor de idade");
  }
}

