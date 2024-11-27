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
	void print();
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

// Clears all data from the TreeMap
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

// Checks if the Tree contains the specified key
// Returns True if it does, or False otherwise
template<class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	// The Tree does not contain the key if it's null or empty
	if (BST == nullptr || BST->root == nullptr) 
	{
		return false;
	}

	TreeMapNode<K, V> desiredKey(key);
	try {
		TreeMapNode<K, V> foundKey = BST->get(desiredKey);
		return foundKey.getKey() == key;
	}
	// BST's get() method will throw an error if it does not contain the key so we catch it to return false
	catch (const logic_error&)
	{
		return false;
	}
}

// Returns the value associated with the specified key
// Throws a logic error if the key cannot be found
template<class K, class V>
V& TreeMap<K, V>::get(K key)
{
	// Throw a logic error if BST is null or empty, or it does not contain the key
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

// Returns a BinaryTree of all the keys contained in the TreeMap
// Returns an empty tree if no data is stored in the TreeMap
template<class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	// return empty BinaryTree if BST is empty or null to prevent errors
	if (BST == nullptr || BST->root == nullptr)
	{
		return BinaryTree<K>();
	}

	TreeMapNode<K, V>* keyArr = BST->toArray();

	BinaryTree<K> keyTree;
	for (int i = 0; i < BST->count(); i++)
	{
		K key = keyArr[i].getKey();
		keyTree.add(key);
	}

	delete[] keyArr;
	return keyTree;
}

// Sets the value of the specified key in the TreeMap to the given value
// Will add a new key to the TreeMap if it has yet to be added
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

// Returns the size of the TreeMap
template<class K, class V>
int TreeMap<K, V>::size()
{
	// Its size is zero if BST is null
	if (BST == nullptr)
	{
		return 0;
	}
	// The size is the same as BST's size so we call its count method
	return BST->count();
}

// Removes the specified key from the TreeMap
// Returns True if successful, or False if the key was not found
template<class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	// There is no key to remove if BST is null
	if (BST == nullptr)
	{
		return false;
	}
	TreeMapNode<K, V> keyToRemove(key);
	return BST->remove(keyToRemove);
}

template<class K, class V>
V& TreeMap<K, V>::operator[](K key)
{
	// This method uses the same logic as get() to prevent duplicate code
	return this->get(key);
}

// Outputs the TreeMap to the console
template<class K, class V>
void TreeMap<K, V>::print()
{
	cout << *BST << endl;
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
