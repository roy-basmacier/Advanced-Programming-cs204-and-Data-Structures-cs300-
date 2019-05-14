//#include "set.h"

// ~~~~~ LINKED LIST ~~~~~
//
template <class itemType>
linkedList<itemType>::linkedList(node<itemType> *headptr = nullptr) : head(headptr) {}

template <class itemType>
linkedList<itemType>::linkedList(itemType arr[], int size) // makes linked list
{
	head = nullptr;
	for(int i = 0; i < size; i++)
	{
		this->add2end(arr[i]);
	}

}

template <class itemType>
linkedList<itemType>::linkedList(const linkedList<itemType> & copy) // copy constructor
{
	head = copy.createClone();
}

template <class itemType>
node<itemType> * linkedList<itemType>::createClone() const // copy constructor helper
{
	if (head == nullptr)
		return nullptr;

	node<itemType> * head_clone = new node<itemType>(head->val, nullptr);
	node<itemType> * ptr = head->next;
	node<itemType> * ptr_clone = head_clone;
	while(ptr)
	{
		ptr_clone->next = new node<itemType>(ptr->val, nullptr);
		ptr = ptr->next;
		ptr_clone = ptr_clone->next;
	}
	return head_clone;
}

template <class itemType>
void linkedList<itemType>::add2end(itemType val) // adds node to end
{
	node<itemType> *nnode = new node<itemType>(val, nullptr);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		node<itemType> *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}

}

template <class itemType>
bool linkedList<itemType>::operator==(const linkedList<itemType> & ll) // compares two linked lists
{
	node<itemType> * lhs_ptr = this->head;
	node<itemType> * rhs_ptr = ll.head;

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
template <class itemType>
Set<itemType>::Set(const Set<itemType> & copy) // copy constructor
{
	head = copy.createClone();
}

template<class itemType>
setNode<itemType> *Set<itemType>::createClone() const // copy constructor helper
{
	if(head == nullptr)
		return nullptr;

	linkedList<itemType> *ll = head->listptr;
	setNode<itemType> * head_clone = new setNode<itemType>(ll, nullptr);
	setNode<itemType> * ptr = head->next;
	setNode<itemType> * ptr_clone = head_clone;
	while(ptr)
	{
		linkedList<itemType> *ll_clone = ptr->listptr;
		ptr_clone->next = new setNode<itemType>((ll_clone), nullptr);
		ptr = ptr->next;
		ptr_clone = ptr_clone->next;
	}
	return head_clone;
}

template <class itemType>
void Set<itemType>::addSet(itemType arr[], int size) // makes/adds linked list to end of set
{
	linkedList<itemType> *ll = new linkedList<itemType>(arr, size);
	setNode<itemType> *nnode = new setNode<itemType>(ll);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		setNode<itemType> *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}
	
}

template <class itemType>
void Set<itemType>::addSet(linkedList<itemType> ll) // adds linked list to end of set
{
	linkedList<itemType> *ll_clone = new linkedList<itemType>();
	ll_clone->head = ll.head;
	setNode<itemType> *nnode = new setNode<itemType>(ll_clone);
	
	if(head == nullptr)
	{
		head = nnode;
	}
	else
	{
		setNode<itemType> *ptr = head, *prv = nullptr;
		while(ptr)
		{
			prv = ptr;
			ptr = ptr->next;
		}
		prv->next = nnode;
	}
	
}

template <class itemType>
bool Set<itemType>::hasList(linkedList<itemType> *ll)
{
	setNode<itemType> * ptr = this->head;
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

template <class itemType>
Set<itemType> Set<itemType>::operator+(const Set<itemType> & rhs)
{
	Set<itemType> result = *this;
	setNode<itemType> * ptr = rhs.head;
	
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

template <class itemType>
Set<itemType> Set<itemType>::operator%(const Set<itemType> & rhs)
{
	Set<itemType> result, rhs_tmp = rhs;
	setNode<itemType> * ptr = this->head;
	
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

template <class itemType>
Set<itemType> Set<itemType>::operator/(const Set<itemType> & rhs)
{
	Set<itemType> result, rhs_tmp = rhs;
	setNode<itemType> * ptr = this->head;
	
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