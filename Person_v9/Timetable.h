#ifndef TIMETABLE_H_
#define TIMETABLE_H_

#include "subject_lib.h"
#include "course_lib.h"
#include "lecturer_lib.h"
#include "common.h"
#include <iomanip>
#include <string>
#include <sstream>

const char separator = ' ';

void LoadTimeTable()
{
	CReadFile("Course.txt");
	LReadFile("Lecturer.txt");
	SubReadFile("Subject.txt");
}


string ReturnDate(int date)
{
	switch(date)
	{
		case 0:
			return "Monday";
			break;
		case 1:
			return "Tuesday";
			break;
		case 2:
			return "Wednesday";
			break;
		case 3:
			return "Thursday";
			break;
		case 4:
			return "Friday";
			break;
		case 5:
			return "Saturday";
			break;
		case 6:
			return "Sunday";
			break;
		default:
			break;
	}
}

string ShowSubInfoByID(string i_sid, int para)
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
			if(q->s.Getid() == i_sid)
			{
				switch(para)
				{
					case 1:
						return q->s.Getsname();
						break;
					case 2:
						return q->s.Getstype();
						break;
					case 3:
						return InttoString(q->s.Getcredit());
						break;
					case 4:
						return q->s.Getpresq();
						break;
				}	
			}
			q = q->next;
		}while (q != NULL);
	}
}

string ShowLInfoByID(int i_id, int para)
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
			if(q->s.Getid() == i_id)
			{
				switch(para)
				{
					case 1:
						return q->s.Getfname();
						break;
					case 2:
						return q->s.Getdob();
						break;
					case 3:
						return q->s.Getaddr();
						break;
					case 4:
						return q->s.Getfield();
						break;
					case 5:
						return InttoString(q->s.Getlecyear());
						break;
					case 6:
						return q->s.Getuniv();
						break;
				}
			}
			q  = q->next;
		}while (q != NULL);
	}
}

template<typename T> void PrintCell(T t, const int& width)
{
	cout << left << setw(width) << setfill(separator) <<t<<"|";
}

void PrintSeparator(const int& width, char x)
{
	cout << right << setw(width) << setfill(x)<<"|";
}

void ShowTableHeader()
{
	PrintCell("SID", 4);
	PrintCell("TC", 2);
	PrintCell("PreqS", 5);
	PrintCell("Room", 13);
	PrintCell("DayTime", 17);
	PrintCell("Lecturer", 19);
	PrintCell("Note", 12);
	cout << endl;
	PrintSeparator(5,' ');
	PrintSeparator(3,' ');
	PrintSeparator(6,' ');
	PrintSeparator(14,' ');
	PrintSeparator(18,' ');
	PrintSeparator(20,' ');
	PrintSeparator(13,' ');
	cout <<endl;
	PrintSeparator(5,'-');
	PrintSeparator(3,'-');
	PrintSeparator(6,'-');
	PrintSeparator(14,'-');
	PrintSeparator(18,'-');
	PrintSeparator(20,'-');
	PrintSeparator(13,'-');
	cout <<endl;
}

void ShowCourse(string i_date, short i_sem, string i_fname)
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
			if(q->s.Getsem() == i_sem || i_sem == 0)
			{
				if(q->s.Gettime_date() == i_date || i_date == "0")
				{
					if(ShowLInfoByID(q->s.Getlid(), 1) == i_fname || i_fname == "0")
					{
						PrintCell(ShowSubInfoByID(q->s.Getsid(), 1), 4);
						PrintCell(ShowSubInfoByID(q->s.Getsid(), 3), 2);
						PrintCell(ShowSubInfoByID(q->s.Getsid(), 4), 5);
						PrintCell(q->s.Getroom(), 13);
						PrintCell(q->s.Gettime(), 17);
						PrintCell(ShowLInfoByID(q->s.Getlid(), 1), 19);
						PrintCell(q->s.Getnote(), 12);
						cout << endl;
						PrintSeparator(5,'-');
						PrintSeparator(3,'-');
						PrintSeparator(6,'-');
						PrintSeparator(14,'-');
						PrintSeparator(18,'-');
						PrintSeparator(20,'-');
						PrintSeparator(13,'-');
						cout <<endl;
					}
				}
			}
			q = q->next;
		}while (q != NULL);
	}
}

string center(string input, int width = 80)
{
	return string((width-input.length())/2, ' ') + input;
}

void ShowTimeTable(short i_sem)
{
	string a = "Timetable of semester "+ InttoString(i_sem) + "/2"+ " 2013-2014:\n";
	cout<< "\n" << center(a) << "\n\n";
	
	cout << right << setw(79) << setfill('=')<<"|"<<endl;
	ShowTableHeader();
	for(int j = 0; j <7; j++)
	{
		ShowCourse(ReturnDate(j), i_sem, "0");
	}
	
}

void SearchLecturerByName()
{
	string info;
	cout << "Input search info: ";
	std::getline(cin,info);
	ofstream fout;
	string test = "searchidlist.txt";
	fout.open(test.c_str());
	LNode *q;
	q = Lhead;
	int count;
	string a = "The desired proff has these course:";
	cout<< "\n" << center(a) << "\n\n";
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
				if(count == 0)
				{
					cout << right << setw(79) << setfill('=')<<"|"<<endl;
					ShowTableHeader();
				}
    			ShowCourse("0", 0, q->s.Getfname());
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
		SearchLecturerByName();
	}
	else
	{
		cout<<"Search More? [Y/N]: ";
		if(CheckAns())
		{
			SearchLecturerByName();
		}
	}
}


#endif
