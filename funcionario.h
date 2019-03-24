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

using namespace std;

class Funcionario() {
	private:
		string m_nome;
		float m_salario;
		Data m_admissao; // Instancia um objeto da classe Data.
	public:
		string getNome();
		float getSalario();
		Data getAdmissao();

		Funcionario();
		Funcionario(string nome_, float salario_, Data admissao_);
		~Funcionario();

		void statusSalario(float porcentagem_);


};

#endif // FUNCIONARIO_H