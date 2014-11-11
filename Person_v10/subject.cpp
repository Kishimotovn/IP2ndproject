#include "Subject.h"

using namespace std;

    Subject::Subject() {
        id="";
        sname="";
        stype="";
        credit=0;
        presq="";
    }

	Subject::Subject(string i_id, string i_sname, string i_stype, short i_credit, string i_presq)
	{
	    id=i_id;
		sname = i_sname;
		stype = i_stype;
		credit=i_credit;
		presq = i_presq;
	}

	void Subject::Show()
	{
		cout << id<<" : "<<sname<<" : "<<stype<<" : "<<credit<<" : "<<presq<<"\n";
	}

	void Subject::Setid(string n_id)
	{
		id = n_id;
	}

	void Subject::Setsname(string n_sname)
	{
		sname = n_sname;
	}

	void Subject::Setstype(string n_stype)
	{
		stype = n_stype;
	}

	void Subject::Setcredit(short n_credit)
	{
		credit = n_credit;
	}

	void Subject::Setpresq(string n_presq)
	{
		presq = n_presq;
	}


	string Subject::Getid()
	{
		return id;
	}
	
	string Subject::Getsname()
	{
		return sname;
	}

	string Subject::Getstype()
	{
		return stype;
	}

	short Subject::Getcredit()
	{
		return credit;
	}

	string Subject::Getpresq()
	{
		return presq;
	}
	
	Subject Subject::Getinfo(string s)
	{		
	string temp, i_id, i_sname, i_stype, i_presq;
	short i_credit;
	
	int mark = s.find(":");
	i_id = s.substr(0,mark);
	
	temp = s.substr(mark+1);
	mark = temp.find(":");
	i_sname = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_stype = temp.substr(0,mark);
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_credit = atoi(temp.substr(0,mark).c_str());
	
	temp = temp.substr(mark+1);
	mark = temp.find(":");
	i_presq = temp.substr(0,mark);
	
	Subject n_sub(i_id, i_sname, i_stype, i_credit, i_presq);
	return n_sub;
	}	
