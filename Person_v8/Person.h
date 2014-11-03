#ifndef PERSON_H_
#define PERSON_H_

#include<string>
#include<iostream>
using namespace std;

class Person{
	protected:
		int id;
		string fname;
		string dob;
		string addr;
	
	public:
		Person();
		Person(int i_id, string i_fname, string i_dob, string i_addr);
		void Show();
		void Setfname(string n_new);
		void Setdob(string n_dOB);
		void Setaddr(string n_addr);
		int Getid();
		string Getfname();
		string Getdob();
		string Getaddr();
		void AddPerson(string p_detail, Person list[], int &counter);
		void ReadFile(string file, Person list[], int &counter);
		void SaveFile(string file, Person list[], int counter);
};

#endif
