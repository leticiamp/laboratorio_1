/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include "jogador.h"
#include "jogo.h"
#include <iostream>

using namespace std;

int getjogadoresAtivos() {
	int ativos = 0;
	int i;

	for (i=0; i < total_jogadores; i++) {
		if (jogadores[i]->getStatus() == ATIVO) {
			ativos ++;
		}
	}

	return ativos;
}

void resultado() {
	cout << "____________________________________________" << endl;
	cout << "Resultado do Jogo" << endl;
	//Mostrar o resultado de todos os jogadores
	for (int i=0; i < total_jogadores; i++) {
		cout << jogadores[i] -> getNome() << "obteve" << jogadores[i] -> getPontos() << "pontos" << endl;
		//verificar se o jogador atual é o vencedor
		if (jogadores[i] == ganhador) {
			cout << jogadores[i] -> getNome() << "venceu" << endl;
		}
		else {
			cout << jogadores[i] -> getNome() << "perdeu" << endl;
		}
	}

}

void Jogo:: novaPartida() {
	int i = 0;
	cout << "____________________________________________"<< endl;
	cout << "Partida " << partidas << endl;
	
	while (i < total_jogadores) {
		//Verificando se há somente um jogador jogando
		if (jogadores[i]->getStatus() != INATIVO && totalJogando() == 1) {
			ganhador = jogadores[i];
			return;
		}

		if (jogadores[i] -> jogarAgora()) {
			jogadores[i] -> JogarDados(d1, d2);

			//verifica se o jogador alcançou o alvo
			if (jogadores[i] -> getPontos() == Jogador::getAlvo()) {	
				ganhador = jogadores[i];
				return;
			}
		}
		i++;
	}

	cout << "____________________________________________"<< endl;

	partidas ++;
}

void Jogo:: run() {
	while(totalJogando() > 1 && getJogadoresAtivos() > 0 && ganhador == nullptr) {
		novaPartida();
	}
	resultado();
}

void Jogo::addJogador(Jogador *novo_) {
	if (total_jogadores < MAX_JOGADORES) {
		jogadores[total_jogadores ++] = novo_;
	}
}

int Jogo::totalJogando() {
	//numero de jogadores jogando
	int jogando = 0;
	//contar quantos jogadores estao jogando (status ativo ou parado)
	for (int i = 0; i < total_jogadores; i++) {
			if (jogadores[i] -> getStatus() == ATIVO || jogadores[i] -> getStatus() == PARADO) {
				jogando ++;
			}
	}

	return jogando;
}

Jogo::Jogo():total_jogadores(0), partidas(0) {}

Jogo::~Jogo() {}