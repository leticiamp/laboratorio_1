/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/
#include <iostream>
#include "cadastro.h"

int Funcionario::contador = 0;
int Empresa:: contadorDeEmpresas = 0; 

int main(int argc, char const *argv[]){
	
	Cadastro *cadastrando = new Cadastro();
	cadastrando->listaOpcaoInicial();
	return 0;
}
