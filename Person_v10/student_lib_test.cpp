#include "student_lib.h"
void InputTask()
{
	cout << "[1]Show all Student\n" << "[2]Find\n" << "[3]Modify\n" << "[4]Addnew\n" << "input task: " ;
	int task = CheckAnsProperties();
	if (task == 1)
	{
		SListShow();
	}
	if(task == 2)
	{
		cout<< "Search By: " << "[1] program\n" << "[2] endyear" << "[3]classroom\n";
		int c = CheckAnsProperties();
		if(c == 1)
		{
			cout<<"Input program's name: ";
			string _program;
			getline(cin, _program);
			Searchprogram(_program);
		}
		if(c == 2)
		{
			cout<<"Input endyear (int): ";
			int _endyear;
			cin >> _endyear;
			Searchendyear(_endyear);
		}
		if(c == 3)
		{
			cout<<"Input class's name: ";
			string _classroom;
			getline(cin, _classroom);
			Searchclass(_classroom);
		}
	}
	if(task == 3)
	{
		ModifyStudent();
	}
	if(task == 4)
	{
		AddnewStudent();
	}
	cout<<"More? ";
	if(CheckAns())
		InputTask();
}

int main()
{
	ReadFile("Student.txt");
	
//	CSaveFile("a.txt");
//	
//	ModifyStudent();
//	AddnewStudent();

	InputTask();
	system("pause");
	return 0;	
}


