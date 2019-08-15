/*
Problema: 2879 - Desvendando Monty Hall
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2879
Autor da resolução: Leonardo Nozaki

Explicação da solucação: A solução é muito simples, sempre que o carro estiver na porta 1, a pessoa não ira ganhar o carro, isso porque a pessoa sempre escolhe a porta 1 inicialmente e troca depois, entao ela nunca fica com a porta 1. Com isso, basta contar o numero de vezes em que o carro esta em uma porta diferente de 1 para saber o numero de vezes que havera ganhador
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	//Variavel auxiliar
	int n,x,cont;
	cont = 0; //Variavel para contar o numero de ganhadores
	cin>>n; //Numero de leituras
	for(int i=0; i<n; i++){
		cin>>x; 
		if(x != 1){ //Se o carro estiver em outra porta diferente da 1, ele ganha
			cont++; //Mais um ganhou o carro
		}
	}
	//Exibe o numero de ganhadores
	cout<<cont<<endl;
	return 0;
}
