//QUESTAO 2 - LABORATORIO 1

#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "dado.h"

enum Status{ATIVO, INATIVO, PARADO};

class Jogador {
private:
	string m_nome; 
	int m_pontos;
	int m_alvo;
	Status m_status;

public:
	string getNome();
	int getPontos();
	int getAlvo();
	Status getStatus();

	void Jogar(Dado &d1, Dado &d2);
	bool JogarAgora();

	Jogador();
	Jogador(string nome_);
	~Jogador();
}

#endif