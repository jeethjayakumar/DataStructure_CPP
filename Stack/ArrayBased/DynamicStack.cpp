#include <iostream>
#include <cstdlib>
using namespace std;

#define DEF_SIZE 5
#define DEF_LOAD_FACTOR 0.5

class Stack
{
	int *a;
	int top;
	int len;
	double load_fact;
	bool isFull();
	void reallocate();
public:
	Stack();
	Stack(int size, double l_factor);
	~Stack();
	bool isEmpty();
	void push(int a_data);
	int pop();
	int getTop();
	void display();
};

Stack::Stack()
{
	len = DEF_SIZE;
	a = new(nothrow) int[len];
	if (a == nullptr)
	{
		cout<<"Error allocating the memory for Stack!!! Aborting!!!\n";
		exit(-1);
	}
	top = -1;
	load_fact = DEF_LOAD_FACTOR;
}

Stack::Stack(int size, double l_factor)
{
	if (size == 0)
		len = DEF_SIZE;
	else
		len = size;

	if (l_factor == 0.0)
		load_fact = DEF_LOAD_FACTOR;
	else
		load_fact = l_factor;

	top = -1;

	a = new (nothrow) int [len];
	if (a == nullptr)
	{
		cout<<"Error allocating the memory for Stack!!! Aborting!!!\n";
		exit(-1);
	}
}

Stack::~Stack()
{
	if (isEmpty())
	{
		cout<<"Stack Empty!!!Nothing to free!!!\n";
	}
	else
	{
		delete [] a;
	}
	a = nullptr;
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return (top == len);
}

void Stack::reallocate()
{
	int size_inc;
	int *tmp_arr;

	size_inc = len * load_fact;
	tmp_arr = new(nothrow) int[len + size_inc];
	if (tmp_arr == nullptr)
	{
		cout<<"Error reallocating memory!!! Aborting!!!\n";
		delete [] a;
		a = nullptr;
		exit(-1);
	}
	else
	{
		for (int i = 0; i <= len; i++)
		{
			tmp_arr[i] = a[i];
		}
		delete [] a;
		a = tmp_arr;
		len += size_inc;
	}
}

void Stack::push(int a_data)
{
	if (isFull())
		reallocate();
	a[++top] = a_data;
}

int Stack::pop()
{
	int temp = a[top];
	top--;
	return temp;
}

int Stack::getTop()
{
	return a[top];
}

void Stack::display()
{
	for (int i = 0; i <= top; i++)
		cout<<a[i]<<"\n"; 
}

int main()
{
	Stack s;
	int a[] = {1,2,3,4,5};
	int alen = sizeof(a)/sizeof(int);
	int i;
	
	for (i = 0; i < alen; i++)
		s.push(a[i]);

	cout<<"Current Stack contents: \n";
	s.display();

	int b[] = {6,5,4,3,2,1};
	int blen = sizeof(b)/sizeof(int);

	for (i = 0; i < blen; i++)
		s.push(b[i]);

	cout<<"Current Stack contents: \n";
	s.display();

	return 0;
}
