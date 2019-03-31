/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
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
	cout << "A Média de Funcionários é "
		 << ((float) Funcionario::getNumeroDeFuncionarios()/Empresa::getTotalEmpresas())
		 << endl;
}

char Cadastro::listaOpcaoInicial(){ // Método que mostra as alternativas iniciais.
	char alternativa = '0';
	while ( alternativa == '0' ||
			alternativa == '1' ||
			alternativa == '2' ||
			alternativa == '3' ||
			alternativa == '4'){
		cout << " ++++++++++++++++++++++++++++++++++++++++" << "\n"
			 << " Digite '1' para: Média de Funcionários" << "\n"
			 << " Digite '2' para: Escolher uma Empresa" << "\n"
			 << " Digite '3' para: Escolher um Funcionário " << "\n"
			 << " Digite '4' para: Sair deste Menu" << "\n"
			 << " Alternatva escolhida: "; 
			 cin >> alternativa;
		switch(alternativa){
			case '0' : cout << "Alternativa inválida!" 
							<< endl;
			case '1' : mediaDeFuncionarios();
				break;
			case '2' : listaOpcaoSecundaria();
				break;
			case '3' : listaOpcoesDeAlteracao();
				break;
			case '4' : // Nenhuma ação. Somente sai do menu.
				break;
		}
	}
	cout << "Alternativa inválida!" << endl;
	return alternativa;
}

char Cadastro::listaOpcaoSecundaria(){ // Método que relaciona opcões secundárias relativas à empresa escolhida.
	char alternativa = '0';
	while ( alternativa == '0' ||
			alternativa == '1' ||
			alternativa == '2' ||
			alternativa == '3' ||
			alternativa == '4' ||
			alternativa == '5'){
		cout << " Escolha uma das seguintes alternativas: " << "\n"
			 << " ++++++++++++++++++++++++++++++++++++++++" << "\n"
			 << " Digite '1' para: Listar todas as empresas" << "\n"
			 << " Digite '2' para: Modificar uma características de uma empresa" << "\n"
			 << " Digite '3' para: Adicionar uma empresa " << "\n"
			 << " Digite '4' para: Remover uma empresa " << "\n"
			 << " Digite '5' para: Sair" << "\n"
			 << " Alternatva escolhida: "; cin >> alternativa;
		switch(alternativa){
			case '0' : cout << "Alternativa inválida!" 
							<< endl;
			case '1' : mostrarTodasAsEmpresas();
				break;
			case '2' : listaOpcoesDeAlteracao();
				break;
			case '3' : inserirEmpresa();
				break;
			case '4' : excluirEmpresa();
				break;
			case '5' : // Nenhuma ação. Somente sai do menu.
				break;
		}
	}
	cout << "Alternativa inválida!" << endl;
	return alternativa;	
}

char Cadastro::listaOpcoesDeAlteracao(){ // Método que apresenta possibilidades de edição/mudança.
	char alternativa = '0';
	while ( alternativa == '0' ||
			alternativa == '1' ||
			alternativa == '2' ||
			alternativa == '3' ||
			alternativa == '4' ||
			alternativa == '5'){
		cout << " Escolha uma das seguintes alternativas: " << "\n"
			 << " ++++++++++++++++++++++++++++++++++++++++" << "\n"
			 << " Digite '1' para: Listar todas os funcionários" << "\n"
			 << " Digite '2' para: Modificar o salário dos funcionários" << "\n"
			 << " Digite '3' para: Adicionar um funcionário " << "\n"
			 << " Digite '4' para: Excluir um funcionário " << "\n"
			 << " Digite '5' para: Sair" << "\n"
			 << " Alternatva escolhida: "; cin >> alternativa;
		switch(alternativa){
			case '0' : cout << "Alternativa inválida!" 
							<< endl;
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
		}
	}
	cout << "Alternativa inválida!" << endl;
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
	cout << "Esse cadastro possui " << totalDeEmpresas << "empresas cadastradas."
		 << "\n" << "================================" << "Lista de empresas: ";
	int k = 0;
	while( k < totalDeEmpresas){
		cout << "Empresa Nº" << k+1 << " ---- "
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
		cout << "Não é possível adicionar uma nova empresa a este cadastro." << endl;
	}
	cout << "Empresa " << novaEmpresa << "adicionada com sucesso!" << endl;
}

