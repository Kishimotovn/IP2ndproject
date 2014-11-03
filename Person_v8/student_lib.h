#ifndef STUDENT_LIB_H_
#define STUDENT_LIB_H_

#include "Student.h"

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

Node *head, *tail, *t_student;
Student m_student;


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

void PListShow()
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

void Searchstudent()
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
		Searchstudent();
	}
}

bool CheckAns()
{ 
	string ans;
	cin >> ans;
	cin.clear();
	cin.ignore(100, '\n');
	if(ans == "y")
		return true;
	else if(ans == "n")
		return false;
	else
	{
		cout<<"Input y or n: ";
		CheckAns();	
	}			
}

int FindStudentId()
{
	ifstream fin;
	string file = "searchidlist.txt";
	fin.open(file.c_str());
	int _id;
	Node *q;
	
	cout<<"Input desired student's id: ";
	cin >> _id;
	cin.clear();
	cin.ignore(100, '\n');
	
	//find id
	t_student = head;
	do
	{
		if (t_student->s.Getid() == _id) 
		{
			string temp = "";
			while (getline(fin,temp))
			{
				if(_id == atoi(temp.c_str()))
				{
					t_student->s.Show();
					return t_student->s.Getid();
				}
			}
		}
		t_student = t_student->next;
	}while (t_student != NULL);
	fin.close();
	return -1;
}


int FinalCheck()
{
	int temp;
	temp = FindStudentId();
	if(temp != -1)
	{
		cout<<"Is this your student? [Y/N]: ";
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

int CheckAnsProperties()
{ 
	string ans;
	std::getline(cin, ans);
	if(ans == "1") return 1;
	if(ans == "2") return 2;
	if(ans == "3") return 3;
	if(ans == "4") return 4;
	cout << "Moi so ma cung nhap sai! Nhap lai de .,l,, : ";
	return CheckAnsProperties();
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
			m_student.Setfname(i_value);
			break;
		case 2:
			m_student.Setdob(i_value);
			break;
		case 3:
			m_student.Setprogram(i_value);
			break;
		case 4:
			m_student.Setaddr(i_value);
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
	t_student->s.Show();
	ChangeProperty();
	cout << "This is the final result: \n";
	m_student.Show();
	cout << "You wanna keep the changes? [Y/N]: ";
//	cin.clear();
//	cin.ignore(100, '\n');
	if(CheckAns())
	{
		t_student -> s = m_student;
		SaveFile("b.txt");
		ReadFile("b.txt");
		cout<<"Saved changes!";
	}
	else
	{
		m_student = t_student->s;
		cout<<"Rechange? ";
		if(CheckAns())
		{
			CoreModify(); 
		}
	}
}

void Modifystudent()
{
	int i_id;
	Searchstudent();
	i_id = FinalCheck();
	if(i_id != -1)
	{
		m_student = t_student -> s;
		cout << "Ok, now modify this student:\n";
		CoreModify();
		cout << "\nChange another student? [Y/N]: ";
		if(CheckAns())
		{
			Modifystudent();
		}
	}
	cout << "Het phim!\n";
}

int CountStudentNumber()
{
	int studentcount = 0;
	Node *q;
	q = head;
	do
	{
		studentcount +=1;
		q = q->next;
	}while (q != NULL);
	return studentcount;
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
	cout << "Input new student's info:"<<"\n";
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
