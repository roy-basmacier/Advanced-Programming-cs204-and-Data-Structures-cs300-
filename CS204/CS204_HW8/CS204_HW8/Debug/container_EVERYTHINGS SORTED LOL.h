#include<iostream>
using namespace std;

struct node
{
	int info;
	node * next;
	node(int i = 0, node* ptr = nullptr) : info(i), next(ptr){}
};

class Container
{
public:
	Container(node* n = nullptr) : head(n){cout << "a";};
	virtual ~Container(){};
	virtual void insertElement(int) = 0;
	virtual void deleteElement(int) = 0;
	virtual void print() = 0;
protected:
	node* head; // or top or first
};



class LinkedList: public Container
{
public:
	LinkedList(){};
	~LinkedList()
	{
		cout << "Destructing LinkedList\n";
		node * ptr = head;
		node * prv = nullptr;
		while(ptr)
		{
			if(prv)
				delete prv;
			prv = ptr;
			ptr = ptr->next;
		}
		if(prv)
			delete prv;
	}
	void insertElement(int i)
	{
		cout << i << " is inserted to linked list\n";
		// no nodes in list
		if(head == nullptr)
			head = new node(i);
		
		// only one node
		else if (head->next == nullptr)
		{
			if(i > head->info)
				head->next = new node(i);
			else
				head = new node(i,head);
		}
		
		//more than one node in list
		else
		{
			node* ptr = head;
			node* prv = nullptr;
			while(ptr)
			{
				//checking where to insert i
				if (i < ptr->info)
					break;

				prv = ptr;
				ptr = ptr->next;
			}
			node * nnode = new node(i, nullptr);
			if(prv != nullptr)
			{
				prv->next = nnode;
				nnode->next = ptr;
			}
			else
			{
				head = nnode;
				nnode->next = ptr;
			}
		}

	}
	void deleteElement(int i)
	{
		node * ptr = head;
		node * prv = nullptr;
		node * temp;
		while(ptr)
		{
			if (ptr->info == i)
				break;
			prv = ptr;
			ptr = ptr->next;
		}
		
		// if node is between two nodes
		if(prv)
		{
			temp = prv;
			prv->next = ptr->next;
			delete temp;
		}

		//if node is the first element
		else if (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}

		//if node not in list
		else
		{
			cout << i << " not found in  linkedlist.\n";
			return; 
		}
		cout << i << " is deleted from the linkedlist.\n";
	};
	void print()
	{
		cout << "Printing linked list\n";
		node* ptr = head;
		while(ptr)
		{
			cout << ptr->info << " ";
			ptr = ptr->next;
		}

	}
	
};

class Stack : public Container
{
public:
	Stack(){};
	~Stack()
	{ 
		int _;
		cout << "Destructing Stack\n";
		while(!isEmpty())
			pop(_);
	}
	void insertElement(int i) // recursive sorted insert
	{
		
		// finding the position we want to insert the new node to

		// if given i is the smallest number
		if(isEmpty())
		{
			cout << "Inserting " << i << " to stack\n";
			push(i);
			return;
		}

		int x;
		pop(x);
		

		// if i is smaller than the top remove top and check next until we find a smaller value
		if(i < x)
		{
			insertElement(i);
			push(x);
		}
		else
		{
			cout << "Inserting " << i << " to stack\n";
			push(x);
			push(i);
		}

	}
	void deleteElement(int i) // recursive delete
	{
		// end of stack
		if(isEmpty())
		{
			cout << i  << " not in stack\n";
			return;
		}

		int x;
		pop(x);
		if(x == i)
		{
			cout << "deleting " << i << " from stack\n";
			return;
		}
		deleteElement(i);
		push(x);




	}

	void print()
	{
		cout << "Printing Stack\n";
		printHelper();
		cout << "\n";
	}
private:
	void printHelper() //recursive print
	{
		if(!isEmpty())
		{
			int x;
			pop(x);
			printHelper();
			cout << x << " ";
			push(x);
		}
	}
	void push(int i) // inserts node to top
	{
		node * nnode = new node(i);
		if(isEmpty())
			head = nnode;
		else
		{
			nnode->next = head;
			head = nnode;
		}
	}
	void pop(int &x)//removes top and returns ref of node's info
	{
		node *temp;
		if(isEmpty())
			cout << "The stack is empty\n";
		else
		{
			x = head->info;
			temp =  head->next;
			delete head;
			head = temp;
		}
	}
	bool isEmpty()
	{
		if (head)
			return false;
		return true;
	}
};



class Queue : public Container
{
public:
	Queue(node * end = nullptr, int s = 0): rear(end), size(s){}
	~Queue()
	{
		int _;
		cout << "Destructing queue\n";
		while(!isEmpty())
			dequeue(_);
	}
	void insertElement(int i)
	{
		cout << "Inserting " << i << " to queue\n";
		bool inserted = false;
		if(isEmpty())
			enqueue(i);
		else
		{
			int x;
			int SIZE = size, j = 0;
			for(; j<SIZE; j++)
			{
				dequeue(x);
				if(x > i && !inserted)
				{
					enqueue(i);
					inserted = true;
				}

				enqueue(x);
			}
			if (!inserted)
				enqueue(i);
		}

	}
	void deleteElement(int i)
	{
		int x;
		int SIZE = size, j = 0;
		for(; j < SIZE; j++)
		{
			dequeue(x);
			if(x != i)
				enqueue(x);
		}

	}
	void print()
	{
		int x;
		cout << "printing queue\n";
		for(int i = 0; i < size; i++)
		{
			dequeue(x);
			cout << x << " ";
			enqueue(x);
		}
		cout << "\n";
	}
private:
	void enqueue(int i)
	{
		size++;
		node * nnode = new node(i);
		if(isEmpty())
		{
			head = nnode;
			rear = head;
		}
		else
		{
			rear->next = nnode;
			rear = nnode;
		}

	}
	void dequeue(int &x)
	{
		node * temp;
		if(!isEmpty())
		{
			size--;
			x = head->info;
			temp = head;
			head = head->next;
			delete temp;
		}

	}
	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}
	int size;
	node * rear;
};
