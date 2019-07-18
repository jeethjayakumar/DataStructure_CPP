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
	bool isEmpty();
	bool isFull();
public:
	Queue(int size=DEF_SIZE, double load_fact=LOAD_FACTOR);
	~Queue();
	void enqueue(int item);
	int dequeue();
	int getFront();
	int getRear();
	void dispQueue();	
};

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
