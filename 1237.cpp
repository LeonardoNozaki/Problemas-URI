/*
Problema: 1237 - Comparação de Substring
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1237
Autor da resolução: Leonardo Nozaki

Explicação da solucação: É preciso ler as duas strings corresponentes e utilizar a funcao maxSubstr, nessa funcao, primeiramente vamos deixar a menor string em str1 e a maior string em str2, é importante deixar a menor string em str1, pois a complexidade do problema será o quadrado do tamanho da str1 vezes o tamanho da str2 e para uma menor complexidade, str1 deve ser o menor possivel.
Com isso, vamos procurar a maior substring da seguinte maneira, começamos com toda a string str1 e procuramos em str2 para ver se ela é uma substring de str2, se for retorna o tamanho, caso contrario continua e transforma str1 em substrings de tamanho str1.length - 1 e verifica novamente e continua diminuindo caso nao seja substring de str2. Se nada for encontrado, retorna 0.
*/


#include <bits/stdc++.h>
using namespace std;

//Funcao para encontrar o tamanho maximo de uma substring presente nas duas strings de parametro
int maxSubstr(string str1, string str2){
	//Variaveis auxiliares	
	string aux; //Armazena uma substring de str1
	int len1 = str1.length(); //Tamanho da string str1
	int len2 = str2.length(); //Tamanho da string str2
	int temp; //Armazenar um valor na hora do swap 
	size_t pos; //Posicao da substring 
	
	if(len1 > len2){
		//Realizar operacao de swap para deixar a menor string em str1
		str1.swap(str2);
		temp = len1;
		len1 = len2;
		len2 = temp;
	}
	
	//Quebrar em substrings e verificar todas as possibilidades
	//Tamanho da substring de len1 ate 1
	for(int i = len1; i >= 1; i--){
		//Posicao que a substring comeca
		for(int j = 0; j < len1-i+1; j++){
			aux = str1.substr (j,i); //j representa a posicao inicial que comeca a substring em str1, enquanto que i representa o tamanho da substring a ser extraida de str1

			pos = str2.find(aux); //Verifica se aux é substring de str2, se for pos != npos, se nao for pos == npos

			if (pos != string::npos){ 
				//Substring encontrada em str2
				return i;
			}
		}
	}
	//Nenhuma substring semelhante encontrada
	return 0;
}

int main(){
	string str1, str2;
	//Faz a leitura da entrada ate nao haver mais nada (EOF)
	while(getline(cin,str1)){
		getline(cin,str2);
		//Chama a funcao e exibe o resultado
		cout<<maxSubstr(str1, str2)<<endl;
	}
	return 0;
}
