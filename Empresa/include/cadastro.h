/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#ifndef _CADASTRO_H_
#define _CADASTRO_H_

using namespace std;
#define MAXIMO_DE_EMPRESAS 10

class Cadastro{
public:
	char listaOpcaoInicial(string opcaoInicial); // Método que mostra opções iniciais.
	char listaOpcaoSecundaria(string opcaoSecundaria); // Método que mostra opções secundárias relativas à empresa escolhida.
	char listaOpcoesDeAlteracao(string opcaoAlteracao); // Método que apresenta possibilidades de edição/mudança.
	int pesquisarEmpresa(string algumaEmpresa); // Método que pesquisa uma empresa pelo nome.
	void mostrarTodasAsEmpresas(); // Método para listar todas as empresas já cadastradas.
	void inserirEmpresa(); // Método para criar uma nova empresa.
	void excluirEmpresa(); // Método para remover uma referida empresa.
	void mostrarFuncionarios(); // Método para listar os funcionários de uma referida empresa.
	void alteraSalario(); // Método para modificar os salários dos funcionários de uma referida empresa.
	void inserirFuncionario(); // Método para adicionar funcionário à referida empresa.
	void excluirFuncionario(); // Método para demitir funcionário de uma referida empresa.
	void mediaDeFuncionarios(); // Método para apresentar o número médio de funcionários por empresa.

	Cadastro(); // Método construtor padrão para instanciar uma empresa.
	~Cadastro(); // Método destrutor.
private:
	Empresa *empresas[MAXIMO_DE_EMPRESAS];
	int totalDeEmpresas;
}

#endif // _CADATRO_H_