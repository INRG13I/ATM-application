//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#include "../Header Files/Service.h"

//----------------------------------------------------------------------------------------------------------- Methods //


void Service::add(Transaction& newTransaction)
{
    List<Currency> currencyList = newTransaction.getCurrencyList();

    for (int i = 0; i < currencyList.getSize(); i++)
    {
        int position = totalCurrencyPool.find(currencyList.getElement(i));

        if (position != -1) {

            int sum = totalCurrencyPool.getElement(position).getValue();

            sum *= totalCurrencyPool.getElement(position).getQuantity();

            int value = totalCurrencyPool.getElement(position).getValue();

            int quantity = totalCurrencyPool.getElement(position).getQuantity();

            if (newTransaction.getType() == '-') {

                sum -= currencyList.getElement(i).getValue()*currencyList.getElement(i).getQuantity();

                quantity -= currencyList.getElement(i).getQuantity();

                if (sum < 0) {
                    return;
                }
            }
            else
            {
                sum += currencyList.getElement(i).getValue() * currencyList.getElement(i).getQuantity();
                quantity += currencyList.getElement(i).getQuantity();
            }
            totalCurrencyPool.update(position, Currency(value, quantity));
        }
        else
        {
            totalCurrencyPool.add(currencyList.getElement(i));
        }
    }
    repo.add(newTransaction);
}

void Service::del(int position)
{
    repo.del(position);
}

void Service::update(int position, Transaction& newTransaction)
{
    repo.update(position, newTransaction);
}

List<Transaction> Service::getAll() const
{
    return repo.getAll();
}

List<Currency> Service::leastBills(int sum)
{
        List<Currency> list;
        List<Currency> currencyList(this->getTotalCurrency());

        int currentSum = 0;

        currencyList.bubblesort();

        for (int i = 0; i < currencyList.getSize() && currentSum<sum; i++)
        {
            int amount = 0;

            int currencyValue = currencyList.getElement(i).getValue();
            int currencyQuantity = currencyList.getElement(i).getQuantity();


            while ((currentSum + currencyValue <= sum) && (amount<=currencyQuantity)) {
                currentSum += currencyValue;
                amount++;
            }
            if (amount != 0) {

                list.add(Currency(currencyValue, amount));
            }
        }

        return list;

}

List<Currency> Service::getTotalCurrency() const
{
    return totalCurrencyPool;
}
