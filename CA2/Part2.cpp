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

int main() 
{
	TreeMap<char, BinaryTree<string>> map;
	
	// The name of the file that the application will try to read
	// Example file is "TextFile.txt"
	string fileName = "";
	cout << "File name (include file extension): ";
	cin >> fileName;

	ifstream fin(fileName);
	if (fin)
	{
		// Raw string from file
		string fileString;
		while (!fin.eof())
		{
			fin >> fileString;
			//cout << "New string from file: " <<  fileString << endl;
			
			// Filtered word from file
			string wordToInput = "";
			// Filter out any non-alphabetic characters from the string, as the word should contain letters
			for (char c : fileString)
			{
				if (isalpha(c))
				{
					wordToInput += tolower(c);	// Convert to lowercase to avoid duplicate letters/words in the TreeMap
				}
			}
			
			// If there were no letters, we ignore it and move to the next string in the file
			if (!wordToInput.empty())
			{
				char letter = wordToInput.front();
				if (!map.containsKey(letter))
				{
					BinaryTree<string> newTree;
					newTree.add(wordToInput);
					map.put(letter, newTree);
					//cout << "New key '" << letter << "' added" << endl;
				}
				else
				{
					map.get(letter).add(wordToInput);
					//cout << "Added new word '" << wordToInput << "' to key '" << letter << "'" << endl;
				}
			}
		}
		fin.close();
	}
	else
	{
		cout << "Unable to open file - File may not exist." << endl << "Please check spelling and that you included the file extension." << endl;
		return 1;
	}

	BinaryTree<char> keyTree(map.keySet());
	cout << "Letters contained in file: " << keyTree << endl << endl;
	
	char* keyArr = keyTree.toArray();

	cout << "List of words in file by letter: " << endl;
	for (int i = 0; i < keyTree.count(); i++)
	{
		cout << keyArr[i] << ": " << map.get(keyArr[i]) << endl;
	}

	//map.print();
	return 0;
}
