#include "Course.h"

	Course::Course()
	{
		sid = "";
		lid = 0;
		sem = 0;
		room = "";
		time_starth = "";
		time_endh = "";
		time_date = "";
		time = "";
	}
	
	Course::Course(string i_sid, int i_lid, short i_sem, string i_room, string i_time_starth, string i_time_endh, string i_time_date)
	{
		sid = i_sid;
		lid = i_lid;
		sem = i_sem;
		room = i_room;
		time_starth = i_time_starth;
		time_endh = i_time_endh;
		time_date = i_time_date;
		time = i_time_starth + ":" + i_time_endh + ":" + i_time_date;
	}
		
	void Course::Setsid(string i_sid)
	{
		sid = i_sid;
	}
	void Course::Setlid(int i_lid)
	{
		lid = i_lid;
	}
	void Course::Setsem(short i_sem)
	{
		sem = i_sem;
	}
	void Course::Setroom(string i_room)
	{
		room = i_room;
	}
	void Course::Settime_starth(string i_time_starth)
	{
		time_starth = i_time_starth;
	}
	
	void Course::Settime_endh(string i_time_endh)
	{
		time_endh = i_time_endh;
	}
	void Course::Settime_date(string i_time_date)
	{
		time_date = i_time_date;
	}
	void Course::Settime(string i_time_starth, string i_time_endh, string i_time_date)
	{
		time_starth = i_time_starth;
		time_endh = i_time_endh;
		time_date = i_time_date;
		time = i_time_starth + ":" + i_time_endh + ":" + i_time_date;
	}
		
	string Course::Getsid()
	{
		return sid;
	}
	int Course::Getlid()
	{
		return lid;
	}
	short Course::Getsem()
	{
		return sem;
	}
	string Course::Getroom()
	{
		return room;
	}
	string Course::Gettime_starth()
	{
		return time_starth;
	}
	string Course::Gettime_endh()
	{
		return time_endh;
	}
	string Course::Gettime_date()
	{
		return time_date;
	}
	string Course::Gettime()
	{
		return time;
	}
		
	void Course::Show()
	{
		cout<<sid<<":"<<lid<<":"<<sem<<":"<<room<<":"<<time_starth<<":"<<time_endh<<":"<<time_date<<endl;
	}
	
	void Course::Showtt()
	{
		cout<<time_date<<" from "<<time_starth<< " to " <<time_endh<<": "<<sid<<" in room: "<<room<<endl;
	}
