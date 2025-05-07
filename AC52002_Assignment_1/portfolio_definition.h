#ifndef PORTFOLIO_DEF_H
#define PORTFOLIO_DEF_H

#include <string>
using namespace std;

template <class Type>
class Portfolio
{
private:
    int portfolioSize;
    int indexOfTop;
    int indexOfFront;

public:
    Portfolio(int portfolioSize = 10);
    ~Portfolio();

    Type* contents;

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