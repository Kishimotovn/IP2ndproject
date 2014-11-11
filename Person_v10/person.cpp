#include "Person.h"
	
	//Constructor
	Person::Person()
	{
		id = 0;
		fname = "";
		dob = "";
		addr = "";
	}
	
	//Constructor Overload
	Person::Person(int i_id, string i_fname, string i_dob, string i_addr)
	{
		id = i_id;
		fname = i_fname;
		dob = i_dob;
		addr = i_addr;
	}
	
	//Show information: id:fname:dob:addr
	void Person::Show()
	{
		cout<<id<<":"<<fname<<":"<<dob<<":"<<addr<<"\n";
	}
	
	//Set info of person
	void Person::Setfname(string n_name)
	{
		fname = n_name;
	}
	
	void Person::Setdob(string n_dob)
	{
		dob = n_dob;
	}
	
	void Person::Setaddr(string n_addr)
	{
		addr = n_addr;
	}
	
	//Get info of person
	int Person::Getid()
	{
		return id;
	}
	string Person::Getfname()
	{
		return fname;
	}
	string Person::Getdob()
	{
		return dob;
	}
	string Person::Getaddr()
	{
		return addr;
	}
