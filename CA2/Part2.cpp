#include "BSTNode.h"
#include "BinaryTree.h"
#include "TreeMapNode.h"
#include "TreeMap.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "VectorOperatorOverload.h"
#include <iomanip>

using namespace std;

int PartTwo();
int StageFour();

int main() 
{
	string stage = "";
	cout << "Run Part 2 or Stage 4? (2 or 4): ";
	cin >> stage;

	if (stage == "2")
	{
		return PartTwo();
	}
	else if (stage == "4")
	{
		return StageFour();
	}
	else
	{
		cout << "Invalid option. Please rerun and try again." << endl;
		return 1;
	}
}

int PartTwo()
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

struct Game
{
	string title;
	string releaseDate;
	string genre;
	string platform;
	double price;
};

TreeMap<string, vector<Game>> createIndex(const vector<Game>& data, const string& field);
void printIndex(TreeMap<string, vector<Game>>& index, const string& field);
vector<Game> searchForValueByField(TreeMap<string, vector<Game>>& index, string& value);
void printResults(vector<string>& headers, vector<Game>& games);
bool containsHeader(vector<std::string>& headers, std::string& field);

TreeMap<string, vector<Game>> createIndex(const vector<Game>& data, const string& field)
{
	TreeMap<string, vector<Game>> index;
	for (Game game : data)
	{
		string key;
		if (field == "game_title")
		{ key = game.title; }
		else if (field == "release_date") 
		{ key = game.releaseDate; }
		else if (field == "genre") 
		{ key = game.genre; }
		else if (field == "platform") 
		{ key = game.platform; }
		else if (field == "price") 
		{ key = to_string(game.price); }

		if (!key.empty())
		{
			if (index.containsKey(key))
			{
				index[key].push_back(game);
			}
			else
			{
				vector<Game> newTree;
				newTree.push_back(game);
				index.put(key, newTree);
			}
		}
	}
	return index;
}

void printIndex(TreeMap<string, vector<Game>>& index, const string& field)
{
	cout << setw(25) << left << field << setw(25) << left << "count" << endl;

	BinaryTree<string> keyTree(index.keySet());
	string* keyArr = keyTree.toArray();

	bool isPrice = field == "price";
	for (int i = 0; i < keyTree.count(); i++)
	{
		cout << setw(25) << left;
		// Print the price field values as doubles
		if (isPrice)
		{
			cout << stod(keyArr[i]);
		}
		else
		{
			cout << keyArr[i];
		}
		cout << setw(25) << left << index.get(keyArr[i]).size() << endl;
	}
}

vector<Game> searchForValueByField(TreeMap<string, vector<Game>>& index, string& value)
{
	vector<Game> results;
	results = index.get(value);
	return results;
}

void printResults(vector<string>& headers, vector<Game>& results)
{
	for (string column : headers)
	{
		cout << setw(25) << left << column;
	}
	cout << endl;
	for (Game g : results)
	{
		cout << setw(25) << left << g.title << setw(25) << left << g.releaseDate << setw(25) << left << g.genre << setw(25) << left << g.platform << g.price << endl;
	}
}

bool containsHeader(vector<std::string>& headers, std::string& field)
{
	for (string header : headers)
	{
		if (field == header)
		{
			return true;
		}
	}
	return false;
}

int StageFour()
{
	string fileName = "VideoGames.csv";

	vector<Game> games;
	vector<string> headers;

	ifstream fin(fileName);
	if (fin)
	{
		string column;
		for (int i = 0; i < 4; i++)
		{
			getline(fin, column, ',');
			headers.push_back(column);
		}
		getline(fin, column, '\n');
		headers.push_back(column);

		while (!fin.eof())
		{
			Game newGame;
			//cout << "reading title..." << endl;
			getline(fin, newGame.title, ',');
			//cout << "reading release date..." << endl;
			getline(fin, newGame.releaseDate, ',');
			//cout << "reading genre..." << endl;
			getline(fin, newGame.genre, ',');
			//cout << "reading platform..." << endl;
			getline(fin, newGame.platform, ',');
			string price;
			//cout << "reading price..." << endl;
			getline(fin, price, '\n');
			newGame.price = stod(price);

			games.push_back(newGame);
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		return 1;
	}

	cout << "Data read from " << fileName << ": " << endl;
	printResults(headers, games);


	cout << endl << endl << "Create an Index from a field " << headers << ": ";

	string field;
	cin >> field;

	bool isHeader = containsHeader(headers, field);

	if (isHeader)
	{
		TreeMap<string, vector<Game>> newIndex = createIndex(games, field);
		printIndex(newIndex, field);
	}
	else
	{
		cout << "Invalid field." << endl;
	}


	cout << endl << endl << "Search for a value from a field " << headers << ": ";
	cin >> field;

	if (!containsHeader(headers, field))
	{
		cout << "Invalid field." << endl;
		return 1;
	}

	cout << endl << "Value: ";
	string value;
	cin >> value;

	if (field == "price")
	{
		double price = stod(value);
		value = to_string(price);
	}

	TreeMap<string, vector<Game>> newIndex = createIndex(games, field);
	vector<Game> results = searchForValueByField(newIndex, value);
	
	if (!results.empty())
	{
		cout << "Results for " << field << " = " << value << ": " << endl;
		printResults(headers, results);
	}
	else 
	{
		cout << "No results found." << endl;
	}
	

	return 0;
}
