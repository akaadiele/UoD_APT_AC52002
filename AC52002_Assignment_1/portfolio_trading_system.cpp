//#include <iostream>
//#include <string>
//using namespace std;

#include "stack_template.h"
#include "stock_def.h"

#include <fstream>

// Global variables
int numberOfStocks;
Stack<Stock> stockStack(numberOfStocks);

// Function prototypes
void stockPerformance();
void findStock();
bool setUpTestData();
bool setUpTestDataFromFile();
void showStockPortfolio();
string stringToUpperCase(string str);

bool sellFifo(string stockToTrade);
bool buyLifo(string stockToTrade);
bool sellLifo(string stockToTrade);

int main() {

	int menuInput;
	char quitInput = 'N';

	while (toupper(quitInput) != 'Y') {
		cout << "\nWelcome to KRYSTAL Stock Portfolio Trading System! \n" << endl;

		cout << "Enter 1 to enter a stock performance" << endl;
		cout << "Enter 2 to find stock" << endl;
		cout << "Enter 3 to set up test data" << endl;		cout << "Enter 4 to show stock portfolio" << endl;

		cin >> menuInput;

		switch (menuInput)
		{
		case 1:
			cout << "Enter stock name" << endl;
			break;


		case 2:
			findStock();
			break;


		case 3:
			cout << "Setting up test data: " << endl;
			cout << "Enter 1 to set up test data manually" << endl;
			cout << "Enter 2 to set up test data from file\n" << endl;
			int testDataInput;
			cin >> testDataInput;
			switch (testDataInput)
			{
			case 1:
				cout << "Setting up test data manually \n" << endl;
				setUpTestData() ? cout << "Test data set up successfully." << endl : cout << "Failed to set up test data." << endl;
				break;
			case 2:
				cout << "Setting up test data from file \n" << endl;
				setUpTestDataFromFile() ? cout << "Test data set up successfully." << endl : cout << "Failed to set up test data." << endl;
				break;
			default:
				cout << "Invalid input" << endl;
				break;
			}
			break;


		case 4:
			cout << "Showing stock portfolio... \n" << endl;
			showStockPortfolio();
			break;


		default:
			cout << "Invalid input" << endl;
			break;
		}

		cout << "Enter 'Y' to quit program" << endl;
		cin >> quitInput;
		if (quitInput == 'Y') {
			break;
		}
	}



	/*
		// Print the stack contents
		cout << "Stack contents:" << endl;
		stockStack.printStack();
		cout << endl;

		// Pop an item from the stack
		Stock poppedStock;
		stockStack.pop(poppedStock);
		cout << "Popped stock: " << poppedStock.getName() << ", " << poppedStock.getNumberOfShares() << ", " << poppedStock.getPricePerShare() << endl;
		cout << endl;

		// Print the stack contents after popping
		cout << "Stack contents after popping:" << endl;
		stockStack.printStack();
		cout << endl;

		// Duplicate the top element
		stockStack.duplicate();
		cout << "Stack contents after duplicating the top element:" << endl;
		stockStack.printStack();
		cout << endl;

		// Delete all occurrences of a specific stock
		string stockToDelete = "MSFT";
		stockStack.deleteAllOccurence(stockToDelete);
		cout << "Stack contents after deleting all occurrences of " << stockToDelete << ":" << endl;
		stockStack.printStack();
		cout << endl;

		// Get the top and bottom elements
		Stock topStock = stockStack.top();
		Stock bottomStock = stockStack.bottom();
		cout << "Top stock: " << topStock.getName() << ", " << topStock.getNumberOfShares() << ", " << topStock.getPricePerShare() << endl;
		cout << "Bottom stock: " << bottomStock.getName() << ", " << bottomStock.getNumberOfShares() << ", " << bottomStock.getPricePerShare() << endl;
		cout << endl;


		// Check if the stack is empty
		if (stockStack.empty()) {
			cout << "The stack is empty." << endl;
		}
		else {
			cout << "The stack is not empty." << endl;
		}
		cout << endl;


		// Check if the stack is full
		if (stockStack.full()) {
			cout << "The stack is full." << endl;
		}
		else {
			cout << "The stack is not full." << endl;
		}
		cout << endl;


		// Clear the stack
		while (!stockStack.empty()) {
			stockStack.pop(poppedStock);
			cout << "Popped stock: " << poppedStock.getName() << ", " << poppedStock.getNumberOfShares() << ", " << poppedStock.getPricePerShare() << endl;
		}
		cout << endl;
		cout << "Stack contents after clearing:" << endl;
		stockStack.printStack();
		cout << endl;
		*/

	return 0;
}


