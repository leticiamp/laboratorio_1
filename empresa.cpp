/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#include "empresa.h"
using namespace std;

/* 
========================================
MÉTODOS CONSTRUTORES DA CLASSE "Empresa"
========================================
*/

Empresa::Empresa(): // Construtor padrão.
					m_cnpj("00.000.000/0000-00"),
					m_nomeEmpresa("Empty Name"),
					m_totalFuncionarios(0)
					{
					m_contador += 1;
}

Empresa::Empresa(string nomeEmpresa_, string cnpjEmpresa_): // Construtor parametrizado.
					m_cnpj(nomeEmpresa_),
					m_nomeEmpresa(cnpjEmpresa_),
					m_totalFuncionarios(0)
					{
					m_contador += 1;
}

/* 
====================================
MÉTODO DESTRUTOR DA CLASSE "EMPRESA"
====================================
*/

Empresa::~Empresa(){ //Ao destruir a empresa, destrói também todos os seus funcionários.
	int i = 0;
	while(i < m_totalFuncionarios){
		i++;
		delete m_nome[i-1];
	}
}

/* 
=================================
MÉTODO PARA CONTRATAR FUNCIONÁRIO
=================================
*/

bool Empresa::contrataFuncionario(Funcionario *novoFuncionario){
	if (m_totalFuncionarios <= MAXIMO_DE_FUNCIONARIOS){
		int i = 0;
		while(i < m_totalFuncionarios){ // Pesquisa sequencialmente pra saber se o funcionário já está contratado.
			if ((*novoFuncionario) == (m_nome[i])){
				cout << "Esse funcionário já pertence à empresa." << endl;
				delete novoFuncionario;
				return false;
			}
			i++;
		}
		m_totalFuncionarios++; // Contabiliza uma contratação.
		m_nome[m_totalFuncionarios] = novoFuncionario; //Efetivamente, a empresa contrata.
		return true;	
	}
	else{ // Se passar do número limite, não contrata.
		return false;
	}
}

/* 
===============================
MÉTODO PARA DEMITIR FUNCIONÁRIO
===============================
*/

bool Empresa::demiteFuncionario(string nome_){ // Pesquisa pelo nome, dentre os funcionários, para demití-lo.
	bool demitido = false;
	for (int i = 0; i < m_totalFuncionarios; i++)
	{
		if ((m_nome[i]->getNome()) == nome_){
			m_totalFuncionarios--;
			delete m_nome[i];
			demitiu = true;
		}
		if (demitido == true){
			m_nome[i] = m_nome[i+1]; // Reposiciona os funcionários, a partir do demitido, para uma posição anterior na lista.
		}
	}
	return demitido;
}

/* 
========================================================
MÉTODO PARA MOSTRAR TODOS OS FUNCIONÁRIOS DE UMA EMPRESA
========================================================
*/

void Empresa::informaFuncionarios(){
	cout << "A empresa " << m_nomeEmpresa << " possui os seguintes funcionários." << endl;
	int i = 0;
	while (i < m_totalFuncionarios)
	{
		cout << (*nome[i]) << endl;
		i++;
	}
}

/* 
==============================================
MÉTODO PARA AUMENTAR O SALÁRIO PERCENTUALMENTE
DE TODOS OS FUNCIONÁRIOS DE UMA MESMA EMPRESA
==============================================
*/

void Empresa::aumentaSalario(float taxaAumento){
	int i = 0;
	while (i < m_totalFuncionarios)
	{
		m_nome[i]->aumentaSalario(taxaAumento);
		i++;
	}
}

/* 
============================================
MÉTODO GETTERS (PARA MOSTRAR ALGUM ATRIBUTO)
============================================
*/

string Empresa::getCnpj(){
	return m_cnpj;
}

int getM_totalFuncionarios() {
	return m_totalFuncionarios;
}


//Faltam getters para mostrar os funcionários
