/*
Problema: 1253 - Cifra de Cesar
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1253
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Esse é um problema bastante simples, basta ler as N linhas correspodentes e realizar o deslocamento de acordo com o valor informado depois da string. Como caracteres tambem pode ser entedidos com valores numericos (Ex: 'A' == 65), podemos realizar operacoes entre caracteres de uma string e inteiros. Portanto, se o deslocamento para a esquerda nao passar de 'A', basta fazer: letra - x. Caso contrario, é preciso subtrair ate chegar no 'A' e depois subtrair o restante apartir de 'Z': 'Z' - (x - (letra - 'A')) + 1. Onde o termo letra representa a letra na cifra de cesar a ser decodificada, x o valor utilizado na decodificação (numero de deslocamento).
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	//Variaveis auxiliares
	int n,x,len;
	string str;

	//Faz a leitura do numero de casos de testes
	cin>>n;
	getchar();

	for(int i = 0; i < n; i++){
		//Faz a leitura da string de entrada
		getline(cin,str);

		//Faz a leitura do deslocamento
		cin>>x;
		getchar();	

		len = str.length(); //Calcula o tamanho da string

		//Percorre toda a string
		for(int j = 0; j < len; j++){ 
			//Faz a conversao do caracterer atual
			if(str[j] - x < 'A'){
				
				str[j] = 'Z' - (x - (str[j] - 'A')) + 1;
			}
			else{
				str[j] = str[j] - x;
			}
		}
		//Exibe o resultado
		cout<<str<<endl;
	}

	return 0;
}
