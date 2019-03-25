/*
Disciplina: Linguagem de Programação I
Professor: Silvio
Alunos: Letícia Moura e Odilon Júlio
===========================================================================
*/

#include "data.h"
using namespace std;

/* 
========================================
MÉTODOS CONSTRUTORES DA CLASSE "Date"
========================================
*/

Date::Date(const int& d, const int& m, const int& y){ // Construtor parametrizado.
	day_ = d;
	month_ = m;
	year_ = y; 
};

Date::Date(){// Construtor padrão. (inline definitions)
	year_ = 0;
	month_ = 0;
	day_ = 0;
};

int Date::day() const{
	return day_;
};

int Date::month() const{
	return month_;
};

int Date::year() const{
	return year_;
};

void Date::set_day (const int& day){
	Date::day_ = day;
};

void Date::set_month (const int& month){
	Date::month_ = month;
};

void Date::set_year (const int& year){
	Date::year_ = year;
};

bool Date::valid() const {
	// Esse método irá checar se a data fornecida é válida ou não.
	// Se a data não é válida, então será retornado o valor FALSE.
	// Apesar disso, é preciso uma checagem a mais no valor do ano.

	if (year_ < 0){
		return FALSE;
	}
	if(month_ > 12 || month_ < 1){
		return FALSE;
	}
	if (day_ > 31 || day_ < 1){
		return FALSE;
	}
	if ((day_ == 31 &&
		(month_ == 2 || month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11))){
		return FALSE;
	}
	if (day_ == 30 && month_ == 2){
		return FALSE;
	}
	if (year_ < 2000){
		if ((day_ == 29 && month_ == 2) && !((year_ - 1900)%4 == 0)){
			return FALSE;
		}
	}
	if (year_ > 2000){
		if ((day_ == 29 && month_ == 2) && !((year_ - 2000)%4 == 0)){
			return FALSE;
		}
	}
	return TRUE;

};

bool //









