/*
Disciplina: Linguagem de Programação I
Laboratório I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
Arquivo: main.cpp 
===========================================================================
*/
#include <iostream>
#include "cadastro.h"

int Funcionario::contador = 0;
int Empresa:: contadorDeEmpresas = 0; 

int main(int argc, char const *argv[]){
	
	Cadastro cadastrando;
	cadastrando.listaOpcaoInicial("MENU PRINCIPAL");
	return 0;
}
