/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio

Atividade: Empresa
===========================================================================
*/


#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include <string>
#include <random>
#include <vector>

using namespace std;

class Empresa{

public:
	string getFuncionarios();
	string setFuncionarios();

	//static int distanciaTotal; // Atributo público estático.
	//static int getDistanciaTotal();
	//int getDistanciaPercorrida();
	//int getQuantidadePulos();
	//void setIdentificador(int id);
	//void setDistanciaPercorrida(int dp);
	//void setQuantidadePulos(int qp);
	//void setPulo(int pl);
	//int getPulo();
	//void pular();
	//string getEspecie();
	//void setEspecie(string nome);
	Empresa(); // Método Construtor para as empresas.
	~Empresa(); // Método Destrutor para as empresas.

private:
	string nome;
	int cnpj;
	vector<string> funcionarios; //lista de funcionarios
	//int identificador; //Atributo privado para identificar o sapo.
	//int distanciaPercorrida; // Atributo privado para armazenar a distância percorrida por um sapo.
	//int quantidadePulos; // Atributo privado para armazenar o número de pulos efetuados por um sapo.
	//int pulo;
	//string especie;
	//random_device rd;
	//default_random_engine gen;
	//uniform_int_distribution<>dis;
};

class Funcionario(){
	public:
		string nome;
		float salario;
		//inserir uma classe para a data aqui...
	private:


};*/
/*
class Data(){
	//ver no link do arquivo do lab
}
*/

/*// MÉTODO CONSTRUTOR // ====================
Sapo::Sapo(int sp):rd(), gen(rd()), dis(1, 7){
	
	setDistanciaPercorrida(0);
	setQuantidadePulos(0);
	setPulo(round(dis(gen)));
	
	setIdentificador(sp);
	
	if (identificador == 1)
	{
		setEspecie("Sapo Cururu");
	}
	else if (identificador == 2)
	{
		setEspecie("Sapo Boi");
	}
	else if (identificador == 3)
	{
		setEspecie("Sapo Brejeiro");
	}
}
*/
// MÉTODO DESTRUTOR // =====================
/*
Sapo::~Sapo(){
	//Destrutor do método construtor Sapo.
}
*/
/*	
// MÉTODO QUE FAZ O SAPO PULAR // ==========
void Sapo::pular(){
	switch(Sapo::getDistanciaPercorrida() < Sapo::getDistanciaTotal()){
		case true:
			distanciaPercorrida = distanciaPercorrida + getPulo();
			quantidadePulos += 1;

		case false:
			break;
	}
}
*/

// MÉTODOS GETTERS // ======================
	
string Empresa::getFuncionarios(string nome){
	return funcionario[nome];
}
	
	
	/*
int Sapo::getDistanciaTotal(){
	return distanciaTotal;
}
int Sapo::getPulo(){
	return pulo;
}
string Sapo::getEspecie(){
	return especie;
}
int Sapo::getDistanciaPercorrida(){
	return distanciaPercorrida;
}
int Sapo::getQuantidadePulos(){
	return quantidadePulos;
}
int Sapo::getIdentificador(){
	return identificador;
}
*/
//MÉTODOS SETTERS//=========================

void Empresa::string setFuncionarios(string nome){
	// criar um algoritmo para criar um funcionário, chamando a classe...
	
	
}
	/*
void Sapo::setPulo(int pl){
	pulo = pl;
}
void Sapo::setEspecie(string nome){
	especie = nome;
}
void Sapo::setIdentificador(int id){
	identificador = id;
}
void Sapo::setDistanciaPercorrida(int dp){
	distanciaPercorrida = dp;
}
void Sapo::setQuantidadePulos(int qp){
	quantidadePulos = qp;
}
*/
#endif // CLASSE_H_INCLUDED
