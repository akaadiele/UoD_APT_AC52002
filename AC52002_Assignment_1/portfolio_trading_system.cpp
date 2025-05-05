//#include <iostream>
#include <string>
#include <fstream>

//#include <chrono>
//#include <thread>

#include "stack_queue_template.h"
#include "stock_def.h"

using namespace std;


// ------------------------------------------------------------------------
// Function definitions
void stockPerformance(Stack<Stock> stockStack);
void findStock(Stack<Stock> stockStack);
Stack<Stock> setUpTestData();
Stack<Stock> setUpTestDataFromFile();
void showStockPortfolio(Stack<Stock> stockStack);
// ------------------------------------------------------------------------
string stringToUpperCase(string str);
bool sellFifo(string stockToTrade, Stack<Stock> stockStack);
bool buyLifo(string stockToTrade, Stack<Stock> stockStack);
bool sellLifo(string stockToTrade, Stack<Stock> stockStack);
// ------------------------------------------------------------------------


int main() {
	Stack<Stock> portfolioStack;

	int menuInput;
	string quitInput;

	do {
		cout << "\n------------------------------------------------------------------------" << endl;
		cout << "************************************************************************" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Welcome to KRYSTAL Stock Portfolio Trading System! \n" << endl;
		cout << "Enter 1 to enter a stock performance" << endl;
		cout << "Enter 2 to find stock" << endl;
		cout << "Enter 3 to set up test data" << endl;
		cout << "Enter 4 to show stock portfolio" << endl;
		cout << "Enter 0 to quit program" << endl;
		cin >> menuInput;

		if ( (menuInput < 0) || (menuInput > 4) ) {
			cout << "\n! Invalid input" << endl;
			cout << "Exiting program..." << endl;

			exit(0);
		}
		else {

			switch (menuInput)
			{
			case 1:
				stockPerformance(portfolioStack);
				quitInput = "N";
				break;

			case 2:
				findStock(portfolioStack);
				quitInput = "N";
				break;

			case 3:
				cout << "\nSetting up test data: " << endl;
				cout << "Enter 1 to set up test data manually" << endl;
				cout << "Enter 2 to set up test data from file\n" << endl;
				int testDataInput;
				cin >> testDataInput;

				switch (testDataInput)
				{
				case 1:
					cout << "\nSetting up data manually..." << endl;
					portfolioStack = setUpTestData();
					if (!portfolioStack.empty()) { cout << "\nData set up successfully." << endl; }
					else { cout << "\nFailed to set up test data." << endl; }
					break;

				case 2:
					cout << "\nSetting up data from file..." << endl;
					portfolioStack = setUpTestDataFromFile();
					if (!portfolioStack.empty()) { cout << "\nData set up successfully." << endl; }
					else { cout << "\nFailed to set up test data." << endl; }
					break;

				default:
					cout << "\n! Invalid input" << endl;
					break;
				}

				quitInput = "N";
				break;

			case 4:
				showStockPortfolio(portfolioStack);
				quitInput = "N";
				break;

			case 0:
				quitInput = "Y";
				break;

			default:
				cout << "\n! Invalid input" << endl;
				break;
			}
		}

		if (quitInput != "N") {
		cout << "\nConfirm exit? (Y/N)" << endl;
		cin >> quitInput;
		quitInput = stringToUpperCase(quitInput);
		}

		//// Waiting for 1 second
		//this_thread::sleep_for(chrono::seconds(1));	
	} while (quitInput.compare("Y"));

	return 0;
}


void stockPerformance(Stack<Stock> stockStack) {
	// Function to enter stock performance
	string stockToTrade;
	double percentChange;

	cout << "\nEnter stock name: ";
	cin >> stockToTrade;
	stockToTrade = stringToUpperCase(stockToTrade);

	cout << "Enter percentage change: ";
	cin >> percentChange;


	if ((percentChange >= 5) && (percentChange <= 20)) {
		sellFifo(stockToTrade, stockStack);
	}
	else if ((percentChange >= -1) && (percentChange <= -0.5)) {
		buyLifo(stockToTrade, stockStack);
	}
	else if ((percentChange >= -3) && (percentChange <= -1.1)) {
		sellLifo(stockToTrade, stockStack);
	}
	else {
		cout << "\nPortforlio is retained." << endl;
	}
}

// ------------------------------------------------------------------------

