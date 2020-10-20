#include <string>
using namespace std;

#include <stdexcept>
#include <iostream>
#include <stdlib.h>

#include "CamadaFisica.h"

void AplicacaoTransmissora(void);

int main(void){

  AplicacaoTransmissora();

  return 0;

} // fim do metodo main

void AplicacaoTransmissora(void){
  string mensagem;
  cout << "\033[1;34mAplicacao Transmissora: \033[0m\n";
  cout << "Digite uma mensagem:" << endl;
  //cin >> mensagem;

  getline(cin,mensagem);

  cout << "\033[1;32mMensagem a ser transmitida: \033[0m";
	cout << mensagem << endl << endl;

  // chama a proxima camada
  CamadaDeAplicacaoTransmissora(mensagem);
}
