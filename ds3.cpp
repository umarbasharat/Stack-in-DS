#include<iostream>
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
	char s1[100];
	char s2[100];
	int i=0;
	
	cout<<"Enter a string"<<endl;
//	cin.ignore();
	cin.getline(s1,100);

  for(int i=0; s1[i]; i++)
   {
  	s.push(s1[i]);
   }
  
  cout<<endl;
  cout<<"Reverse string is"<<endl;
  
   	while(!s.isEmpty())
   	{
	s2[i]=s.top();
   	cout<<s2[i];
   	s.pop();
   }

}

