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

int find_size(int quadro[]){

	int i = 0;
	while (1)
	{

		if (quadro[i] == 2)
		{
			break;
		}
		i++;
	}

return i;
}

void converte(string mensagem, int quadro[], int pos)
{

	int x, j, i;

	j = ((pos * 8) - 1) + 8;

	bitset<8> set(mensagem[pos]);

	if (mensagem[pos] == ' ')
	{

		// espaço, caso especial
		set.reset();   // todos são zero
		set.set(5, 1); // 32 == espaço
	}

	for (i = 0; i < 8; i++)
	{

		if (set.test(i))
		{

			quadro[j] = 1;
			j--;

		}
		else
		{

			quadro[j] = 0;
			j--;

		}
	}

	return;
}

void CamadaDeAplicacaoTransmissora(string mensagem)
{

	// int quadro[] = mensagem
	// trabalhando com bits
	// chama a proxima camada

	// VAMOS PASSAR COM UM FOR POR CADA LETRA
	// CADA LETRA = 2 HEXADECIMAIS = 8 BITS
	// O ARRAY DE INTEIRO VAI SER TAMANHO str.size() * 8, aloca dinamicamente pra ficar legal
	// usa funcao pronta pra pegar cada letra e traduzir pra hexa, que traduz pra binario (utf-8)

	// cout<<"What is the letter you wanna convert?"<<endl;
	// cin >> letter;
	// cout << bitset<8>(letter).to_string() << endl;

	// int const tamanho = 8*(mensagem.size());
	cout << "\033[1;34mCamada de Aplicacao Transmissora\033[0m\n";

	int i, j, x;
	int tamanho_quadro_final = 8 * (mensagem.length());

	int *quadro, *letra_atual;
	quadro = new (nothrow) int[tamanho_quadro_final];

	for (j = 0; j < mensagem.size(); j++)
	{

		converte(mensagem, quadro, j);

	}
	for(i = 0; i < tamanho_quadro_final; i++){

		cout << quadro[i];

	}
	cout << endl << endl;

quadro[tamanho_quadro_final] = 2;

CamadaFisicaTransmissora(quadro);

} // fim do metodo

void CamadaFisicaTransmissora(int quadro[])
{

	cout << "\033[1;34mCamada Fisica Transmissora: \033[0m\n";
	int tipoDeCodificacao = CODIFICACAO;

	int i = 0;
	int tamanho_fluxo;
	tamanho_fluxo = find_size(quadro) * 2;

	int *fluxoBrutoDeBits;

	fluxoBrutoDeBits = new (nothrow) int[tamanho_fluxo];

	switch (tipoDeCodificacao)
	{
		case 0: //codificacao binaria

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);

		cout << "\033[1;35mCodificacao Binaria: \033[0m\n";
		for (i = 0; i < tamanho_fluxo; i++)
		{
			cout << fluxoBrutoDeBits[i];
		}
		cout << endl << endl;

		break;

		case 1: //codificacao manchester

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);

		cout << "\033[1;35mCodificacao Manchester: \033[0m\n";
		for (i = 0; i < tamanho_fluxo; i++)
		{
			cout << fluxoBrutoDeBits[i];
		}
		cout << endl << endl;

		break;

		case 2: //codificacao manchester diferencial

		fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(quadro);

		cout << "\033[1;35mCodificacao Manchester Diferencial: \033[0m\n";
		for (i = 0; i < tamanho_fluxo; i++)
		{
			cout << fluxoBrutoDeBits[i];
		}
		cout << endl << endl;

		break;

	} // fim do switch/case

	MeioDeComunicacao(fluxoBrutoDeBits);
}

