/*
Problema: 2880 - Enigma
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2880
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Fazer a leitura das duas strings e pegar o tamanho delas. Criar dois for para percorrer as strings, o primeiro for define onde comeca a string cifrada e o segundo for percorre o crib e compara com a posicao atual da string cifrada. Se em algum momento houver semelhança entre os caracteres da cifrada e crib, entao uma flag é ativada até o fim da analise do crib. Se no fim da analise do crib, a flag nao estiver ativada, entao a ultima analise é uma possivel posicao da crib na mensagem cifrada.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	//Criacao das strings
	string cifrada, crib;
	//Leitura das strings pela entrada padrao
	cin>>cifrada;
	getchar();
	cin>>crib;
	getchar();

	//Calcular o tamanho das strings
	int len1, len2,flag,cont;
	len1 = cifrada.length();
	len2 = crib.length();

	//Setar o valor inicial da flag e do contador
	flag = 0;
	cont = 0;	

	//For para definir a posicao inicial do cifrado
	for(int i = 0; i <= len1 - len2; i++){
		//Reseta o valor da flag
		flag = 0;

		//Percorre as strings e compara
		for(int j = 0; j < len2; j++){
			//Compara as duas strings
			if(cifrada[i + j] == crib[j]){
				//Se for igual, flag ativa
				flag = 1;
			}
		}

		//Se a flag nao estiver ativa, essa analise é uma possivel posicao da crib na cifrada
		if(flag == 0){
			cont++;
		}
	}

	//Exibe o numero de possivel posicoes que a crib pode estar na msg cifrada
	cout<<cont<<endl;
	return 0;
}
