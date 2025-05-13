// hash_map_test.cpp : Example program that uses an STL unordered map as a hash map
// Modified from example given at: https://www.bogotobogo.com/Algorithms/hashmap_hashtable.php

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashMap.h"

using namespace std;

int main()
{
	// Create the HashMap, setting the maximium number of key pairs
	HashMap map(1000);
	string line;

	// Open the data text file
	ifstream input("dictionary.txt");
	if (!input)
	{
		cout << "Error opening input data file  " << endl;
		exit(1);
	}

	// Read in the data in pairs, putting each pair into the hashmap
	while (!input.eof())
	{
		string word1, word2;
		input >> word1 >> word2;

		if (word1.length() > 0)
		{
			map.put(word1, word2);
		}
	}

	// Display the hash map contents
	map.showMap();
	return 0;
}



