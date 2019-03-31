/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include <iostream>
#include <string>
#include "data.h"

using namespace std;

class Funcionario {

public:
	string getNome(); // Método para mostrar o nome do funcionário.
	double getSalario(); // Método para mostrar o salário do funcionário.
	Date getAdmissao(); // Método para mostrar a data de admissão do funcionário.
	void setAdmissao(const int& d, const int& m, const int& y);
	void alteraSalario(float porcentagem); // Atualiza o salário percentualmente.
	// Sobrecarga dos operadores '==' e '!=' para poder comparar dois objetos da classe Funcionario.
	bool operator != (const Funcionario &funcionarioDiferente); 
	bool operator == (const Funcionario &funcionarioDiferente);
	// Método estático para mostrar o número total de funcionários (objetos) instanciados.
	static int getNumeroDeFuncionarios(){return contador;} // Informa quantos são os funcionários. 
	Funcionario(); // Método construtor padrão
	// Método construtor parametrizado.
	Funcionario(string nomeFuncionario, double salarioFuncionario, Date admissaoFuncionario); 
	~Funcionario(); // Método destrutor.
	// Sobrecarga de operadores de extração e inserção das classes "ostream" e "istream".
	friend ostream& operator << (ostream& output, const Funcionario& algumFuncionario);
	friend istream& operator >> (istream& input, Funcionario& algumFuncionario);

private:
	string nome; // Atributo para o nome do funcionário.
	Date admissao; // Instancia um objeto data da classe Data.
	double salario; // Atributo para o salário do funcionário.
	static int contador; // Atributo estático para contar os funcionários.
};

#endif // _FUNCIONARIO_H_
