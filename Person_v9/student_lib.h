#ifndef Student_LIB_H_
#define Student_LIB_H_

#include "Student.h"
#include "common.h"

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;

//Link list
struct Node 
{
	Node *next;
	Student s;
};

Node *head, *tail, *t_Student;
Student m_Student;


void InitQueue()
{
	head = tail = NULL;
}

void Push(Student n_s)
{
	Node *el;
	el = new Node;
	el -> s = n_s;
	el -> next = NULL;
	if(head == NULL)
	{
		head = tail = el; 
	}
	else
	{
		tail ->next = el;
		tail = el;
	}
}

int Pop()
{
	Node *temp;
	Student d_s;
	
	if(head == NULL)
	{
		cout<<"List empty!.\n";
	}
	
	temp = head;
	head = temp -> next;
	d_s = temp -> s;
	delete temp; 
}

void AddStudent(string s_detail)
{
	string temp, i_fname, i_dob, i_addr, i_program, i_classroom;
	int i_id, i_endyear;
	
	int mark = s_detail.find(":");
	i_id = atoi(s_detail.substr(0,mark).c_str());
	
	temp = s_detail.substr(mark+1);
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
	i_program = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_classroom = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_endyear = atoi(temp.substr(0,mark).c_str());
	
	Student s(i_id, i_fname, i_dob, i_addr, i_program, i_classroom, i_endyear);
	Push(s);
}

void ReadFile(string file)
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
			AddStudent(temp);
		}
		fin.close();
	}
}

void SaveFile(string file)
{
	ofstream fout;
	fout.open(file.c_str());
	Node *q;
	q = head;
	while(q != NULL)
	{
		fout<<q->s.Getid()<<":"<<q->s.Getfname()<<":"<<q->s.Getdob()<<":"<<q->s.Getaddr()<<":"<<q->s.Getprogram()<<":"<<q->s.Getclassroom()<<":"<<q->s.Getendyear()<<endl;
		q = q -> next;
	}
	fout.close();
}

void SListShow()
{
	Node *q;
	q = head;
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

void Searchprogram(string _program)
{
	Node *q;
	q = head;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			if(q->s.Getprogram() == _program)
			{
				cout<<q->s.Getfname()<<"\n";
			}
			q = q->next;
		}while (q != NULL);
	}
}

void Searchclass(string _classroom)
{
	Node *q;
	q = head;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			if(q->s.Getclassroom() == _classroom)
			{
				cout<<q->s.Getfname()<<"\n";
			}
			q = q->next;
		}while (q != NULL);
	}
}

void Searchendyear(int _endyear)
{
	Node *q;
	q = head;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			if(q->s.Getendyear() == _endyear)
			{
				cout<<q->s.Getfname()<<"\n";
			}
			q = q->next;
		}while (q != NULL);
	}
}

void SearchStudent()
{
	string info;
	cout << "Input search info: ";
	std::getline(cin,info);
	ofstream fout;
	string test = "searchidlist.txt";
	fout.open(test.c_str());
	Node *q;
	q = head;
	int count;
	if(q == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		//find name
		do
		{
			if (q->s.Getfname().find(info) != string::npos) 
			{
    			q->s.Show();
    			fout<<q->s.Getid()<<endl;
    			count += 1;
			}
			q = q->next;
		}while (q != NULL);
		
		//find dob
		q = head;
		do
		{
			if (q->s.Getdob().find(info) != string::npos) 
			{
    			q->s.Show();
    			fout<<q->s.Getid()<<endl;
    			count += 1;
			}
			q = q->next;
		}while (q != NULL);
		
		//find program
		q = head;
		do
		{
			if (q->s.Getprogram().find(info) != string::npos) 
			{
    			q->s.Show();
    			fout<<q->s.Getid()<<endl;
    			count += 1;
			}
			q = q->next;
		}while (q != NULL);
		
		//find addr
		q = head;
		do
		{
			if (q->s.Getaddr().find(info) != string::npos) 
			{
    			q->s.Show();
    			fout<<q->s.Getid()<<endl;
    			count += 1;
			}
			q = q->next;
		}while (q != NULL);
		
		//find endyear
		q = head;
		do
		{
			if ((static_cast<ostringstream*>( &(ostringstream() << q->s.Getendyear()) )->str()).find(info) != string::npos) 
			{
    			q->s.Show();
    			fout<<q->s.Getid()<<endl;
    			count += 1;
			}
			q = q->next;
		}while (q != NULL);
	}
	fout.close();
	if(count == 0)
	{
		cout << "No one's like that! Re search!\n";
		SearchStudent();
	}
}


