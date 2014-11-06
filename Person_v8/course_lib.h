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
	Course c;
};

CNode *chead, *ctail;


void CInitQueue()
{
	chead = ctail = NULL;
}

void CPush(Course n_c)
{
	CNode *el;
	el = new CNode;
	el -> c = n_c;
	el -> next = NULL;
	if(chead == NULL)
	{
		chead = ctail = el; 
	}
	else
	{
		ctail ->next = el;
		ctail = el;
	}
}

int CPop()
{
	CNode *temp;
	Course d_c;
	
	if(chead == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = chead;
	chead = temp -> next;
	d_c = temp -> c;
	delete temp; 
}

void AddCourse(string c_detail)
{
	string temp, i_sid, i_room, i_time_starth, i_time_endh, i_time_date;
	int i_lid;
	short i_sem;
	
	int mark = c_detail.find(":");
	i_sid = c_detail.substr(0,mark);
	
	temp = c_detail.substr(mark+1);
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
	
	Course c(i_sid, i_lid, i_sem, i_room, i_time_starth, i_time_endh, i_time_date);
	CPush(c);
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
	q = chead;
	while(q != NULL)
	{
		fout<<q->c.Getsid()<<":"<<q->c.Getlid()<<":"<<q->c.Getsem()<<":"<<q->c.Getroom()<<":"<<q->c.Gettime_starth()<<":"<<q->c.Gettime_endh()<<":"<<q->c.Gettime_date()<<endl;
		q = q -> next;
	}
	fout.close();
}

void CListShow()
{
	CNode *q;
	q = chead;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			q -> c.Show();
			q = q->next;
		}while (q != NULL);
	}
}

void Searchdate(string i_time_date, short i_sem)
{
	CNode *q;
	q = chead;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			if(q->c.Getsem() == i_sem)
			{
				if(q->c.Gettime_date() == i_time_date)
				{
					q->c.Showtt();
				}
			}
			q = q->next;
		}while (q != NULL);
	}
}

#endif
