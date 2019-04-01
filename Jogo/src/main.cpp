/*
Disciplina: Linguagem de Programação I
Professor: Silvio	
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include "jogo.h"
#include <iostream>

//int Jogador::alvo = 100;

int main() {
	Jogo jogoDosDados;
   
	jogoDosDados.inserirJogador(new Jogador("Mateus"));
	jogoDosDados.inserirJogador(new Jogador("Lucas"));
	jogoDosDados.inserirJogador(new Jogador("José"));

	jogoDosDados.agoraVai();

	return 0;
}