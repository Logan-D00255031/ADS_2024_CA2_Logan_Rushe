#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VectorOperatorOverload.h"

using namespace std;
void DisplayBool(bool b);

int main() 
{
	/*int a = 6;
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

	TreeMap<int, string> *map = new TreeMap<int, string>();
	map->put(1, "hi");
	map->put(2, "bye");
	map->put(3, "hello");
	cout << "string in key 3: ";
	cout << map->get(3) << endl;*/

	TreeMap<char, BinaryTree<string>> map;
	
	string fileName = "TextFile.txt";
	ifstream fin(fileName);
	if (fin)
	{
		string fileWord;
		while (!fin.eof())
		{
			fin >> fileWord;
			// Filter out any non-alphabetic characters as the word should only be comprised of letters
			string wordToInput = "";
			for (char c : fileWord)
			{
				if (isalpha(c))
				{
					wordToInput += c;
				}
			}

			if (!wordToInput.empty())
			{
				char letter = wordToInput.front();
				if (!map.containsKey(letter))
				{
					BinaryTree<string> newTree;
					newTree.add(wordToInput);
					map.put(letter, newTree);
				}
				else
				{
					map.get(letter).add(wordToInput);
				}
			}
		}
		fin.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	
	map.print();
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
