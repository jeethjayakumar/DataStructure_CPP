#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *nxt_p;
public:
	Node(int data = -1, Node *nxt_p = nullptr);
	~Node();
	void createNode(int data, Node *nxt);
	int getData();
};

class Llist
{
	Node *head;
	Node *curr;
	Node *tail;
public:
	Llist();
	~Llist();
	void insertNodeBeg(int &data);
	void insertNodeEnd(int &data);
	void deleteNodebyNum(int &data);
	void deleteNodebyIdx(int &idx);
	int searchNode(int &data);
	void rotateNodeNtimes(int &n);
	int findMidNode();
	void display_List(); 
};

Node::Node(int data, Node *nxt_p)
{
	this->data = data;
	this->nxt_p = nxt_p;
}

Node::~Node()
{
	nxt_p = nullptr;
}

Llist::Llist()
{
	head = new Node();
	curr = new Node();
	tail = new Node();
	head = curr = tail = nullptr;	
}

Llist::~Llist()
{

}

void Llist::insertNodeBeg(int data)
{

}

void Llist::insertNodeEnd(int data)
{

}

void Llist::deleteNodebyNum(int data)
{

}

void Llist::deleteNodebyIdx(int idx)
{

}

int Llist::searchNode(int data)
{

}

void Llist::rotateNodeNtimes(int n)
{

}

int Llist::findMidNode()
{

}

void Llist::display_List()
{

}

int main()
{
	return 0;:
};
