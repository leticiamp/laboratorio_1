/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#ifndef JOGO_H
#define JOGO_H

#include "dado.h"
#include "jogador.h"

#define MAX_JOGADORES 5;

class Jogo {
private:
	int total_jogadores;
	Jogador * jogadores[MAX_JOGADORES];
	int partidas;
	Dado m_d1, m_d2;
	Jogador ganhador = nullptr;
public:
	int getTotal_jogadores();
	int getJogadoresAtivos(); 

	void resultado();
	void novapartida(); 
	void run();
	void addJogador(Jogador *novo_);
	int totalJogando(); 

	Jogo();
	~Jogo();
};

#endif