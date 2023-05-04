#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <condition_variable>

using namespace std;

const int NUM_PISTAS = 10; //quantidade de pistas ou competidores
const int TAM_PISTA = 50; //quantidade de passos tamanho do percurso

int competid(){
	int competidores;
	cout<<"Digite o numero de competidores";
	cin>>competidores;
	NUM_PISTAS = competidores;
}




atomic<bool> jogoRodando(true);
atomic<bool> jogoIniciado(false);
atomic<int> posicaoJogador[NUM_PISTAS];
mutex mtx;
condition_variable cv;
// funcao que controla a logica do jogo
void logicaJogo(){
	while(!jogoIniciado){
		this_thread::yield();
	}
	
	while(jogoRodando){
		for(int i=0; i<NUM_PISTAS; i++){
			posicaoJogador[i] += rand() % 3+1; //jogador movimenta
			if(posicaoJogador[i] >= TAM_PISTA){
				jogoRodando = false;
				break;
			}
		}
	
	unique_lock<mutex> lock(mtx);
	cv.notify_all();
	lock.unlock();
	
	this_thread::sleep_for(chrono::milliseconds(500));
	}
}

void desenhaJogo(){
	while(!jogoIniciado){
		this_thread::yield();
	}
	
	while(jogoRodando){
		unique_lock<mutex> lock(mtx);
		cv.wait(lock);
		
		system("cls");
		
		for(int i=0; i<NUM_PISTAS; i++){
			cout<<"Pista"<<i+1<<": ";
			for(int j=0; j<TAM_PISTA; j++){
				if(j == posicaoJogador[i]){
					cout<<"X";
				} else{
					cout<<"-";
				}
			}
			cout<<endl;
		}
		lock.unlock();
	}
}

void entradaUsuario(){
	while(!jogoIniciado){
		int pista;
		cout<<"Escolha em competidor (1-"<<NUM_PISTAS<<"):";
		cin>>pista;
		
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Valor Invalido. Tente Novamente."<<endl;
			continue;	
		}
		
		if(pista < 1 || pista > NUM_PISTAS){
			cout << "Competidor Invalido, Escolha um numero entre 1 e "<<NUM_PISTAS<<","<<endl;
			continue;
		}
			
		posicaoJogador[pista - 1] += 3;
		jogoIniciado = true;	
	}
}

int main(){
	//competid();
	thread t1(logicaJogo);
	thread t2(desenhaJogo);
	thread t3(entradaUsuario);
	
	t1.join();
	t2.join();
	t3.join();
	//t4.join();
	
	return 0;
}



