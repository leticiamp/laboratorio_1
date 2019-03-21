/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

class Empresa {
	private:
		string m_nome_empresa;
		int m_cnpj;
		int m_total_funcionarios;
	public:
		Empresa(string nome_, int cnpj_);
		~Empresa();

		string getNome_empresa();
		int getCnpj();
		int getTotalFuncionarios();
	
};

#endif