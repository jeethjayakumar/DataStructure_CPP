#include <iostream>
using namespace std;
#define DEF_SIZE 10

class Stack
{
	int *data;
	int top;
	int len;
	bool isFull();
public:
	Stack(int size);
	Stack();
	~Stack();
	bool isEmpty();
	void push(int Item);
	int pop();
	int getTop();
	void dispFull();
	int getTopIdx();
};

Stack::Stack()
{
	len = DEF_SIZE;
	data = new int[len];
	top = -1;
}

Stack::Stack(int size)
{
	if (size == 0) 
		len = DEF_SIZE;
	else 
		len = size;
	
	data = new int[len];
	top = -1;
}

Stack::~Stack()
{
	delete [] data;
	top = -1;
}

void Stack::push(int Item)
{
	if (isFull() == true)
		cout<<"Stack Full!!! Cannot add more elements!!!\n";
	else
		data[++top] = Item;
}

int Stack::getTopIdx()
{
	return top;
}

int Stack::pop()
{
	int temp;
	if (isEmpty() != true)
	{
		temp = data[top];
		top--;
		return temp;
	}
	else
	{
		cout<<"Stack Empty!!! No elements to remove from stack!!!\n";
		return -1;
	}
}

int Stack::getTop()
{
	return data[top];
}

void Stack::dispFull()
{
	for (int i = 0; i <= top; i++)
		cout<<data[i]<<"\n";
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return (top == len);
}

void populateStack(int &a_i, Stack &dat, Stack &mindata)
{
	int min_temp, dat_temp;

	if (dat.isEmpty())
	{
		dat.push(a_i);
		mindata.push(-1);
	}
	else
	{
		min_temp = mindata.getTop();
		dat_temp = dat.getTop();
		if (a_i > dat_temp)
		{
			if (min_temp == -1)
			{
				min_temp = dat_temp;
			}
			else
			{
				if (min_temp > dat_temp)
				{
					min_temp = dat_temp;
				}
			}
		}
		else
		{
			if ((min_temp != -1) && (a_i < min_temp))
				min_temp = -1;
		}
		
		dat.push(a_i);
		mindata.push(min_temp);
	}
}


int main()
{
	Stack dat, mindata;
	int a[] = {5,6,4,8,3,2,1};
//	int a[] = {4,5,2,10,8};
	int alen = sizeof(a)/sizeof(int);

	for (int i = 0; i < alen; i++) 
		populateStack(a[i], dat, mindata);

	cout<<"Input Stack Data: \n";
	dat.dispFull();

	cout<<"Min Stack Data: \n";
	mindata.dispFull();

	cout<<"Current Smallest Element: "<<mindata.getTop()<<"\n";
	return(0);
}
