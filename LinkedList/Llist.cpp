#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *nxt_p;
public:
	Node(int data = -1, Node *nxt_p = nullptr);
	~Node();
	int getData();
	void setData(int &data);
	void setNxtp(Node *nxt);
	Node* getNxtp();
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
  	delete nxt_p;
	nxt_p = nullptr;
}

int Node::getData()
{
	return data;
}

void Node::setData(int &data)
{
	this->data = data;
}

void Node::setNxtp(Node *nxt)
{
	nxt_p = nxt;
}

Node* Node::getNxtp()
{
	return nxt_p;
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
	delete head;
	delete curr;
	delete tail;
	head = curr = tail = nullptr;	
}

void Llist::insertNodeBeg(int data)
{
	Node *temp = new Node(data, nullptr);	
	
	if (head == nullptr)
	{
		head = curr = tail = temp;
	}
	else
	{
		temp->setNxtp(head);
		head = temp;
	}
}

void Llist::insertNodeEnd(int data)
{
	Node *temp = new Node(data, nullptr);

	if (head == nullptr)
	{
		head = curr = tail = temp;
	}
	else
	{
		tail->setNxtp(temp);
		tail = temp;
	}
}

void Llist::deleteNodebyNum(int data)
{
	bool deleted = false;
	
	if (head->getData() == data)
	{
		head = head->getNxtp();
		deleted = true;	
	}
	else
	{
		curr = head->getNxtp();
		while (curr != nullptr)
		{
			if (curr->getData() == data)
			{
				Node *temp = curr->getNxtp();
				curr->setData(temp->getData());
				curr->setNxtp(temp->getNxtp());
				delete temp;
				temp = nullptr;
				deleted = true;	
				break;
			}
			else
				curr = curr->getNxtp();	
		}
	}

	if (deleted == true)
        	cout<<"Number "<<data<<" deleted from the list\n";	
	else
		cout<<"Number "<<data<<" not found in list to delete!!!\n";
}

void Llist::deleteNodebyIdx(int idx)
{
        bool deleted = false;

	if (idx <= 0)
	{
		cout<<"Invalid index "<<idx<<" !!! Index value starts with 1 ...\n";
		return ;
	}
	
	if (idx == 1) // Deleting the first node
	{
		head = head->getNxtp();
		deleted = true;	
	}
	else
	{
		curr = head->getNxtp();
		int count = 2;
		
		while (curr != nullptr)
		{
			if (count == idx)
			{
				Node* temp = curr->getNxtp();
				curr->setData(temp->getData());
				curr->setNxtp(temp->getNxtp());
				delete temp;
				temp = nullptr;
				deleted = true;
				break;	
			}
			else
			{
				curr = curr->getNxtp();
				count++;
			}

		}	
	}

	if (deleted == true)
	{
		cout<<"Element of idx "<<idx<<" is deleted!!!\n";
	}
	else
	{
		cout<<"List not long enough!!! Length of the current list is "<<count<<"\n";
	}
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
