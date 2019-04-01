/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/

#ifndef _DADO_H_
#define _DADO_H_

#include <random>

using namespace std;

class Dado {
public:
	Dado(); // Método construtor padrão.
	~Dado(); // Método destrutor.
	int jogueODado(); // Método de lançamento dos dados que retorna a soma dos valores do lançamento.
	int getValorAcumulado(); // Método que mostra o valor acumulado.

private:
	int resultado;
	int valorAcumulado;
	// Caracterização do lançamento randômico.
	random_device rd; 
	default_random_engine gen;
	uniform_int_distribution<>dis;

};

#endif // _DADO_H_