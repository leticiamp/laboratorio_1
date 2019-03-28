/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#include "funcionario.h" // Chama o arquivo de cabeçalho que contém a classe Funcionário.

/*
=========================================
MÉTODOS "GETTERS"
=========================================
*/

string Funcionario::getNome() {
	return nome;
}

float Funcionario::getSalario() {
	return salario;
}

Data Funcionario::getAdmissao() {
	return admissao;
}

static int getNumeroDeFuncionarios(){
	return contador;
}
/*
=========================================
MÉTODOS "SETTERS"
=========================================
*/

void Funcionario::alteraSalario(float porcentagem) {
	salario = salario * ((porcentagem/100) + 1);
}

/*
=========================================
MÉTODOS CONSTRUTORES E DESTRUTOR
=========================================
*/
// Construtor padrão.
Funcionario::Funcionario():
	nome("Empty"),
	salario(0.0),
	admissao(Date(1, 1, 2000)) {
}
// Construtor parametrizado.
Funcionario::Funcionario( string nomeFuncionario,
						  float salarioFuncionario,
						  Date admissaoFuncionario):
	nome(nomeFuncionario),
	salario(nomeFuncionario),
	admissao(admissaoFuncionario) 
	{
	contador++;
}

Funcionario::~Funcionario(){
	contador--;
}

/*
=========================================
IMPLEMENTAÇÃO DAS SOBRECARGAS DE OPERADORES
=========================================
*/

/////+++++++++++++ENTENDER E ADICIONAR O "STREAM" AQUI

// Sobrecarrega operadores de comparação para permitir operação entre dois objetos da classe Funcionario.
bool Funcionario::operator == (const Funcionario &funcionarioDiferente){
	return (nome == funcionarioDiferente.nome);
}

bool Funcionario::operator != (const Funcionario &funcionarioDiferente){
	return (nome != funcionarioDiferente.nome);
}