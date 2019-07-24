/*
Problema: 1235 - De Dentro para Fora
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1243
Autor da resolução: Leonardo Nozaki

Explicação da solução: Para resolver esse problema é preciso ler as linhas de entrada, quebrar cada linhas em tokens separados por espaço em branco (processo de token feito pela funcao tokenizing), armazenar esses tokens em um vector e analisar token por token utilizado a funcao isWord que verifica se um determinado token é uma palavra ou nao e retorna o tamanho da palavra ou -1 se não for uma palavra. Depois de verificar todas os tokens, deve-se verificar se há uma ou mais palavras validas, se houver é feito a divisao do tamanho total das palavras pelo numero de palavras para obter o tamanho medio, se não houver nenhuma palavra valida, entao o tamanho medio é zero. Depois disso, basta verificar se o tamanho medio é <=3, <=5 ou >5 para definir a pontuação final.
*/

#include <bits/stdc++.h>
using namespace std;

//Funcao para transformar a string de entrada em diversos tokens divididos por espaco
vector<string> tokenizing(string original){
	//Vector para armazenar os tokens
	vector<string> tokens;

	//Colocar a string de entrada no stream para ser utilizada para realizar o tokenizing
	stringstream check1(original); 
      
	//Armazena o token resultado
    	string intermediate; 

	//Realiza o tokenizing utilizando o getline no processo
    	while(getline(check1, intermediate, ' ')) { 
        	tokens.push_back(intermediate); 
    	} 
	return tokens;
}

//Funcao para verificar se uma string de entrada é uma palavra ou nao
//Retorna valor >1 se for, ou retorna -1 se nao for
int isWord(string word){
	int len = word.length(); //Tamanho da string de entrada
	int flag = 0; //Flag que armazena se a entrada é palavra ou nao
	bool letter = false; //Auxiliar para dizer se apareceu alguma letra
	bool point = false; //Auxiliar para dizer se apareceu um ponto final

	//Percorre toda a string de entrada
	for(int i = 0; i < len; i++){
		//É uma letra
		if(word[i] >= 'a' && word[i] <= 'z'){
			letter = true; //letra
		}
		//É uma letra
		else if(word[i] >= 'A' && word[i] <= 'Z'){
			letter = true; //letra
		}
		//É um ponto final
		else if(word[i] == '.' && i == len - 1){
			//É um ponto final valido, tem letras antes
			if(letter){
				point = true; //ponto final valido
			}
			//É um ponto final invalido, pois não tem letras antes ou o token é composto apenas de um unico ponto
			else{
				flag = 1; //Entrada não é uma palavra
			}
		}
		//É qualquer outro caracter
		else{
			flag = 1; //Entrada nao é uma palavra
		}
	}
	//Se a entrada é uma palavra e tem letras, é uma palavra
	if(flag == 0 && letter == true){
		if(point){ //Se tem ponto final, desconsidera o ponto final no calculo do tamanho da palavra
			return len - 1;
		}
		else{ 
			return len;
		}
	}
	//A entrada não é uma palavra, erro
	else{ 
		return -1;
	}
}

int main(){
	//Variaveis auxiliares
	string str; //String de entrada
	int result = 0; //Resultado retornado pela funcao isWord
	int count = 0; //Numero de palavras validas
	int soma = 0; //Soma dos comprimentos das palavras
	int div = 0; //tamanho medio das palavras
	while(getline(cin, str)){
		//Zera todas as variaveis auxiliares
		result = 0;
		count = 0;
		soma = 0;
		div = 0;

		//Quebra a entrada em tokens
		vector<string> tokens (tokenizing(str));

		//Analisa todos os tokens
		for(int i = 0; i < tokens.size(); i++){
        		result = isWord(tokens[i]);
			if(result > 0){
				//Token é uma palavra
				count++;
				soma += result;
			}	
		}

		//Verifica se não há nenhuma palavra 
		if(count == 0){
			//Se nao tiver palavra, o tamanho medio é zero
			div = 0;
		}
		else{
			//Tamanho medio é igual a divisao do comprimento pelo número de palavras
			div = soma/count;
		}

		//Analisa o resultado do tamanho medio para definir a resposta
		if(div <= 3){
			cout<<"250"<<endl;
		}
		else if(div <= 5){
			cout<<"500"<<endl;
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	return 0;
}
