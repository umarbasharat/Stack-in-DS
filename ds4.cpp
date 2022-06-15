#include<iostream>
#include<fstream>
using namespace std;

template <typename T>
struct Node{
	Node<T> *Next;
	T data;
};

template <typename T>
class Stack
{
	private:
	Node <T> *topPtr;
	
	public:
	Stack()
	{
	 topPtr=NULL;	
	}	
     
	void push(T value)
	{
		Node <T> *temp;
		temp=new Node<T>;
		temp->data=value;
		temp->Next=topPtr;
		topPtr=temp;
	} 
	
	void pop()
	{
		if(!isEmpty())
		{
		Node <T> *temp;
		temp=topPtr;
		topPtr=topPtr->Next;
		delete temp;
		}
		else{
			cout<<"Stack is empty"<<endl;
			
		}
		
	}
	
	
	T top() const
	{
		if(!isEmpty())
		return topPtr->data;
	}
	
	bool isEmpty() const
	{
		return topPtr==NULL;
	}
	
	bool IsFull() const
	{
		//return topPNULL;
		Node <T> *temp;
		temp=new Node <T>;
		if(temp==NULL) return true;
		else 
		{
			delete temp;
			return false;
		}
	}
	
	void make_Empty()
	{
		while(!isEmpty())
		pop();
	}
 
  ~Stack()
  {
  	delete[]topPtr;
  }
		
};

int main()
{
	Stack <char> s;
	const int SIZE=100;
	char balanced[SIZE];
	int i;
	
	cout<<"Enter a string"<<endl;
	cin.getline(balanced,SIZE);
	fstream fout;
	
	fout.open("Balanced.txt",ios::out);
	if(!fout) cout<<"File does not exist";
	else
	{
		for(int i=0; balanced[i]; i++)
		fout<<balanced[i];
			
	}
	fout.close();
	
	//Now read file
	char ch; 
	fstream fin;
	fin.open("Balanced.txt",ios::in);
	
	if(!fin) cout<<"File does not found"<<endl;
	
	else
	{
		while(!fin.eof())
		{
			fin.getline(balanced,SIZE);
			cout<<balanced;
		}
	    cout<<endl;
	    
		for(int i=0; balanced[i] ;i++)
	    {
		  if(!s.IsFull())
		  {
			if(balanced[i]== '(' || balanced[i]=='[' || balanced[i] == '{')
		    {
				s.push(balanced[i]);
			}
		  } 
		
		  if(!s.isEmpty())
		  {
			if(s.top()=='{' && balanced[i]== '}' || s.top()=='[' && balanced[i]==']' || s.top()=='(' && balanced[i]==')' )
			{
				ch=s.top();
				s.pop();
			}
		  }
	    }
	
	}
	
	
	//Expression will be imbalaced when stack is not empty
	
	if(s.isEmpty())
	{
	 cout<<"Expression is balanced"<<endl;	
	}
	
	else
	{
	 cout<<"Expression is imbalanced";
	}
}
