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
  cout << "Digite uma mensagem:" << endl;
  cin >> mensagem;
  // chama a proxima camada
  CamadaDeAplicacaoTransmissora(mensagem);
}
