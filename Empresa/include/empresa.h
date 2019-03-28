/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef EMPRESA_H
#define EMPRESA_H
#include "funcionario.h"
#define MAXIMO_DE_FUNCIONARIOS 50

class Empresa {
public:
	/* 
	Sobrecarga de operadores que, por referência, operar com
	objetos da classe empresa.
	*/
	friend ostream& operator << ( ostream& output, const Empresa& empresaTal);
	friend istream& operator >> ( istream& input, Empresa& empresaTal);

	static int getTotalFuncionarios(); // Método estático que informa o número de funcionários desta empresa.
	string getNomeEmpresa(); // Método que mostra o nome da empresa.
	string getCnpj(); // Método que mostra o CNPJ da empresa.
	void informaFuncionarios(); // Método que mostra todos os funcionários desta empresa.
	void alteraSalarioEmpresa(float taxaPercentual); // Método que aumenta (ou diminui) salário de todos os funcionários desta empresa percentualmente.
	bool contrataFuncionario(Funcionario *novoFuncionario); // Cria/adiciona funcionários.
	bool demiteFuncionario(string nomeFuncionario); // Exclui funcionário.
	Empresa(); // Construtor padrão.
	Empresa(string nomeEmpresa, string cnpjEmpresa); // Construtor parametrizado.
	~Empresa();	// Destrutor.

private:
	string nomeDestaEmpresa;
	string cnpjDestaEmpresa;
	int totalFuncionarios;
	static int contadorDeFuncionarios;
	// Instancia funcionários até o limite permitido em um vetor com alocação dinâmica.
	// É privado e só pode ser alterado por métodos dessa classe.
	Funcionario *todosOsFuncionarios[MAXIMO_DE_FUNCIONARIOS];
};	

#endif // EMPRESA_H

