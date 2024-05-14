//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#ifndef LAB_2_SD_CURRENCY_H
#define LAB_2_SD_CURRENCY_H


#include <iostream>
class Currency {
private:
    int value;
    int quantity;


public:
//------------------------------------------------------------------------------------------------------ Constructors //

    Currency();
    Currency(int newValue, int newQuantity);
    Currency(const Currency &newCurrency);

    ~Currency() = default;

//------------------------------------------------------------------------------------------------- Getters & Setters //

    void setValue(int newValue);
    void setQuantity(int newQuantity);

    int getValue() const;
    int getQuantity() const;

//------------------------------------------------------------------------------------------------ Operator Overloads //

    Currency &operator=(const Currency &rCurrency);
    bool operator==(const Currency& rCurrency);
    bool operator>(const Currency& rCurrency);
    bool operator<(const Currency& rCurrency);

    friend std::ostream& operator<<(std::ostream& os, Currency& currency);
    friend std::istream& operator>>(std::istream& is, Currency& currency);


};
#endif //LAB_2_SD_CURRENCY_H
