/*
Disciplina: Linguagem de Programação I
Laboratório I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
Arquivo: cadastro.cpp
===========================================================================
*/

#include <iostream>
#include "cadastro.h"

using namespace std;
/*
========================================================
MÉTODOS CONSTRUTOR E DESTRUTOR DE CADASTROS DE EMPRESAS.
========================================================
*/


/*
Método Construtor padrão para instanciar objeto da classe Cadastro, 
o qual é inicializado com nenhuma empresa.
*/
Cadastro::Cadastro(): totalDeEmpresas(0){

}

/*
Método Destrutor que exclui um cadastro e, simultaneamente, exclui 
também as respectivas empresas cadastradas.
*/
Cadastro::~Cadastro(){
	int i = 0;
	while ( i < totalDeEmpresas){
		delete empresas[i];
		i++;
	}
}

/*
==========================
MÉTODOS GETTERS E SETTERS.
==========================
*/

void Cadastro::mediaDeFuncionarios(){
	if ((float) Funcionario::getNumeroDeFuncionarios() > 0 &&
		 Empresa::getTotalEmpresas() > 0){
		cout << " A Média de Funcionários é "
		 << ((float) Funcionario::getNumeroDeFuncionarios()/Empresa::getTotalEmpresas())
		 << endl;
	}
	else{
		cout << " Desculpe! Não foi possível informar a média." << endl;
	}
}

