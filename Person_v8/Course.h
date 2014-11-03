#ifndef COURSE_H_
#define COURSE_H_

#include<cstring>
#include<string>
#include<iostream>

using namespace std;
class Course
{
	string sid;
	int lid;
	short sem;
	string room;
	string time_starth;
	string time_endh;
	string time_date;
	string time = time_starth + ":"+ time_endh +":"+ time_date;
	
	public:
		Course();
		Course(string i_sid, int i_lid, short i_sem, string i_room, string i_time_starth, string i_time_endh, string i_time_date);
		
		void Setsid(string i_sid);
		void Setlid(int i_lid);
		void Setsem(short i_sem);
		void Setroom(string i_room);
		void Settime_starth(string i_time_starth);
		void Settime_endh(string i_time_endh);
		void Settime_date(string i_time_date);
		void Settime(string i_time_starth, string i_time_endh, string i_time_date);
		
		string Getsid();
		int Getlid();
		short Getsem();
		string Getroom();
		string Gettime_starth();
		string Gettime_endh();
		string Gettime_date();
		string Gettime();
		
		void Show();
};
#endif
