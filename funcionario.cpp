#include "funcionario.h"

string Funcionario::getNome() {
	return m_nome;
}

double Funcionario::getSalario() {
	return m_salario;
}

Data Funcionario::getAdmissao() {
	return m_admissao;
}

void Funcionario::status() {
	
}

Funcionario::Funcionario():
	m_nome("Lucas"),
	m_salario(0.0),
	m_admissao(Data(10,6,2013)) {
}


