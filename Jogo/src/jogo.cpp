/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include "jogo.h"

int getM_total_jogadores() {
	return m_total_jogadores;
}

int getjogadoresAtivos() {
	int ativos = 0;
	int i;

	for (i=0; i < m_total_jogadores; i++) {
		if (m_jogadores->getStatus() == ATIVO) {
			ativos ++;
		}
	}

	return ativos;
}

void Jogo::addJogador(Jogador *novo_) {
	if (m_total_jogadores < MAX_JOGADORES) {
		
	}
}