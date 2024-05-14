//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#include "../Header Files/ATM.h"
#include "../Header Files/Transaction.h"
#include "../Header Files/Currency.h"
#include "../Header Files/List.h"
#include "../Header Files/Service.h"


#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void ATM::printMenu()
{
    cout << " --------------------------------------- \n";
    cout << "|add transaction                        |\n";
    cout << "|add currency                           |\n";
    cout << "|print transaction                      |\n";
    cout << "|print currency                         |\n";
    cout << "|withdraw                               |\n";
    cout << "|exit                                   |\n";
    cout << " --------------------------------------- \n";
}

void ATM::addTransaction()
{
    Transaction transaction;

    char type_in[20], type;
    int totalSum=0;
    List<Currency> currency;

    cout << "Type: ";
    cin >> type_in;
    if(strcmp(type_in , "deposit") == 0) type ='+';
    if(strcmp(type_in , "withdraw") == 0) type ='-';

    int n;

    cout << "Enter amount of currency you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Currency bill;
        cin >> bill;
        currency.add(bill);
        totalSum += bill.getQuantity() * bill.getValue();
    }

    transaction.setType(type);
    transaction.setTotalSum(totalSum);
    transaction.setCurrencyList(currency);

    service.add(transaction);
}

void ATM::printTransactions()
{
    List<Transaction> list(service.getAll());


    for (int i = 0; i < list.getSize(); i++)
    {
        Transaction transaction(list.getElement(i));

        cout << "Type: " << transaction.getType()<<"\n";
        cout << "Total sum: " << transaction.getTotalSum() << "\n";

        List<Currency> list(transaction.getCurrencyList());

        for (int i = 0; i < list.getSize(); i++)
        {
            Currency currency(list.getElement(i));

            cout << currency << "\n";
        }
    }

}

void ATM::printCurrency()
{
    List<Currency> list(service.getTotalCurrency());

    for (int i = 0; i < list.getSize(); i++)
    {
        Currency currency(list.getElement(i));

        cout << currency << "\n";
    }
}

void ATM::leastBills() {
    int sum;
    List<Currency> currencyList;

    std::cout << "Enter sum to withdraw: ";
    std::cin >> sum;

    currencyList = service.leastBills(sum);

    for (int i = 0; i < currencyList.getSize(); i++)
    {
        Currency currency(currencyList.getElement(i));

        std::cout << currency << "\n";
    }

    char option;


    std::cout << "Do you accept this transaction?: [y/n]";
    std::cin >> option;
    std::cout << "\n";

    if (option == 'y')
    {
        Transaction transaction('-', sum, currencyList);

        service.add(transaction);
    }
    else
    {
        return;
    }
}

void ATM::run() {
    while (true) {
        char option1[20], option2[20];

        this->printMenu();

        cin >> option1 ;

        if (strcmp(option1, "add") == 0) {
            cin >> option2;
            if (strcmp(option2, "transaction") == 0) {
                this->addTransaction();
            } else if (strcmp(option2, "currency") == 0) {
                char opt;
                cout << "Do you have admin rights? [y/n]" << endl;
                cin >> opt;
                if (opt == 'y') {
                    Transaction transaction;

                    char type = '+';
                    int totalSum = 0;
                    List<Currency> currency;

                    int n;

                    cout << "Enter amount of currency you want to add: ";
                    cin >> n;

                    for (int i = 0; i < n; i++) {
                        Currency bill;
                        cin >> bill;
                        currency.add(bill);
                        totalSum += bill.getQuantity() * bill.getValue();
                    }

                    transaction.setType(type);
                    transaction.setTotalSum(totalSum);
                    transaction.setCurrencyList(currency);

                    service.add(transaction);
                }
            }


        }else if(strcmp(option1 , "print") == 0){
            cin >> option2;
            if(strcmp(option2 , "transaction") == 0){
                this->printTransactions();
            }else if(strcmp(option2 , "currency") == 0){
                this->printCurrency();
            }

        }else if(strcmp(option1 , "withdraw") == 0){
            this->leastBills();
        }else if(strcmp(option1 , "exit") == 0){
            cout<<"Bye bye"<<endl;
            return;
        }else{
            cout<<"Optiune inexistenta"<<endl;
        }

    }

}
