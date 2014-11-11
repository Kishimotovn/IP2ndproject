//#include "Timetable.h"
//#include "common.h"
//#include "windows.h"
//
//void CheckTimetable()
//{
//	CNode *q1, *q2;
//	q1 = Chead;
//	if(q1 == NULL)
//	{
//		cout<<"empty";
//		return;
//	}
//	else
//	{
//		do
//		{
//			q2 = q1;
//			do 
//			{
//				if((q1->s.Gettime_starth() == q2->next->s.Gettime_starth()) && (q1->s.Gettime_endh() == q2->next->s.Gettime_endh()) && (q1->s.Gettime_date() == q2->next->s.Gettime_date()))
//				{
//					if((q1->s.Getlid() == q2->next->s.Getlid()))
//					{
//						cout << "Have same lecturer here:\n";
//						q1->s.Show();
//						q2->next->s.Show();
//					}
//					if((q1->s.Getroom() == q2->next->s.Getroom()))
//					{
//						cout << "Have same room here:\n";
//						q1->s.Show();
//						q2->next->s.Show();
//					}
//				}
//				q2 = q2->next;
//			}while (q2 ->next != NULL);	
//			q1 = q1 -> next;		
//		}while(q1 != NULL && q1->next != NULL);
//	}
//}
//
//void InputTask()
//{
//	cout << "\n[1]Show Timetable of 1st Semester\n" << "[2]Show Timetable of 2nd Semester\n" << "[3]Search By Lecturer's Name\n" << "[4]Exit\n"<< "Input task(1-4): " ;
//	int task = CheckAnsProperties();
//	if (task == 1)
//	{
//		ShowTimeTable(1);
//	}
//	else if(task == 2)
//	{
//		ShowTimeTable(2);
//	}
//	else if(task == 3)
//	{
//		SearchLecturerByName();
//	}
//	else if(task == 4)
//	{
//		exit(1);
//	}
//	else
//	{
//		cout << "Moi so ma cung nhap sai! Nhap lai de .,l,, : ";
//		InputTask();
//	}
//	InputTask();
//}
//
//int main()
//{
//	LoadTimeTable();
//	InputTask();
//	cout<<"Het phim!";
//	return 0;
//}
