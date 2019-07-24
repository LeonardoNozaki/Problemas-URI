/*
Problema: 1234 - Sentença Dançante
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1234
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Esse é um problema simples, basta ler as linhas de entrada e chamar a funcao invertCase para deixar a linha como uma senteca dançante. A funcao inverte o case das letras se necessario (dependendo das suas posicoes) ou mantem caso nao seja necessario (Está no case esperado dado a sua posição ou nao é uma letra). A funcao retorna uma string no formato de sentença dançante e basta exibir o resultado.
*/

#include <bits/stdc++.h>
using namespace std;

//Funcao para transformar a string de entrada em uma sentenca dancante 
string invertCase(string original){
	//Variaveis auxiliares
	string invert; //String que armazena a senteca dancante
	int len = original.length(); //Tamanho da string de entrada
	char aux; //Char que armazena um caracter para trocar o case
	int count = 0; //Contador para controlar quando realizar a troca do case

	//For para percorrer toda a string de entrada
	for(int i = 0; i < len; i++){
		//Condicao para trocar de case
		if(original[i] >= 'a' && original[i] <= 'z' && count%2 == 0){
			aux = original[i];
			invert.push_back(toupper(aux));
			count++;
		}
		//Condicao para nao trocar de case
		else if(original[i] >= 'a' && original[i] <= 'z' && count%2 == 1){
			invert.push_back(original[i]);
			count++;
		}
		//Condicao para trocar de case
		else if(original[i] >= 'A' && original[i] <= 'Z' && count%2 == 1){
			aux = original[i];
			invert.push_back(tolower(aux));
			count++;
		}
		//Condicao para nao trocar de case
		else if(original[i] >= 'A' && original[i] <= 'Z' && count%2 == 0){
			invert.push_back(original[i]);
			count++;
		}
		//Apenas copiar e nao fazer nada
		else{
			invert.push_back(original[i]);
		}
	}
	//Retorna a string como senteca dancante
	return invert;
}

int main(){
	string str;
	//Faz a leitura da entrada ate nao haver mais nada (EOF)
	while(getline(cin,str)){
		//Chama a funcao e exibe o resultado
		cout<<invertCase(str)<<endl;
	}
	return 0;
}
