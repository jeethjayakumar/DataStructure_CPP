#include <iostream>
using namespace std;

#define DEF_SIZE 10
#define LOAD_FACTOR 0.5

class Queue
{
	int *data;
	int size;
	int front;
	int rear;
	double load_fact;
	bool isFull();
	void reallocate();
public:
	Queue(int size=DEF_SIZE, double load_fact=LOAD_FACTOR);
	~Queue();
	void enqueue(int item);
	void dequeue();
	int getFront();
	int getRear();
	void dispQueue();	
	bool isEmpty();
};

Queue::Queue(int size, double load_fact)
{
	if (size == 0)
		this->size = DEF_SIZE;
	else
		this->size = size;
	
	if (load_fact == 0.0)
		this->load_fact = LOAD_FACTOR;
	else
		this->load_fact = load_fact;

	data = new(nothrow) int[size];
	front = -1;
	rear = -1;	
}

Queue::~Queue()
{
	delete [] data;
	front = -1;
	rear = -1;
	load_fact = 0.0;
	size = 0;
}

bool Queue::isEmpty()
{
	return (front == -1);
}

bool Queue::isFull()
{
	return (((rear + 1)%size) == front);
}

void Queue::reallocate()
{
	int newsize = size + (size * load_fact);
	int *new_data = new int [newsize];

	if (new_data == nullptr)
	{
		cout<<"Error reallocating memory!!! Aborting!!!\n";
		delete [] data;
		data = nullptr;
		size = 0;
		exit (-1);	
	}
	else
	{
		for (int i = front; i < size; i++)
			new_data[i] = data[i];
		delete [] data;
		data = new_data;
		size = newsize;
		cout<<"New Queue size: "<<size<<"\n";	
	}
}

void Queue::enqueue(int item)
{
	if (isFull())
	{
		cout<<"Queue space full... Increasing the size!!!\n";	
		reallocate();
	}

	rear = (rear + 1) % size;
	data[rear] = item;
	
	if (front == -1) front = rear;
}

void Queue::dequeue()
{
	if (isEmpty())
	{
		cout<<"Queue is Empty... Nothing to dequeue...\n";
	}
	else
	{
		int val = data[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front+1)%size;
		cout<<"Removing "<<val<<"\n";
	}
}

int Queue::getFront()
{
	return data[front];
}

int Queue::getRear()
{
	return data[rear];
}

void Queue::dispQueue()
{
	for (int i = front; i <= rear; i++)
		cout<<data[i]<<" ";
	cout<<"\n";
}

int main()
{
	Queue q;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int b[] = {11,12,13,14,15,16};
	int alen = sizeof(a)/sizeof(int);
	int blen = sizeof(b)/sizeof(int);
	int i;

	for (i = 0; i < alen; i++)
		q.enqueue(a[i]);

	cout<<"Current Queue data: ";
	q.dispQueue();
	
	cout<<"Adding new data...\n";
	for(i = 0; i < blen; i++)
		q.enqueue(b[i]);

	cout<<"Current Queue data: ";
	q.dispQueue();
	
	return 0;
}
