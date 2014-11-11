#ifndef COMMON_H_
#define COMMON_H_

#include <sstream>

string InttoString (short a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}

bool CheckAns()
{ 
	string ans;
	cin >> ans;
	cin.clear();
	cin.ignore(100, '\n');
	if(ans == "y")
		return true;
	else if(ans == "n")
		return false;
	else
	{
		cout<<"Input y or n: ";
		CheckAns();	
	}			
}

int CheckAnsProperties()
{ 
	string ans;
	std::getline(cin, ans);
	if(ans == "1") return 1;
	if(ans == "2") return 2;
	if(ans == "3") return 3;
	if(ans == "4") return 4;
	cout << "Moi so ma cung nhap sai! Nhap lai de .,l,, : ";
	return CheckAnsProperties();
}
#endif
