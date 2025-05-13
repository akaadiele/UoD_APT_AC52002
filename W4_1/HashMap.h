/**
 * Class to implement a simple HashMap
 */

#pragma once
#include <string>

 // Only used is a HashMap size is not specified on construction
const int MAX_HASH_SIZE = 1024;

// This class allows us to implement HashMap chaining if mulitple data items 
// result in the same hash key. Each data iterm is stored in a KeyPair instance
class KeyPair {
public:
	std::string key;
	std::string value;
	KeyPair* next;
};

/**
 *
 */
class HashMap
{
private:
	KeyPair** table;
	int max_size;

public:
	HashMap();
	HashMap(int size);
	~HashMap();

	unsigned int hash_function(std::string);
	KeyPair* lookup(std::string s);
	void put(std::string key, std::string value);
	void showMap();

};