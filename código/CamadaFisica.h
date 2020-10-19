#include <stdexcept>
#include <iostream>
#include <string>
#include <stdlib.h>

#define CODIFICACAO 1

// CODIFICACAO = 0 (Codificação Binária)
// CODIFICACAO = 1 (Codificação Manchester)
// CODIFICACAO = 2 (Codificação Manchester Diferencial)

//
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
//