#ifndef SUBJECTS_H_
#define SUBJECTS_H_
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Subject{
		string id;
		string sname;
		string stype;
		short credit;
		string presq;
	public:
		Subject();
		Subject(string i_id, string i_sname, string i_stype, short i_credit, string i_presq);
		void Show();
		void Setid(string n_id);
		void Setsname(string n_sname);
		void Setcredit(short n_credit);
		void Setstype(string n_stype);
		short Getcredit();
		void Setpresq(string n_presq);
		string Getsname();
		string Getstype();
		string Getpresq();
};


#endif // SUBJECTS_H_
