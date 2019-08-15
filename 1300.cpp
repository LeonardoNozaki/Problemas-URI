/*
Problema: 1300 - Horas e Minutos
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1300
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Para solucionar esse problema, primeiro foi construido a funcao angMinimo que dado a hora e o minuto, ele calcula o valor do menor angulo formado entre esses dois ponteiros. Depois, na funcao main, foi criado um vetor com 181 posicoes onde cada posicao representa um angulo (0 <= a <= 180) e o primeiro for zera todas as posicoes do vetor e os outros dois fors encadeados fazem todas as combinacoes de horas e minutos e chama a funcao de angMinimo para calcular o angulo e colocar esse angulo no vetor.
Depois que tudo foi calculado, basta ler cada linha da entrada e verificar no vetor se aquele valor é possivel (vetor[a] == 1) ou nao é possivel (vetor[a] == 0).
*/

#include <bits/stdc++.h>
using namespace std;

//Funcao para calcular o angulo minimo entre os ponteiros das horas e minutos
int angMinimo(int h, int m){
	int ang1, ang2, angMenor, angMaior;

	//Calcula o angulo que o ponteiro dos minutos forma
	int angM = m * 6; // 360/60 = 6 graus cada minuto

	//Calcula o angulo que o ponteiro das horas forma
	int angH = (h * 30) + ((m/12) * 6); // 360/12 = 30 graus cada hora, m/12 * 6 pois cada a 12minutos faz o ponteiro das horas se mover 6 graus

	//Verificar qual ponteiro tem o maior e menor angulo
	if(angH > angM){
		angMaior = angH;
		angMenor = angM;
	}
	else{
		angMaior = angM;
		angMenor = angH;
	}

	//Tem duas possibilidades de encontrar o angulo minimo 
	ang1 = angMaior - angMenor; //Subtrair o maior angulo pelo menor
	ang2 = (360 - angMaior) +angMenor; //Subtrair 360 pelo maior angulo e completar com o menor angulo

	//Verifica qual é menor angulo e retorna
	if(ang1 > ang2){
		return ang2;
	}
	else{
		return ang1;
	}
}

int main(){
	//Variaveis auxiliares
	int a, resultado; //a é variavel de leitura, resultado recebe o valor da funcao angMinimo
	int angulos[181]; //Vetor de angulo que vai de 0 ate 180

	//Zera todo o vetor
	for(int i = 0; i <= 180; i++){
		angulos[i] = 0;
	}

	//Faz todas as possibilidades de horas e minutos
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 60; j++){
			//Chama a funcao para calcular o angulo minimo
			resultado = angMinimo(i, j);
		
			//Verifica se o resultado ja foi colocado no vetor
			if(angulos[resultado] == 0){
				//Atualiza o vetor se ainda nao foi colocado
				angulos[resultado] = 1;
			}
		}
	}
	
	//Leitura e saida
	while(cin>>a){
		if(angulos[a] == 1){
			cout<<"Y"<<endl;
		}
		else{
			cout<<"N"<<endl;
		}
	}
}
