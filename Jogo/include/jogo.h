/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include "dado.h"
#include "jogador.h"

#define MAXIMO_DE_JOGADORES 5

class Jogo {
private:
	int totalDeJogadores;
	int numeroDaRodada;

	Dado dadoUm, dadoDois;

	Jogador *todosOsJogadores[MAXIMO_DE_JOGADORES];
	Jogador *jogadorQueGanhou = nullptr;
public:
	int getJogadoresAtivos(); 

	void resultadoFinal();
	void proximaRodada(); 
	void agoraVai();
	void inserirJogador(Jogador *novoJogador);
	int totalJogando(); 

	Jogo();
	~Jogo();
};

#endif // JOGO_H