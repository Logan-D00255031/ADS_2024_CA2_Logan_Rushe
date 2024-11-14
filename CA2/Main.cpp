#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

#include <iostream>
#include "Main.h"

using namespace std;
void DisplayBool(bool b);

int main() 
{
	int a = 6;
	int b = 5;
	TreeMapNode<int, int> *n = new TreeMapNode<int, int>(4);
	TreeMapNode<int, int> *n2 = new TreeMapNode<int, int>(5);
	//cout << n->getKey() << " < " << n2->getKey() << endl;
	bool test = n < n2;
	DisplayBool(test);
	test = n > n2;
	DisplayBool(test);
	test = n == n2;
	DisplayBool(test);
	test = n != n2;
	DisplayBool(test);
	//cout << test << endl;
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
