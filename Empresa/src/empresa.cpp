/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#include "empresa.h"
using namespace std;

/* 
=================================
MÉTODO PARA CONTRATAR FUNCIONÁRIO
=================================
*/

bool Empresa::contrataFuncionario(Funcionario *novoFuncionario){
	if (totalFuncionarios <= MAXIMO_DE_FUNCIONARIOS){
		int i = 0;
		while(i < totalFuncionarios){ // Pesquisa sequencialmente pra saber se o funcionário já está contratado.
			if ((*novoFuncionario) == (todosOsFuncionarios[i])){
				cout << "Esse funcionário já trabalha na empresa!" << endl;
				delete novoFuncionario;
				return FALSE;
			}
			i++;
		}
		totalFuncionarios++; // Contabiliza uma contratação.
		todosOsFuncionarios[totalFuncionarios] = novoFuncionario; //Efetivamente, a empresa contrata.
		return TRUE;	
	}
	else{ // Se passar do número limite, não contrata.
		return FALSE;
	}
}

/* 
===============================
MÉTODO PARA DEMITIR FUNCIONÁRIO
===============================
*/

bool Empresa::demiteFuncionario(string nomeFuncionario){ // Pesquisa pelo nome, dentre os funcionários, para demití-lo.
	bool demitido = FALSE;
	for (int i = 0; i < totalFuncionarios; i++)
	{
		if ((todosOsFuncionarios[i]->getNome()) == nomeFuncionario){
			totalFuncionarios--;
			delete todosOsFuncionarios[i];
			demitido = TRUE;
		}
		if (demitido == TRUE){ // Reposiciona os funcionários, a partir do demitido, para uma posição anterior na lista.
			todosOsFuncionarios[i] = todosOsFuncionarios[i+1];
		}
	}
	return demitido;
}

/* 
========================================================
MÉTODO PARA MOSTRAR TODOS OS FUNCIONÁRIOS DE UMA EMPRESA
========================================================
*/
// Método que lista todos os funcionários de uma referida empresa.
void Empresa::informaFuncionarios(){
	cout << "A empresa " << m_nomeEmpresa <<
	" possui os seguintes funcionários:" << endl;
	int i = 0;
	while (i < totalFuncionarios)
	{
		cout << (*todosOsFuncionarios[i]) << endl;
		i++;
	}
}

/* 
==============================================
MÉTODO PARA AUMENTAR O SALÁRIO PERCENTUALMENTE
DE TODOS OS FUNCIONÁRIOS DE UMA MESMA EMPRESA
==============================================
*/
void Empresa::alteraSalarioEmpresa(float taxaAumento){
	int i = 0;
	while (i < totalFuncionarios)
	{
		todosOsFuncionarios[i]->alteraSalario(taxaPercentual);
		i++;
	}
}

/* 
============================================
MÉTODO GETTERS (PARA MOSTRAR ALGUM ATRIBUTO)
============================================
*/

string Empresa::getCnpj(){
	return cnpjDestaEmpresa;
}

int Empresa::getTotalFuncionarios() {
	return totalFuncionarios;
}

Funcionario **Empresa::informaFuncionarios(){
	return todosOsFuncionarios;
}

/* 
========================================
MÉTODOS CONSTRUTORES DA CLASSE "Empresa"
========================================
*/

Empresa::Empresa(): // Construtor padrão. 
					cnpjDestaEmpresa("00.000.000/0000-00"),
					nomeDestaEmpresa("Empty Name"),
					totalFuncionarios(0)
					{
					contadorDeFuncionarios += 1;
}

Empresa::Empresa(string nomeEmpresa, string cnpjEmpresa): // Construtor parametrizado.
					cnpjDestaEmpresa(nomeEmpresa),
					nomeDestaEmpresa(cnpjEmpresa),
					totalFuncionarios(0)
					{
					contadorDeFuncionarios += 1;
}

/* 
====================================
MÉTODO DESTRUTOR DA CLASSE "EMPRESA"
====================================
*/

Empresa::~Empresa(){ //Ao destruir a empresa, destrói também todos os seus funcionários.
	int i = 0;
	while(i < totalFuncionarios){
		i++;
		delete totalFuncionarios[i-1];
	}
}

/* 
====================================
SOBRECARGA DE OPERADORES
====================================
*/
ostream& operator << ( ostream& output, const Empresa& empresaTal){
	output 	<< empresaTal.cnpjDestaEmpresa << "   ---    "
			<< empresaTal.nomeDestaEmpresa << "   ---    "
			<< empresaTal.totalFuncionarios << "funcionários contratados."
			<< endl;
	return output;
}

istream& operator >> ( istream& input, Empresa& empresaTal){
	cout << " CNPJ: ";
	getline( input, empresaTal.cnpjDestaEmpresa);
	cout << " Nome da Empresa: ";
	getline( input, empresaTal.cnpjDestaEmpresa);
	return input;
}