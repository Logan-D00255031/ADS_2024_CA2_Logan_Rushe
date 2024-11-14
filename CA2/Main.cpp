#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

#include <iostream>

using namespace std;
void DisplayBool(bool b);

int main() 
{
	int a = 6;
	int b = 5;
	TreeMapNode<int, int> node1(a);
	TreeMapNode<int, int> node2(b);
	TreeMapNode<int, int> node3(a);
	bool test = node1 < node2;
	DisplayBool(test);
	test = node1 > node2;
	DisplayBool(test);
	test = node3 == node1;
	DisplayBool(test);
	test = node1 != node3;
	DisplayBool(test);
}

void DisplayBool(bool b)
{
	if (b)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
}
