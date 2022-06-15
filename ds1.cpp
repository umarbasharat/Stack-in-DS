#include<iostream>
using namespace std;

template <typename T>
class Stack {

	private:
		int top,size;
		T *data;

	public:
	Stack(int s=100)
	{
		size=s;
		data=new int [size];
		top=0;
	}
	
	void push(T v)
	{
		top++;
		data[top]=v;
	}
	
	void pop()
	{
	   top--;	
	}	
	
	T Top() const
	{
		return data[top];
	}
	
	bool isEmpty() const
	{
		return top==0;
	}
	
	bool isFull() const
	{
	   return top==size;	
	}
	
	void makeEmpty()
	{
		top=0;
	}
	
	~Stack()
	{
		delete [] data;
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

		if(!s.isFull())
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
		val=s.Top();
		cout<< val <<endl;
		s.pop();
	}
}
