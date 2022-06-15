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
	Stack<int>s;
	string str;
	char expression[100];
	int a=0,b=0,digit;
	cout<<"Enter a postfix expression"<<endl;
	cin.getline(expression,100);
	
	for(int i=0; expression[i]; i++ )
	{
		if(expression[i] >= '0' && expression[i] <= '9')
		{
			int digit=expression[i]- 48;
			s.push(digit);
		}
		else if(expression[i] == '+')
		{
		    a=s.top();
			s.pop();
		    b=s.top();
			s.pop();
			s.push(a+b);
		}
		else if(expression[i] == '-')
		{
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			s.push(a-b);
		}
		else if(expression[i] == '*')
		{
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			s.push(a*b);
		}
		else if(expression[i] == '/')
		{
			a=s.top();
			s.pop();
			b=s.top();
			s.pop();
			s.push(a/b);
		}
	}
	cout<<s.top();
	s.pop();
}
