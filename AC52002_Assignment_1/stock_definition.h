#ifndef STOCK_DEF_H
#define STOCK_DEF_H

#include <string>
using namespace std;

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

class Stock
{
private:
	//Member variables
	string stock_name;
	int number_of_shares;
	double price_per_share;

public:
	// Constructors
	Stock();
	Stock(string name, int shares, double price);

	// Member Functions
	int getNumberOfShares();
	double getPricePerShare();
	string getName();
	string printStock();
	void setName(string name);
	void setNumberOfShares(int shares);
	void setPricePerShare(double price);
};


// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
//Function definitions

// Constructor
Stock::Stock() : stock_name(""), number_of_shares(0), price_per_share(0) {
}

// Constructor with parameters
Stock::Stock(string name, int shares, double price) : stock_name(name), number_of_shares(shares), price_per_share(price) {
}

// ------------------------------------------------------------------------
// Functions to get the values of member variables
int Stock::getNumberOfShares() {
	return number_of_shares;
}

double Stock::getPricePerShare() {
	return price_per_share;
}

string Stock::getName() {
	return stock_name;
}

// ------------------------------------------------------------------------
// Function to print the stock details
string Stock::printStock() {
	string printOutput = to_string(number_of_shares) + " shares " + stock_name + " @ " + (char)156 + to_string(price_per_share);
	return printOutput;
}

// ------------------------------------------------------------------------
// Functions to set the values of member variables
void Stock::setName(string name) {
	stock_name = name;
}

void Stock::setNumberOfShares(int shares) {
	number_of_shares = shares;
}

void Stock::setPricePerShare(double price) {
	price_per_share = price;
}

// ------------------------------------------------------------------------
#endif
