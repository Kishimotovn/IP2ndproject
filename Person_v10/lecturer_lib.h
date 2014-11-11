#ifndef Lecturer_LIB_H_
#define Lecturer_LIB_H_

#include "Lecturer.h"

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;

//Link list
struct LNode 
{
	LNode *next;
	Lecturer s;
};

LNode *Lhead, *Ltail;

void LInitQueue()
{
	Lhead = Ltail = NULL;
}

void LPush(Lecturer n_s)
{
	LNode *el;
	el = new LNode;
	el -> s = n_s;
	el -> next = NULL;
	if(Lhead == NULL)
	{
		Lhead = Ltail = el; 
	}
	else
	{
		Ltail ->next = el;
		Ltail = el;
	}
}

int LPop()
{
	LNode *temp;
	Lecturer d_s;
	
	if(Lhead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = Lhead;
	Lhead = temp -> next;
	d_s = temp -> s;
	delete temp; 
}

void AddLecturer(string s_deLtail)
{
	string temp, i_fname, i_dob, i_addr, i_field, i_univ;
	int i_id;
	short i_lecyear;
	
	int mark = s_deLtail.find(":");
	i_id = atoi(s_deLtail.substr(0,mark).c_str());
	
	temp = s_deLtail.substr(mark+1);
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
	
	Lecturer s(i_id, i_fname, i_dob, i_addr, i_field, i_lecyear, i_univ);
	LPush(s);
}

void LReadFile(string file)
{
	ifstream fin;
	fin.open(file.c_str());
	if(!fin.is_open())
	{
		cout<<"Cant read the file.\n";
		exit(1);
	}
	else{
		string temp = "";
		while (getline(fin,temp))
		{
			AddLecturer(temp);
		}
		fin.close();
	}
}

void LSaveFile(string file)
{
	ofstream fout;
	fout.open(file.c_str());
	LNode *q;
	q = Lhead;
	while(q != NULL)
	{
		fout<<q->s.Getid()<<":"<<q->s.Getfname()<<":"<<q->s.Getdob()<<":"<<q->s.Getaddr()<<":"<<q->s.Getfield()<<":"<<q->s.Getlecyear()<<":"<<q->s.Getuniv()<<endl;
		q = q -> next;
	}
	fout.close();
}

void LListShow()
{
	LNode *q;
	q = Lhead;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			q -> s.Show();
			q = q->next;
		}while (q != NULL);
	}
}


#endif

