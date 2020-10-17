
#include <string>
using namespace std;

#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h> 
#include <bitset>
#include <stdlib.h>


#include "CamadaFisica.h"

void converte(string mensagem, int quadro[], int pos){

  int x, j, i; 

  bitset<8> set(mensagem[pos]); 

  cout << set << endl; 

  j = ((pos*8)-1);

  int novo_quadro[8]; 

  for(x=0; x<mensagem.size() ; x++){

    for(i = 0; i < 8 ; i++){

      if(set.test(i)){
        
        //quadro[j] = 1;

        cout << "a" << endl; 
        j--; 
      }
      else{
        
        //quadro[j] = 0;
        
        j--;
      }

    } 
    //set.reset(); 

  }

    return; 
  

}


void CamadaDeAplicacaoTransmissora(string mensagem){

  //int quadro[] = mensagem // trabalhando com bits
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
  int tamanho_quadro_final = 8*(mensagem.size()); 
  int x; 

  cout << tamanho_quadro_final <<endl; 

  int *quadro, *letra_atual;
  quadro = new (nothrow) int[tamanho_quadro_final]; 

  converte(mensagem, quadro, 0);

  for(i = 0; i < 8 ; i++){

    cout << quadro[i];  

  }

  //converte(mensagem, quadro, 1);
  
  // CamadaFisicaTransmissora(quadro);

} // fim do metodo

void CamadaFisicaTransmissora(int quadro[]){
  int tipoDeCodificacao = 1;
  int fluxoBrutoDeBits[10];

  switch (tipoDeCodificacao){
    case 0: //codificacao binaria
      
      //fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      
      break;

    case 1: //codificacao manchester
      
      // fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      
      break;

    case 2: //codificacao manchester diferencial
      // fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);
      
      break;
  
  } // fim do switch/case

  //MeioDeComunicacao(fluxoBrutoDeBits);

}

/*
int [] CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[]){
  // implementacao do algoritmo

} // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

int [] CamadaFisicaTransmissoraCodificacaoManchester(int quadro[]){
  // implementacao do algoritmo

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int [] CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[]){
  // implementacao do algoritmo

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial

*/
