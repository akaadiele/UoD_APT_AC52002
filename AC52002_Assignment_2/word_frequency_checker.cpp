/*
* File:	word_frequency_checker.cpp
* Author:	Akachukwu Adiele
* Description:	This program analyzes a file to process each word and count their frequency/occurences.
*				It uses a binary tree to store the words and their frequencies.
*				The program allows the user to view the results in alphabetical order or by frequency.
* Dates created:	18/05/2025
*/
// ------------------------------------------------------------------------

// Include necessary libraries
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <cctype>
using namespace std;

// Include the WordTree header file
#include "word_tree_definitions.h"

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Declaring functions
bool readFileAndInsertWords(WordTree& wordTree, string& textFileName);
string removePunctuation(string word);
string stringToLowerCase(string word);
void saveResultInFile(string outputFileName, string outputContent);
	
// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

int main() {
	// ------------------------------------------------------------------------
	// Declaring variables
	int menuInput; char exitFlag;	// Menu input and exit flag
	int numberOfWords = 0; int frequencyCount = 0; // Number of unique words and their frequency count
	string output = "";	// String to hold the output
	string resultFileName = ""; // String to hold the result file name
	string textFileName = ""; // String to hold the text file name
	
	// ------------------------------------------------------------------------
	// Creating class objects
	WordTree wordTreeByAlphabet; // Create a WordTree object
	WordTree wordTreeByFrequency; // Create a WordTree object

	// Welcome message on screen
	cout << string(100, '-') << endl;
	cout << string(100, '*') << endl;
	cout << string(10, ' ') << "Welcome to 'LexiByte - Word Frequency Checker' !!!" << endl;
	cout << string(100, '*') << endl;
	cout << string(100, '-') << endl;
	cout << "This program will read a file and count the frequency of each word." << endl;
	cout << "After analysis is complete, you may print the result in order of the words or frequency." << endl;
	cout << string(100, '-') << endl;

	// Read the file and insert words into the tree
	if ( !readFileAndInsertWords(wordTreeByAlphabet, textFileName) ) {
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
			exitFlag = 'N';
		}
		else {
			cout << string(100, '-') << endl;

			switch (menuInput) {
			case 1:
				// Print the words in alphabetical order
				cout << "\nAnalysis Result in alphabetical order. \n[ Words (number of occurences) ]:" << endl;
				cout << string(50, '-') << endl << endl;
				
				numberOfWords = 0; frequencyCount = 0; output = ""; // Reset the variables
				wordTreeByAlphabet.printInOrderTraversal(wordTreeByAlphabet.getRoot(), output); // Print the tree via in-order traversal
				wordTreeByAlphabet.countNodesFrequency(wordTreeByAlphabet.getRoot(), numberOfWords, frequencyCount);
				cout << endl << string(50, '-') << endl;
				cout << "Total number of unique words in the file: " << numberOfWords << endl; // Print the total number of words
				cout << "Total number of words in the file: " << frequencyCount << endl; // Print the total number of words
				
				// Save the result in a file
				output += "\n\nTotal number of unique words in the file: " + to_string(numberOfWords);
				output += "\nTotal number of words in the file: " + to_string(frequencyCount) + "\n"; // Append the total number of words to the output string
				resultFileName = "sortByWords_" + textFileName;
				saveResultInFile(resultFileName, output); // Save the result in a file
				cout << "\n! Result saved in file - '" << resultFileName << "'" << endl;

				exitFlag = 'N';
				break;

			case 2:
				// Print the words in order of their frequency
				cout << "\nAnalysis Result in order of their frequency. \n[ Words (number of occurences) ]:" << endl;
				cout << string(50, '-') << endl << endl;
				
				numberOfWords = 0; frequencyCount = 0; output = ""; // Reset the variables
				wordTreeByFrequency.printInOrderTraversal(wordTreeByFrequency.getRoot(), output); // Print the tree via in-order traversal
				wordTreeByFrequency.countNodesFrequency(wordTreeByFrequency.getRoot(), numberOfWords, frequencyCount);
				cout << endl << string(50, '-') << endl;
				cout << "Total number of unique words in the file: " << numberOfWords << endl; // Print the total number of words
				cout << "Total number of words in the file: " << frequencyCount << endl; // Print the total number of words
				
				// Save the result in a file
				output += "\n\nTotal number of unique words in the file: " + to_string(numberOfWords);
				output += "\nTotal number of words in the file: " + to_string(frequencyCount) + "\n"; // Append the total number of words to the output string
				resultFileName = "sortByFrequency_" + textFileName;
				saveResultInFile(resultFileName, output); // Save the result in a file
				cout << "\n! Result saved in file - '" << resultFileName << "'" << endl;
				
				
				exitFlag = 'N';
				break;

			case 3:
				// Analyse a new file
				wordTreeByAlphabet.resetTree(wordTreeByAlphabet.getRoot()); // Reset tree object
				wordTreeByFrequency.resetTree(wordTreeByFrequency.getRoot()); // Reset tree object
				numberOfWords = 0; frequencyCount = 0; // Reset the word and frequency counts
				output = ""; resultFileName = ""; textFileName = ""; // Reset the output, resultFileName, and textFileName

				readFileAndInsertWords(wordTreeByAlphabet, textFileName); // Read new file and insert words into the tree
				wordTreeByAlphabet.buildFrequencySortedTree(wordTreeByAlphabet.getRoot(), wordTreeByFrequency); // Build the frequency sorted tree
				cout << endl;

				exitFlag = 'N';
				break;

			case 0:
				// Exit the program
				cout << "Exiting the program..." << endl;

				exitFlag = 'Y';
				break;

			default:
				// Invalid input
				cout << "!!! Invalid input... Please try again." << endl;

				exitFlag = 'N';
				break;
			}
		}

	} while (exitFlag != 'Y');

	exit(0); // Exit the program
	return 0;
}

// ------------------------------------------------------------------------

// Read the text file and insert words into the binary tree
bool readFileAndInsertWords(WordTree& wordTree, string& textFileName) {
	string fileName, wordInFile;	// Declaring variables

	// Get the file name from user
	cout << "\nEnter file name: ";
	cout << "\n>>> "; cin >> fileName;

	ifstream textFile;	// Stream the file
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
		textFileName = fileName;	// Assign the file name to the variable

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
		if (isalnum(c)) { // Check if the character is alphanumeric
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

// ------------------------------------------------------------------------

// Save the result in a file
void saveResultInFile(string outputFileName, string outputContent) {
	ofstream resultFile;	// Stream the file

	resultFile.open(outputFileName);	// Open the file

	// Check if the file opened successfully
	if (!resultFile) {
		cout << "\n!!! Error opening file." << endl;
		return;
	}

	resultFile << outputContent; // Write the output to the file

	resultFile.close();	// Close the file
}

// ------------------------------------------------------------------------