void Cadastro::excluirEmpresa(){ // Método para remover uma referida empresa.
	string nomeDaEmpresaAExcluir; 
	cout << "Qual empresa deseja excluir deste cadastro?"; getline(cin, nomeDaEmpresaAExcluir);
	bool rearranjar = false;
	int n = 0;
	/*
	for (int i = 0; i < totalDeEmpresas; ++i)
	{
		if (empresas[i]->getNomeEmpresa() == nomeDaEmpresaAExcluir){
			delete empresas[i];
			totalDeEmpresas--;
			rearranjar = true;
		}
		if (rearranjar){
			empresas[i] = empresas[i+1];
		}
	}
	if (rearranjar){
		cout << "A Empresa " << nomeDaEmpresaAExcluir 
			 << " foi excluída com sucesso.";
	}
	else{
		cout << "A Empresa " << nomeDaEmpresaAExcluir
			 << "não pode ser removida, pois não está cadastrada." ;
	}
	*/
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
			 << "não pode ser removida, pois não está cadastrada." ;
	}
}

void Cadastro::mostrarFuncionarios(){
	string nomeDaEmpresaQueMostraFuncionario;
	cout << "Deseja visualizar os funcionparios de qual empresa? ";
	getline(cin, nomeDaEmpresaQueMostraFuncionario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueMostraFuncionario);
	if (numeroDaEmpresa == -1){
		cout << "Desculpe! A Empresa " << nomeDaEmpresaQueMostraFuncionario 
			 << "não está cadastrada!" << endl;
	}
	else{
		cout << "A Empresa " << nomeDaEmpresaQueMostraFuncionario
			 << "possui os seguintes funcionários:" << "\n\n" << endl;
		empresas[numeroDaEmpresa]->informaFuncionarios();
	};
}

void Cadastro::alteraSalario(){
	string nomeDaEmpresaQueAlteraSalario;
	cout << "Deseja alterar o salário de qual empresa? ";
	getline(cin, nomeDaEmpresaQueAlteraSalario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueAlteraSalario);
	if (numeroDaEmpresa == -1){
		cout << "Desculpe! A Empresa " << nomeDaEmpresaQueAlteraSalario 
			 << "não está cadastrada!" << endl;
	}
	else{
		float percentual;
		cout << "O salário da Empresa "<< nomeDaEmpresaQueAlteraSalario
			 << " será atualizado em qual percentual? " << endl;
		cin >> percentual;
		empresas[numeroDaEmpresa]->alteraSalarioEmpresa(percentual);
	}
}	

void Cadastro::inserirFuncionario(){
	string nomeDaEmpresaQueAdicionaFuncionario;
	cout << "Deseja inserir um funcionário em qual empresa? ";
	getline(cin, nomeDaEmpresaQueAdicionaFuncionario);
	int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueAdicionaFuncionario);
	if (numeroDaEmpresa == -1){
		cout << "Desculpe! A Empresa " << nomeDaEmpresaQueAdicionaFuncionario 
			 << "não está cadastrada!" << endl;
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
	cout << "Deseja excluir um funcionário em qual empresa? ";
	getline(cin, nomeDaEmpresaQueDemiteFuncionario);
		int numeroDaEmpresa = pesquisarEmpresa(nomeDaEmpresaQueDemiteFuncionario);
	
	if (numeroDaEmpresa == -1){
		cout << "Desculpe! A Empresa " << nomeDaEmpresaQueDemiteFuncionario
			 << "não está cadastrada!" << endl;
	}
	else{
		cout << "Qual o nome do funcionário da Empresa" << nomeDaEmpresaQueDemiteFuncionario
			 << "que deseja demitir?" << endl;
		getline(cin, nomeDoFuncionarioADemitir);
		if (empresas[numeroDaEmpresa]->demiteFuncionario(nomeDoFuncionarioADemitir)){
			cout << "O funcionário "
				 << nomeDoFuncionarioADemitir
				 << "foi excluído com sucesso!" << endl;
		}
		else{
			cout << "Não foi possível localizar o funcionário "
				 << nomeDoFuncionarioADemitir << endl; 
		}
	}
}


