#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

// Include the portfolio and stock header files
#include "portfolio_template.h"
#include "stock_definition.h"



// ------------------------------------------------------------------------
// Function definitions
void stockPerformance(Portfolio<Stock>& stockPortfolio);
void findStock(Portfolio<Stock>& stockPortfolio);
bool setUpStockData(Portfolio<Stock>& stockPortfolio, int portfolioSize);
bool setUpStockDataFromFile(Portfolio<Stock>& stockPortfolio, int portfolioSize);
void showStockPortfolio(Portfolio<Stock>& stockPortfolio);
// ------------------------------------------------------------------------
bool sellFifo(string stockToTrade, Portfolio<Stock>& stockPortfolio);
bool buyStock(string stockToTrade, Portfolio<Stock>& stockPortfolio);
bool sellLifo(string stockToTrade, Portfolio<Stock>& stockPortfolio);
string stringToUpperCase(string str);
// ------------------------------------------------------------------------


int main() {
	int portfolioSize, menuInput;
	char portfolioSetup; string exitInput;

	cout << "\n------------------------------------------------------------------------" << endl;
	cout << "************************************************************************" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "Welcome to KRYSTAL Stock Portfolio Trading System! \n" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	// Set up the portfolio with the number of stocks estimated
	cout << "\nEnter the number of stocks estimated for your portfolio \n(must be a value greater than 0): " << endl;
	cout << ">>> "; cin >> portfolioSize;

	if (portfolioSize <= 0) {
		cout << "\n!!! Invalid number of stocks. \nExiting program..." << endl;
		exit(0);
	}
	
	Portfolio<Stock> portfolioForStocks(portfolioSize);
	cout << "------------------------------------------------------------------------" << endl;

	do {
		// Display the menu
		cout << "\n------------------------------------------------------------------------" << endl;
		cout << "************************************************************************" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "(1) - To enter a stock performance" << endl;
		cout << "(2) - To find stock" << endl;
		cout << "(3) - To set up test data" << endl;
		cout << "(4) - To show stock portfolio" << endl;
		cout << "(0) - To exit program" << endl;
		cout << ">>> "; cin >> menuInput;

		// Check if the input is valid
		if ((menuInput < 0) || (menuInput > 4)) {
			cout << "\n!!! Invalid input \nExiting program..." << endl;
			exit(0);
		}
		else {
			switch (menuInput)
			{
			case 1:
				// Menu option to enter stock performance
				cout << "------------------------------------------------------------------------" << endl;
				if (portfolioForStocks.empty()) {
					cout << "\n!!! Portfolio is empty" << endl;
				}
				else {
					stockPerformance(portfolioForStocks);
				}
				exitInput = "N";
				break;

			case 2:
				// Menu option to find stock
				cout << "------------------------------------------------------------------------" << endl;
				if (portfolioForStocks.empty()) {
					cout << "\n!!! Portfolio is empty" << endl;
				}
				else {
					findStock(portfolioForStocks);
				}
				exitInput = "N";
				break;

			case 3:
				// Menu option to set up stock data
				cout << "\n------------------------------------------------------------------------" << endl;
				if (!portfolioForStocks.empty()) {
					cout << "! Note that this will clear the previous content of your portfolio" << endl;
					this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
				}

				// Select mode of setting up stock data
				cout << "------------------------------------------------------------------------" << endl;
				cout << "\nHow would you be setting up your stock data: " << endl;
				cout << "(1) - To set up data manually" << endl;
				cout << "(2) - To set up data from file" << endl;
				int testDataInput;
				cout << ">>> "; cin >> testDataInput;

				switch (testDataInput)
				{
				case 1:
					// Set up data manually
					cout << "\nSetting up data manually..." << endl;

					// Clear existing contents of the portfolio
					portfolioForStocks.clearPortfolio();

					if (setUpStockData(portfolioForStocks, portfolioSize)) { cout << "\nData set up successfully." << endl; }
					else { cout << "\nFailed to set up portfolio data." << endl; }
					break;

				case 2:
					// Set up data from file
					cout << "\nSetting up data from file..." << endl;

					// Clear existing contents of the portfolio
					portfolioForStocks.clearPortfolio();

					if (setUpStockDataFromFile(portfolioForStocks, portfolioSize)) { cout << "\nData set up successfully." << endl; }
					else { cout << "\nFailed to set up portfolio data." << endl; }
					break;

				default:
					// Invalid input
					cout << "\n!!! Invalid input" << endl;
					break;
				}
				exitInput = "N";
				break;

			case 4:
				// Menu option to show stock portfolio
				cout << "------------------------------------------------------------------------" << endl;
				if (portfolioForStocks.empty()) {
					cout << "\n!!! Portfolio is empty" << endl;
				}
				else {
					showStockPortfolio(portfolioForStocks);
				}
				exitInput = "N";
				break;

			case 0:
				// Menu option to exit program
				exitInput = "Y";
				break;

			default:
				// Invalid input
				cout << "\n!!! Invalid input" << endl;
				break;
			}
		}

		// Confirm if user wants to exit
		if (exitInput != "N") {
			cout << "\nConfirm exit? (Y/N)" << endl;
			cout << ">>> "; cin >> exitInput;
			exitInput = stringToUpperCase(exitInput);
		}

		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
	} while (exitInput.compare("Y"));

	return 0;
}


