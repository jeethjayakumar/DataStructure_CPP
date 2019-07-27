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
	void setData(int data);
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

void Node::setData(int data)
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
	Node *tmp;
	curr = head;
	while (curr != nullptr)
	{
		tmp = curr;
		delete tmp;
		tmp = nullptr;
		curr = curr->getNxtp();
	}
	head = nullptr;
	tail = nullptr;
}

void Llist::insertNodeBeg(int &data)
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

void Llist::insertNodeEnd(int &data)
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

void Llist::deleteNodebyNum(int &data)
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

void Llist::deleteNodebyIdx(int &idx)
{
        bool deleted = false;
	int count = 2;

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

int Llist::searchNode(int &data)
{
	int count = 1;
	bool found = false;

	if (head->getData() == data)
	{
		return count;
	}

	curr = head->getNxtp();
	while(curr != nullptr)
	{
		count++;
		if (curr->getData() == data)
		{
			return count;
		}
		else
		{
			curr = curr->getNxtp();
		} 
	}	

	if (found == false)
		return -1;
}

void Llist::rotateNodeNtimes(int &n)
{
	
}

int Llist::findMidNode()
{
	int len = 0;
	curr = head;

	while (curr != nullptr)
	{
		len ++;	
		curr = curr->getNxtp();
	}

	int mid = len / 2;
	int count = 0;
	curr = head;
	while (curr != nullptr)
	{
		count ++;
		if (count == mid) break;
		
		curr = curr->getNxtp();
	}

	return curr->getData();
}

void Llist::display_List()
{
	curr = head;

	while (curr != nullptr)
	{
		cout<<curr->getData()<<"->";
		curr = curr->getNxtp();
	}
	cout<<"NULL\n";
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	int alen = sizeof(a)/sizeof(int);
	Llist list;

	for (int i = 0; i < alen; i++)
		list.insertNodeEnd(a[i]);

	cout<<"Input List: ";
	list.display_List();
	cout<<"\n";
	return 0;
};
