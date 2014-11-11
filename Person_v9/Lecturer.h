#ifndef Lecturer_H_
#define Lecturer_H_

#include"person.h"

class Lecturer: public Person
{ //newdata
	string field;
	short lecyear;
	string univ;
public:
	Lecturer();
	Lecturer(int i_id, string i_fname, string i_dob, string i_addr, string i_field, short i_lecyear, string i_univ);
	void Show();
	void Setfield(string n_field);
	void Setlecyear(short n_lecyear);
	void Setuniv(string n_univ);
	string Getfield();
	short Getlecyear();
	string Getuniv();
	};
#endif
