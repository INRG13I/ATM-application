# ATM System

A simple ATM (Automated Teller Machine) system implemented in C++.
# Features

Add Transaction: Users can add transactions to the system.

Print Transaction History: Users can view their transaction history.

Print Currency: Users can view the available currency in the system.

Withdraw Money with Least Bills: Users can withdraw money with the least number of bills possible.

# Classes
ATM

Methods:
    
void run(): Runs the ATM system.

void printMenu(): Prints the menu options.

void addTransaction(): Adds a transaction to the system.

void printTransactions(): Prints the transaction history.

void printCurrency(): Prints the available currency.

void leastBills(): Withdraws money with the least number of bills possible.

# Currency

Methods:

Constructors, destructor, copy constructor. 

Getters and setters for value and quantity.

Overloaded operators: =, ==, >, <.

Input and output stream operators.

# List

Template Class:

Class: Template parameter.

Attributes:
    
Class* list: Pointer to the list.
    
int size: Size of the list.

Methods:
    
Constructors, destructor, copy constructor.
    
int find(Class element): Finds an element in the list.
 
int getSize() const: Gets the size of the list.

void add(Class newElement): Adds a new element to the list.

void del(int position): Deletes an element from the list.

void update(int position, Class newElement): Updates an element in the list.

void bubblesort(): Sorts the list.

Assignment operator overload.

Output stream operator overload.

# Repository

Attributes:

List<Transaction> repo: Repository of transactions.


Methods:

void add(Transaction &newTransaction): Adds a transaction to the repository.

void del(int position): Deletes a transaction from the repository.

void update(int position, Transaction &newTransaction): Updates a transaction in the repository.

List<Transaction> getAll() const: Gets all transactions from the repository.

# Service

Attributes:

Repository repo: Repository of transactions.

List<Currency> totalCurrencyPool: Total currency pool.


Methods:

void add(Transaction &newTransaction): Adds a transaction to the system.

void del(int position): Deletes a transaction from the system.

void update(int position, Transaction &newTransaction): Updates a transaction in the system.

List<Transaction> getAll() const: Gets all transactions from the system.

List<Currency> leastBills(int sum): Withdraws money with the least number of bills possible.

List<Currency> getTotalCurrency() const: Gets the total currency pool.

# Transaction

Attributes:

List<Currency> currencyList: List of currency in the transaction.

char type: Type of transaction ('+' for deposit, '-' for withdrawal).

int totalSum: Total sum of the transaction.


Methods:

Constructors, destructor, copy constructor.

Getters and setters for currencyList, type, and totalSum.

Assignment operator overload.