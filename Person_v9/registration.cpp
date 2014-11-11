#include "registration.h"

using namespace std;

Registration::Registration(){
	sid="";
	lid=0;
	stid="";
}

Registration::Registration(string i_sid, int i_lid, string i_stid)
{
	sid=i_sid;
	lid=i_lid;
	stid=i_stid;
}
void Registration::Show()
{
	cout << sid<<" : "<<lid<<" : "<<stid<<"\n";
}
void Registration::Setsid(string n_sid)
	{
		sid = n_sid;
	}
void Registration::Setlid(int n_lid)
	{
		lid = n_lid;
	}
void Registration::Setstid(string n_stid)
	{
		stid = n_stid;
	}
string Registration::Getsid()
	{
		return sid;
	}
int Registration::Getlid()
	{
		return lid;
	}	
string Registration::Getstid()
	{
		return stid;
	}
