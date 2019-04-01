/*
Disciplina: Linguagem de Programação I
Laboratório I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
Arquivo: cadastro.h 
===========================================================================
*/

#ifndef _CADASTRO_H_
#define _CADASTRO_H_
#include "empresa.h"

using namespace std;
#define MAXIMO_DE_EMPRESAS 10

class Cadastro{
public:
	char listaOpcaoInicial(string abasOrientacao); // Método que mostra opções iniciais.
	char listaOpcaoSecundaria(string abasOrientacao); // Método que mostra opções secundárias da empresa escolhida.
	char listaOpcoesDeAlteracao(string abasOrientacao); // Método que apresenta possibilidades de alteracão.
	int pesquisarEmpresa(string algumaEmpresa); // Método que pesquisa uma empresa pelo nome.
	void mostrarTodasAsEmpresas(); // Método para listar todas as empresas já cadastradas.
	void inserirEmpresa(); // Método para criar uma nova empresa.
	void excluirEmpresa(); // Método para remover uma referida empresa.
	void mostrarFuncionarios(); // Método para listar os funcionários de uma referida empresa.
	void alteraSalario(); // Método para modificar os salários dos funcionários de uma referida empresa.
	void inserirFuncionario(); // Método para adicionar funcionário à referida empresa.
	void excluirFuncionario(); // Método para demitir funcionário de uma referida empresa.
	void mediaDeFuncionarios(); // Método para apresentar o número médio de funcionários por empresa.
//	void mostrarFuncionariosEmExperiencia(); // Funcionários contratados a menos de 90 dias.
	Cadastro(); // Método construtor padrão para instanciar uma empresa.
	~Cadastro(); // Método destrutor.
private:
	Empresa *empresas[MAXIMO_DE_EMPRESAS];
	int totalDeEmpresas;
};

#endif // _CADASTRO_H_