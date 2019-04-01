/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "dado.h"

using namespace std;

enum Situacao{ATIVO, INATIVO, FORA};

class Jogador {
private:
	string nomeDoJogador;
	int pontuacaoTotal;
	Situacao situacaoAtual;
	static int objetivo; // meta de pontos a ser atingida

public:
	string getNomeDoJogador();
	int getPontuacaoTotal();
	Situacao getSituacaoAtual();
	static int getObjetivo(){
		return objetivo;
	}

	void jogarDados(Dado &dadoUm, Dado &dadoDois);
	bool vaiJogarAgora(); //retorna a escolha do jogador para jogar ou nao a partida

	Jogador();
	Jogador(string novoJogador);
	~Jogador();
};

#endif // JOGADOR_H