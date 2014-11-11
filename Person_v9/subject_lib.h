#ifndef SUBJECT_LIB_H_
#define SUBJECT_LIB_H_

#include "Subject.h"

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;

//Link list
struct SubNode 
{
	SubNode *next;
	Subject s;
};

SubNode *Subhead, *Subtail;

void SubInitQueue()
{
	Subhead = Subtail = NULL;
}

void SubPush(Subject n_s)
{
	SubNode *el;
	el = new SubNode;
	el -> s = n_s;
	el -> next = NULL;
	if(Subhead == NULL)
	{
		Subhead = Subtail = el; 
	}
	else
	{
		Subtail ->next = el;
		Subtail = el;
	}
}

int SubPop()
{
	SubNode *temp;
	Subject d_s;
	
	if(Subhead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = Subhead;
	Subhead = temp -> next;
	d_s = temp -> s;
	delete temp; 
}

void AddSubject(string s_deSubtail)
{
	string temp, i_id, i_sname, i_stype, i_presq;
	short i_credit;
	
	int mark = s_deSubtail.find(":");
	i_id = s_deSubtail.substr(0,mark);
	
	temp = s_deSubtail.substr(mark+1);
	mark = temp.find(":");
	i_sname = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_stype = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_credit = atoi(temp.substr(0,mark).c_str());
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_presq = temp.substr(0,mark);
	
	Subject s(i_id, i_sname, i_stype, i_credit, i_presq);
	SubPush(s);
}

void SubReadFile(string file)
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
			AddSubject(temp);
		}
		fin.close();
	}
}

void SubSaveFile(string file)
{
	ofstream fout;
	fout.open(file.c_str());
	SubNode *q;
	q = Subhead;
	while(q != NULL)
	{
		fout<<q->s.Getid()<<":"<<q->s.Getsname()<<":"<<q->s.Getstype()<<":"<<q->s.Getcredit()<<":"<<q->s.Getpresq()<<endl;
		q = q -> next;
	}
	fout.close();
}

void SubListShow()
{
	SubNode *q;
	q = Subhead;
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

