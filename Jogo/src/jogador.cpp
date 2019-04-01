/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include <iostream>
#include "jogador.h"
#include "dado.h"

using namespace std;

int Jogador::objetivo = 20;

string Jogador::getNomeDoJogador() {
	return nomeDoJogador;
}

int Jogador::getPontuacaoTotal() {
	return pontuacaoTotal;
}

Situacao Jogador::getSituacaoAtual() {  
	return situacaoAtual;
}
/* Construtor padrão. */
Jogador::Jogador(): nomeDoJogador("Empty Name"),
					pontuacaoTotal(0),
					situacaoAtual(ATIVO){}
	
Jogador::Jogador(string novoJogador):
					nomeDoJogador(novoJogador),
					pontuacaoTotal(0),
					situacaoAtual(ATIVO){}

Jogador::~Jogador(){}

void Jogador::jogarDados(Dado &dadoUm, Dado &dadoDois){
	int pontosDessaJogada = 0;
	pontosDessaJogada = dadoUm.jogueODado() + dadoDois.jogueODado();
	pontuacaoTotal += pontosDessaJogada;

	if (pontuacaoTotal > Jogador::objetivo) {
		situacaoAtual = FORA;
		cout << nomeDoJogador << " marcou " << pontosDessaJogada << " e passou (" 
			 << pontuacaoTotal << ") pontos. " << "\n\n"
			 << nomeDoJogador << " está FORA!" << endl;
	} 
	else {
		cout << nomeDoJogador << " marcou " << pontosDessaJogada << " pontos. " << endl;
		cout << " Total de pontos: " << pontuacaoTotal << endl;
	}
}

bool Jogador::vaiJogarAgora(){
	if (situacaoAtual == FORA){ // Está fora do jogo.
		return false;
	}

	string escolha;

	do {
		cout << nomeDoJogador << ", vai jogar? (s/n): ";
		cin >> escolha;
	} while (escolha != "s" && escolha != "n");

	if (escolha == "s"){
		situacaoAtual = ATIVO; // Vai jogar.
		
		return true;
	}

	situacaoAtual = INATIVO; // Não vai jogar nessa rodada.

	return false;
}