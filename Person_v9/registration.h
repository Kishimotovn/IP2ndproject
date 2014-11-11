#ifndef REGISTRATION_H_
#define REGISTRATION_H_

#include<string>
#include<iostream>
using namespace std;

class Registration{
	string sid;
	int lid;
	string stid;

public:
	Registration();
	Registration(string i_sid, int i_lid, string i_stid);
	void Show();
	void Setsid(string n_sid);
	void Setstid(string n_stid);
	void Setlid(int n_lid);
	int Getlid();
	string Getsid();
	string Getstid();
	};
#endif