void stockPerformance() {
	// Function to enter stock performance
	string stockToTrade;
	double percentChange;

	cout << "Enter stock name: ";
	cin >> stockToTrade;

	cout << "Enter percentage change: ";
	cin >> percentChange;


	if ((percentChange >= 5) && (percentChange <= 20)) {
		sellFifo(stockToTrade);
	}
	else if ((percentChange >= -1) && (percentChange <= -0.5)) {
		buyLifo(stockToTrade);
	}
	else if ((percentChange >= -3) && (percentChange <= -1.1)) {
		sellLifo(stockToTrade);
	}
	else {
		cout << "Portforlio is retained." << endl;
	}
}


void findStock() {
	// Function to find a stock in the portfolio
	string stockToFind;
	cout << "Enter the stock name to find: ";
	cin >> stockToFind;
	stockToFind = stringToUpperCase(stockToFind);

	// Search for the stock in the stack
	string searchContent;
	int numberOfFoundStocks = 0;

	for (int i = 0; i <= stockStack.getIndexOfTop(); i++) {
		if (stockStack.contents[i].getName() == stockToFind) {
			searchContent = searchContent + "\n" + to_string(stockStack.contents[i].getNumberOfShares()) + " " + stockStack.contents[i].getName() + "  shares @ £" + to_string(stockStack.contents[i].getPricePerShare());

			numberOfFoundStocks += 1;
		}
	}

	if (numberOfFoundStocks == 0) {
		cout << "Stock not found." << endl;;
	}
	else {
		cout << "Stock found: \n------------------------------------------------------------------------" << endl;
		cout << searchContent << endl;
	}

}


bool setUpTestData() {
	// Function to set up test data
	cout << "Setting up stock data..." << endl;
	/*
	int numberOfStocks;
	cout << "Enter the number of stocks to set up: ";
	cin >> numberOfStocks;

	if (numberOfStocks <= 0) {
		cout << "Invalid number of stocks. Exiting setup." << endl;
		return false;
	}

	string stockName; int numberOfShares; double pricePerShare;
	Stack<Stock> stockStack(numberOfStocks);
	for (int i = 0; i < numberOfStocks; i++) {
		cout << "Enter stock name: ";
		cin >> stockName;
		stockName = stringToUpperCase(stockName);

		cout << "Enter number of shares: ";
		cin >> numberOfShares;

		cout << "Enter price per share: ";
		cin >> pricePerShare;

		// Create a Stock object and push it onto the stack
		Stock newStock(stockName, numberOfShares, pricePerShare);
		stockStack.push(newStock);
	}
	*/


	// ### instant dummy test data
	// Create a stack of Stock objects
	int numberOfStocks = 4;
	Stack<Stock> stockStack(numberOfStocks);
	Stock stock1("MSFT", 300, 200.39);
	Stock stock2("GME", 250, 9.39);
	Stock stock3("MSFT", 500, 214.22);
	Stock stock4("MSFT", 100, 222.59);

	// Push stock objects onto the stack
	stockStack.push(stock1);
	stockStack.push(stock2);
	stockStack.push(stock3);
	stockStack.push(stock4);

	return true;
}



