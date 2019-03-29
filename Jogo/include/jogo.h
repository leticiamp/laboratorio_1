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
	int m_total_jogadores;
	Jogador * m_jogadores[MAX_JOGADORES];
	int m_partidas;
	Dado m_d1;
	Dado m_d2;
public:
	int getM_total_jogadores();
	int getJogadoresAtivos();
	int getM_partidas();

	void resultado();
	void novapartida();
	void run();
	void addJogador(Jogador *novo_);

	Jogo();
	~Jogo();
};

#endif