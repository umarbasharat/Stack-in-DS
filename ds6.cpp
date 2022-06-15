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



//function to check precedence
int prior(char ch)
{
  	switch(ch){
	
	case '^':
	{
	 return 3; 
	 break;
    }
	case '*' : case '/' :
	{
	return 2;
	break;		
	}
	case '+': case '-':
	{
	return 1;
	break;
	}
 }
}

int main()
{
	Stack<char>s;
	const int SIZE=25;
	char infix[SIZE];
	char postfix[SIZE]="";
	int j=0,i=0;
	cout<<"Enter infix notation"<<endl;
	cin.getline(infix,SIZE);
	
	for( i=0; infix[i] ;i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') )
		{  
			postfix[j]=infix[i];
			j++;
		}
		
			else if(infix[i]=='(')
		{
			s.push(infix[i]);
		}
		
	    
	    else if(infix[i]== ')')
	    {
	    	while(!s.isEmpty() && s.top() !='(')
	    	{
	    	 postfix[j]=s.top();
	    	 s.pop();
	    	 j++;
			}
			
			if(s.top()== '(')
			{ char c=s.top();
				s.pop();				
			}
		}
		
		else
		{ while(!s.isEmpty() && prior(infix[i]) <= prior(s.top() ) ) 
			{
			postfix[j]=s.top();
			s.pop();
			j++;
		   }
		   s.push(infix[i]);
	    }
	    
	}
	
   while(!s.isEmpty())
   {
   	postfix[j]=s.top();
   	s.pop();
   	j++;
    }
	for( i=0;postfix[i];i++)
	{
		cout<<postfix[i];
	}
	return 0;
}
