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
	if (BST == nullptr || BST->root == nullptr)
	{
		return;
	}
	BST->clear();
	delete BST;
	BST = nullptr;
}

template<class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	if (BST == nullptr || BST->root == nullptr) 
	{
		return false;
	}
	TreeMapNode<K, V> desiredKey(key);
	try {
		TreeMapNode<K, V> foundKey = BST->get(desiredKey);
		return foundKey.getKey() == key;
	}
	catch (const logic_error&)
	{
		return false;
	}
}

template<class K, class V>
V& TreeMap<K, V>::get(K key)
{
	if (BST == nullptr || BST->root == nullptr)
	{
		throw logic_error("Tree is empty");
	}
	if (!containsKey(key))
	{
		throw logic_error("Item not found");
	}
	TreeMapNode<K, V> desiredKey(key);
	TreeMapNode<K, V>& foundKey = BST->get(desiredKey);
	return foundKey.getValue();
}

template<class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	// return empty BinaryTree if BST is empty or nullptr to prevent errors
	if (BST == nullptr || BST->root == nullptr)
	{
		return BinaryTree<K>();
	}

	TreeMapNode<K, V>* keyArr = BST->toArray();

	BinaryTree<K> keyTree;
	for (int i = 0; i < BST->count(); i++)
	{
		keyTree.add(keyArr[i].getKey());
	}

	delete[] keyArr;
	return keyTree;
}

template<class K, class V>
void TreeMap<K, V>::put(K key, V value)
{
	if (BST == nullptr)
	{
		BST = new BinaryTree<TreeMapNode<K, V>>();
	}
	if (!containsKey(key))
	{
		TreeMapNode<K, V> newNode(key, value);
		BST->add(newNode);
	}
	else
	{
		TreeMapNode<K, V> desiredKey(key);
		TreeMapNode<K, V>& currentKey = BST->get(desiredKey);
		currentKey.setValue(value);
	}
}

template<class K, class V>
int TreeMap<K, V>::size()
{
	return BST->count();
}

template<class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	return BST->remove(new TreeMapNode<K, V>(key));
}

template<class K, class V>
V& TreeMap<K, V>::operator[](K key)
{
	if (!containsKey(key))
	{
		throw logic_error("Key not found");
	}
	TreeMapNode<K, V> foundKey = BST->get(new TreeMapNode<K, V>(key));
	return foundKey.getValue();
}

template <class K, class V>
TreeMap<K, V>::~TreeMap()
{
	if (BST != nullptr) 
	{
		delete BST;
		BST = nullptr;
	}
}