void stockPerformance(Portfolio<Stock>& stockPortfolio) {
	// Function to enter stock performance
	string stockToTrade;
	double percentChange;

	// Get stock name and percentage change from user
	cout << "\nEnter stock name: ";
	cout << "\n>>> "; cin >> stockToTrade;
	stockToTrade = stringToUpperCase(stockToTrade);

	cout << "Enter percentage change: ";
	cout << "\n>>> "; cin >> percentChange;

	// Check if the percentage change is valid
	if (percentChange < -100 || percentChange > 100) {
		cout << "\n!!! Invalid percentage change" << endl;
		return;
	}

	// Navigate Trading Strategy based on the percentage change
	if ((percentChange >= 5) && (percentChange <= 20)) {
		// Sell existing stock from portfolio using FIFO method
		sellFifo(stockToTrade, stockPortfolio);
	}
	else if ((percentChange >= -1) && (percentChange <= -0.5)) {
		// Buy stock and push to portfolio
		buyStock(stockToTrade, stockPortfolio);
	}
	else if ((percentChange >= -3) && (percentChange <= -1.1)) {
		// Sell existing stock from portfolio using LIFO method
		sellLifo(stockToTrade, stockPortfolio);
	}
	else {
		// Retaining current stock in portfolio
		char validStock = 'N';
		for (int i = 0; i <= stockPortfolio.getIndexOfTop(); i++) {
			// Check if the stock is in the portfolio
			if (stockPortfolio.contents[i].getName() == stockToTrade) {
				validStock = 'Y';
				break;
			}
		}

		// Stock not found in portfolio
		if (validStock == 'N') {
			cout << "\nStock not found in portfolio." << endl;
		}
		else {
			cout << "\nPortforlio is retained." << endl;
		}
	}
}

// ------------------------------------------------------------------------

