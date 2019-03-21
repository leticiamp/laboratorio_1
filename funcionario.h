/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "data.h"

using std::string;

class Funcionario() {
	private:
		string m_nome;
		float m_salario;
		Data m_admissao;
	public:
		string getNome();
		float getSalario();
		Data getAdimissao();

		Funcionario(string nome_, float salario_, Data admissao_);
		~Funcionario();

		void statusSalario(float porcentagem);
};

#endif