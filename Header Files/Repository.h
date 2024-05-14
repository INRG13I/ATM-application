//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_REPOSITORY_H
#define LAB_2_SD_REPOSITORY_H


#include "List.h"
#include "Transaction.h"

class Repository
{
private:
    List<Transaction> repo;

public:

//------------------------------------------------------------------------------------------------------ Constructors //

    Repository() = default;
    ~Repository() = default;

//----------------------------------------------------------------------------------------------------------- Methods //

    void add(Transaction& newTransaction);
    void del(int position);
    void update(int position,Transaction& newTransaction);
    List<Transaction> getAll()const;
};

#endif //LAB_2_SD_REPOSITORY_H
