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

bool operator == (const Date& d1, const Date& d2){
	//Verificação para igualdades.
	if (!d1.valid()){
		return FALSE;
	};
	if (!d2.valid()){
		return FALSE;
	};
	if ((d1.day() == d2.day())
		&& (d1.month() == d2.month())
		&& (d1.year() == d2.year())){
		return TRUE;
	};
	return FALSE;
}
bool operator != (const Date& d1, const Date& d2){
	return !(d1 == d2);
}

bool operator < (const Date& d1, const Date& d2){
	if (!d1.valid()){ // Sem significado.
		return FALSE;
	}
	if (!d2.valid()){
		return FALSE;
	}
	if (d1.year() < d2.year()){
		return TRUE;
	}
	else if (d1.year() > d2.year()){
		return FALSE;
	}
	else{ // Mesmo ano.
		if (d1.month() < d2.month()){
			return TRUE;
		}
		else if (d1.month() < d2.month()){
			return TRUE;
		}
		else { //Mesmo mês.
			if (d1.day() < d2.day()){
				return TRUE;
			}
			else{
				return FALSE;
			}
		}
	}
	return FALSE;
}

bool operator > (const Date& d1, const Date& d2){
	if (d1 == d2) {
		return FALSE;
	}
	if (d1 < d2){
		return FALSE;
	}
	return TRUE;
}

bool operator <= (const Date& d1, const Date& d2){
	if (d1 == d2){
		return TRUE;
	}
	return (d1 < d2);
}

bool operator >= (const Date& d1, const Date& d2){
	if (d1 == d2){
		return TRUE;
	}
	return (d1 > d2);
}

inline Date next_date(const Date& d){
	Date ndat;
	if (!d.valid()){
		return ndat;
	}
	ndat = Date((d.day() + 1), d.month(), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(1, (d.month() + 1), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(1 , 1, (d.year() + 1));
	return ndat;
}

inline Date previous_date(const Date& d){
	Date ndat;
	if (!d.valid()){ // Retorna zero.
		return ndat;
	}
	ndat = Date((d.day() - 1), d.month(), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(31, (d.month() - 1), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(30, (d.month() - 1), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(29, (d.month() - 1), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(28, (d.month() - 1), d.year());
	if (ndat.valid()){
		return ndat;
	}
	ndat = Date(31, 12, (d.year() - 1));
		return ndat;
}

Date Date::operator ++(int){
	Date d = *this;
	*this = next_date(d);
	return d;
} 

Date Date::operator ++(){ 
	*this = next_date(*this);
	return *this;
}

Date Date::operator --(int){
	Date d = *this;
	*this = previous_date(*this);
	return d;
}

Date Date::operator --(){
	*this = previous_date(*this);
	return *this;
}

inline long long_date(const Date& d){
	if (d.valid()){
		return d.year() * 10000 + d.month() * 100 + d.day();
	}
}
	
ostream & operator << (ostream& os, const Date& d){
	if (d.valid()){
		os << " " << long_date(d) << " ";
	}
	else { 
		os << " invalid date "; 
	}
	return os;
}




