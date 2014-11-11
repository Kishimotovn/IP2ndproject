#include <memory>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>

using namespace std;

template <typename DataType>
class LinkedList
{
	struct Node
	{
		DataType data;
		Node *next;
		//Node(DataType d, Node *n = 0):data(d), next(n){}
	};
	
	Node *head, *tail;
	
	public:
		LinkedList();
		void Push(DataType x);
		void Erase(Node *loc);
		void ReadFile(string file, DataType (*Getinfo)(string));
		void ShowList();
		Node *search(DataType d);
		Node *search(string info);
};	

	template<typename DataType>
		LinkedList<DataType>::LinkedList()
		{
			head = tail = NULL;
		}
		
		template<typename DataType>
		void LinkedList<DataType>::Push(DataType x)
		{
			Node *el;
			el = new Node;
			el -> data = x;
			el -> next = NULL;
			if(head == NULL)
			{
				head = tail = el; 
			}
			else
			{
				tail ->next = el;
				tail = el;
			}
		}
		
		template<typename DataType>
		void LinkedList<DataType>::Erase(Node *loc)
		{
			if(loc == head)
			{
				Node *temp = head;
				head = head ->next;
				delete temp;
				return;
			}
			Node *cur = head;
			while(cur)
			{
				if(cur->next == loc)
				{
					cur -> next = loc  -> next;
					delete loc;
				}
				cur = cur -> next;
			}
		}
		
		
		template<typename DataType>
		void LinkedList<DataType>::ReadFile(string file, DataType (*Getinfo)(string))
		{
			ifstream fin;
			fin.open(file.c_str());
			if(!fin.is_open())
			{
				cout<<"Cant read the file.\n";
				exit(1);
			}
			else{
				string temp = "";
				while (getline(fin,temp))
				{
					Push(Getinfo(temp));
				}
				fin.close();
			}
		}
		
		template<typename DataType>
		void LinkedList<DataType>::ShowList()
		{
			Node *cur;
			cur = head;
			if(cur == NULL)
			{
				cout<<"List epmty.\n";
			}
			else
			{
				do
				{
					cur -> data.Show();
					cur = cur->next;
				}while (cur != NULL);
			}
		}
		
		template<typename DataType>
		typename LinkedList<DataType>::Node* LinkedList<DataType>::search(DataType d)
		{
			if(!head)
			{
				cout<<"Empty List";
				return NULL;
			}
			Node *cur = head;
			while(cur)
			{
				if(cur->data == d)
					return cur;
				cur = cur ->next;
			}
			return NULL;
		}
		
		template<typename DataType>
		typename LinkedList<DataType>::Node* LinkedList<DataType>::search(string info)
		{
			if(!head)
			{
				cout<<"Empty List";
				return NULL;
			}
			Node *cur = head;
			while(cur)
			{
				if(cur->data.Find(info) != 0)
					return cur;
				cur = cur ->next;
			}
			return NULL;
		}
