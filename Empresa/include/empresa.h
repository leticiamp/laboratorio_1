/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

MAXIMO_DE_FUNCIONARIOS 50;

class Empresa {
	private:
		string m_nomeEmpresa;
		string m_cnpj;
		//temos que instanciar aqui um objeto do tipo funcionario 
		int m_totalFuncionarios;
		int m_contador;
	public:
		Empresa(string nome_, string cnpj_);
		~Empresa();

		string getNomeEmpresa();
		string getCnpj();
		int getM_totalFuncionarios();

		void aumentaSalario(float taxaAumento);
		void informaFuncionarios();

		bool contrataFuncionario(string nome_); // Cria/adiciona funcionários.
		bool demiteFuncionario(string nome_); // Exclui funcionário.
};	

#endif // EMPRESA_H

