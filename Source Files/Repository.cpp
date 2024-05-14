//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#include "../Header Files/Repository.h"

//----------------------------------------------------------------------------------------------------------- Methods //

void Repository::add(Transaction& newTransaction)
{
    repo.add(newTransaction);
}

void Repository::del(int position)
{
    repo.del(position);
}

void Repository::update(int position, Transaction& newTransaction)
{
    repo.update(position, newTransaction);
}

List<Transaction> Repository::getAll() const
{
    return repo;
}
