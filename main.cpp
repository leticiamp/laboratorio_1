/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Aluno: Odilon Júlio dos Santos

Atividade: CORRIDA DOS SAPOS
===========================================================================
*/

#include <iostream>
#include "classe.h"

using namespace std;

/* Atributo público estático "distância total"
da corrida inicializado com o valor 1000.*/
int Sapo::distanciaTotal = 500;


int main(){
	Sapo *sp1 = new Sapo(2);
	Sapo *sp2 = new Sapo(3);
	Sapo *sp3 = new Sapo(1);

	while(	sp1->getDistanciaPercorrida() < Sapo::getDistanciaTotal()&&
			sp2->getDistanciaPercorrida() < Sapo::getDistanciaTotal()&&
			sp3->getDistanciaPercorrida() < Sapo::getDistanciaTotal()){
		
		sp1->pular();
			if(sp1->getDistanciaPercorrida() >= Sapo::getDistanciaTotal()){
				cout << "O " << sp1->getEspecie() << " venceu, pois pulou "<< sp1->getQuantidadePulos() << " vez(es) e percorreu, no total, a distância de " << sp1->getDistanciaPercorrida() << "." << endl;
				break;	
			}
		sp2->pular();
			if(sp2->getDistanciaPercorrida() >= Sapo::getDistanciaTotal()){
				cout << "O " << sp2->getEspecie() << " venceu, pois pulou "<< sp2->getQuantidadePulos() << " vez(es) e percorreu, no total, a distância de " << sp2->getDistanciaPercorrida() << "." << endl;
				break;
			}
		sp3->pular();
			if(sp3->getDistanciaPercorrida() >= Sapo::getDistanciaTotal()){
				cout << "O " << sp3->getEspecie() << " venceu, pois pulou "<< sp3->getQuantidadePulos() << " vez(es) e percorreu, no total, a distância de " << sp3->getDistanciaPercorrida() << "." << endl;
				break;
			}
	}

	return 0;
}
