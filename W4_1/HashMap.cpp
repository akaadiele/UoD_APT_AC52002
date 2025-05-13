#include "HashMap.h"
#include <iostream>
using namespace std;

// Default constructor, calls the second constructor with the
// Default hash nmap size
HashMap::HashMap() : HashMap(MAX_HASH_SIZE)
{

}

// Creates the HashMap of KeyPair items
HashMap::HashMap(int size) : max_size(size)
{
	table = new KeyPair * [max_size];
	for (int i = 0; i < max_size; i++) table[i] = NULL;
}

// Destructor: Frees the memory used by the HashMap
HashMap::~HashMap()
{
	for (int i = 0; i < max_size; i++)
		if (table[i] != NULL) delete table[i];
	delete[] table;
}

/**
 * HashMap::lookup
 * Returns the key pair using the string as a lookup (through calling the
 * hashing function.
 */
KeyPair* HashMap::lookup(string s)
{
	KeyPair* key_pair;

	// Could combine these in a singel code line but seeprated for clarity
	unsigned int hash_value = hash_function(s);
	key_pair = table[hash_value];

	for (; key_pair != NULL; key_pair = key_pair->next)
	{
		// found
		if ((key_pair->key).compare(s) == 0) return key_pair;
	}
	// not found
	return NULL;
}

/**
 * HashMap::put
 * Put a key pair into a hash map.
 */
void HashMap::put(string key, std::string value)
{
	KeyPair* key_pair;
	unsigned int hash;

	// If not found already in HashMap
	if (!(key_pair = lookup(key)))
	{
		key_pair = new KeyPair;
		key_pair->key = key;
		key_pair->value = value;
		hash = hash_function(key);
		key_pair->next = table[hash];
		table[hash] = key_pair;

	}
	else
	{
		// Already in HashMap
		key_pair->key = key;
		key_pair->value = value;
		hash = hash_function(key);
		table[hash] = key_pair;
	}
}


/**
 * Output the HashMap contents
 */
void HashMap::showMap()
{
	KeyPair* key_pair;
	for (int i = 0; i < max_size; i++) {
		key_pair = table[i];

		// If we have daat in this hash slot, print it out
		if (key_pair)
		{
			cout << "table[" << i << "] " << key_pair->key << " : " << key_pair->value;
			key_pair = key_pair->next;

			// Output any 'chained' daat in this Hash slot
			while (key_pair)
			{
				cout << "->" << key_pair->key << " : " << key_pair->value;
				key_pair = key_pair->next;
			}
			cout << endl;
		}
	}
}

/**
 * hash_function
 * Returns a hash value based on the string characters
 */
unsigned int HashMap::hash_function(string s)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < s.length(); i++)
	{
		hash = s[i] + 31 * hash;
	}
	return hash % max_size;
}


