#ifndef STOCK_DEF_H
#define STOCK_DEF_H

#include <string>
#include <iostream>

using namespace std;

class Stock
{
private:
	string stock_name;
	int number_of_shares;
	double price_per_share;

public:
	// Constructor
	Stock();
	Stock(string name, int shares, double price);

	// Member Functions
	void setName(string name);
	void setNumberOfShares(int shares);
	void setPricePerShare(double price);

	string getName();
	int getNumberOfShares();
	double getPricePerShare();

	string printStock();
};

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
//Function definitions

// Constructor
Stock::Stock() : stock_name(""), number_of_shares(0), price_per_share(0) {
}

Stock::Stock(string name, int shares, double price) : stock_name(name), number_of_shares(shares), price_per_share(price) {
}


void Stock::setName(string name) {
	stock_name = name;
}


void Stock::setNumberOfShares(int shares) {
	number_of_shares = shares;
}


void Stock::setPricePerShare(double price) {
	price_per_share = price;
}


string Stock::getName() {
	return stock_name;
}


int Stock::getNumberOfShares() {
	return number_of_shares;
}


double Stock::getPricePerShare() {
	return price_per_share;
}


string Stock::printStock() {
	//cout << number_of_shares << " " << stock_name << " shares @ £" << price_per_share;
	string printOutput = to_string(number_of_shares) + " " + stock_name + " shares @ " + (char)156 + to_string(price_per_share);
	return printOutput;
}


#endif