void findStock(Stack<Stock> stockStack) {
	// Function to find a stock in the portfolio
	string stockToFind;
	cout << "\nEnter the stock name to find: ";
	cin >> stockToFind;
	stockToFind = stringToUpperCase(stockToFind);

	// Search for the stock in the stack
	string searchContent;
	int numberOfFoundStocks = 0;

	for (int i = 0; i <= stockStack.getIndexOfTop(); i++) {
		if (stockStack.contents[i].getName() == stockToFind) {
			searchContent = searchContent + "\n" + to_string(stockStack.contents[i].getNumberOfShares()) + " " + stockStack.contents[i].getName() + "  shares @ " + (char)156 + to_string(stockStack.contents[i].getPricePerShare());

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

// ------------------------------------------------------------------------

Stack<Stock> setUpTestData() {
	// Function to set up test data
	cout << "\nSetting up stock data..." << endl;

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

	Stock stock1("MSFT", 100, 200.39);
	Stock stock2("GME", 500, 9.39);
	Stock stock3("MSFT", 250, 214.22);
	Stock stock4("MSFT", 300, 222.59);

	// Push stock objects onto the stack
	stockStack.push(stock1);
	stockStack.push(stock2);
	stockStack.push(stock3);
	stockStack.push(stock4);


	return stockStack;
}

// ------------------------------------------------------------------------

Stack<Stock> setUpTestDataFromFile() {
	cout << "Setting up stock data from file..." << endl;

	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;

	// Function to set up test data from a file
	ifstream stocksFile;
	stocksFile.open(fileName);

	// Check if the file opened successfully
	if (!stocksFile) {
		cout << "Error opening file." << endl;
		return false;
	}

	string stockName;
	int numberOfShares;
	double pricePerShare;

	// Count number of stocks in file (number of lines in file)
	int numberOfStocks = 0;
	while (stocksFile >> stockName >> numberOfShares >> pricePerShare) {
		numberOfStocks += 1;
	}
	stocksFile.close();


	// Build the portfolio stack
	stocksFile.open(fileName);

	Stack<Stock> stockStack(numberOfStocks);
	while (stocksFile >> stockName >> numberOfShares >> pricePerShare) {
		string stockNameTemp = string(stockName);
		int numberOfSharesTemp = int(numberOfShares);
		double pricePerShareTemp = double(pricePerShare);

		stockName = stringToUpperCase(stockName);

		Stock newStock(stockNameTemp, numberOfSharesTemp, pricePerShareTemp);
		stockStack.push(newStock);
	}

	stocksFile.close();

	return stockStack;
}

// ------------------------------------------------------------------------

void showStockPortfolio(Stack<Stock> stockStack) {
	if (!stockStack.empty()) {
		// Show the stock portfolio
		cout << "\nYour Current Stock Portfolio:" << endl;
		cout << "------------------------------------------------------------------------" << endl;

		// Print the stack contents
		stockStack.printStack();
		cout << endl;
	}
	else {
		cout << "\nYour stock portfolio is empty." << endl;
		cout << "Please set up stock data first." << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << endl;
		//exit(0);
	}
}

// ------------------------------------------------------------------------

bool sellFifo(string stockToTrade, Stack<Stock> stockStack) {
	
	char tradeCompleted = 'N';
	Stack<Stock> noTradeStockStack(stockStack.getStockStack());
	int sharesToTrade;

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
		cout << "\nStock not found in portfolio." << endl;
		return false;
	}
	else {
		// Print the stock portfolio before trading
		cout << "\nStock portfolio before trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockStack.printStack();
		cout << endl;

		cout << "\nEnter amount of shares you wish to sell from the earliest purchase: ";
		cin >> sharesToTrade;
	}

	// Check if shares to trade are more than available shares
	if (sharesToTrade > availableShares) {
		cout << "\n! Not enough shares to trade." << endl;
		cout << "Available shares: " << availableShares << endl;
		cout << "Trade all available shares?" << endl;
		cout << "Enter 'Y' for yes or any other key to cancel: ";

		char confirmTrade;
		cin >> confirmTrade;

		if (toupper(confirmTrade) == 'Y') {
			// Trade all available shares
			sharesToTrade = availableShares;
		}
		else {
			// Cancel trade
			cout << "\nTrade cancelled." << endl;
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
				stockStack.remove(currentStock);
				stockStack.add(currentStock);
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
		stockStack.add(currentStock);
		noTradeStockStack.remove(currentStock);
	}

	// Print the stock portfolio after trading
	cout << "\nStock portfolio after trading:" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	stockStack.printStack();
	cout << endl << endl;
	cout << "Trade completed." << endl;
	return true;
}

// ------------------------------------------------------------------------

bool buyLifo(string stockToTrade, Stack<Stock> stockStack) {
	char tradeCompleted = 'N';
	int sharesToTrade;

	for (int i = stockStack.getIndexOfTop(); i >= 0; i--) {
		Stock currentStock = stockStack.contents[i];
		if (currentStock.getName() == stockToTrade) {
			cout << "\nEnter amount of shares you wish to buy at the current price: ";
			cin >> sharesToTrade;

			currentStock.setNumberOfShares(currentStock.getNumberOfShares() + sharesToTrade);
			tradeCompleted = 'Y';
			break;
		}
	}

	if (tradeCompleted == 'N') {
		cout << "\nStock not found in portfolio." << endl;
		return false;
	}

	// Print the stock portfolio after trading
	cout << "\nStock portfolio after trading:" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	stockStack.printStack();
	cout << endl << endl;
	cout << "Trade completed." << endl;
	return true;
}

// ------------------------------------------------------------------------

bool sellLifo(string stockToTrade, Stack<Stock> stockStack) {

	char tradeCompleted = 'N';
	Stack<Stock> noTradeStockStack(stockStack.getStockStack());
	int sharesToTrade;


	//Check for total shares for stock available in portfolio to sell
	int availableShares = 0;
	char validStock = 'N';
	for (int i = stockStack.getIndexOfTop(); i >= 0; i--) {
		Stock currentStock = stockStack.contents[i];
		if (currentStock.getName() == stockToTrade) {
			availableShares += currentStock.getNumberOfShares();
			validStock = 'Y';
		}
	}

	// Stock not found in portfolio
	if (validStock == 'N') {
		cout << "\nStock not found in portfolio." << endl;
		return false;
	}
	else {
		// Print the stock portfolio before trading
		cout << "\nStock portfolio before trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockStack.printStack();
		cout << endl;

		cout << "\nEnter amount of shares you wish to sell from the most recent purchase: ";
		cin >> sharesToTrade;
	}

	// Check if shares to trade are more than available shares
	if (sharesToTrade > availableShares) {
		cout << "\n! Not enough shares to trade." << endl;
		cout << "Available shares: " << availableShares << endl;
		cout << "Trade all available shares?" << endl;
		cout << "Enter 'Y' for yes or any other key to cancel: ";

		char confirmTrade;
		cin >> confirmTrade;

		if (toupper(confirmTrade) == 'Y') {
			// Trade all available shares
			sharesToTrade = availableShares;
		}
		else {
			// Cancel trade
			cout << "\nTrade cancelled." << endl;
			return false;
		}
	}

	while ((!stockStack.empty()) && (tradeCompleted == 'N')) {
		Stock currentStock = stockStack.top();
		if (currentStock.getName() == stockToTrade) {

			if (sharesToTrade > currentStock.getNumberOfShares()) {
				sharesToTrade -= currentStock.getNumberOfShares();
				stockStack.pop(currentStock);
				tradeCompleted = 'N';
			}
			else if (sharesToTrade == currentStock.getNumberOfShares()) {
				stockStack.pop(currentStock);
				tradeCompleted = 'Y';
			}
			else {
				currentStock.setNumberOfShares(currentStock.getNumberOfShares() - sharesToTrade);
				stockStack.pop(currentStock);
				stockStack.push(currentStock);
				tradeCompleted = 'Y';
			}
		}
		else {
			noTradeStockStack.push(currentStock);
		}
	}

	// Move stocks back to original stack
	while (!noTradeStockStack.empty()) {
		Stock currentNoTradeStock = noTradeStockStack.bottom();
		stockStack.push(currentNoTradeStock);
		noTradeStockStack.remove(currentNoTradeStock);
	}

	// Print the stock portfolio after trading
	cout << "\nStock portfolio after trading:" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	stockStack.printStack();
	cout << endl << endl;
	cout << "Trade completed." << endl;
	return true;
}

// ------------------------------------------------------------------------

string stringToUpperCase(string str) {
	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}

// ------------------------------------------------------------------------
