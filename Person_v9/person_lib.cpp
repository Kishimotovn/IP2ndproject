//#include "person_lib.h"
//
//struct LNode 
//{
//	LNode *next;
//	Person p;
//};
//
//LNode *Subhead, *Subtail;
//
//void InitQueue()
//{
//	Subhead = Subtail = NULL;
//}
//
//void SubPush(Person n_p)
//{
//	LNode *el;
//	el = new LNode;
//	el -> p = n_p;
//	el -> next = NULL;
//	if(Subhead == NULL)
//	{
//		Subhead = Subtail = el; 
//	}
//	else
//	{
//		Subtail ->next = el;
//		Subtail = el;
//	}
//}
//
//int SubPop()
//{
//	LNode *temp;
//	Person d_p;
//	
//	if(Subhead == NULL)
//	{
//		cout<<"List empty!.\n";
//	}
//	
//	temp = Subhead;
//	Subhead = temp -> next;
//	d_p = temp -> p;
//	delete temp; 
//}
//
//void AddPerson(string p_deSubtail)
//{
//	string temp, i_fname, i_dob, i_addr;
//	int i_id;
//	
//	int mark = p_deSubtail.find(":");
//	i_id = atoi(p_deSubtail.substr(0,mark).c_str());
//	
//	temp = p_deSubtail.substr(mark+1);
//	mark = temp.find(":");
//	i_fname = temp.substr(0,mark);
//	
//	temp = temp.substr(mark+1);
//	mark = temp.find(":");
//	i_dob = temp.substr(0,mark);
//	
//	temp = temp.substr(mark+1);
//	mark = temp.find(":");
//	i_addr = temp.substr(0,mark);
//	
//	Person p(i_id, i_fname, i_dob, i_addr);
//	SubPush(p);
//}
//
//void CReadFile(string file)
//{
//	ifstream fin;
//	fin.open(file.c_str());
//	if(!fin.is_open())
//	{
//		cout<<"Cant read the file.\n";
//		exit(1);
//	}
//	else{
//		string temp = "";
//		while (getline(fin,temp))
//		{
//			AddPerson(temp);
//		}
//		fin.close();
//	}
//}
//void CSaveFile(string file)
//{
//	ofstream fout;
//	fout.open(file.c_str());
//	LNode *q;
//	q = Subhead;
//	while(q != NULL)
//	{
//		fout<<q->p.Getid()<<":"<<q->p.Getfname()<<":"<<q->p.Getdob()<<":"<<q->p.Getaddr()<<endl;
//		q = q -> next;
//	}
//	fout.close();
//}
//
//void PListShow()
//{
//	LNode *q;
//	q = Subhead;
//	if(q == NULL)
//	{
//		cout<<"List epmty.\n";
//	}
//	else
//	{
//		do
//		{
//			q -> p.Show();
//			q = q->next;
//		}while (q != NULL);
//	}
//}