void findStock(Portfolio<Stock>& stockPortfolio) {
	// Function to find a stock in the portfolio
	
	// Get stock name from user
	string stockToFind;
	cout << "\nEnter the stock name to find: ";
	cout << "\n>>> "; cin >> stockToFind;
	stockToFind = stringToUpperCase(stockToFind);

	// Search for the stock in the portfolio
	int numberOfFoundStocks = 0;
	string searchContent;

	cout << "\nSearching for stock..." << endl;
	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

	// Check if the stock is in the portfolio
	for (int i = 0; i <= stockPortfolio.getIndexOfTop(); i++) {
		if (stockPortfolio.contents[i].getName() == stockToFind) {
			searchContent = searchContent + "\n" + to_string(stockPortfolio.contents[i].getNumberOfShares()) + " " + stockPortfolio.contents[i].getName() + "  shares @ " + (char)156 + to_string(stockPortfolio.contents[i].getPricePerShare());

			numberOfFoundStocks += 1;
		}
	}

	// Check if the stock was found
	if (numberOfFoundStocks == 0) {
		// Stock not found in portfolio
		cout << "\nStock not found." << endl;;
	}
	else {
		// Print the stock details
		cout << "\nStock found: \n------------------------------------------------------------------------" << endl;
		cout << searchContent << endl;
	}

}

// ------------------------------------------------------------------------

bool setUpStockData(Portfolio<Stock>& stockPortfolio, int portfolioSize) {
	// Function to set up stock data
	
	
	// Get the number of stocks to set up
	int numberOfStocks;
	cout << "Enter the number of stocks to set up: ";
	cout << "\n>>> "; cin >> numberOfStocks;

	if (numberOfStocks <= 0) {
		cout << "Invalid number of stocks. Exiting setup." << endl;
		return false;
	}

	// Check if the number of stocks is more than the portfolio size
	if (numberOfStocks > portfolioSize) {
		cout << "\n!!! Number of stocks greater that portfolio size. \nExiting setup." << endl;
		return false;
	}

	int numberOfShares; double pricePerShare; string stockName;
	for (int i = 0; i < numberOfStocks; i++) {
		cout << "\n--------------------------\nStock " << i+1 << ": ";
		
		// Get stock name, number of shares, and price per share from user
		cout << "\nEnter stock name: ";
		cout << "\n>>> "; cin >> stockName;
		stockName = stringToUpperCase(stockName);

		cout << "\nEnter number of shares: ";
		cout << "\n>>> "; cin >> numberOfShares;

		// Check if the number of shares is valid
		if (numberOfShares <= 0) {
			cout << "\n!!! Invalid number of shares." << endl;
			return false;
		}


		cout << "\nEnter price per share: ";
		cout << "\n>>> "; cin >> pricePerShare;

		// Check if the price per share is valid
		if (pricePerShare <= 0) {
			cout << "\n!!! Invalid price." << endl;
			return false;
		}

		// Create a Stock object and push it onto the portfolio
		Stock newStock(stockName, numberOfShares, pricePerShare);
		stockPortfolio.push(newStock);

		cout << endl;
	}
	

	cout << "\nSetting up stock data inputted..." << endl;
	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

	return true;
}

// ------------------------------------------------------------------------

