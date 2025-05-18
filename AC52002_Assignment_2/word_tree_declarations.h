/*
* File:	word_tree_declarations.h
* Author:	Akachukwu Adiele
* Description:	This header file contains the declarations of the WordTree class,
*				which implements a binary tree to store words and their frequencies.
*				It is associated with the word_frequency_checker.cpp file.
* Dates created:	18/05/2025
*/
// ------------------------------------------------------------------------

#ifndef WORD_TREE_DECLARATIONS_H
#define WORD_TREE_DECLARATIONS_H

// ------------------------------------------------------------------------
// Include necessary libraries
#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// WordTree class declaration
class WordTree {
private:
	// Node structure for the binary tree
	class Node {
	public:
		string word;
		int frequency;
		Node* left;
		Node* right;

		Node() : word(""), frequency(0), left(nullptr), right(nullptr) {}
		Node(string data, int freq = 1, Node* left = nullptr, Node* right = nullptr) : word(data), frequency(freq), left(left), right(right) {}
	};

	// Member variable
	Node* root;	// Root node of the tree

public:
	// Constructor and Destructor
	WordTree();
	~WordTree();

	// Member Functions
	bool empty() const;
	Node* createNode(const string& newWord);
	bool insertNode(const string& newWord);
	void printInOrderTraversal(Node* node, string& output);
	Node* getRoot() const;
	void buildFrequencySortedTree(Node* node, WordTree& wordTreeFrequency);
	Node* createNodeWithFrequency(const string& newWord, const int frequency);
	bool insertNodeSortFrequency(Node* node);
	void resetTree(Node* node);
	void countNodesFrequency(Node* node, int& nodeCount, int& frequencyCount);
};

// ------------------------------------------------------------------------

#endif

// ------------------------------------------------------------------------