int FindStudentId()
{
	ifstream fin;
	string file = "searchidlist.txt";
	fin.open(file.c_str());
	int _id;
	Node *q;
	
	cout<<"Input desired Student's id: ";
	cin >> _id;
	cin.clear();
	cin.ignore(100, '\n');
	
	//find id
	t_Student = head;
	do
	{
		if (t_Student->s.Getid() == _id) 
		{
			string temp = "";
			while (getline(fin,temp))
			{
				if(_id == atoi(temp.c_str()))
				{
					t_Student->s.Show();
					return t_Student->s.Getid();
				}
			}
		}
		t_Student = t_Student->next;
	}while (t_Student != NULL);
	fin.close();
	return -1;
}


int FinalCheck()
{
	int temp;
	temp = FindStudentId();
	if(temp != -1)
	{
		cout<<"Is this your Student? [Y/N]: ";
		if(CheckAns())
		{
			return temp;
		}
		else
		{
			cout<<"Wanna find again? [Y/N]";
			if(CheckAns())
				return FinalCheck();
		}		
	}
	else
	{
		cout<<"Cant find or not in list! Wanna find again? [Y/N]: ";
		if(CheckAns())
			FinalCheck();
	}
	return -1;
} 

void ChangeProperty()
{
	cout << "Which property do you want to change?\n" << "[1]: name\n" << "[2]: dob\n" << "[3]: program\n" << "[4]: address\n";
	int prop = CheckAnsProperties();
	cout << "Input new value: ";
	string i_value;
	std::getline(cin, i_value);
	switch(prop)
	{
		case 1:
			m_Student.Setfname(i_value);
			break;
		case 2:
			m_Student.Setdob(i_value);
			break;
		case 3:
			m_Student.Setprogram(i_value);
			break;
		case 4:
			m_Student.Setaddr(i_value);
			break;
		default:
			break;
	}
	cout << "Change more? [Y/N]: ";
	if(CheckAns())
		ChangeProperty();
}

void CoreModify()
{
	t_Student->s.Show();
	ChangeProperty();
	cout << "This is the final result: \n";
	m_Student.Show();
	cout << "You wanna keep the changes? [Y/N]: ";
//	cin.clear();
//	cin.ignore(100, '\n');
	if(CheckAns())
	{
		t_Student -> s = m_Student;
		SaveFile("b.txt");
		ReadFile("b.txt");
		cout<<"Saved changes!";
	}
	else
	{
		m_Student = t_Student->s;
		cout<<"Rechange? ";
		if(CheckAns())
		{
			CoreModify(); 
		}
	}
}

void ModifyStudent()
{
	int i_id;
	SearchStudent();
	i_id = FinalCheck();
	if(i_id != -1)
	{
		m_Student = t_Student -> s;
		cout << "Ok, now modify this Student:\n";
		CoreModify();
		cout << "\nChange another Student? [Y/N]: ";
		if(CheckAns())
		{
			ModifyStudent();
		}
	}
	cout << "Het phim!\n";
}

int CountStudentNumber()
{
	int Studentcount = 0;
	Node *q;
	q = head;
	do
	{
		Studentcount +=1;
		q = q->next;
	}while (q != NULL);
	return Studentcount;
}

int CheckRepetitive(Student x)
{
	int counter = 0;
	Node *q;
	q = head;
	do
	{
		if((q->s.Getfname() == x.Getfname()) && (q->s.Getdob() == x.Getdob()) 
		&& (q->s.Getaddr() == x.Getaddr()) && (q->s.Getprogram() == x.Getprogram()) && (q->s.Getclassroom() == x.Getclassroom()))
		{
			counter += 1;
			cout<< "There is a repetitive:" << "\n";
			q->s.Show();
		} 
		q = q->next;
	}while (q != NULL);
	return counter;
}

void AddnewStudent()
{
	int i_id = CountStudentNumber() + 1;
	string i_name, i_dob, i_addr, i_program, i_classroom;
	int i_endyear;
	Student n_s;
	cout << "Input new Student's info:"<<"\n";
	cout << "Input name: ";
	getline(cin, i_name);
	
	cout << "Input dob: ";
	getline(cin, i_dob);
	
	cout << "Input addr: ";
	getline(cin, i_addr);
	
	cout << "Input program: ";
	getline(cin, i_program);
	
	cout << "Input classroom: ";
	getline(cin, i_classroom);
	
	n_s.Setid(i_id);
	n_s.Setfname(i_name);
	n_s.Setdob(i_dob);
	n_s.Setaddr(i_addr);
	n_s.Setprogram(i_program);
	n_s.Setclassroom(i_classroom);
	
	if(CheckRepetitive(n_s) == 0)
	{
		Push(n_s);
		SaveFile("c.txt");
		cout << "Student's info is added\n";
		cout << "new Student info:\n";
		n_s.Show();
	}
	else
	{
		cout<<"There has been repeatitives!" << "Redo? [Y/N]: ";
		if(CheckAns())
		{
			AddnewStudent();
		}
	}
}

#endif
