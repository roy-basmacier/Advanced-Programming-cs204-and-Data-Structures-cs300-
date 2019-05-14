#include <iostream>

using namespace std;
/*
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/
struct node {
  char c;
  node* next;

  node(char _c, node* _next) : c(_c), next(_next) {}
};

//this is a linked list of characters, i.e., a string
class MyString {
private:
  node* head; //we store head
  node* tail; //and we store tail
public:
  MyString() {
    head = tail = nullptr;
  }

  //TODO: this function adds a new character c to the end of the list
  void addToEnd(char c) {
	//cout << "adding to end " << c << endl;
    //TODO: Implement this function
	node *nnode = new node(c, nullptr);
	if (head == nullptr)
	{
		head = nnode;
		tail = nnode;
	}
	else
	{
		node* temp = head;
		node* prv = nullptr;
		while(temp)
		{
			prv = temp;
			temp = temp->next;
		}
		prv->next = nnode;
		temp = nnode;
		tail = nnode;
	}

  }

  //TODO: this function adds a new character c to the beginning of the list
  void addToBeginning(char c) {
	  //cout << "adding to beg " << c << endl;
    //TODO: Implement this function
	  node *nnode = new node(c, nullptr);
	  if (head == nullptr)
	  {
		  head = nnode;
		  tail = nnode;
	  }
	  else
	  {
	  nnode->next = head;
	  head = nnode;
	  }

  }

  //prints the characters in the list from head to tail
  void printString() {
    node* ptr = head;
    while(ptr) {
      cout << ptr->c;
      ptr = ptr->next;
    }
    cout << endl;
  }

  //TODO: a recursive helper function to print the characters in the list from tail to head
  void printStringReverseHelper(node* ptr) {
    //TODO: Implement this function
	  if (ptr)
	  {
		  printStringReverseHelper(ptr->next);
		   cout << ptr->c;
	  }
	 
	  return;
  }

  //TODO: this function prints the characters in the list in reverse order
  void printStringReverse() {
	  //cout << "rec print" << endl;
    printStringReverseHelper(head);
    cout << endl;
  }

  //TODO: this function searches the string str (of length len) inside the linked list
  //if len == 0 return 0
  //if the string is not there, we return -1
  //if len < 0 return -2 and print "invalid string length" to the console 
  //if the string is there we return its starting point 
  int find(const char* str, int len) {
    if (len == 0)
		return 0;
	else if (len < 0)
		return -2;
	else
	{
		int cnt = 0;
		int index = 0;
		node *start_ptr = head;
		node *ptr = head;
		while(start_ptr)
		{
			for (int i = 0; i<len; i++)
			{
				if (ptr)
				{
					//cout<< ptr->c;
					if (str[i] == ptr->c)
						cnt++;
					else
					{
						cnt = 0;
					}
					ptr = ptr->next;
				}
			}
			//cout << "~";
			if (cnt == len)
				return index;	
			index += 1;
			start_ptr = start_ptr->next;
			ptr = start_ptr;
		}

		return -1;
	}

  }
  
  //TODO: this function helps the sort function
  //this nodes removes a node with the maximum char (w.r.t. ASCII) from the list
  //it returns the extracted node's address (we do not delete it)
  node* extract_max() {
	  //cout << "extracting" << endl;
    //Implement this
	  node *temp = head;
	  node *max_node = head;

	  while(temp)
	  {
		  //cout << temp->c << endl;
		  if(temp->c > max_node->c)
			  max_node = temp;
		  temp = temp->next;
	  }
	  temp = head;
	  node *prv_max = nullptr;
	  //cout << "MAX IS" << max_node->c << endl;
	  while(temp)
	  {
		  if (temp == max_node)
		  {
			  break;
		  }
		  prv_max = temp;
		  temp = temp->next;
	  }
	  if(max_node == tail)
	  {
		  prv_max->next = nullptr;
		  tail = prv_max;
	  }
	  else if(max_node == head)
	  {
		  head = max_node->next;
	  }
	  else if(tail == head)
	  {
		  head = nullptr;
		  tail = nullptr;
	  }
	  else
		  prv_max->next = max_node->next;

	  tail->next = nullptr;
	  return max_node;
  }

  //sorts the characters in the list in ASCII order by using extract_max function
  void basic_sort() {
    node* new_head = extract_max();
    tail = new_head;

    while(head) {
      node* tmp = extract_max();
      tmp->next = new_head;
      new_head = tmp;
    }

    head = new_head;
  }
};

int main() {
  MyString ms;

  ms.addToEnd('a');
  ms.addToEnd('l'); 
  ms.addToEnd('i');
  ms.printString();


  ms.addToBeginning(' ');
  ms.addToBeginning('t');
  ms.addToBeginning('E');
  ms.addToBeginning('m');
  ms.addToBeginning('h');
  ms.addToBeginning('e');
  ms.addToBeginning('m');
  ms.printString();
  ms.printStringReverse();

  cout << ms.find("kamer", 5) << endl;
  cout << ms.find("ali", 3) << endl;
  cout << ms.find("i", 1) << endl;

  ms.basic_sort();
  ms.printString();
  ms.printStringReverse();
}

