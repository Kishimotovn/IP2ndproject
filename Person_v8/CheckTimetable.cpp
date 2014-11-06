#include "subject_lib.h"
#include "course_lib.h"
#include "lecturer_lib.h"

void Check()
{
	CNode *q1, *q2;
	string test1, test2, test3;
	q1 = chead;
	if(q1 == NULL)
	{
		cout<<"List epmty.\n";
	}
	else
	{
		do
		{
			q2 = q1;
			do
			{
				if((q1->c.Gettime_starth() == q2->next->c.Gettime_starth()) && (q1->c.Gettime_endh() == q2->next->c.Gettime_endh()) && (q1->c.Gettime_date() == q2->next->c.Gettime_date()))
				{
					if((q1->c.Getroom() == q2->next->c.Getroom()))
					{
						cout<<"Same room at:\n";
						q1->c.Show();
						q2->next->c.Show();
					}
					if((q1->c.Getlid() == q2->next->c.Getlid()))
					{
						cout<<"Same lecturer at:\n";
						q1->c.Show();
						q2->next->c.Show();
					}
				}
				q2 = q2->next;
			}while (q2 -> next != NULL);
			q1 = q1->next;	
		}while (q1 != NULL && q1 ->next != NULL);
	}
}

string Date(int i)
{
	switch(i)
	{
		case 0: 
			return "Mon";
			break;
		case 1:
			return "Tue";
			break;
		case 2:
			return "Wed";
			break;
		case 3:
			return "Thu";
			break;
		case 4:
			return "Fri";
			break;
		case 5:
			return "Sat";
			break;
		case 6:
			return "Sun";
			break;
		default:
			break;
	}
}

void ShowTimetable()
{
	for(int j = 1; j<3; j++)
	{
		cout<< "Semester "<<j<<":\n";
		for(int i = 0; i <7;i++)
			Searchdate(Date(i), j);
	}
}

int main()
{
	CReadFile("course.txt");
	SubReadFile("Subjects.txt");
	LReadFile("lecturer.txt");
	CListShow();
	Check();
	ShowTimetable();
//	SubListShow();
//	LListShow();
	
	return 0;
}

