#include <string>
using namespace std;

#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>
#include <bitset>
#include <stdlib.h>
#include <array> 
#include <cmath>

#include "CamadaFisica.h"

void converte(string mensagem, int quadro[], int pos){

	int x, j, i;

	j = ((pos*8)-1) + 8;

	bitset<8> set(mensagem[pos]);

	if(mensagem[pos] == ' '){

		// espaço, caso especial
		cout << "Espaço supimpa."; 

		set.reset(); // todos são zero
		set.set(5, 1); // 32 == espaço

	} 

		//cout << set << endl;

		//j = ((pos*8)-1) + 8;

		//cout << j << endl;

		//int novo_quadro[8];

		//	for(x=0; x<mensagem.size() ; x++){

	for(i = 0; i < 8 ; i++){

		if(set.test(i)){

			quadro[j] = 1;

			//cout << "a" << endl;
			j--;
		}
		else{

			quadro[j] = 0;

			j--;
		}

	}

	
	return;

}


void CamadaDeAplicacaoTransmissora(string mensagem){

	//int quadro[] = mensagem 
	// trabalhando com bits
	//chama a proxima camada

	// VAMOS PASSAR COM UM FOR POR CADA LETRA
	// CADA LETRA = 2 HEXADECIMAIS = 8 BITS
	// O ARRAY DE INTEIRO VAI SER TAMANHO str.size() * 8, aloca dinamicamente pra ficar legal
	// usa funcao pronta pra pegar cada letra e traduzir pra hexa, que traduz pra binario (utf-8)

	// cout<<"What is the letter you wanna convert?"<<endl;
	// cin >> letter;
	// cout << bitset<8>(letter).to_string() << endl;

	//int const tamanho = 8*(mensagem.size());


	int i;
	int j;
	int tamanho_quadro_final = 8*(mensagem.length());
	int x;

	cout << tamanho_quadro_final <<endl;

	int *quadro, *letra_atual;
	quadro = new (nothrow) int[tamanho_quadro_final];

	for(j = 0; j < mensagem.size(); j++){

		converte(mensagem, quadro, j);

		cout << mensagem[j] << " se tornou ";

		for(i = j*8; i < (j*8 + 8)  ; i++){

			cout << quadro[i];

		}

  		cout << endl;
	}

	for(j = 0; j < tamanho_quadro_final; j++){

		cout << quadro[j];

	}

	cout << endl;
	/*
		converte(mensagem, quadro, 1);

		for(i = 0; i < 8 ; i++){

		cout << quadro[i];

		}

	cout << endl;
	*/
		//converte(mensagem, quadro, 1);

	quadro[tamanho_quadro_final] = 2; 

	CamadaFisicaTransmissora(quadro);

} // fim do metodo

void CamadaFisicaTransmissora(int quadro[]){

	int tipoDeCodificacao = 2;

 	int i = 0; 

	while(1){
	
		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}
	 
	int tamanho_fluxo;
	tamanho_fluxo = i*2; 

	int *fluxoBrutoDeBits; 

	fluxoBrutoDeBits = new (nothrow) int[tamanho_fluxo]; 

	cout << tamanho_fluxo << endl;

	switch (tipoDeCodificacao){
	case 0: //codificacao binaria

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);

		cout << "Camada Fisica Transmissora: "; 
		for(i=0 ; i < tamanho_fluxo ; i++){
			cout << fluxoBrutoDeBits[i]; 
		}
		cout << endl; 

		break;

	case 1: //codificacao manchester

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);

		cout << "Camada Fisica Transmissora: "; 
		for(i=0 ; i < tamanho_fluxo ; i++){
			cout << fluxoBrutoDeBits[i]; 
		}
		cout << endl; 

		break;

	case 2: //codificacao manchester diferencial

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);

		cout << "Camada Fisica Transmissora: "; 
		for(i=0 ; i < tamanho_fluxo ; i++){
			cout << fluxoBrutoDeBits[i]; 
		}
		cout << endl; 

		break;

	} // fim do switch/case

	//MeioDeComunicacao(fluxoBrutoDeBits);

}

int* CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]){
	// implementacao do algoritmo

	int i = 0; 

	while(1){
	
		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho_fluxo;
	tamanho_fluxo = i*2; 
	cout << tamanho_fluxo << endl; 

	int *fluxoCodificado; 

	fluxoCodificado = new (nothrow) int[tamanho_fluxo]; 

	int j;
	int x=0; 

	for(j=0; j < i ; j++){

		// xor 00 e 01 = 01
		// xor 11 e 01 = 10
		// clock = 01 01 01 01 ...
		if(quadro[j] == 0){
			fluxoCodificado[x] = 0;
			x++;
			fluxoCodificado[x] = 1;  
			x++;
		}
		if(quadro[j] == 1){
			fluxoCodificado[x] = 1;
			x++;
			fluxoCodificado[x] = 0;  
			x++;
		}

	} 

	cout << endl; 

	cout << "Codificação Manchester: "; 

	for(j=0; j < tamanho_fluxo ; j++){
		cout << fluxoCodificado[j]; 
	}
	cout << endl; 

	fluxoCodificado[tamanho_fluxo] = 2; 

	//int tamanho_quadro = sizeof(quadro); 

	//cout << "tamanho:" << tamanho_quadro << endl; 

	return 	fluxoCodificado; 

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester



int* CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]){
	// implementacao do algoritmo

	cout << "binarior" << endl;  

	int i = 0; 

	while(1){
	
		cout << quadro[i] << endl; 

		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho_fluxo;
	tamanho_fluxo = i*2; 
	cout << tamanho_fluxo << endl; 

	int *fluxoCodificado; 

	fluxoCodificado = new (nothrow) int[tamanho_fluxo];

	int j; 
	
	int x = 0;

	for(j=0 ; j < i ; j++){

		fluxoCodificado[x] = quadro[j]; 
		x++; 

		fluxoCodificado[x] = quadro[j]; 
		x++; 

	}  

	fluxoCodificado[tamanho_fluxo] = 2; 

	return fluxoCodificado; 

} // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

	
int* CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]){
	// implementacao do algoritmo

	cout << "oi, manchesto diferetne " << endl; 

	int i = 0; 

	while(1){
	
		cout << quadro[i] << endl; 

		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho_fluxo;
	tamanho_fluxo = i*2; 
	cout << tamanho_fluxo << endl; 

	int *fluxoCodificado; 

	fluxoCodificado = new (nothrow) int[tamanho_fluxo]; 


	int j;
	int x = 0; 

	// 0  1  0  1  1  0  0 
	// 00 11 00 11 11 00 00
	// 01 10 10 01 10 10 10

	// 0  1  1  1  1  0  1  0
	// 00 11 11 11 11 00 11 00
	// 01 10 01 10 01 01 10 10

	// 01 10 01 10 01 10 0

	// 0  1  1  0  0  0  0  1
	// 01 10 01 10 01 01 01 01 01 10

	int passado[2];

	passado[0] = 0;
	passado[1] = 1;  

	int antes = 0; 

	for(j=0; j < i ; j++){

		cout << quadro[j] << endl; 

		if(quadro[j] == 0){

			if(antes == 0){

			fluxoCodificado[x] = 0;
			x++;
			fluxoCodificado[x] = 1;
			x++;
			}

			if(antes == 1){

			fluxoCodificado[x] = 1;
			x++;
			fluxoCodificado[x] = 0;
			x++;

			}
			

		}
		else{

		if(quadro[j] == 1){

			if( antes == 0){
				
				antes = 1; 

				passado[0] = 1; 
				passado[1] = 0; 

				fluxoCodificado[x] = 1;
				x++;
				fluxoCodificado[x] = 0;
				x++;

			}
			if( antes == 1 ){

				antes = 0; 

				passado[0] = 0; 
				passado[1] = 1;	

				fluxoCodificado[x] = 0;
				x++;
				fluxoCodificado[x] = 1;
				x++;			

			}

		}
		}
 

	}

	return 	fluxoCodificado; 

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial


void MeioDeComunicacao(int fluxoBrutodeBits[]){


	int i = 0; 

	cout << "comunicandooooooo" << endl; 

	while(1){
	
		if(fluxoBrutodeBits[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho = i; 

	int* fluxoBrutoDeBitsPontoA; 
	int* fluxoBrutoDeBitsPontoB; 

	fluxoBrutoDeBitsPontoA = new (nothrow) int[tamanho];
	fluxoBrutoDeBitsPontoB = new (nothrow) int[tamanho];

	//strcpy(fluxoBrutoDeBitsPontoA, fluxoBrutodeBits); 

	for(i = 0; i < tamanho ; i++){
		fluxoBrutoDeBitsPontoA[i] = fluxoBrutodeBits[i]; 
	}
	
	for(i = 0; i < tamanho ; i++){
		fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i]; 
		cout << fluxoBrutoDeBitsPontoB[i]; 
	}
	cout << endl; 

	fluxoBrutoDeBitsPontoB[tamanho] = 2; 

	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB); 

}

void CamadaFisicaReceptora(int quadro[]){

	cout << "recebendooooo" << endl; 

	int tipoDeDecodificacao = 2; 

	int i = 0; 

	while(1){
	
		if(quadro[i]==2){
			cout << "achei o final" << endl;  
			break; 
		} 
		i++; 
	}
	 
	int *fluxoBrutoDeBits; 

	fluxoBrutoDeBits = new (nothrow) int[i]; 

	cout << i << endl; 

	switch(tipoDeDecodificacao){

		case 0:

			fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro); 

			for(int j = 0; j < i; j++){
				cout << fluxoBrutoDeBits[j]; 
			}
			cout << endl; 

			break; 
		case 1:

			fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro); 

			for(int j = 0; j < i; j++){
				cout << fluxoBrutoDeBits[j]; 
			}
			cout << endl; 

			break; 
		case 2:

			break; 
	}

	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits); 

}

int* CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[]){

	cout << "decod binaria" << endl; 

	return quadro; 
}

int* CamadaFisicaReceptoraDecodificacaoManchester(int quadro[]){

	cout << "decodificandoooooo" << endl; 

	int i = 0; 

	while(1){
	
		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho_fluxo;
	tamanho_fluxo = i; 
	cout << tamanho_fluxo << endl; 

	int *fluxoDecodificado; 

	fluxoDecodificado = new (nothrow) int[tamanho_fluxo]; 

	int j, x; 
	x = 0; 

	for(j=0; j < i ; j++){

		// xor 01 e 01 = 00
		// xor 10 e 01 = 11
		// clock = 01 01 01 01 ...
		if((quadro[j] == 0) && (quadro[j+1] == 1)){
			fluxoDecodificado[x] = 0;
			x++;
			fluxoDecodificado[x] = 0;  
			x++;
		}
		if((quadro[j] == 1) && (quadro[j+1] == 0)){
			fluxoDecodificado[x] = 1;
			x++;
			fluxoDecodificado[x] = 1;  
			x++;
		} 
		j++; 

		fluxoDecodificado[tamanho_fluxo] = 2;
 

	}

	//011110100110000101110000
	//011110100110000101110000

	cout << "Fluxo decodificado manchester:" << endl; 
	for(j=0; j < i ; j++){
		cout << fluxoDecodificado[j]; 
	} 
	cout << endl;

	return fluxoDecodificado;

}

void CamadaDeAplicacaoReceptora(int quadro[]){

	// transformando em string

	int i = 0; 

	while(1){
	
		if(quadro[i]==2){
			cout << "achei o final" << endl; 
			cout << i << endl;  
			break; 
		} 
		i++; 
	}

	int tamanho_quadro = i; 
	int tamanho_mensagem_ascii = i/2; 

	cout << "fazendo virar string, CamadaDeAplicacaoReceptora" << endl;

	cout << tamanho_mensagem_ascii << endl; 

	int *fluxoFinal; 

	fluxoFinal = new (nothrow) int[tamanho_mensagem_ascii]; 

	int j = 0; 

	for(i = 0 ; i < tamanho_quadro ; i=i+2){

		fluxoFinal[j] = quadro[i]; 

		cout << fluxoFinal[j]; // tamanho = tamanho_mensagem_ascii

		j++; 
	}


	cout << endl; 

	// reverse bitset

	string mensagem; 

	int decimal = 0;
	int y; 

	cout << "tamanho do da mensagem: " << (tamanho_mensagem_ascii / 8) << endl; 

	// 01111010

	
	for(i = 0; i < (tamanho_mensagem_ascii / 8) ; i++){

		decimal = 0;

		y = 0;

		for(j = ((i*8) + 7) ; j >= (i*8) ; j--){

			if(fluxoFinal[j] == 1){

				decimal = decimal + pow(2, y); 

			}

			y++; 

		}

		cout << decimal << endl; 


		mensagem.push_back((char)decimal); 

	}
	

	cout<< mensagem <<endl;


	AplicacaoReceptora(mensagem); 

}

void AplicacaoReceptora(string mensagem){
	cout << "A mensagem recebida foi: " << mensagem << endl; 
}

