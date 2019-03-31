/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
LABORATÓRIO I - QUESTÃO 2 - JOGO DOS DADOS
===========================================================================
*/
#include <random>

#include "dado.h"

using namespace std;

/*
==================================
MÉTODO CONSTRUTOR DA CLASSE "Dado"
==================================
*/

Dado::Dado():gen(rd()), dis(1, 6){
	resultado = round(dis(gen));
}

Dado::getValor_acumulado(){
	return valor_acumulado;
}