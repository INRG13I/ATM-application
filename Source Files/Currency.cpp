//
// Created by Nicolaescu Raoul on 05.04.2023.
//

#include "../Header Files/Currency.h"


//------------------------------------------------------------------------------------------------------ Constructors //

Currency::Currency()
{
    this->setValue(0);
    this->setQuantity(0);
}

Currency::Currency(int newValue, int newQuantity)
{
    this->setValue(newValue);
    this->setQuantity(newQuantity);
}

Currency::Currency(const Currency& newCurrency)
{
    this->setValue(newCurrency.getValue());
    this->setQuantity(newCurrency.getQuantity());
}

//------------------------------------------------------------------------------------------------- Getters & Setters //

void Currency::setValue(int newValue)
{
    this->value = newValue;
}

void Currency::setQuantity(int newQuantity)
{
    this->quantity = newQuantity;
}

int Currency::getValue()const
{
    return this->value;
}

int Currency::getQuantity()const
{
    return this->quantity;
}

//------------------------------------------------------------------------------------------------ Operator Overloads //

Currency& Currency::operator=(const Currency& rCurrency)
{
    if (this != &rCurrency)
    {
        this->setValue(rCurrency.getValue());
        this->setQuantity(rCurrency.getQuantity());
    }
    return *this;
}

bool Currency::operator==(const Currency& rCurrency)
{
    return (this->getValue() == rCurrency.getValue());
}

bool Currency::operator>(const Currency& rCurrency)
{
    return (this->getValue()>rCurrency.getValue());
}

bool Currency::operator<(const Currency& rCurrency)
{
    return (this->getValue()<rCurrency.getValue());
}

std::istream& operator>>(std::istream& is, Currency& currency)
{
    std::cout << "Insert value:";
    is >> currency.value;
    std::cout << "Insert quantity:";
    is >> currency.quantity;
    std::cout << "\n";
    return is;
}

std::ostream &operator<<(std::ostream &os, Currency &currency) {
    os << "Value: " << currency.getValue() << "\n";
    os << "Quantity: " << currency.getQuantity() << "\n";
    return os;
}
