//QUESTAO 2 - LABORATORIO 1

#ifndef JOGADOR_H
#define JOGADOR_H

class Jogador {
private:
	string m_nome;
	int m_pontos;

public:
	string getNome();
	int getPontos();

	Jogador(string nome_);
	~Jogador();
}

#endif