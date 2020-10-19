#include <stdexcept>
#include <iostream>
#include <string>
#include <stdlib.h>

void converte(string mensagem, int* quadro, int pos); 
void CamadaDeAplicacaoTransmissora(string mensagem); 
void CamadaFisicaTransmissora(int* quadro);
//
int *CamadaFisicaTransmissoraCodificacaoBinaria(int *quadro);
int *CamadaFisicaReceptoraDecodificacaoBinaria(int *quadro);
//
int *CamadaFisicaTransmissoraCodificacaoManchester(int *quadro);
int *CamadaFisicaReceptoraDecodificacaoManchester(int *quadro); 
//
int *CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int *quadro);

int *CamadaFisicaReceptoraDecodificacaoManchesterDiferencial (int *quadro);

//

void MeioDeComunicacao(int* fluxoBrutodeBits); 
void CamadaFisicaReceptora(int* quadro); 
void CamadaDeAplicacaoReceptora(int* quadro); 
void AplicacaoReceptora(string mensagem); 