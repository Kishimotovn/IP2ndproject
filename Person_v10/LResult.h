#ifndef LRESULT_H_
#define LRESULT_H_

#include<string>
#include<iostream>
using namespace std;

class LResult{
	int mid;
	int mid_w;
	int final;
public:
	LResult();
	LResult(int i_mid, int i_mid_w, int i_final);
	void Show();
	void Setmid(int n_mid);
	void Setmid_w(int n_mid_w);
	void Setfinal(int n_final);
	int Getmid();
	int Getmid_w();
	int Getfinal();
};
#endif
