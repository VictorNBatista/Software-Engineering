/*PROGRAMA DE ALOCACAO DINAMICA DE MEMORIA
  GERENCIAMENTO DE MEMORIA*/
#include <iostream>
using namespace std;

int main(){
	int n=5, i, *ptr, sum = 0;
	
	ptr = new int[n]; //aloca a memoria dinamicamente
	
	if(ptr == NULL){
		cout<<"Error! Memoria nao alocada";
		exit(0);
	}
	
	cout<<"Digite os "<< n << " elementos: ";
	for(i=0; i<5;i++){
		cin>>*(ptr+i);
		sum += *(ptr+i);
	}
	
	cout<<"O ponteiro esta no endereço: "<< ptr << endl;
	cout<<"A soma dos numeros cadastrados eh: "<<sum<<endl;
	
	delete[] ptr; //libera a memoria alocada
	
}
