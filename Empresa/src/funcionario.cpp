/*
Disciplina: Linguagem de Programação I
Laboratório I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
Arquivo: funcionario.cpp
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

double Funcionario::getSalario() {
	return salario;
}

Date Funcionario::getAdmissao() {
	return admissao;
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
void Funcionario::setAdmissao(const int& d, const int& m, const int& y){
	admissao.set_day(d);
	admissao.set_month(m);
	admissao.set_year(y);
}
*/

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
						  double salarioFuncionario,
						  Date admissaoFuncionario):
	nome(nomeFuncionario), salario(salarioFuncionario), admissao(admissaoFuncionario){
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
bool Funcionario::operator!= (const Funcionario &funcionarioDiferente){
	return !((*this) == funcionarioDiferente);
}
bool Funcionario::operator== (const Funcionario &funcionarioDiferente){
	return (this->nome== funcionarioDiferente.nome);
}


// Sobrecarga de operadores de extração e inserção.
ostream& operator<< (ostream& output, const Funcionario& algumFuncionario){
	output  << algumFuncionario.nome << "  ---  "
			<< algumFuncionario.salario << "  ---  "
			<< algumFuncionario.admissao << endl;
	return output;
}

istream& operator>> (istream& input, Funcionario& algumFuncionario){
	cout << "Nome do Funcionário: ";
	getline(input, algumFuncionario.nome);
	cout << "Salário: R$ ";
	input >> algumFuncionario.salario;
	cout << "Data de Admissão: ";
	input >> algumFuncionario.admissao;
	return input;
}




