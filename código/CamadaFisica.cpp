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

  CamadaFisicaTransmissora(quadro);

} // fim do metodo CamadaDeAplicacaoTransmissora

void CamadaFisicaTransmissora(int quadro[]){
  int tipoDeCodificacao = 1;
  int fluxoBrutoDeBits [];

  switch (tipoDeCodificacao){
    case 0: //codificacao binaria
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
      break;

    case 1: //codificacao manchester
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
      break;

    case 2: //codificacao manchester diferencial
      fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);
      break;
  } // fim do switch/case

  MeioDeComunicacao(fluxoBrutoDeBits);

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
