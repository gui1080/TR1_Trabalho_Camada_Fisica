void main (void){
  
  AplicacaoTrainsmissora();

} // fim do metodo main

void AplicacaoTrainsmissora(void){
  string mensagem;
  cout << "Digite uma mensagem:" << endl;
  cin >> mensagem;
  // chama a proxima camada
  CamadaDeAplicacaoTransmissora(mensagem);
}
