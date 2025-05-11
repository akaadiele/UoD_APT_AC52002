#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

#include "word_tree_template.h"

bool readFileAndInsertWords(WordTree& wordTree);

string stringToLowerCase(string word);

int main()
{
	int menuInput; string exitInput;
	WordTree wordTree; // Create a WordTree object
	WordTree wordTreeFrequency; // Create a WordTree object


	cout << string(100, '-') << endl;
	cout << "Welcome to the Word Frequency Checker!" << endl;
	cout << string(100, '-') << endl;
	cout << "This program will read a file and count the frequency of each word." << endl;
	cout << "After analysis is complete, you may print the result in order of the words or frequency." << endl;
	cout << string(100, '-') << endl;

	readFileAndInsertWords(wordTree); // Read the file and insert words into the tree
	wordTree.buildFrequencySortedTree(wordTree.getRoot(), wordTreeFrequency); // Build the frequency sorted tree

	do {
		cout << string(100, '-') << endl;
		cout << "Please select an option:" << endl;
		cout << "(1) - Print the words in alphabetical order." << endl;
		cout << "(2) - Print the words in order of their frequency." << endl;
		cout << "(3) - Analyse a different file." << endl;
		cout << "(0) - Exit the program." << endl;
		cout << ">>> "; cin >> menuInput;
		cout << endl;

		cout << string(100, '-') << endl;
		switch (menuInput)
		{
		case 1:
			// Print the words in alphabetical order
			cout << "\nAnalysis Result in alphabetical order. \n[Words (number of occurences)]:" << endl;
			cout << string(50, '-') << endl << endl;
			wordTree.printInOrderTraversal(wordTree.getRoot()); // Print the tree via in-order traversal
			cout << endl << endl;

			exitInput = "N";
			break;

		case 2:
			// Print the words in order of their frequency
			cout << "\nAnalysis Result in order of their frequency. \n[Words (number of occurences)]:" << endl;
			cout << string(50, '-') << endl << endl;
			wordTreeFrequency.printInOrderTraversal(wordTreeFrequency.getRoot()); // Print the tree via in-order traversal
			cout << endl << endl;

			exitInput = "N";
			break;

		case 3:
			// Analyse a different file
			cout << string(50, '-') << endl;

			wordTree.resetTree(); // Clear the frequency tree
			wordTreeFrequency.resetTree(); // Clear the frequency tree

			readFileAndInsertWords(wordTree); // Read the file and insert words into the tree
			wordTree.buildFrequencySortedTree(wordTree.getRoot(), wordTreeFrequency); // Build the frequency sorted tree

			exitInput = "N";
			break;

		case 0:
			// Exit the program
			cout << "Exiting the program..." << endl;
			exitInput = "Y";
			//exit(0);
			break;

		default:
			// Invalid input
			cout << "!!! Invalid input..." << endl;
			exitInput = "N";
			break;

		}

	} while (exitInput.compare("Y"));
	exit(0); // Exit the program
	return 0;
}


// Read the file and insert words into the tree
bool readFileAndInsertWords(WordTree& wordTree) {
	string fileName, wordInFile;

	// Get the file name from user
	cout << "\nEnter file name: ";
	cout << "\n>>> "; cin >> fileName;
	//fileName = "text.txt"; // ###

	// Check if the file exists and stream file
	ifstream textFile;
	textFile.open(fileName);

	// Check if the file opened successfully
	if (!textFile) {
		cout << "\n!!! Error opening file." << endl;
		return false;
	}


	// Read words from the file and insert them into the tree
	while (textFile >> wordInFile) {
		// Check if the word is valid
		if (wordInFile.length() <= 0) {
			cout << "\n!!! Invalid word." << endl;
			return false;
		}

		wordInFile = stringToLowerCase(wordInFile);

		// Insert the word into the tree
		wordTree.insertNode(wordInFile);
	}

	// Close the file
	textFile.close();


	// Check if the word tree is empty
	if (wordTree.empty()) {
		return false;
	}
	else {
		//Successful load of the tree nodes
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		cout << "\nFile loaded successfully..." << endl;

		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		cout << "\nAnalysing file..." << endl;

		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		cout << "\nAnalysis complete..." << endl;
		cout << "\nYou may now print the results." << endl << endl;

		return true;
	}

}



// Convert the word to lowercase
string stringToLowerCase(string word) {
	for (char& c : word) {
		c = tolower(c);
	}
	return word;
}