/*
Problema: 1235 - De Dentro para Fora
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1235
Autor da resolução: Leonardo Nozaki
*/

#include <bits/stdc++.h>
using namespace std;

//Funcao para decifrar a string original dado a string de entrada
string decifre(string str){
	//Variaveis auxiliares
	string original; //String para armazenar o resultado
	int len = str.length(); //Tamanho da string de entrada
	int half = len/2; //Tamanho da metade do tamanho total
	for(int i = half-1; i >= 0; i--){ //Percorre do centro para esquerda
		original.push_back(str[i]); //Adiciona na string de resultado
	}
	for(int i = len-1; i >= half; i--){ //Percorre da direita para o centro
		original.push_back(str[i]); //Adiciona na string de resultado
	}
	return original; //Retorna o resultado
}

int main(){
	int n; //Numero de casos
	string str; //String de entrada
	cin>>n; //Leitura do numero de casos
	getchar(); //Descartar \n
	for(int i = 0; i < n; i++){ 
		getline(cin,str); //Leitura dos casos de testes
		//Chama a funcao e exibe o resultado
		cout<<decifre(str)<<endl;
	}
	return 0;
}