char Cadastro::listaOpcaoInicial(string abasOrientacao){ // Método que mostra as alternativas iniciais.
	char alternativa = '0';
	do{
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   "  << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: " << "\n"
			 << " Digite '1' para: Média de Funcionários por Empresa" << "\n"
			 << " Digite '2' para: Opções de Empresa" << "\n"
			 << " Digite '3' para: Opções de Funcionário " << "\n"
			 << " Digite '4' para: Sair deste Menu" << "\n"
			 << " Alternativa escolhida: "; 
			 cin >> alternativa; cin.ignore();
		switch(alternativa){
			case '1' : mediaDeFuncionarios();
				break;
			case '2' : listaOpcaoSecundaria("\n Menu Inicial > Empresa ");
				break;
			case '3' : listaOpcoesDeAlteracao("\n Menu Inicial > Funcionário ");
				break;
			case '4' : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != '4');
	return alternativa;
}

char Cadastro::listaOpcaoSecundaria(string abasOrientacao){ // Método que relaciona opcões secundárias relativas à empresa escolhida.
	char alternativa;
	do {
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   " << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: " << "\n"
			 << " Digite '1' para: Listar todas as empresas" << "\n"
			 << " Digite '2' para: Editar funcionários de uma empresa" << "\n"
			 << " Digite '3' para: Adicionar uma empresa " << "\n"
			 << " Digite '4' para: Remover uma empresa " << "\n"
			 << " Digite '5' para: Sair " << "\n"
			 << " Alternativa escolhida: "; cin >> alternativa; cin.ignore();
		switch(alternativa){
			case '1' : mostrarTodasAsEmpresas();
				break;
			case '2' : listaOpcoesDeAlteracao("\n Menu Inicial > Empresa > Alterar");
				break;
			case '3' : inserirEmpresa();
				break;
			case '4' : excluirEmpresa();
				break;
			case '5' : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != '5');
	return alternativa;	
}

char Cadastro::listaOpcoesDeAlteracao(string abasOrientacao){ // Método que apresenta possibilidades de edição/mudança.
	char alternativa = '0';
	do{
		cout << " \n ++++++++++++++++++++++++++++++++++++++++++++++\n" << "\n"
			 << "                   " << abasOrientacao
			 << " \n Escolha uma das seguintes alternativas abaixo: " << "\n"
			 << " Digite '1' para: Listar todas os funcionários" << "\n"
			 << " Digite '2' para: Modificar o salário dos funcionários" << "\n"
			 << " Digite '3' para: Adicionar um funcionário " << "\n"
			 << " Digite '4' para: Excluir um funcionário " << "\n"
			 << " Digite '5' para: Sair" << "\n"
			 << " Alternativa escolhida: "; cin >> alternativa; cin.ignore();
		switch(alternativa){
			case '1' : mostrarFuncionarios();
				break;
			case '2' : alteraSalario();
				break;
			case '3' : inserirFuncionario();
				break;
			case '4' : excluirFuncionario();
				break;
			case '5' : // Nenhuma ação. Somente sai do menu.
				break;
			default : cout << " \n\n Alternativa inválida!" << endl;
		}
	} while (alternativa != '5');
	
	return alternativa;		
}	

int Cadastro::pesquisarEmpresa(string algumaEmpresa){ // Método que pesquisa uma empresa pelo nome e retorna sua posição.
	int p = 0;
	/*
	O retorno deverá ser em inteiros, portanto é necessária uma representação booleana 
	dada por números. A fim de evitar duplo sentido, será utilizado o -1.
	*/
	int encontrou = -1;
	while(p < totalDeEmpresas){
		if (empresas[p]->getNomeEmpresa() == algumaEmpresa)
		{
			return p; // Retorna o índice da citada empresa. 
		}
		p++;
	}
	return encontrou; 
}

void Cadastro::mostrarTodasAsEmpresas(){ // Método para listar todas as empresas já cadastradas.
	cout << "\n\n Esse cadastro possui " << totalDeEmpresas << " empresa(s) cadastrada(s)."
		 << "\n" << "\n=============================================" 
		 << "\n Lista de empresas cadastradas: \n\n";
	int k = 0;
	while( k < totalDeEmpresas){
		cout << " Empresa Nº" << k+1 << " :::: "
			 << (*empresas[k]) << endl;
		k++;
	}
}	

void Cadastro::inserirEmpresa(){ // Método para criar uma nova empresa.
	Empresa *novaEmpresa = new Empresa();
	cin >> (*novaEmpresa);
	if (totalDeEmpresas < MAXIMO_DE_EMPRESAS){
		empresas[totalDeEmpresas++] = novaEmpresa;
	}
	else{
		cout << " Não é possível adicionar uma nova empresa a este cadastro." << endl;
	}
	cout << " Empresa adicionada com sucesso!" << endl;
}

void Cadastro::excluirEmpresa(){ // Método para remover uma referida empresa.
	string nomeDaEmpresaAExcluir; 
	cout << " Qual empresa deseja excluir deste cadastro? "; getline(cin, nomeDaEmpresaAExcluir);
	bool rearranjar = false;
	int n = 0;
	while(n < totalDeEmpresas){
		if(empresas[n]->getNomeEmpresa() == nomeDaEmpresaAExcluir){
			delete empresas[n];
			totalDeEmpresas--;
			rearranjar = true;
		}
		if (rearranjar){		
			empresas[n] = empresas[n+1]; //Reposiciona as empresas que estavam a frente da empresa removida.
		}
		n++;
	}
	if (rearranjar){
		cout << "A Empresa " << nomeDaEmpresaAExcluir 
			 << " foi excluída com sucesso.";
	}
	else{
		cout << "A Empresa " << nomeDaEmpresaAExcluir
			 << " não pode ser removida, pois não está cadastrada." ;
	}
}

void Cadastro::mostrarFuncionarios(){
	string nomeDaEmpresaQueMostraFuncionario;
	cout << "\n\n Deseja visualizar os funcionários de qual empresa? ";
	getline(cin, nomeDaEmpresaQueMostraFuncionario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueMostraFuncionario);
	if (numeroDaEmpresa == -1){
		cout << " Desculpe! A Empresa " << nomeDaEmpresaQueMostraFuncionario 
			 << " não está cadastrada!" << endl;
	}
	else{
		cout << " A Empresa " << nomeDaEmpresaQueMostraFuncionario
			 << " possui os seguintes funcionários:" << "\n\n" << endl;
		empresas[numeroDaEmpresa]->informaFuncionarios();
	};
}

void Cadastro::alteraSalario(){
	string nomeDaEmpresaQueAlteraSalario;
	cout << "Deseja alterar o salário de qual empresa? ";
	getline(cin, nomeDaEmpresaQueAlteraSalario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueAlteraSalario);
	if (numeroDaEmpresa == -1){
		cout << " Desculpe! A Empresa " << nomeDaEmpresaQueAlteraSalario 
			 << " não está cadastrada!" << endl;
	}
	else{
		float percentual;
		cout << " O salário da Empresa "<< nomeDaEmpresaQueAlteraSalario
			 << " será atualizado em qual percentual? " << endl;
		cin >> percentual;
		empresas[numeroDaEmpresa]->alteraSalarioEmpresa(percentual);
	}
}	

void Cadastro::inserirFuncionario(){
	string nomeDaEmpresaQueAdicionaFuncionario;
	cout << " Deseja inserir um funcionário em qual empresa? ";
	getline(cin, nomeDaEmpresaQueAdicionaFuncionario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueAdicionaFuncionario);
	if (numeroDaEmpresa == -1){
		cout << " Desculpe! A Empresa " << nomeDaEmpresaQueAdicionaFuncionario 
			 << " não está cadastrada!" << endl;
	}
	else{
		Funcionario *novoFuncionario = new Funcionario();
		cin >> (*novoFuncionario);
		if (empresas[numeroDaEmpresa]->getTotalFuncionarios() < MAXIMO_DE_FUNCIONARIOS){
			empresas[numeroDaEmpresa]->contrataFuncionario(novoFuncionario);
		}
	}
}	

void Cadastro::excluirFuncionario(){
	string nomeDaEmpresaQueDemiteFuncionario;
	string nomeDoFuncionarioADemitir;
	cout << " Deseja excluir um funcionário em qual empresa? ";
	getline(cin, nomeDaEmpresaQueDemiteFuncionario);
		int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueDemiteFuncionario);
	
	if (numeroDaEmpresa == -1){
		cout << " Desculpe! A Empresa " << nomeDaEmpresaQueDemiteFuncionario
			 << " não está cadastrada!" << endl;
	}
	else{
		cout << " Qual o nome do funcionário da Empresa" << nomeDaEmpresaQueDemiteFuncionario
			 << " que deseja demitir?" << endl;
		getline(cin, nomeDoFuncionarioADemitir);
		if (empresas[numeroDaEmpresa]->demiteFuncionario(nomeDoFuncionarioADemitir)){
			cout << " O funcionário "
				 << nomeDoFuncionarioADemitir
				 << " foi excluído com sucesso!" << endl;
		}
		else{
			cout << " Não foi possível localizar o funcionário "
				 << nomeDoFuncionarioADemitir << endl; 
		}
	}
}


