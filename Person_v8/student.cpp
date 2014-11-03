#include "Student.h"

	Student::Student() : Person()
	{
		program = "";
		classroom = "";
		endyear = 0;
		
	}
	
	Student::Student(int i_id, string i_fname, string i_dob, string i_addr, string i_program, string i_classroom, int i_endyear) : Person(i_id, i_fname, i_dob, i_addr)
	{
		program = i_program;
		classroom = i_classroom;
		endyear = i_endyear;
	}
	
	void Student::Show()
	{
		cout<<id<<":"<<fname<<":"<<dob<<":"<<addr<<":"<<program<<":"<<classroom<<":"<<endyear<<"\n";
	}
	
	void Student::Setid(int n_id)
	{
		id = n_id;
	}
	
	void Student::Setprogram(string n_program)
	{
		program = n_program;
	}
	
	void Student::Setclassroom(string n_classroom)
	{
		classroom = n_classroom;
	}
	
	void Student::Setendyear(int n_endyear)
	{
		endyear = n_endyear;
	}
	
	string Student::Getprogram()
	{
		return program;
	}
	
	string Student::Getclassroom()
	{
		return classroom;
	}
	
	int Student::Getendyear()
	{
		return endyear;
	}
