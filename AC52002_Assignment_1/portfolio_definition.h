#ifndef PORTFOLIO_DEF_H
#define PORTFOLIO_DEF_H

#include <string>
using namespace std;

// ------------------------------------------------------------------------
// ------------------------------------------------------------------------

template <class Type>
class Portfolio
{
private:
    // Member variables
    int portfolioSize;
    int indexOfTop;
    int indexOfBottom;

public:
	// Member variable
    Type* contents;

	// Constructors and Destructor
    Portfolio(int portfolioSize = 10);
    ~Portfolio();

    // Member Functions
    bool empty() const;
    bool full() const;
    bool push(const Type& new_element);
    bool pop(Type& top_element);
    bool remove(Type& bottom_element);
    bool add(const Type& new_element);
    Type top();
    Type bottom();
    int getIndexOfTop();
    int getPortfolioSize();
    void printPortfolio();
    void clearPortfolio();
	bool sellFifoInPortfolio(string stockToSellName, int stockToSellAmount);
    bool sellLifoInPortfolio(string stockToSellName, int stockToSellAmount);
};

#endif