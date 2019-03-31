/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include "jogo.h"
#include <iostream>

int Jogador::alvo = 100;

int main() {
	Jogo teste;

	teste.addJogador(new Jogador("Mateus"));
	teste.addJogador(new Jogador("Lucas"));
	teste.addJogador(new Jogador("José"));

	teste.run();

	return 0;
}