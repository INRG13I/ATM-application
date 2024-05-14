//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_TRANSACTION_H
#define LAB_2_SD_TRANSACTION_H


#include "List.h"
#include "Currency.h"

class Transaction
{
private:
    List<Currency> currencyList;
    char type;
    int totalSum;

public:

//------------------------------------------------------------------------------------------------------ Constructors //

    Transaction();
    Transaction(char newType, int newTotalSum, List<Currency>& newCurrencyList);
    Transaction(const Transaction& newTransaction);

    ~Transaction() = default;

//------------------------------------------------------------------------------------------------- Getters & Setters //


    List<Currency> getCurrencyList()const;
    char getType()const;
    int getTotalSum()const;

    void setCurrencyList(List<Currency> newCurrencyList);
    void setType(char newType);
    void setTotalSum(int newTotalSum);

//------------------------------------------------------------------------------------------------ Operator overloads //


    Transaction& operator=(const Transaction& rTransaction);

};



#endif //LAB_2_SD_TRANSACTION_H
