#include "course.h"

int main()
{
	//empty course
	Course c1;
	c1.Show();
	
	
	//course(string i_sid, int i_lid, short i_sem, string i_room, string i_time_starth, string i_time_endh, string i_time_date)
	Course c2("ICT101", 101, 1, "710", "9h", "12h", "Fri");
	c2.Show();
	
	c1.Setsid("Phys102");
	c1.Setlid(102);
	c1.Setsem(3);
	c1.Setroom("205");
	c1.Settime_starth("9h30");
	c1.Settime_endh("11h25");
	c1.Settime_date("Sat");
	c1.Show();
	
	Course c3(c1.Getsid(), c1.Getlid(), c1.Getsem(), c1.Getroom(), c1.Gettime_starth(), c1.Gettime_endh(), c1.Gettime_date());
	c3.Show();
	
	system("pause");
	return 0;	
}
