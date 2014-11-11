#ifndef COURSE_LIB_H_
#define COURSE_LIB_H_

#include "Course.h"

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;

//Link list
struct CNode 
{
	CNode *next;
	Course s;
};

CNode *Chead, *Ctail;

void CInitQueue()
{
	Chead = Ctail = NULL;
}

void CPush(Course n_s)
{
	CNode *el;
	el = new CNode;
	el -> s = n_s;
	el -> next = NULL;
	if(Chead == NULL)
	{
		Chead = Ctail = el; 
	}
	else
	{
		Ctail ->next = el;
		Ctail = el;
	}
}

int CPop()
{
	CNode *temp;
	Course d_s;
	
	if(Chead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = Chead;
	Chead = temp -> next;
	d_s = temp -> s;
	delete temp; 
}

void AddCourse(string s_deCtail)
{
	string temp, i_sid, i_room, i_time_starth, i_time_endh, i_time_date, i_note;
	int i_id, i_lid;
	short i_sem;
	
	int mark = s_deCtail.find(":");
	i_sid = s_deCtail.substr(0,mark);
	
	temp = s_deCtail.substr(mark+1);
	mark = temp.find(":");
	i_lid = atoi(temp.substr(0,mark).c_str());
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_sem = atoi(temp.substr(0,mark).c_str());
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_room = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_time_starth = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_time_endh = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_time_date = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_note = temp.substr(0,mark);
	
	Course s(i_sid, i_lid, i_sem, i_room, i_time_starth, i_time_endh, i_time_date, i_note);
	CPush(s);
}

void CReadFile(string file)
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
			AddCourse(temp);
		}
		fin.close();
	}
}

void CSaveFile(string file)
{
	ofstream fout;
	fout.open(file.c_str());
	CNode *q;
	q = Chead;
	while(q != NULL)
	{
		fout<<q->s.Getsid()<<":"<<q->s.Getlid()<<":"<<q->s.Getsem()<<":"<<q->s.Getroom()<<":"<<q->s.Gettime_starth()<<":"<<q->s.Gettime_endh()<<":"<<q->s.Gettime_date()<<":"<<q->s.Getnote()<<endl;
		q = q -> next;
	}
	fout.close();
}

void CListShow()
{
	CNode *q;
	q = Chead;
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
