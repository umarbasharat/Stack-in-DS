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
		Stack <int> s;
	int totalVals,val,values;
	
	cout<<"How many values do you want to push into stack?? "<<endl;
	cin>>totalVals;
	
	cout<<endl;
	
	cout<<"Push\t" << totalVals << " values into stack"<<endl;
	for(int i=0;i<totalVals;i++)
	{

		if(!s.IsFull())
		{
			
			cin>>values;
			s.push(values);
		}
		
		else
		{
			cout<<"stack is full"<<endl;
		}
		
	}
	
	cout<<"Poped values are"<<endl;
	while(!s.isEmpty())
	{
		val=s.top();
		cout<< val <<endl;
		s.pop();
	}
}

