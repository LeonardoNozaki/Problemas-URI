/*
Problema: 2779 - Album da copa
Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/2779
Autor da resolução: Leonardo Nozaki

Explicação da solucação: Vamos utiliar um vetor para ser o album, inicialmente nao ha nenhuma figurinha no album e elas vao sendo adicionadas conforme é feito a leitura (se a figurinha nao foi colada ainda, cola-se ela mudando o valor do vetor para 1 e diminui o contador de figurinhas faltantes), porem se a figurinha ja foi colada, ela deve ser descartada e o numero de figurinhas faltantes permanece o mesmo. No fim, basta exibir o numero de figurinhas faltantes
*/

import java.util.*;

public class Main{
	public static void main(String []args){
		//Criacao de um obj scanner para leitura dos dados
       		Scanner sc1 = new Scanner(System.in); 
	
		//Variaveis auxiliares
		int n = sc1.nextInt(); //Numero de figurinhas
		int total = n, f; //Numero de figurinhas faltantes e figurinha atual
		int[] figu = new int[n]; //Album de figurinha

		//Iniciar o album como vazio
		for(int i = 0; i < n; i++){
			figu[i] = 0;
		}

		//Leitura do numero de figurinhas compradas
		int m = sc1.nextInt();
		for(int i = 0; i < m; i++){
			f = sc1.nextInt(); //Leitura da figurinha atual
			f = f - 1; //-1, pois as figurinhas vao de 1 ate n, o vetor vai de 0 ate n-1
			if(figu[f] == 0){ //Verifica se a figurinha atual nao existe ainda
				figu[f] = 1; //Adiciona figurinha
				total = total - 1; //Subtrai um do numero de figurinhas faltantes
			}
		}

		//Imprime numero faltante de figurinhas
		System.out.println(total);
    	}
}
