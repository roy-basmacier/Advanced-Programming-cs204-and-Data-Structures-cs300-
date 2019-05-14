#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
using namespace std;

template <class K, class V>
struct tableNode
{
	K key;
	V value;
	tableNode<K, V>* next;
	tableNode(K k = "", V v = "", tableNode<K, V>* nxt = nullptr) : key(k), value(v), next(nxt) {}
};

template <class K, class V>
class HashTable
{
public:
	HashTable(int, double,tableNode<K, V>*);
	~HashTable();

	int hash(K);
	bool isPrime(int);
	int nextPrime(int); 

	void rehash(tableNode<K, V>*);
	void addKey(tableNode<K, V>*);
	void makeEmpty();
	tableNode<K, V>* search(K);
	tableNode<K, V> **arr;
	int size;
	double loadFactor; //limit
};
#include "HashTable.cpp"
#endif