bool setUpStockDataFromFile(Portfolio<Stock>& stockPortfolio, int portfolioSize) {
	// Function to set up stock data from a file

	cout << "\nEnsure that file is in the same directory as the program." << endl;
	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

	cout << "\n! Format for the file contents is as follows:" << endl;
	cout << "<Stock Name> <Number Of Shares> <Price Per Share>" << endl;
	cout << "\n! Example: \nMSFT 100 200.39 \nGME  500 9.39" << endl;
	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second


	// Get the file name from user
	string fileName;
	cout << "\nEnter file name: ";
	cout << "\n>>> "; cin >> fileName;

	// Check if the file exists and stream file
	ifstream stocksFile;
	stocksFile.open(fileName);

	// Check if the file opened successfully
	if (!stocksFile) {
		cout << "\n!!! Error opening file." << endl;
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
	
	// Check if the number of stocks is more than the portfolio size
	if (numberOfStocks > portfolioSize) {
		cout << "\n!!! Number of stocks greater that portfolio size. \nExiting setup." << endl;
		return false;
	}

	stocksFile.close();


	// Build the portfolio portfolio
	stocksFile.open(fileName);

	int lineCount = 0;
	while (stocksFile >> stockName >> numberOfShares >> pricePerShare) {
		lineCount += 1;

		string stockNameTemp = string(stockName);
		int numberOfSharesTemp = int(numberOfShares);
		double pricePerShareTemp = double(pricePerShare);

		// Check if the stock name is valid
		if (numberOfShares <= 0) {
			cout << "\n!!! Invalid number of shares. (Line - " << lineCount << ")" << endl;
			cout << "Check the file for errors." << endl;
			return false;
		}

		// Check if the number of shares is valid
		if (pricePerShare <= 0) {
			cout << "\n!!! Invalid price." << endl;
			cout << "Check the file for errors." << endl;
			return false;
		}

		stockName = stringToUpperCase(stockName);

		// Create a Stock object and push it onto the portfolio
		Stock newStock(stockNameTemp, numberOfSharesTemp, pricePerShareTemp);
		stockPortfolio.push(newStock);
	}

	// Close the file
	stocksFile.close();

	if (stockPortfolio.empty()) {
		return false;
	}

	cout << "\nSetting up stock data from file..." << endl;
	this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

	return true;
}

// ------------------------------------------------------------------------

void showStockPortfolio(Portfolio<Stock>& stockPortfolio) {
	// Function to show the stock portfolio

	// Check if the portfolio is empty
	if (!stockPortfolio.empty()) {
		// Show the stock portfolio
		cout << "\nYour Current Stock Portfolio:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

		// Print the portfolio contents
		stockPortfolio.printPortfolio();
		cout << "------------------------------------------------------------------------" << endl;

		cout << endl;
	}
	else {
		// Portfolio is empty
		cout << "\nYour stock portfolio is empty." << endl;
		cout << "Please set up stock data first." << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << endl;
		//exit(0);
	}
}

// ------------------------------------------------------------------------

bool sellFifo(string stockToTrade, Portfolio<Stock>& stockPortfolio) {
	// Function to sell stock using FIFO method

	int sharesToTrade;

	//Check for total shares for stock available in portfolio to sell
	int availableShares = 0;
	char validStock = 'N';
	for (int i = 0; i <= stockPortfolio.getIndexOfTop(); i++) {
		Stock currentStock = stockPortfolio.contents[i];
		if (currentStock.getName() == stockToTrade) {
			availableShares += currentStock.getNumberOfShares();
			validStock = 'Y';
		}
	}

	// Check if the stock is in the portfolio
	if (validStock == 'N') {
		// Stock not found in portfolio
		cout << "\nStock not found in portfolio." << endl;
		return false;
	}
	else {
		// Print the stock portfolio before trading
		cout << "\nStock portfolio before trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockPortfolio.printPortfolio();
		cout << endl;

		cout << "\nEnter number of shares you wish to sell from the earliest purchase: ";
		cout << "\n>>> "; cin >> sharesToTrade;

		// Check if the number of shares is valid
		if (sharesToTrade <= 0) {
			cout << "\n!!! Invalid number of shares." << endl;
			return false;
		}
	}

	// Check if shares to trade are more than available shares
	if (sharesToTrade > availableShares) {
		cout << "\n!!! Not enough shares to trade." << endl;
		cout << "Available shares: " << availableShares << endl;
		cout << "Trade all available shares? " << endl;
		cout << "Enter 'Y' for yes or any other key to cancel: ";

		char confirmTrade;
		cout << "\n>>> "; cin >> confirmTrade;

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

	// Sell the stock using FIFO method
	if (stockPortfolio.sellFifoInPortfolio(stockToTrade, sharesToTrade)) {
		cout << "\nTrade in progress...:" << endl;
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second
		
		// Print the stock portfolio after trading
		cout << "\nStock portfolio after trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockPortfolio.printPortfolio();
		cout << endl << endl;
		cout << "Trade completed." << endl;
	}
	else {
		// Trade failed
		cout << "\n!!! Trade failed." << endl;
		return false;
	}
	
	return true;
}

// ------------------------------------------------------------------------

bool buyStock(string stockToTrade, Portfolio<Stock>& stockPortfolio) {
	// Function to buy stock and push to portfolio

	if (stockPortfolio.full()) {
		cout << "\n!!! Portfolio  is full";
		return false;
	}

	int numberOfShares; double pricePerShare;

	cout << "Enter number of shares to purchase: ";
	cout << "\n>>> "; cin >> numberOfShares;
	if (numberOfShares <= 0) {
		cout << "\n!!! Invalid number of shares." << endl;
		return false;
	}

	cout << "Enter price per share for this purchase: ";
	cout << "\n>>> "; cin >> pricePerShare;
	if (pricePerShare <= 0) {
		cout << "\n!!! Invalid price." << endl;
		return false;
	}


	// Create a Stock object and push it onto the portfolio
	Stock newStock(stockToTrade, numberOfShares, pricePerShare);
	if (stockPortfolio.push(newStock)) {
		cout << "\nTrade in progress...:" << endl;
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

		cout << "\nStock purchased:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << stockPortfolio.top().printStock();
		cout << endl << endl;

		// Print the stock portfolio after trading
		cout << "\nStock portfolio after trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockPortfolio.printPortfolio();
		cout << endl << endl;
		cout << "Trade completed." << endl;
	}
	else {
		cout << "\n!!! Portfolio  is full";
		return false;
	}

	return true;
}

// ------------------------------------------------------------------------

bool sellLifo(string stockToTrade, Portfolio<Stock>& stockPortfolio) {
	// Function to sell stock using LIFO method

	int sharesToTrade;

	//Check for total shares for stock available in portfolio to sell
	int availableShares = 0;
	char validStock = 'N';
	for (int i = stockPortfolio.getIndexOfTop(); i >= 0; i--) {
		Stock currentStock = stockPortfolio.contents[i];
		if (currentStock.getName() == stockToTrade) {
			availableShares += currentStock.getNumberOfShares();
			validStock = 'Y';
		}
	}

	// Check if the stock is in the portfolio
	if (validStock == 'N') {
		// Stock not found in portfolio
		cout << "\nStock not found in portfolio." << endl;
		return false;
	}
	else {
		// Print the stock portfolio before trading
		cout << "\nStock portfolio before trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockPortfolio.printPortfolio();
		cout << endl;

		cout << "\nEnter number of shares you wish to sell from the most recent purchase: ";
		cout << "\n>>> "; cin >> sharesToTrade;

		// Check if the number of shares is valid
		if (sharesToTrade <= 0) {
			cout << "\n!!! Invalid number of shares." << endl;
			return false;
		}

	}

	// Check if shares to trade are more than available shares
	if (sharesToTrade > availableShares) {
		cout << "\n!!! Not enough shares to trade." << endl;
		cout << "Available shares: " << availableShares << endl;
		cout << "Trade all available shares?" << endl;
		cout << "Enter 'Y' for yes or any other key to cancel: ";

		char confirmTrade;
		cout << "\n>>> "; cin >> confirmTrade;

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

	if (stockPortfolio.sellLifoInPortfolio(stockToTrade, sharesToTrade)) {
		cout << "\nTrade in progress...:" << endl;
		this_thread::sleep_for(chrono::seconds(1));		// Waiting for 1 second

		// Print the stock portfolio after trading
		cout << "\nStock portfolio after trading:" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		stockPortfolio.printPortfolio();
		cout << endl << endl;
		cout << "Trade completed." << endl;
		return true;
	} else {
		// Trade failed
		cout << "\n!!! Trade failed." << endl;
		return false;
	}
}

// ------------------------------------------------------------------------

string stringToUpperCase(string str) {
	// Function to convert string to uppercase

	for (char& c : str) {
		c = toupper(c);
	}
	return str;
}

// ------------------------------------------------------------------------
