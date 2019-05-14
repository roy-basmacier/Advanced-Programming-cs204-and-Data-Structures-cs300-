#include "HashTable.h"
#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

template <class K, class V>
bool HashTable<K, V>::isPrime(int x)
{
    if (x < 2)
        return false;
	int i = 2;
    while(1)
    {
        int q = x / i;
        if (q < i)
            return true;
        if (x == q * i)
            return false;
		i++;
    }
    return true;
}

template <class K, class V>
int HashTable<K, V>::nextPrime(int x)
{
	while (!isPrime(x))
		x++;
	return x;
}

template <class K, class V>
HashTable<K, V>::HashTable(int s, double lf = 0.15, tableNode<K, V>* head = nullptr): size(s),loadFactor(lf), arr(new tableNode<K, V>*[s]())
{
	int uniqueWord = 0;
	double clf = 0.0;

	tableNode<K, V>* itr = head;
	while(itr)
	{
		uniqueWord++;
		clf = uniqueWord/(size *1.0);
		if(clf > loadFactor)
			break;

		// adds to hashtable
		addKey(itr);
		itr = itr->next;
	}
	if (clf > loadFactor)
		rehash(head);
}

template <class K, class V>
HashTable<K, V>::~HashTable()
{

}

template <class K, class V>
void HashTable<K, V>::rehash(tableNode<K, V>* head)
{
	int uniqueWord = 0;
	double clf = 0.0; // current load factor
	cout << "rehashing...\nprevious table size: " << size;
	int newSize = nextPrime(2 * size);

	// TODO EMPTY HASHTABLE
	makeEmpty();
	arr = new tableNode<K, V>*[newSize]();

	size = newSize;
	cout << ", new table size: " << size << " current unique word count ";

	tableNode<K, V>* itr = head;
	while(itr)
	{
		uniqueWord++;
		clf = uniqueWord/(size * 1.0);
		if(clf > loadFactor)
		{
			cout << uniqueWord << ", current load factorasd: " << clf<< endl;
			break;
		}

		// add to hashtable
		addKey(itr);
		itr = itr->next;
	}
	if (clf > loadFactor)
		rehash(head);
	else
	{
		cout << uniqueWord << ", current load factorasd: " << clf/2.0 << endl;
	}




}

template <class K, class V>
void HashTable<K, V>::addKey(tableNode<K, V>* node)
{
	int i = hash(node->key);
	tableNode<K, V>* nnode = new tableNode<K, V>(node->key, node->value);
	// case1: the index is empty
	if (arr[i] == nullptr)
		arr[i] = nnode;
	//
	else
	{
		tableNode<K, V>* itr = arr[i];
		while(itr)
			itr = itr->next;

		itr = nnode;

	}

}

template <class K, class V>
tableNode<K, V>* HashTable<K, V>::search(K key)
{
	return arr[hash(key)];
}


template <class K, class V>
int HashTable<K, V>::hash(K word)
{
	int h = 1;
	int pow;
	for(int i = 0; i < word.size(); i++)
	{
		pow = 54;
		for (int j = 0; j < i; j++)
		{
			pow *= pow;
			pow = pow %size;
		}
		h += pow * word[i];
		h %= size;
	}
	return h % size;
}

template <class K, class V>
void HashTable<K, V>::makeEmpty()
{
	tableNode<K, V>* ptr, *itr;
	for(int i = 0; i < size; i++)
	{
		if(arr[i])
		{
			itr = arr[i];
			while(itr)
			{
				ptr = itr;
				itr = itr->next;
				delete ptr;
			}

		}

	}
	arr = nullptr;
}


#endif