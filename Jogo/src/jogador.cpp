/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include <iostream>
#include "jogador.h"
#include "dado.h"

using namespace std;

int Jogador::alvo = 20;

string Jogador::getNome() {
	return nome;
}

int Jogador::getPontos() {
	return pontos;
}

Status Jogador::getStatus() {  
	return status;
}

Jogador::Jogador(): nome("Miguel"),
pontos(0),
status(ATIVO){}
	
Jogador::Jogador(string nome_):
nome(nome_),
pontos(0),
status(ATIVO){}

Jogador::~Jogador(){}

void Jogador::JogarDados(Dado &d1, Dado &d2){
	int jogada = d1.jogarDados() + d2.jogarDados();
	pontos += jogada;

	if (pontos > Jogador::alvo) {
		status = INATIVO;
		cout << nome << " fez " << jogada << " e passou (" << pontos << ") pontos. " << endl;
		cout << nome << "está INATIVO" << endl;
	} 
	else {
		cout << nome << " fez " << jogada << " pontos. " << endl;
		cout << " Total de pontos: " << pontos << endl;
	}
}

bool Jogador::jogarAgora(){
	if (status == INATIVO){
		return false;
	}

	string escolha;

	do {
		cout << nome << ", vai jogar? (s/n): ";
		cin >> escolha;
	} while (escolha != "s" && escolha != "n");

	if (escolha == "s"){
		status = ATIVO;
		
		return true;
	}

	status = PARADO;

	return false;
}