int *CamadaFisicaTransmissoraCodificacaoManchester(int quadro[])
{
	// implementacao do algoritmo

	int i = 0;
	int tamanho_fluxo;
	i = find_size(quadro);
	tamanho_fluxo = i * 2;

	int *fluxoCodificado;

	fluxoCodificado = new (nothrow) int[tamanho_fluxo];

	int j;
	int x = 0;

	for (j = 0; j < i; j++)
	{

		// xor 00 e 01 = 01
		// xor 11 e 01 = 10
		// clock = 01 01 01 01 ...
		if (quadro[j] == 0)
		{
			fluxoCodificado[x] = 0;
			x++;
			fluxoCodificado[x] = 1;
			x++;
		}
		if (quadro[j] == 1)
		{
			fluxoCodificado[x] = 1;
			x++;
			fluxoCodificado[x] = 0;
			x++;
		}
	}

	fluxoCodificado[tamanho_fluxo] = 2;

	//int tamanho_quadro = sizeof(quadro);

	//cout << "tamanho:" << tamanho_quadro << endl;

	return fluxoCodificado;

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchester

int *CamadaFisicaTransmissoraCodificacaoBinaria(int quadro[])
{
	// implementacao do algoritmo

	int i = 0;
	int tamanho_fluxo;
	i = find_size(quadro);
	tamanho_fluxo = i * 2;

	int *fluxoCodificado;

	fluxoCodificado = new (nothrow) int[tamanho_fluxo];

	int j;

	int x = 0;

	for (j = 0; j < i; j++)
	{

		fluxoCodificado[x] = quadro[j];
		x++;

		fluxoCodificado[x] = quadro[j];
		x++;
	}

	fluxoCodificado[tamanho_fluxo] = 2;

	return fluxoCodificado;

} // fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

int *CamadaFisicaTransmissoraCodificacaoManchesterDiferencial(int quadro[])
{
	// implementacao do algoritmo

	int i = 0;
	int tamanho_fluxo;
	i = find_size(quadro);
	tamanho_fluxo = i * 2;

	int *fluxoCodificado;

	fluxoCodificado = new (nothrow) int[tamanho_fluxo];

	int j;
	int x = 0;

	// 0  1  0  1  1  0  0
	// 00 11 00 11 11 00 00
	// 01 10 10 01 10 10 10

	// z
	// 0  1  1  1  1  0  1  0
	// 00 11 11 11 11 00 11 00
	// 01 10 01 10 01 01 10 10

	// logica inversa

	// 00 11 11 11 11 00 11 00

	// 01 10 01 10 01 10 0

	// 0  1  1  0  0  0  0  1
	// 01 10 01 10 01 01 01 01 01 10

	int passado[2];

	passado[0] = 0;
	passado[1] = 1;

	for (j = 0; j < i; j++)
	{
		if (quadro[j] == 0)
		{

			fluxoCodificado[x] = passado[0];
			x++;
			fluxoCodificado[x] = passado[1];
			x++;
		}
		else
		{

			if (quadro[j] == 1)
			{

				if (passado[0] == 0)
				{

					passado[0] = 1;
					passado[1] = 0;

					fluxoCodificado[x] = 1;
					x++;
					fluxoCodificado[x] = 0;
					x++;
				}

				else if (passado[0] == 1)
				{

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

	fluxoCodificado[tamanho_fluxo] = 2;

	return fluxoCodificado;

} // fim do metodo CamadaFisicaTransmissoraCodificacaoManchesterDiferencial

void MeioDeComunicacao(int fluxoBrutodeBits[])
{

	int i = 0;

	cout << "\033[1;33mMeio de Transmissao\033[0m\n";

	int tamanho = find_size(fluxoBrutodeBits);

	int *fluxoBrutoDeBitsPontoA;
	int *fluxoBrutoDeBitsPontoB;

	fluxoBrutoDeBitsPontoA = new (nothrow) int[tamanho];
	fluxoBrutoDeBitsPontoB = new (nothrow) int[tamanho];

	for (i = 0; i < tamanho; i++)
	{
		fluxoBrutoDeBitsPontoA[i] = fluxoBrutodeBits[i];
	}

	for (i = 0; i < tamanho; i++)
	{
		fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
	}
	cout << endl;

	fluxoBrutoDeBitsPontoB[tamanho] = 2;

	CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora(int quadro[])
{

	cout << "\033[1;34mCamada Fisica Receptora\033[0m\n";

	int tipoDeDecodificacao = CODIFICACAO;

	int i = 0;
	i = find_size(quadro);
	int *fluxoBrutoDeBits;

	fluxoBrutoDeBits = new (nothrow) int[i];

	switch (tipoDeDecodificacao)
	{

		case 0:

		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoBinaria(quadro);

		cout << "\033[1;35mDecodificacao Binaria: \033[0m\n";
		for (int j = 0; j < i; j++)
		{
			cout << fluxoBrutoDeBits[j];
		}
		cout << endl << endl;

		break;
		case 1:

		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchester(quadro);

		cout << "\033[1;35mDecodificacao Manchester: \033[0m\n";
		for (int j = 0; j < i; j++)
		{
			cout << fluxoBrutoDeBits[j];
		}
		cout << endl << endl;

		break;
		case 2:

		fluxoBrutoDeBits = CamadaFisicaReceptoraDecodificacaoManchesterDiferencial(quadro);

		cout << "\033[1;35mDecodificacao Manchester Diferencial: \033[0m\n";
		for (int j = 0; j < i; j++)
		{
			cout << fluxoBrutoDeBits[j];
		}
		cout << endl << endl;

		break;
	}

	CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

int *CamadaFisicaReceptoraDecodificacaoBinaria(int quadro[])
{

	return quadro;
}

int *CamadaFisicaReceptoraDecodificacaoManchester(int quadro[])
{

	int i = 0;
	int tamanho_fluxo;
	i = find_size(quadro);
	tamanho_fluxo = i;

	int *fluxoDecodificado;

	fluxoDecodificado = new (nothrow) int[tamanho_fluxo];

	int j, x;
	x = 0;

	for (j = 0; j < i; j++)
	{

		// xor 01 e 01 = 00
		// xor 10 e 01 = 11
		// clock = 01 01 01 01 ...
		if ((quadro[j] == 0) && (quadro[j + 1] == 1))
		{
			fluxoDecodificado[x] = 0;
			x++;
			fluxoDecodificado[x] = 0;
			x++;
		}
		if ((quadro[j] == 1) && (quadro[j + 1] == 0))
		{
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

	return fluxoDecodificado;
}

void CamadaDeAplicacaoReceptora(int quadro[])
{

	cout << "\033[1;34mCamada de Aplicação Receptora\033[0m\n";
	// transformando em string

	int i = 0;
	i = find_size(quadro);
	int tamanho_quadro = i;
	int tamanho_mensagem_ascii = i / 2;

	int *fluxoFinal;

	fluxoFinal = new (nothrow) int[tamanho_mensagem_ascii];

	int j = 0;

	for (i = 0; i < tamanho_quadro; i = i + 2)
	{

		fluxoFinal[j] = quadro[i];

		cout << fluxoFinal[j]; // tamanho = tamanho_mensagem_ascii

		j++;
	}

	cout << endl << endl;

	// reverse bitset

	string mensagem;

	int decimal = 0;
	int y;
	// 01111010

	for (i = 0; i < (tamanho_mensagem_ascii / 8); i++)
	{

		decimal = 0;

		y = 0;

		for (j = ((i * 8) + 7); j >= (i * 8); j--)
		{

			if (fluxoFinal[j] == 1)
			{

				decimal = decimal + pow(2, y);
			}

			y++;
		}

		mensagem.push_back((char)decimal);
	}

	AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem)
{
	cout << "\033[1;34mAplicacao Receptora\033[0m\n";
	cout << "\033[1;32mA mensagem recebida foi: \033[0m";
	cout << mensagem << endl;
}

int *CamadaFisicaReceptoraDecodificacaoManchesterDiferencial (int quadro[]){

	int i = 0;
	i = find_size(quadro);
	int tamanho_fluxo;
	tamanho_fluxo = i;

	int *fluxoDecodificado;

	fluxoDecodificado = new (nothrow) int[tamanho_fluxo];

	int j, x;
	x = 0;

	int passado[2];

	passado[0] = 0;
	passado[1] = 1;

	for (j = 0; j < tamanho_fluxo; j=j+2)
	{

		if ((quadro[j] == 0 && quadro[j+1] == 1))
		{
			if((passado[0] == 0 && passado[1] == 1)){

				fluxoDecodificado[x] = 0;
				x++;
				fluxoDecodificado[x] = 0;
				x++;

			}else if((passado[0] == 1 && passado[1] == 0)){

				fluxoDecodificado[x] = 1;
				x++;
				fluxoDecodificado[x] = 1;
				x++;

				passado[0] = 0;
				passado[1] = 1;

			}
		}

		else if ((quadro[j] == 1 && quadro[j+1] == 0))
		{
			if((passado[0] == 1 && passado[1] == 0)){

				fluxoDecodificado[x] = 0;
				x++;
				fluxoDecodificado[x] = 0;
				x++;

			}else if((passado[0] == 0 && passado[1] == 1)){

				fluxoDecodificado[x] = 1;
				x++;
				fluxoDecodificado[x] = 1;
				x++;

				passado[0] = 1;
				passado[1] = 0;

			}

		}

	}

	fluxoDecodificado[tamanho_fluxo] = 2;

	return fluxoDecodificado;
}
