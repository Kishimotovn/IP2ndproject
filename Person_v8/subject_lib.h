#ifndef Subject_LIB_H_
#define Subject_LIB_H_

#include "Subjects.h"

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
	Subject sub;
};

SubNode *Subhead, *Subtail;


void SubInitQueue()
{
	Subhead = Subtail = NULL;
}

void SubPush(Subject n_sub)
{
	SubNode *el;
	el = new SubNode;
	el -> sub = n_sub;
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
	Subject d_sub;
	
	if(Subhead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = Subhead;
	Subhead = temp -> next;
	d_sub = temp -> sub;
	delete temp; 
}

void AddSubject(string sub_detail)
{
	string temp, i_id, i_sname, i_stype, i_presq;
	short  i_credit;
	
	int mark = sub_detail.find(":");
	i_id = sub_detail.substr(0,mark);
	
	temp = sub_detail.substr(mark+1);
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
	
	Subject sub(i_id, i_sname, i_stype, i_credit, i_presq);
	SubPush(sub);
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
		fout<<q->sub.Getid()<<":"<<q->sub.Getsname()<<":"<<q->sub.Getstype()<<":"<<q->sub.Getcredit()<<":"<<q->sub.Getpresq()<<endl;
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
			q -> sub.Show();
			q = q->next;
		}while (q != NULL);
	}
}

#endif
