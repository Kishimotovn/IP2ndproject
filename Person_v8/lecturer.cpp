#include"lecturer.h"

Lecturer::Lecturer():Person(){
	field="";
	lecyear=0;
	univ="";
}
Lecturer::Lecturer(int i_id, string i_fname, string i_dob, string i_addr, string i_field, short i_lecyear, string i_univ):Person(i_id, i_fname, i_dob, i_addr)
{
	field=i_field;
	lecyear=i_lecyear;
	univ=i_univ;	
}

void Lecturer::Show(){
	cout<<id<<":"<<fname<<":"<<dob<<":"<<addr<<"."<<field<<":"<<lecyear<<"."<<univ<<"\n";
}

void Lecturer::Setfield(string n_field){
	field=n_field;
}

void Lecturer::Setlecyear(short n_lecyear){
	lecyear=n_lecyear;
}

void Lecturer::Setuniv(string n_univ){
	univ=n_univ;
}

string Lecturer::Getfield(){
	return field;
}

short Lecturer::Getlecyear(){
	return lecyear;
}

string Lecturer::Getuniv(){
	return univ;
}


	

