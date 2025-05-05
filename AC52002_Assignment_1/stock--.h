//#include "stock_def.h"
//
//// Constructor
//Stock::Stock() : stock_name(""), number_of_shares(0), price_per_share(0) {
//}
//
//Stock::Stock(string name, int shares, double price) : stock_name(name), number_of_shares(shares), price_per_share(price) {
//}
//
//
//void Stock::setName(string name) {
//	stock_name = name;
//}
//
//
//void Stock::setNumberOfShares(int shares) {
//	number_of_shares = shares;
//}
//
//
//void Stock::setPricePerShare(double price) {
//	price_per_share = price;
//}
//
//
//string Stock::getName() {
//	return stock_name;
//}
//
//
//int Stock::getNumberOfShares() {
//	return number_of_shares;
//}
//
//
//double Stock::getPricePerShare() {
//	return price_per_share;
//}
//
//
//string Stock::printStock() {
//	//cout << number_of_shares << " " << stock_name << " shares @ £" << price_per_share;
//	string printOutput = to_string(number_of_shares) + " " + stock_name + " shares @ £" + to_string(price_per_share);
//	return printOutput;
//}
