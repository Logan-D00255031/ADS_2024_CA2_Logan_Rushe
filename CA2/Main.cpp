#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

#include <iostream>

using namespace std;

int main() 
{
	TreeMapNode<int, int> *n = new TreeMapNode<int, int>(5);
	TreeMapNode<int, int>* n2 = new TreeMapNode<int, int>(6);
	cout << (n > n2) << endl;
}