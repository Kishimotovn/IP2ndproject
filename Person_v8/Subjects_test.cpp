#include "Subjects.h"
#include<cstdlib>
int main()
{
	//empty subject
	Subject s1;
	s1.Show();
	Subject s2("ICT 2.2", "Sniping", "Optional",2,"Winking 1.1");
	s2.Show();
	s1.Setid("Sniping");
	s1.Setsname("ICT 2.2");
	s1.Setstype("Optional");
	s1.Setcredit(2);
	s1.Setpresq("Winking 1.1");
	s1.Show();
	system("pause");
	return 0;
}
