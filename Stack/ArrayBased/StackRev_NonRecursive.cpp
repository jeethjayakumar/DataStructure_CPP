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
	{
		data[++top] = Item;
	}
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

void stackReversal(Stack &dat, Stack &rev_dat)
{
	int temp;
	while(dat.isEmpty()==false)
	{
		temp = dat.pop();
		rev_dat.push(temp);
	}	
}

int main()
{
	Stack dat, rev_dat;
	int a[] = {1,2,3,4,5};
	int alen = sizeof(a)/sizeof(int);

	for (int i =0 ; i < alen; i++)
		dat.push(a[i]);

	cout<<"Before Reversal, Input Stack:\n";
	dat.dispFull();

	stackReversal(dat, rev_dat);

	cout<<"After Reversal, Stack:\n";
	rev_dat.dispFull();
 
	return 0;
}
