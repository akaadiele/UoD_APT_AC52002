#ifndef PORTFOLIO_TEMPLATE_H
#define PORTFOLIO_TEMPLATE_H

#include <iostream>
#include <iomanip>
using namespace std;

// Include portfolio header file
#include "portfolio_definition.h"

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

// Constructor
template <class Type>
Portfolio<Type> ::Portfolio(int portfolio_size) : portfolioSize(portfolio_size), contents(new Type[portfolio_size]), indexOfTop(-1), indexOfBottom(0) {
}

// Destructor
template <class Type>
Portfolio<Type> :: ~Portfolio()
{
	delete[] contents;
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------
// Member functions

// empty
// check if the portfolio is empty
template <class Type>
bool Portfolio<Type> ::empty() const
{
	return (indexOfTop == -1) ? true : false;
}

// full
// check if the portfolio is full
template <class Type>
bool Portfolio<Type> ::full() const
{
	return (indexOfTop == portfolioSize - 1) ? true : false;
}

// ------------------------------------------------------------------------

// push (LIFO)
// push new elements onto the portfolio at the top
template <class Type>
bool Portfolio<Type> ::push(const Type& new_element)
{
	if (full()) {
		return false;
	}
	else {
		indexOfTop++;
		contents[indexOfTop] = new_element;
		return true;
	}
}

// pop (LIFO)
// pop elements from the portfolio at the top
template <class Type>
bool Portfolio<Type> ::pop(Type& top_element)
{
	if (empty()) {
		return false;
	}
	else {
		top_element = contents[indexOfTop];
		indexOfTop--;
		return true;
	}
}

// ------------------------------------------------------------------------

// remove (FIFO)
// remove elements from the portfolio at the bottom
template <class Type>
bool Portfolio<Type>::remove(Type& bottom_element) {
	if (empty())
		return false;
	else
	{
		bottom_element = contents[indexOfBottom];

		Type* tempContents = new Type[portfolioSize];
		int tempIndex = -1;
		for (int i = 1; i <= indexOfTop; i++) {
			tempIndex++;
			tempContents[tempIndex] = contents[i];
		}
		delete[] contents;
		contents = tempContents;
		indexOfTop = tempIndex;

		return true;
	}
}

// add (FIFO)
// add new elements to the portfolio at the bottom
template <class Type>
bool Portfolio<Type>::add(const Type& new_element) {
	if (full())
		return false;
	else
	{
		Type* tempContents = new Type[portfolioSize];
		tempContents[0] = new_element;

		int tempIndex = 0;
		for (int i = 0; i <= indexOfTop; i++) {
			if (contents[i].getNumberOfShares() > 0) {
				tempIndex++;
				tempContents[tempIndex] = contents[i];
			}
		}
		delete[] contents;
		contents = tempContents;
		indexOfTop = tempIndex;

		return true;
	}
}

// ------------------------------------------------------------------------

// top
// return the top element of the portfolio
template <class Type>
Type Portfolio<Type>::top()
{
	return contents[indexOfTop];
}

// bottom
// return the bottom element of the portfolio
template <class Type>
Type Portfolio<Type>::bottom()
{
	return contents[indexOfBottom];
}

// ------------------------------------------------------------------------

// getIndexOfTop
// return the index of the top element of the portfolio
template <class Type>
int Portfolio<Type>::getIndexOfTop() {
	return indexOfTop;
}

// getPortfolioSize
// return the size of the portfolio
template <class Type>
int Portfolio<Type>::getPortfolioSize() {
	return portfolioSize;
}

// printPortfolio
// print the contents of the portfolio
template <class Type>
void Portfolio<Type>::printPortfolio() {
	for (int i = 0; i <= indexOfTop; i++) {
		//cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);
		//cout << setw(15) << left << contents[i].printStock() << " " << endl;
		cout << fixed << setprecision(2);
		cout << left << " " << contents[i].getNumberOfShares() << " shares " << contents[i].getName() << " @ " << (char)156 << contents[i].getPricePerShare() << " " << endl;;
	}
}

// clearPortfolio
// clear the contents of the portfolio
template <class Type>
void Portfolio<Type>::clearPortfolio() {
	while (!empty()) {
		Type temp;
		pop(temp);
	}
}

// ------------------------------------------------------------------------

// sellLifoInPortfolio
// sell stock in the portfolio using LIFO method
template <class Type>
bool Portfolio<Type>::sellLifoInPortfolio(string stockToSellName, int stockToSellAmount) {
	char tradeCompleted = 'N';

	int noTradeStockStackIndex = -1;
	Type* noTradeStockStack = new Type[portfolioSize];
	
	while ((!empty()) && (tradeCompleted == 'N')) {
		// Get the top stock from the portfolio
		Type currentStock = top();
		if (currentStock.getName() == stockToSellName) {
			// Check if the stock to sell amount is greater than the current stock shares
			if (stockToSellAmount > currentStock.getNumberOfShares()) {
				pop(currentStock);
				stockToSellAmount -= currentStock.getNumberOfShares();
				tradeCompleted = 'N';
			}
			// Check if the stock to sell amount is equal to the current stock shares
			else if (stockToSellAmount == currentStock.getNumberOfShares()) {
				pop(currentStock);
				tradeCompleted = 'Y';
			}
			// Check if the stock to sell amount is less than the current stock shares
			else {
				pop(currentStock);
				currentStock.setNumberOfShares(currentStock.getNumberOfShares() - stockToSellAmount);
				push(currentStock);
				tradeCompleted = 'Y';
			}
		}
		else {
			// Move the current stock to the noTradeStockStack
			pop(currentStock);
			noTradeStockStackIndex++;
			noTradeStockStack[noTradeStockStackIndex] = currentStock;
		}
	}

	// Move stocks back to original portfolio
	for (int i = noTradeStockStackIndex; i >= 0; i--) {
		push(noTradeStockStack[i]);
	}

	// Check if the trade was completed successfully
	if (tradeCompleted == 'Y') {
		return true;
	}
	else {
		return false;
	}
}


// sellFifoInPortfolio
// sell stock in the portfolio using FIFO method
template <class Type>
bool Portfolio<Type>::sellFifoInPortfolio(string stockToSellName, int stockToSellAmount) {
	char tradeCompleted = 'N';
	
	int noTradeStockStackIndex = -1;
	Type* noTradeStockStack = new Type[portfolioSize];
	
	while ((!empty()) && (tradeCompleted == 'N')) {
		// Get the bottom stock from the portfolio
		Type currentStock = bottom();

		if (currentStock.getName() == stockToSellName) {
			// Check if the stock to sell amount is greater than the current stock shares
			if (stockToSellAmount > currentStock.getNumberOfShares()) {
				remove(currentStock);
				stockToSellAmount -= currentStock.getNumberOfShares();
				tradeCompleted = 'N';
			}
			// Check if the stock to sell amount is equal to the current stock shares
			else if (stockToSellAmount == currentStock.getNumberOfShares()) {
				remove(currentStock);
				tradeCompleted = 'Y';
			}
			// Check if the stock to sell amount is less than the current stock shares
			else {
				remove(currentStock);
				currentStock.setNumberOfShares(currentStock.getNumberOfShares() - stockToSellAmount);
				add(currentStock);
				tradeCompleted = 'Y';
			}
		}
		else {
			// Move the current stock to the noTradeStockStack
			remove(currentStock);
			noTradeStockStackIndex++;
			noTradeStockStack[noTradeStockStackIndex] = currentStock;
		}
	}

	// Move stocks back to original portfolio
	for (int i = noTradeStockStackIndex; i >= 0; i--) {
		add(noTradeStockStack[i]);
	}

	// Check if the trade was completed successfully
	if (tradeCompleted == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

#endif