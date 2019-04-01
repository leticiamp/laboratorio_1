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

int Jogo::getJogadoresAtivos() {
	int jogadoresAtivos = 0;
	int j = 0;

	while (j < totalDeJogadores) {
		if (todosOsJogadores[j]->getSituacaoAtual() == ATIVO) {
			jogadoresAtivos ++;
		}
		j++;
	}

	return jogadoresAtivos;
}

void Jogo::resultadoFinal() {
	cout << "_____________________________________________" << endl;
	cout << "++++++++++++++ RESULTADO FINAL ++++++++++++++\n\n\n" << endl;
	//Mostrar o resultado de todos os jogadores
	for (int i = 0; i < totalDeJogadores; i++) {
		cout << todosOsJogadores[i]->getNomeDoJogador() << " obteve "
			 << todosOsJogadores[i]->getPontuacaoTotal() << " pontos.\n\n " << endl;
		//verificar se o jogador atual é o vencedor
		if (todosOsJogadores[i] == jogadorQueGanhou) {
			cout << todosOsJogadores[i]->getNomeDoJogador() << " venceu!\n\n" << endl;
		}
		else {
			cout << todosOsJogadores[i]->getNomeDoJogador() << " perdeu!\n\n" << endl;
		}
	}

}

void Jogo::proximaRodada() {
	int i = 0;
	cout << "____________________________________________"<< endl;
	cout << "____________________________________________"<< endl;
	cout << "Partida " << numeroDaRodada << "\n\n" << endl;
	
	while (i < totalDeJogadores) {
		//Verificando se há somente um jogador jogando
		if (todosOsJogadores[i]->getSituacaoAtual() != FORA && totalJogando() == 1) {
			jogadorQueGanhou = todosOsJogadores[i];
			break;
		}

		if (todosOsJogadores[i]->vaiJogarAgora()) {
			
			todosOsJogadores[i]->jogarDados(dadoUm, dadoDois);

			//verifica se o jogador alcançou o objetivo.
			if (todosOsJogadores[i]->getPontuacaoTotal() == Jogador::getObjetivo()) {	
				jogadorQueGanhou = todosOsJogadores[i];
				break;
			}
		}
		i++;
	}
	cout << "____________________________________________" << endl;
	cout << "____________________________________________" << endl;

	numeroDaRodada++;
}

void Jogo::agoraVai() {
	while(totalJogando() > 1 && getJogadoresAtivos() > 0 && jogadorQueGanhou == nullptr) {
		proximaRodada();
	}
	int maiorNumero = 0;
	if (jogadorQueGanhou == nullptr){
		int j = 0;
		while(j < totalDeJogadores){
			if (todosOsJogadores[j]->getSituacaoAtual() != FORA && 
				todosOsJogadores[j]->getPontuacaoTotal() > maiorNumero){
				jogadorQueGanhou = todosOsJogadores[j];
				maiorNumero = todosOsJogadores[j]->getPontuacaoTotal();
			} 
		j++;	
		}
	}
	resultadoFinal();
}

void Jogo::inserirJogador(Jogador *novoJogador) {
	if (totalDeJogadores < MAXIMO_DE_JOGADORES) {
		todosOsJogadores[totalDeJogadores++] = novoJogador;
	}
}

int Jogo::totalJogando() {
	//numero de jogadores jogando
	int jogandoAgora = 0;
	//contar quantos jogadores estao jogando (status ativo ou parado)
	for (int i = 0; i < totalDeJogadores; i++) {
			if (todosOsJogadores[i]->getSituacaoAtual() == ATIVO ||
				todosOsJogadores[i]->getSituacaoAtual() == INATIVO) {
				jogandoAgora ++;
			}
	}

	return jogandoAgora;
}

Jogo::Jogo():totalDeJogadores(0), numeroDaRodada(0) {}

Jogo::~Jogo(){}