//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#include "../Header Files/Transaction.h"


//------------------------------------------------------------------------------------------------------ Constructors //

Transaction::Transaction()
{
    type = '0';
    totalSum = 0;
}

Transaction::Transaction(char newType, int newTotalSum, List<Currency>& newCurrencyList)
{
    this->setCurrencyList(newCurrencyList);
    this->setType(newType);
    this->setTotalSum(newTotalSum);
}

Transaction::Transaction(const Transaction& newTransaction)
{
    this->setCurrencyList(newTransaction.getCurrencyList());
    this->setType(newTransaction.getType());
    this->setTotalSum(newTransaction.getTotalSum());
}

//------------------------------------------------------------------------------------------------- Getters & Setters //

List<Currency> Transaction::getCurrencyList() const
{
    return currencyList;
}

char Transaction::getType()const
{
    return type;
}

int Transaction::getTotalSum()const
{
    return totalSum;
}

void Transaction::setCurrencyList(List<Currency> newCurrencyList)
{
    currencyList = newCurrencyList;
}

void Transaction::setType(char newType)
{
    type = newType;
}

void Transaction::setTotalSum(int newTotalSum)
{
    totalSum = newTotalSum;
}

//------------------------------------------------------------------------------------------------ Operator overloads //


Transaction& Transaction::operator=(const Transaction& rTransaction)
{
    if (this != &rTransaction) {

        this->setCurrencyList(rTransaction.getCurrencyList());
        this->setType(rTransaction.getType());
        this->setTotalSum(rTransaction.getTotalSum());


    }

    return *this;
}
