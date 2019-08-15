/*
Problema: 2884 - Interruptores
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2884
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Primeiro é necessario ler os tamanhos de lampadas e interruptores para criar as ED necessarias, é criado um vetor de int para as lampadas e um vetor de vector de int para os interruptores. O valor -1 significa lampada desligada e o valor 1 significa lampada ligada, com esses valores fica mais facil alternar entre ligado e desligado, pois basta multiplicar o valor atual por -1.
Com todas as lampadas desligadas inicialmente, é lido e setado as lampadas citadas para ligadas, depois disso é feito a leitura dos interruptores e armazenado no vetor de vector. Depois de definir o estado inicial das lampadas, esse estado é armazenado em outro vetor para realizar a comparacao futura pela funcao comparador(inicial, lampadas, m). 
Agora é so ler as lampadas associadas ao interruptor, trocar os estados e verificar se todas estao desligadas depois desse processo, repetir ate que todas estejam desligadas ou entre em ciclo infinito, a cada n vezes é feito a verificao se as lampadas estao no mesmo estado que o estado inicial, pois se estiver nao havera solucao para o problema, pois o ciclo dos n interruptores vai continuar e nunca sera possivel desligar por conta do ciclo infinito
*/

#include <bits/stdc++.h>
using namespace std;

//Funcao para comparar o estado inicial e o estado atual das lampadas
//Se os estados forem iguais retorna false, se forem diferentes retorna true
bool comparador(int *inicial, int *atual, int m){
	for(int i = 0; i < m; i++){
		if(inicial[i] != atual[i]){
			return true;
		}
	}
	return false;
}
 
//Funcao para comparar o estado atual das lampadas
//Se todas as lampadas estiverem desligadas (Valor -1) retorna true, se alguma estiver ligada retorna false
bool desligado(int *atual, int m){
	for(int i = 0; i < m; i++){
		if(atual[i] != -1){
			return false;
		}
	}
	return true;

}

int main(){
	//Variaveis auxiliares de entrada e saida do problema
	int n, m, l, x, k, y, cont;

	//Leitura dos valores
	cin>>n>>m;

	//Define as lampadas
	int lampadas[m], inicial[m];

	//Define os interruptores
	vector <int> interruptores[n];

	//Seta as lampadas como desligado (Valor -1)
	for(int i = 0; i < m; i++){
		lampadas[i] = -1;
	}

	//Leitura e set das lampadas acessas inicialmente (valor 1)
	cin>>l;
	for(int i = 0; i < l; i++){
		cin>>x;
		lampadas[x-1] *= -1;
	}

	//Leitura e armazenamento da combinacao dos interruptores
	for(int i = 0; i < n; i++){
		cin>>k;
		for(int j = 0; j < k; j++){
			cin>>y;
			interruptores[i].push_back(y-1);
		}
	}

	//Copiar o estado inicial das lampadas para comparacao futura
	for(int i = 0; i < m; i++){
		inicial[i] = lampadas[i];
	}

	//Verifica se inicialmente as lampadas nao estao todas desligadas (Desnecessario, mas feito mesmo assim)
	cont = 0;
	if(desligado(lampadas, m)){
		cout<<0<<endl;
		return 0;
	}
	
	//Faz o processo de 1,2,3...n 
	do{
		//Percorre os n interruptores
		for(int i = 0; i < n; i++){
			//Altera o valor das lampadas ligadas ao interruptor
			for(int j = 0; j < interruptores[i].size(); j++){
				lampadas[interruptores[i][j]] *= -1;
			}

			cont++; //Mexeu em mais um interruptor

			//Se todas as lampadas estiverem desligadas, quer dizer que acabou
			if(desligado(lampadas, m)){
				cout<<cont<<endl; //Informa o numero de interruptores mexidos
				return 0;
			}
		}
	}while(comparador(inicial, lampadas, m)); //Se as lampadas atuais estao no mesmo estado que inicialmente, depois de varias rodadas pelos n interruptores, quer dizer que nao ha solucao
	//Imprime -1 para informar que nao ha solucao
	cout<<"-1"<<endl;
	return 0;
}
