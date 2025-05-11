#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

// Include the WordTree header file
#include "word_tree_template.h"

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// Function definitions
bool readFileAndInsertWords(WordTree& wordTree);
string removePunctuation(string word);
string stringToLowerCase(string word);
// ------------------------------------------------------------------------

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

int main()
{
	// Declaring variables
	int menuInput; string exitInput;

	WordTree wordTreeByAlphabet; // Create a WordTree object
	WordTree wordTreeByFrequency; // Create a WordTree object

	// Welcome message on screen
	cout << string(100, '-') << endl;
	cout << "Welcome to the Word Frequency Checker!" << endl;
	cout << string(100, '-') << endl;
	cout << "This program will read a file and count the frequency of each word." << endl;
	cout << "After analysis is complete, you may print the result in order of the words or frequency." << endl;
	cout << string(100, '-') << endl;

	// Read the file and insert words into the tree
	if (!readFileAndInsertWords(wordTreeByAlphabet)) {
		cout << "\n!!! Error reading/processing file. \nExiting program..." << endl;
		exit(0);
	}
	wordTreeByAlphabet.buildFrequencySortedTree(wordTreeByAlphabet.getRoot(), wordTreeByFrequency); // Build the frequency sorted tree


	do {
		// Display the menu
		cout << string(100, '-') << endl;
		cout << "Please select an option:" << endl;
		cout << "(1) - View result (alphabetical order)." << endl;
		cout << "(2) - View result (order of frequencies)." << endl;
		cout << "(3) - Analyse a new file." << endl;
		cout << "(0) - Exit the program." << endl;
		cout << ">>> "; cin >> menuInput;
		cout << endl;

		// Check if the input is valid
		if ((menuInput < 0) || (menuInput > 3)) {
			cout << "!!! Invalid input... Please try again." << endl;
			exitInput = "N";
		}
		else {
			cout << string(100, '-') << endl;
			switch (menuInput)
			{
			case 1:
				// Print the words in alphabetical order
				cout << "\nAnalysis Result in alphabetical order. \n[ Words (number of occurences) ]:" << endl;
				cout << string(50, '-') << endl << endl;
				wordTreeByAlphabet.printInOrderTraversal(wordTreeByAlphabet.getRoot()); // Print the tree via in-order traversal
				cout << endl << endl;

				exitInput = "N";
				break;

			case 2:
				// Print the words in order of their frequency
				cout << "\nAnalysis Result in order of their frequency. \n[ Words (number of occurences) ]:" << endl;
				cout << string(50, '-') << endl << endl;
				wordTreeByFrequency.printInOrderTraversal(wordTreeByFrequency.getRoot()); // Print the tree via in-order traversal
				cout << endl;

				exitInput = "N";
				break;

			case 3:
				// Analyse a new file
				cout << string(50, '-') << endl;
				wordTreeByAlphabet.resetTree(); // Clear the frequency tree
				wordTreeByFrequency.resetTree(); // Clear the frequency tree
				readFileAndInsertWords(wordTreeByAlphabet); // Read the file and insert words into the tree
				wordTreeByAlphabet.buildFrequencySortedTree(wordTreeByAlphabet.getRoot(), wordTreeByFrequency); // Build the frequency sorted tree
				cout << endl;

				exitInput = "N";
				break;

			case 0:
				// Exit the program
				cout << "Exiting the program..." << endl;

				exitInput = "Y";
				break;

			default:
				// Invalid input
				cout << "!!! Invalid input... Please try again." << endl;

				exitInput = "N";
				break;
			}
		}

	} while (exitInput.compare("Y"));

	exit(0); // Exit the program
	return 0;
}

// ------------------------------------------------------------------------

// Read the text file and insert words into the binary tree
bool readFileAndInsertWords(WordTree& wordTree) {
	string fileName, wordInFile;	// Declaring variables

	// Get the file name from user
	cout << "\nEnter file name: ";
	cout << "\n>>> "; cin >> fileName;

	// Check if the file exists and stream file
	ifstream textFile;
	textFile.open(fileName);	// Open the file

	// Check if the file opened successfully
	if (!textFile) {
		cout << "\n!!! Error opening file." << endl;
		return false;
	}

	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
	cout << "\nFile loaded successfully..." << endl;

	// Read words from the file and insert them into the tree
	while (textFile >> wordInFile) {
		// Check if the word is valid (not empty)
		if (wordInFile.length() <= 0) {
			cout << "\n!!! Invalid word." << endl;
			return false;
		}

		// Performing checks and conversions on the word

		wordInFile = removePunctuation(wordInFile); // Remove punctuation marks from the word
		wordInFile = stringToLowerCase(wordInFile); // Convert the word to lowercase


		wordTree.insertNode(wordInFile);	// Insert the word into the tree
	}

	textFile.close();	// Close the file


	// Check if the word tree is empty
	if (wordTree.empty()) {
		return false;
	}
	else {
		//Successful load of the tree nodes
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		cout << "\nAnalysing file..." << endl;

		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		cout << "\nAnalysis complete... You may now print the results." << endl << endl;
		return true;
	}

}

// ------------------------------------------------------------------------

// Remove punctuation marks from a word
string removePunctuation(string word) {
	string wordWithoutPunctuation;	// New string to hold the cleaned up word
	for (char c : word) {
		if (isalpha(c)) { // Check if the character is alphanumeric
			wordWithoutPunctuation += c; // Append to the cleaned up word
		}
	}
	return wordWithoutPunctuation;
}

// ------------------------------------------------------------------------

// Convert a word to lowercase
string stringToLowerCase(string word) {
	for (char& c : word) {
		c = tolower(c);
	}
	return word;
}