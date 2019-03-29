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

enum Status{ATIVO, INATIVO, PARADO};

class Jogador {
private:
	string nome; 
	int pontos;
	int alvo;
	Status status;

public:
	string getNome();
	int getPontos();
	int getAlvo();
	Status getStatus();

	void JogarDados(Dado &d1, Dado &d2);
	bool JogarAgora(); //retorna a escolha do jogador para jogar ou nao a partida

	Jogador();
	Jogador(string nome_);
	~Jogador();
}

#endif