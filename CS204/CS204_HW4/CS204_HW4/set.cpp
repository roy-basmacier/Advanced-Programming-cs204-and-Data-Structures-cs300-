#include "set.h"

// ~~~~~ LINKED LIST ~~~~~
//

linkedList::linkedList(node *headptr = nullptr) : head(headptr) {}

linkedList::linkedList(int arr[], int size) // makes linked list
{
	head = nullptr;
	for(int i = 0; i < size; i++)
	{
		this->add2end(arr[i]);
	}

}

linkedList::linkedList(const linkedList & copy) // copy constructor
{
	head = copy.createClone();
}

node * linkedList::createClone() const // copy constructor helper
{
	if (head == nullptr)
		return nullptr;

	node * head_clone = new node(head->val, nullptr);
	node * ptr = head->next;
	node * ptr_clone = head_clone;
	while(ptr)
	{
		ptr_clone->next = new node(ptr->val, nullptr);
		ptr = ptr->next;
		ptr_clone = ptr_clone->next;
	}
	return head_clone;
}

void linkedList::add2end(int val) // adds node to end
{
	node *nnode = new node(val, nullptr);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		node *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}

}

bool linkedList::operator==(const linkedList & ll) // compares two linked lists
{
	node * lhs_ptr = this->head;
	node * rhs_ptr = ll.head;

	//both are nullptr
	if(lhs_ptr == rhs_ptr)
		return true;

	if(lhs_ptr != nullptr && rhs_ptr != nullptr)
	{
		while(true)
		{
			if(lhs_ptr && rhs_ptr && lhs_ptr->val == rhs_ptr->val)
			{
				lhs_ptr = lhs_ptr->next;
				rhs_ptr = rhs_ptr->next;
				if(lhs_ptr == nullptr && rhs_ptr == nullptr)
					return true;
			}
			else
				return false;

		}

	}

	// one is null other is notr
	else
		return false;

	return true;
}

// ~~~~~~ SET ~~~~~
//
Set::Set(const Set & copy) // copy constructor
{
	head = copy.createClone();
}

setNode *Set::createClone() const // copy constructor helper
{
	if(head == nullptr)
		return nullptr;

	linkedList *ll = head->listptr;
	setNode * head_clone = new setNode(ll, nullptr);
	setNode * ptr = head->next;
	setNode * ptr_clone = head_clone;
	while(ptr)
	{
		linkedList *ll_clone = ptr->listptr;
		ptr_clone->next = new setNode((ll_clone), nullptr);
		ptr = ptr->next;
		ptr_clone = ptr_clone->next;
	}
	return head_clone;
}

void Set::addSet(int arr[], int size) // makes/adds linked list to end of set
{
	linkedList *ll = new linkedList(arr, size);
	setNode *nnode = new setNode(ll);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		setNode *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}
	
}

void Set::addSet(linkedList ll) // adds linked list to end of set
{
	linkedList *ll_clone = new linkedList();
	ll_clone->head = ll.head;
	setNode *nnode = new setNode(ll_clone);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		setNode *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}
	
}

bool Set::hasList(linkedList *ll)
{
	setNode * ptr = this->head;
	if (ptr == nullptr)
		return false;

	while(ptr)
	{
		if(*ptr->listptr == *ll )
			return true;

		ptr = ptr->next;
	}
	return false;
}

Set Set::operator+(const Set & rhs)
{
	Set result = *this;
	setNode * ptr = rhs.head;
	
	if(ptr != nullptr)
	{
		while(ptr)
		{
			//if not in result then add
			if(! hasList(ptr->listptr))
			{
				result.addSet(*ptr->listptr);

			}
			ptr = ptr->next;
		}

	}

	return result;
}

Set Set::operator%(const Set & rhs)
{
	Set result, rhs_tmp = rhs;
	setNode * ptr = this->head;
	
	if(ptr != nullptr)
	{
		while(ptr)
		{
			//if both not in result then add
			if(hasList(ptr->listptr) && rhs_tmp.hasList(ptr->listptr))
			{
				result.addSet(*ptr->listptr);

			}
			ptr = ptr->next;
		}
	}
	return result;
}

Set Set::operator/(const Set & rhs)
{
	Set result, rhs_tmp = rhs;
	setNode * ptr = this->head;
	
	if(ptr != nullptr)
	{
		while(ptr)
		{
			//if not in rhs then add
			if(!rhs_tmp.hasList(ptr->listptr))
			{
				result.addSet(*ptr->listptr);
			}
			ptr = ptr->next;
		}
	}
	return result;
}