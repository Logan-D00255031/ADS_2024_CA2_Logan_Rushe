#pragma once
#include "BSTNode.h"

#include <iostream>

using namespace std;
template <class K, class V>
class TreeMapNode
{
	BSTNode<K> *key;
	V value;

public:
	TreeMapNode();
	TreeMapNode(K key);
	TreeMapNode(const TreeMapNode<K, V>& other);
	TreeMapNode<K, V> operator=(const TreeMapNode<K, V>& other);
	bool operator>(const TreeMapNode<K, V>& other);
	bool operator<(const TreeMapNode<K, V>& other);
	bool operator==(const TreeMapNode<K, V>& other);
	bool operator!=(const TreeMapNode<K, V>& other);
	V& getValue();
	void setValue(V value);
	BSTNode<K>* getKey(K key);
	void setKey(BSTNode<K> *key);
	~TreeMapNode();

};

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode()
{
	key = nullptr;
}

template<class K, class V>
inline TreeMapNode<K, V>::TreeMapNode(K key)
{
	this->key = *key;
}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(const TreeMapNode<K, V>& other)
{
	key = nullptr;
	if (other.key != nullptr) 
	{
		this->key = new BSTNode<K>(*other.key);
	}
}

template<class K, class V>
TreeMapNode<K, V> TreeMapNode<K, V>::operator=(const TreeMapNode<K, V>& other)
{
	if (this == &other)
	{
		return this;
	}
	key = nullptr;
	if (other.key != nullptr)
	{
		this->key = new BSTNode<K>(*other.key);
	}
}

template<class K, class V>
bool TreeMapNode<K, V>::operator>(const TreeMapNode<K, V>& other)	// Overloaded > operator when comparing to another TreeMapNode
{
	return this->key > other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator<(const TreeMapNode<K, V>& other)	// Overloaded < operator when comparing to another TreeMapNode
{
	return this->key < other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator==(const TreeMapNode<K, V>& other)	// Overloaded == operator when comparing to another TreeMapNode
{
	return this->key == other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator!=(const TreeMapNode<K, V>& other)	// Overloaded != operator when comparing to another TreeMapNode
{
	return this->key != other.key;
}

template<class K, class V>
V& TreeMapNode<K, V>::getValue()
{
	return this->value;
}

template<class K, class V>
void TreeMapNode<K, V>::setValue(V value)
{
	this->value = value;
}

template<class K, class V>
BSTNode<K>* TreeMapNode<K, V>::getKey(K key)
{
	return this->key;
}

template<class K, class V>
void TreeMapNode<K, V>::setKey(BSTNode<K>* key)
{
	this->key = key;
}

template<class K, class V>
TreeMapNode<K, V>::~TreeMapNode()
{
	if (key != nullptr) 
	{
		delete key;
		key = nullptr;
	}
}