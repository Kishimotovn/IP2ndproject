#ifndef LECTURER_LIB_H_
#define LECTURER_LIB_H_

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
	Lecturer l;
};

LNode *Lhead, *Ltail;


void LInitQueue()
{
	Lhead = Ltail = NULL;
}

void LPush(Lecturer n_l)
{
	LNode *el;
	el = new LNode;
	el -> l = n_l;
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
	Lecturer d_l;
	
	if(Lhead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = Lhead;
	Lhead = temp -> next;
	d_l = temp -> l;
	delete temp; 
}

void AddLecturer(string l_detail)
{
	string temp, i_fname, i_dob, i_addr, i_field, i_univ;
	int i_id;
	short i_lecyear;
	
	int mark = l_detail.find(":");
	i_id = atoi(l_detail.substr(0,mark).c_str());
	
	temp = l_detail.substr(mark+1);
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
	
	Lecturer l(i_id, i_fname, i_dob, i_addr, i_field, i_lecyear, i_univ);
	LPush(l);
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
		fout<<q->l.Getid()<<":"<<q->l.Getfname()<<":"<<q->l.Getdob()<<":"<<q->l.Getaddr()<<":"<<q->l.Getfield()<<":"<<q->l.Getlecyear()<<":"<<q->l.Getuniv()<<endl;
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
			q -> l.Show();
			q = q->next;
		}while (q != NULL);
	}
}

#endif
