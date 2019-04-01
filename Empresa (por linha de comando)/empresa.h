/*
Disciplina: Linguagem de Programação I
Laboratório I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
Arquivo: empresa.h
===========================================================================
*/

#ifndef _EMPRESA_H_
#define _EMPRESA_H_
#include "funcionario.h"

using namespace std;

#define MAXIMO_DE_FUNCIONARIOS 50

class Empresa {
private:
	string nomeDestaEmpresa;
	string cnpjDestaEmpresa;
	int totalFuncionarios;
	static int contadorDeEmpresas;
	// Instancia funcionários até o limite permitido em um vetor com alocação dinâmica.
	// É privado e só pode ser alterado por métodos dessa classe.
	Funcionario *todosOsFuncionarios[MAXIMO_DE_FUNCIONARIOS];
public:
	/* 
	Sobrecarga de operadores que, por referência, operar com
	objetos da classe empresa.
	*/
	friend ostream& operator << ( ostream& output, const Empresa& empresaTal);
	friend istream& operator >> ( istream& input, Empresa& empresaTal);

	static int getTotalEmpresas(); // Método estático que informa o número de empresas existentes, inclusive essa.
	string getNomeEmpresa(); // Método que mostra o nome da empresa.
	string getCnpj(); // Método que mostra o CNPJ da empresa.
	int getTotalFuncionarios(); // Método que mostra o número de funcionários em uma empresa.
	void informaFuncionarios(); // Método que mostra todos os funcionários desta empresa.
//	void informaFuncionariosEmExperiencia(); // Lista funcionários em experiência.
	void alteraSalarioEmpresa(float taxaPercentual); // Método que aumenta (ou diminui) salário de todos os funcionários desta empresa percentualmente.
	bool contrataFuncionario(Funcionario *novoFuncionario); // Cria/adiciona funcionários.
	bool demiteFuncionario(string nomeFuncionario); // Exclui funcionário.
	//Funcionario **getInformaFuncionarios();
	Empresa(); // Construtor padrão.
	Empresa(string nomeEmpresa, string cnpjEmpresa); // Construtor parametrizado.
	~Empresa();	// Destrutor.
};	

#endif // _EMPRESA_H_

