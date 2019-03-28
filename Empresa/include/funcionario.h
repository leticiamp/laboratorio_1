/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Funcionario {

public:
	string getNome(); // Método para mostrar o nome do funcionário.
	float getSalario(); // Método para mostrar o salário do funcionário.
	Date getAdmissao(); // Método para mostrar a data de admissão do funcionário.
	Funcionario(); // Método construtor padrão
	// Método construtor parametrizado.
	Funcionario(string nomeFuncionario, float salarioFuncionario, Data admissaoFuncionario); 
	~Funcionario(); // Método destrutor.
	void alteraSalario(float porcentagem); // Atualiza o salário percentualmente.
	// Sobrecarga dos operadores '==' e '!=' para poder comparar dois objetos da classe Funcionario.
	bool operator != (const Funcionario &funcionarioDiferente); 
	bool operator == (const Funcionario &funcionarioDiferente);
	// Método estático para mostrar o número total de funcionários (objetos) instanciados.
	static int getNumeroDeFuncionarios();
	/*
	++++++++++ENTENDER E ADICIONAR LINHAS FRIENDS++++++++++++++
	*/

private:
	string nome; // Atributo para o nome do funcionário.
	Date admissao; // Instancia um objeto data da classe Data.
	float salario; // Atributo para o salário do funcionário.
	static int contador; // Atributo estático para contar os funcionários.

};

#endif // FUNCIONARIO_H