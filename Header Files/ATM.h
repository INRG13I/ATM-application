//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_ATM_H
#define LAB_2_SD_ATM_H

#include "Service.h"
class ATM
{
private:
    Service service;

    void printMenu();

    void addTransaction();
    void printTransactions();
    void printCurrency();
    void leastBills();


public:
    void run();
};


#endif //LAB_2_SD_ATM_H
