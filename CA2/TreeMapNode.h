#pragma once
#include "BSTNode.h"

#include <iostream>
#include <vector>
#include "VectorOperatorOverload.h"	// Needed to print vectors from cout <<

using namespace std;
template <class K, class V>
class TreeMapNode
{
	K key;
	V value;

public:
	TreeMapNode();
	TreeMapNode(K key, V value);
	TreeMapNode(K key);
	TreeMapNode(const TreeMapNode<K, V>& other);
	TreeMapNode<K, V>& operator=(const TreeMapNode<K, V>& other);
	bool operator>(const TreeMapNode<K, V>& other) const;
	bool operator<(const TreeMapNode<K, V>& other) const;
	bool operator==(const TreeMapNode<K, V>& other) const;
	bool operator!=(const TreeMapNode<K, V>& other) const;

	template<class K, class V>
	friend ostream& operator<<(ostream& os, const TreeMapNode<K, V>& node);

	V& getValue();
	void setValue(V value);
	K getKey() const;
	void setKey(K key);
	~TreeMapNode() = default;

};

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode()
{

}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(K key, V value)
{
	this->key = key;
	this->value = value;
}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(K key)
{
	this->key = key;
}

template<class K, class V>
TreeMapNode<K, V>::TreeMapNode(const TreeMapNode<K, V>& other)
{
	this->key = other.key;
	this->value = other.value;
}

template<class K, class V>
TreeMapNode<K, V>& TreeMapNode<K, V>::operator=(const TreeMapNode<K, V>& other)
{
	if (this != &other) {
		this->key = other.key;
		this->value = other.value;
	}
	return *this;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator>(const TreeMapNode<K, V>& other) const	// Overloaded > operator when comparing to another TreeMapNode
{
	//cout << "Comparing " << this->key << " > " << other.key << endl;
	return this->key > other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator<(const TreeMapNode<K, V>& other) const	// Overloaded < operator when comparing to another TreeMapNode
{
	//cout << "Comparing " << this->key << " < " << other.key << endl;
	return this->key < other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator==(const TreeMapNode<K, V>& other) const	// Overloaded == operator when comparing to another TreeMapNode
{
	//cout << "Comparing " << this->key << " == " << other.key << endl;
	return this->key == other.key;
}

template<class K, class V>
bool TreeMapNode<K, V>::operator!=(const TreeMapNode<K, V>& other) const	// Overloaded != operator when comparing to another TreeMapNode
{
	//cout << "Comparing " << this->key << " != " << other.key << endl;
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
K TreeMapNode<K, V>::getKey() const
{
	return this->key;
}

template<class K, class V>
void TreeMapNode<K, V>::setKey(K key)
{
	this->key = key;
}

template<class K, class V>
inline ostream& operator<<(ostream& os, const TreeMapNode<K, V>& node)
{
	os << "[Key: " << node.key << ", Value: " << node.value << "]";
	return os;
}
