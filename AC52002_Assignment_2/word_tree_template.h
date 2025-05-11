#ifndef WORD_TREE_TEMPLATE_H
#define WORD_TREE_TEMPLATE_H


#include "word_tree_definition.h"

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Constructor
WordTree::WordTree() : root(nullptr) {}

// Destructor
WordTree::~WordTree()
{
	resetTree();
}

// Check if the tree is empty
bool WordTree::empty() const
{
	return (root == nullptr);
}

// Function to create a new node with 'word' only
WordTree::Node* WordTree::createNode(const string& newWord) {
	Node* newNode = new Node(newWord);
	newNode->word = newWord; // Set the word
	newNode->frequency = 1; // Initialize frequency to 1
	newNode->left = newNode->right = nullptr;

	return newNode;
}

// Function to insert a new node into the tree
bool WordTree::insertNode(const string& newWord)
{
	char wordInserted = 'N';

	if (empty())
	{
		//Node* newNode = new Node(newWord);
		root = createNode(newWord);
		wordInserted = 'Y';
	}
	else {
		Node* current = root;

		while (wordInserted == 'N')
		{
			if (newWord < current->word)
			{
				if (current->left == nullptr)
				{
					//current->left = new Node(newWord);
					current->left = createNode(newWord);
					wordInserted = 'Y';
				}
				current = current->left;
			}
			else if (newWord > current->word)
			{
				if (current->right == nullptr)
				{
					//current->right = new Node(newWord);
					current->right = createNode(newWord);
					wordInserted = 'Y';
				}
				current = current->right;
			}
			else
			{
				current->frequency++;  // Word already exists, increment frequency
				wordInserted = 'Y';
			}
		}
	}

	if (wordInserted == 'Y')
	{
		return true;
	}
	else
	{
		return false; // Insertion failed
	}
}



// Function to print the tree nodes via in-order traversal
void WordTree::printInOrderTraversal(Node* node) const
{
	if (node != nullptr) {
		// Traverse left subtree
		printInOrderTraversal(node->left);
		// Print current node
		cout << node->word << " (" << node->frequency << ")" << endl;
		// Traverse right subtree
		printInOrderTraversal(node->right);
	}
}



// Function to get the root node of the tree
WordTree::Node* WordTree::getRoot() const
{
	return root;
}


// Function to build a new tree with the nodes sorted by the word frequency
void WordTree::buildFrequencySortedTree(Node* node, WordTree& wordTreeFrequency) {
	if (node != nullptr)
	{
		wordTreeFrequency.insertNodeSortFrequency(node); // Insert the node into the sorted array

		buildFrequencySortedTree(node->left, wordTreeFrequency);	// Traverse left subtree

		buildFrequencySortedTree(node->right, wordTreeFrequency);	// Traverse right subtree
	}
}


// Function to create a new node with both word and frequency
WordTree::Node* WordTree::createNodeWithFrequency(const string& newWord, const int frequency) {
	Node* newNode = new Node(newWord);
	newNode->word = newWord; // Set the word
	newNode->frequency = frequency; // Initialize frequency to 1
	newNode->left = newNode->right = nullptr;

	return newNode;
}


// Function to insert a new node into the tree, ordered based on frequency
bool WordTree::insertNodeSortFrequency(Node* node)
{
	char wordInserted = 'N';

	if (empty())
	{
		root = createNodeWithFrequency(node->word, node->frequency);
		wordInserted = 'Y';
	}
	else {
		Node* current = root;

		while (wordInserted == 'N')
		{
			if (node->frequency > current->frequency)
			{
				if (current->left == nullptr)
				{
					current->left = createNodeWithFrequency(node->word, node->frequency);
					wordInserted = 'Y';
				}
				current = current->left;
			}
			else if (node->frequency < current->frequency)
			{
				if (current->right == nullptr)
				{
					current->right = createNodeWithFrequency(node->word, node->frequency);
					wordInserted = 'Y';
				}
				current = current->right;
			}
			else
			{
				// When the frequency is the same, insert based on word
				if (node->word < current->word)
				{
					if (current->left == nullptr)
					{
						current->left = createNodeWithFrequency(node->word, node->frequency);
						wordInserted = 'Y';
					}
					current = current->left;
				}
				else if (node->word > current->word)
				{
					if (current->right == nullptr)
					{
						current->right = createNodeWithFrequency(node->word, node->frequency);
						wordInserted = 'Y';
					}
					current = current->right;
				}
			}

		}
	}

	if (wordInserted == 'Y')
	{
		return true;
	}
	else
	{
		return false; // Insertion failed
	}
}


// Function to reset the tree
void WordTree::resetTree() {
	// Reset the root to null in the tree to avoid memory leaks
	root = nullptr;
}


#endif // !1
