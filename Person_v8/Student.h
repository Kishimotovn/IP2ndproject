#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student: public Person
{
	
	string program;
	string classroom;
	int endyear;
	
	public:
		Student();
		Student(int i_id, string i_fname, string i_dob, string i_addr, string i_program, string i_classroom, int i_endyear);
		void Show();
		void Setid(int n_id); 
		void Setprogram(string n_program);
		void Setclassroom(string n_classroom);
		void Setendyear(int n_endyear);
		string Getprogram();
		string Getclassroom();
		int Getendyear();
};
#endif
