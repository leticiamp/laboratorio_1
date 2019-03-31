/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#include "funcionario.h" // Chama o arquivo de cabeçalho que contém a classe Funcionário.
using namespace std;

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

Date Funcionario::getAdmissao() {
	return admissao;
}

int getNumeroDeFuncionarios(){
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
===========================================
IMPLEMENTAÇÃO DAS SOBRECARGAS DE OPERADORES
===========================================
*/
/*
 Sobrecarrega operadores de comparação para permitir operação entre
dois objetos da classe Funcionario.
*/
bool Funcionario::operator != (const Funcionario &funcionarioDiferente){
	return (Funcionario->nome != funcionarioDiferente.nome);
}
bool Funcionario::operator == (const Funcionario &funcionarioDiferente){
	return (Funcionario->nome == funcionarioDiferente.nome);
}


// Sobrecarga de operadores de extração e inserção.
ostream& operator << (ostream& output, const Funcionario& algumFuncionario){
	output  << algumFuncionario.nome << "  ---  "
			<< algumFuncionario.salario << "  ---  "
			<< algumFuncionario.admissao << endl;
	return output;
}

istream& operator >> (istream& input, Funcionario& algumFuncionario){
	cout << "Nome: "; getline(input, algumFuncionario.nome);
	cout << "Salário: R$"; getline(input, algumFuncionario.salario);
	cout << "Data de Admissão: "; getline(input, algumFuncionario.admissao);
	return input;
}



