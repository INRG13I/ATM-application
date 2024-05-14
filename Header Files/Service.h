//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_SERVICE_H
#define LAB_2_SD_SERVICE_H


#include "Repository.h"

class Service
{
private:
    Repository repo;
    List<Currency> totalCurrencyPool;

public:

//------------------------------------------------------------------------------------------------------ Constructors //


    Service() = default;
    ~Service() = default;

//----------------------------------------------------------------------------------------------------------- Methods //


    void add(Transaction& newTransaction);
    void del(int position);
    void update(int position, Transaction& newTransaction);
    List<Transaction> getAll()const;

    List<Currency> leastBills(int sum);

    List<Currency> getTotalCurrency()const;
};


#endif //LAB_2_SD_SERVICE_H
