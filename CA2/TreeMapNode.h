#pragma once
#include "BSTNode.h"

#include <iostream>

using namespace std;
template <class K, class V>
class TreeMapNode
{
	K key;
	V value;

public:
	TreeMapNode();
	TreeMapNode(K key);
	TreeMapNode(const TreeMapNode<K, V>& other);
	TreeMapNode<K, V> operator=(const TreeMapNode<K, V>& other);
	bool operator>(const TreeMapNode<K, V>& other) const;
	bool operator<(const TreeMapNode<K, V>& other) const;
	bool operator==(const TreeMapNode<K, V>& other) const;
	bool operator!=(const TreeMapNode<K, V>& other) const;
	V& getValue();
	void setValue(V value);
	K getKey();
	void setKey(K key);
	~TreeMapNode();

};

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode()
{
	key = nullptr;
}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(K key)
{
	this->key = key;
}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(const TreeMapNode<K, V>& other)
{
	key = nullptr;
	if (other.key != nullptr) 
	{
		this->key = *other.key;
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
		this->key = *other.key;
	}
}

template<class K, class V>
bool TreeMapNode<K, V>::operator>(const TreeMapNode<K, V>& other) const	// Overloaded > operator when comparing to another TreeMapNode
{
	return getKey() > other.getKey();
}

template<class K, class V>
bool TreeMapNode<K, V>::operator<(const TreeMapNode<K, V>& other) const	// Overloaded < operator when comparing to another TreeMapNode
{
	return getKey() < other.getKey();
}

template<class K, class V>
bool TreeMapNode<K, V>::operator==(const TreeMapNode<K, V>& other) const	// Overloaded == operator when comparing to another TreeMapNode
{
	return getKey() == other.getKey();
}

template<class K, class V>
bool TreeMapNode<K, V>::operator!=(const TreeMapNode<K, V>& other) const	// Overloaded != operator when comparing to another TreeMapNode
{
	return getKey() != other.getKey();
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
K TreeMapNode<K, V>::getKey()
{
	return this->key;
}

template<class K, class V>
void TreeMapNode<K, V>::setKey(K key)
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