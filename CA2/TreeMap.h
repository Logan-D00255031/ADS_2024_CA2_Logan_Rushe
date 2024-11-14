#pragma once
#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"

#include <iostream>

using namespace std;

template <class K, class V>
class TreeMap
{
	BinaryTree<TreeMapNode<K, V>> *BST;

public:
	TreeMap();
	TreeMap(const TreeMap<K, V>& other);
	TreeMap<K, V> operator=(const TreeMap<K, V>& other);
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	V& operator[](K key);
	~TreeMap<K, V>();

};

template <class K, class V>
TreeMap<K, V>::TreeMap()
{
	BST = nullptr;
}

template <class K, class V>
TreeMap<K, V>::TreeMap(const TreeMap<K, V>& other)
{
	BST = nullptr;
	if (other.BST != nullptr)
		BST = new TreeMap<K, V>(*other.BST);
}

template <class K, class V>
TreeMap<K, V> TreeMap<K, V>::operator=(const TreeMap<K, V>& other)
{
	if (this == &other)
		return *this;
	if (other.BST != nullptr)
		BST = new TreeMap<K, V>(*other.BST);
	else
		BST = nullptr;
	return *this;
}

template<class K, class V>
void TreeMap<K, V>::clear()
{
	BST->clear();
	delete BST;
	BST = nullptr;
}

template<class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	TreeMapNode<K, V> desiredKey = new TreeMapNode<K, V>(key);
	if (BST->get(desiredKey))
	{
		return true;
	}
	return false;
}

template<class K, class V>
V& TreeMap<K, V>::get(K key)
{
	// TODO: insert return statement here
}

template<class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	return BinaryTree<K>();
}

template<class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
}

template<class K, class V>
int TreeMap<K, V>::size()
{
	return 0;
}

template<class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	return false;
}

template<class K, class V>
inline V& TreeMap<K, V>::operator[](K key)
{
	// TODO: insert return statement here
}

template <class K, class V>
TreeMap<K, V>::~TreeMap()
{

}