bool setUpTestDataFromFile() {
	cout << "Setting up stock data from file..." << endl;

	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;

	// Function to set up test data from a file
	ifstream stocksFile;
	stocksFile.open("fileName");

	// Check if the file opened successfully
	if (!stocksFile) {
		cout << "Error opening file." << endl;
		return false;
	}

	string stockName;
	int numberOfShares;
	double pricePerShare;
	while (stocksFile >> stockName >> numberOfShares >> pricePerShare) {
		stockName = stringToUpperCase(stockName);

		Stock newStock(stockName, numberOfShares, pricePerShare);
		stockStack.push(newStock);
	}
	stocksFile.close();

	return true;
}


void showStockPortfolio() {
	// Show the stock portfolio
	cout << "Your Current Stock Portfolio:" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	// Print the stack contents
	stockStack.printStack();
	cout << endl;
}


string stringToUpperCase(string str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}


bool sellFifo(string stockToTrade) {

	char tradeCompleted = 'N';
	Stack<Stock> noTradeStockStack(numberOfStocks);
	int sharesToTrade;

	cout << "Enter amount of shares to trade: ";
	cin >> sharesToTrade;

	//Check for total shares for stock available in portfolio to sell
	int availableShares = 0;
	char validStock = 'N';
	for (int i = 0; i <= stockStack.getIndexOfTop(); i++) {
		Stock currentStock = stockStack.contents[i];
		if (currentStock.getName() == stockToTrade) {
			availableShares += currentStock.getNumberOfShares();
			validStock = 'Y';
		}
	}

	// Stock not found in portfolio
	if (validStock == 'N') {
		cout << "Stock not found in portfolio." << endl;
		return false;
	}
	else {
		// Print the stock portfolio before trading
		cout << "Stock portfolio before trading:" << endl;
		stockStack.printStack();
		cout << endl;
		cout << "Trade completed." << endl << endl;
		return true;
	}

	// Check if shares to trade are more than available shares
	if (sharesToTrade > availableShares) {
		cout << "! Not enough shares to trade." << endl;
		cout << "Available shares: " << availableShares << endl;
		cout << "Trade all available shares?" << endl;
		cout << "Enter 'Y' for yes or 'N' for no: ";

		char confirmTrade;
		cin >> confirmTrade;

		if (toupper(confirmTrade) == 'Y') {
			// Trade all available shares
			sharesToTrade = availableShares;
		}
		else {
			// Cancel trade
			cout << "Trade cancelled." << endl;
			return false;
		}
	}

	while ((!stockStack.empty()) && (tradeCompleted == 'N')) {
		Stock currentStock = stockStack.bottom();
		if (currentStock.getName() == stockToTrade) {

			if (sharesToTrade > currentStock.getNumberOfShares()) {
				sharesToTrade -= currentStock.getNumberOfShares();
				stockStack.remove(currentStock);
				tradeCompleted = 'N';
			}
			else if (sharesToTrade == currentStock.getNumberOfShares()) {
				stockStack.remove(currentStock);
				tradeCompleted = 'Y';
			}
			else {
				currentStock.setNumberOfShares(currentStock.getNumberOfShares() - sharesToTrade);
				//stockStack.remove();
				//stockStack.push(currentStock);
				tradeCompleted = 'Y';
			}
			

		}
		else {
			noTradeStockStack.push(currentStock);
		}
	}

	// Move stocks back to original stack
	while (!noTradeStockStack.empty()) {
		Stock currentStock = noTradeStockStack.bottom();
		stockStack.push(currentStock);
		noTradeStockStack.remove(currentStock);
	}

	// Print the stock portfolio after trading
	cout << "Stock portfolio after trading:" << endl;
	stockStack.printStack();
	cout << endl << endl;
	cout << "Trade completed." << endl;
	return true;
}


bool buyLifo(string stockToTrade) {
	return true;
}

bool sellLifo(string stockToTrade) {
	return true;
}
