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

#endif
