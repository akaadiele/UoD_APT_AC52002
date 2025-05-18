/*
* File:	word_tree_definitions.h
* Author:	Akachukwu Adiele
* Description:	This header file contains the definitions of the WordTree class member functions
*				already declared in the word_tree_declarations.h file.
*				It is associated with the word_frequency_checker.cpp file.
* Dates created:	18/05/2025
*/
// ------------------------------------------------------------------------

#ifndef WORD_TREE_DEFINITIONS_H
#define WORD_TREE_DEFINITIONS_H

// ------------------------------------------------------------------------
// Include header file for the WordTree class declarations
#include "word_tree_declarations.h"

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Constructor
WordTree::WordTree() : root(nullptr) {}

// Destructor
WordTree::~WordTree() {
	resetTree(root);	// Reset the tree by deleting all nodes
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Check if the tree is empty
bool WordTree::empty() const {
	return (root == nullptr);
}

// ------------------------------------------------------------------------

// Function to create a new node with 'word' only
WordTree::Node* WordTree::createNode(const string& newWord) {
	Node* newNode = new Node(newWord);
	newNode->word = newWord; // Set the word
	newNode->frequency = 1; // Initialize frequency to 1
	newNode->left = newNode->right = nullptr;

	return newNode;
}

// ------------------------------------------------------------------------

// Function to insert a new node into the tree
bool WordTree::insertNode(const string& newWord) {
	char wordInserted = 'N';

	if (empty()) {
		//Node* newNode = new Node(newWord);
		root = createNode(newWord);
		wordInserted = 'Y';
	}
	else {
		Node* current = root;

		while (wordInserted == 'N') {
			if (newWord < current->word) {
				if (current->left == nullptr) {
					//current->left = new Node(newWord);
					current->left = createNode(newWord);
					wordInserted = 'Y';
				}
				current = current->left;
			}
			else if (newWord > current->word) {
				if (current->right == nullptr) {
					//current->right = new Node(newWord);
					current->right = createNode(newWord);
					wordInserted = 'Y';
				}
				current = current->right;
			}
			else {
				current->frequency++;  // Word already exists, increment frequency
				wordInserted = 'Y';
			}
		}
	}

	if (wordInserted == 'Y') {
		return true;
	}
	else {
		return false; // Insertion failed
	}
}

// ------------------------------------------------------------------------

// Function to print the tree nodes via in-order traversal
void WordTree::printInOrderTraversal(Node* node, string& output) {
	if (node != nullptr) {
		printInOrderTraversal(node->left, output);	// Traverse left subtree
				
		cout << node->word << " (" << node->frequency << ")" << endl;	// Print current node
		
		output += node->word + " (" + to_string(node->frequency) + ") \n";	// Append to output string
				
		printInOrderTraversal(node->right, output);	// Traverse right subtree
	}
}

// ------------------------------------------------------------------------

// Function to get the root node of the tree
WordTree::Node* WordTree::getRoot() const {
	return root;
}

// ------------------------------------------------------------------------

// Function to build a new tree instance with the same nodes but sorted by the word frequency
void WordTree::buildFrequencySortedTree(Node* node, WordTree& wordTreeFrequency) {
	if (node != nullptr) {
		wordTreeFrequency.insertNodeSortFrequency(node); // Insert the node into the array sorted by frequency

		buildFrequencySortedTree(node->left, wordTreeFrequency);	// Traverse left subtree

		buildFrequencySortedTree(node->right, wordTreeFrequency);	// Traverse right subtree
	}
}

// ------------------------------------------------------------------------

// Function to create a new node with both word and frequency
WordTree::Node* WordTree::createNodeWithFrequency(const string& newWord, const int frequency) {
	Node* newNode = new Node(newWord);
	newNode->word = newWord; // Set the word
	newNode->frequency = frequency; // Initialize frequency to 1
	newNode->left = newNode->right = nullptr;

	return newNode;
}

// ------------------------------------------------------------------------

// Function to insert a new node into the tree, prioritizing order by frequency and then alphabetically
bool WordTree::insertNodeSortFrequency(Node* node) {
	char wordInserted = 'N';

	if (empty()) {
		root = createNodeWithFrequency(node->word, node->frequency);
		wordInserted = 'Y';
	}
	else {
		Node* current = root;

		while (wordInserted == 'N') {
			if (node->frequency > current->frequency) {
				// Insert node to the left if frequency is greater (to cater for descending order during traversal)
				if (current->left == nullptr) {
					current->left = createNodeWithFrequency(node->word, node->frequency);
					wordInserted = 'Y';
				}
				current = current->left;
			}
			else if (node->frequency < current->frequency) {
				// Insert node to the right if frequency is less (to cater for descending order during traversal)
				if (current->right == nullptr) {
					current->right = createNodeWithFrequency(node->word, node->frequency);
					wordInserted = 'Y';
				}
				current = current->right;
			}
			else {
				// When the frequency is the same, insert based on word
				if (node->word < current->word) {
					if (current->left == nullptr) {
						current->left = createNodeWithFrequency(node->word, node->frequency);
						wordInserted = 'Y';
					}
					current = current->left;
				}
				else if (node->word > current->word) {
					if (current->right == nullptr) {
						current->right = createNodeWithFrequency(node->word, node->frequency);
						wordInserted = 'Y';
					}
					current = current->right;
				}
			}

		}
	}

	if (wordInserted == 'Y') {
		return true;
	}
	else {
		return false; // Insertion failed
	}
}

// ------------------------------------------------------------------------

// Function to reset the tree from the root
void WordTree::resetTree(Node* node) {
	// Reset the binary tree by traversing and deleting each node
	
	if (node != nullptr) {
		resetTree(node->left);	// Reset left subtree
		resetTree(node->right);	// Reset right subtree
		delete node;			// Delete the current node

		if (node == root) {
			root = nullptr;	// Set root to nullptr after deleting all nodes
		}
	}
}

// ------------------------------------------------------------------------

// Function to count the number of nodes and their frequencies
void WordTree::countNodesFrequency(Node* node, int& nodeCount, int& frequencyCount) {
	//int count = 0;
	Node* currentNode = node;

	if (currentNode != nullptr) {
		countNodesFrequency(currentNode->left, nodeCount, frequencyCount);	// Count left subtree
		countNodesFrequency(currentNode->right, nodeCount, frequencyCount);	// Count right subtree

		nodeCount++;	// Increment the count for the current node
		frequencyCount += currentNode->frequency;	// Increment the frequency count
	}
}

// ------------------------------------------------------------------------

#endif

// ------------------------------------------------------------------------
