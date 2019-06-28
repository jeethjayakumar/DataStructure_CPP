#include <iostream>
using namespace std;

#define DEF_SIZE 10

class Stack
{
	char *braces;
	int top;
	int len;
	bool isFull();
public:
	Stack();
	Stack(int size);
	~Stack();
	bool isEmpty();
	void push(char c);
	char pop();
	char getTop();
	void dispFull();
};

Stack::Stack()
{
	len = DEF_SIZE;
	top = -1;
	braces = new char[len];
}

Stack::Stack(int size)
{
	len = (size == 0) ? DEF_SIZE : size;
	top = -1;
	braces = new char [len];
}

Stack::~Stack()
{
	delete [] braces;
	len = 0;
	top = -1;
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return (top == len);
}

void Stack::push(char c)
{
	if (isFull() != true)
	{
		braces[++top] = c;
	}
}

char Stack::pop()
{
	if (isEmpty() != true)
	{
		char temp = braces[top];
		top --;
		len --
		return braces[top];
	}
}

char Stack::getTop()
{
	return braces[top];
}

void Stack::dispFull()
{
	for (int i = 0; i <= len; i++)
		cout<<braces[i]<<"\n";
}


bool validate_string(string inp)
{
	int i;
	Stack s(inp.length());
	bool res = true;
	char c_temp;

	for (i = 0; i < inp.length() && res == true; i++)
	{
		if (inp[i] == '(' ||
		    inp[i] == '{' ||
		    inp[i] == '<' ||
		    inp[i] == '[')
			s.push(inp[i]);
		else
		{
			if (s.isEmpty() == false)
			{	
				switch(inp[i])
				{
					case ')':
						if (s.getTop() != '(') 
							res = false;
						else c_temp = s.pop();
						break;
					case '}': 
						if (s.getTop() != '{') 
							res = false;
						else c_temp = s.pop();
						break;
					case '>': 
						if (s.getTop() != '<') 
							res = false;
						else c_temp = s.pop();
						break;
					case ']': 
						if (s.getTop() != '[') 
							res = false;
						else c_temp = s.pop();
						break;
					default:
						continue;
				}
			}
		}
	}

	return s.isEmpty();
}

int main()
{
	string inp = "((a+b))";
	bool result = validate_string(inp);

	if (result == true)
		cout<<inp<<" is a valid string\n";
	else
		cout<<inp<<" is not a valid string\n";
}
