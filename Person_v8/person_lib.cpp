//#include "person_lib.h"
//
//struct Node 
//{
//	Node *next;
//	Person p;
//};
//
//Node *head, *tail;
//
//void InitQueue()
//{
//	head = tail = NULL;
//}
//
//void Push(Person n_p)
//{
//	Node *el;
//	el = new Node;
//	el -> p = n_p;
//	el -> next = NULL;
//	if(head == NULL)
//	{
//		head = tail = el; 
//	}
//	else
//	{
//		tail ->next = el;
//		tail = el;
//	}
//}
//
//int Pop()
//{
//	Node *temp;
//	Person d_p;
//	
//	if(head == NULL)
//	{
//		cout<<"List empty!.\n";
//	}
//	
//	temp = head;
//	head = temp -> next;
//	d_p = temp -> p;
//	delete temp; 
//}
//
//void AddPerson(string p_detail)
//{
//	string temp, i_fname, i_dob, i_addr;
//	int i_id;
//	
//	int mark = p_detail.find(":");
//	i_id = atoi(p_detail.substr(0,mark).c_str());
//	
//	temp = p_detail.substr(mark+1);
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
//	Push(p);
//}
//
//void ReadFile(string file)
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
//void SaveFile(string file)
//{
//	ofstream fout;
//	fout.open(file.c_str());
//	Node *q;
//	q = head;
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
//	Node *q;
//	q = head;
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
