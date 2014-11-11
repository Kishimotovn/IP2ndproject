#include"Lecturer.h"

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

Lecturer Lecturer::Getinfo(string s)
{
	string temp, i_fname, i_dob, i_addr, i_field, i_univ;
	int i_id;
	short i_lecyear;
	
	int mark = s.find(":");
	i_id = atoi(s.substr(0,mark).c_str());
	
	temp = s.substr(mark+1);
	mark = temp.find(":");
	i_fname = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_dob = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_addr = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_field = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_lecyear = atoi(temp.substr(0,mark).c_str());
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_univ = temp.substr(0,mark).c_str();
	
	Lecturer n_l(i_id, i_fname, i_dob, i_addr, i_field, i_lecyear, i_univ);
	return n_l;
}
	
int Lecturer::Find(string info)
{
	int count = 0;
	if(fname.find(info) != string::npos)
	{
		count+=1;
	}
	if(dob.find(info) != string::npos)
	{
		count+=1;
	}
	if(addr.find(info) != string::npos)
	{
		count+=1;
	}
	if(field.find(info) != string::npos)
	{
		count+=1;
	}
	if(lecyear.find(itoa(info.c_str())) != string::npos)
	{
		count+=1;
	}
	if(univ.find(info) != string::npos)
	{
		count+=1;
	}
	return count;
}

