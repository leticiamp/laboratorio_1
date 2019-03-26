/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#include <iostream>
#include "jogador.h"

using namespace std;

string Jogador::getNome() {
	return m_nome;
}

int Jogador::getPontos() {
	return m_pontos;
}

int Jogador::getAlvo() {
	return m_alvo;
}

Status Jogador::getStatus() {
	return m_status;
}

Jogador::Jogador():
m_nome("Miguel"),
m_pontos(0),
m_status(ATIVO){}
	
Jogador::Jogador(string nome_):
m_nome(nome_),
m_pontos(0),
m_status(ATIVO){}

Jogador::~Jogador(){}

void Jogador::Jogar(Dado &d1, Dado &d2){
	int jogada = d1.jogar() + d2.jogar();
	m_pontos += jogada;

	if (m_pontos > m_alvo) {
		m_status = INATIVO;
		cout << m_nome << " fez " << jogada << " e passou (" << m_pontos << ") pontos. " << endl;
		cout << m_nome << "está INATIVO" << endl;
	} 
	else {
		cout << m_nome << " fez " << jogada << " pontos. " << endl;
		cout << " Total de pontos: " << m_pontos << endl;
	}
}

bool Jogador::jogarAgora(){
	if (m_status == INATIVO){
		return false;
	}

	string escolha;

	do {
		cout << m_nome << ", vai jogar? (sim/nao): ";
		cin >> "Você escolheu " << escolha;
	} while (escolha != "sim" && escolha != "nao");

	if (escolha == "sim"){
		m_status = ATIVO;
		
		return true;
	}

	m_status = PARADO;

	return false;
}