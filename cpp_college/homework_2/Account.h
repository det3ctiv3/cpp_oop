#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// TASK 1: BASE CLASS ACCOUNT
// ============================================================================
// This is the parent class that will be inherited by SavingsAccount and CheckingAccount

class Account {
protected:
    // Protected means: accessible by this class AND its derived classes
    // (but not from outside)
    string ownerName;
    double balance;

public:
    // PARAMETERIZED CONSTRUCTOR
    // This constructor requires parameters when creating an Account object
    // Example: Account acc("John", 1000.0);
    Account(string name = "", double bal = 0.0) : ownerName(name), balance(bal) {
        // The ": ownerName(name), balance(bal)" is called an initializer list
        // It initializes member variables before the constructor body runs
        // This is more efficient than assigning values inside the constructor
    }

    // GETTER METHOD
    // Returns the current balance (read-only access to private data)
    double getBalance() const {
        return balance;
    }

    // VIRTUAL FUNCTION
    // "virtual" means: derived classes can override this function
    // This allows polymorphism (calling the correct version based on object type)
    virtual void display() const {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }

    // VIRTUAL DESTRUCTOR
    // Destructor is called when an object is destroyed
    // "virtual" ensures the correct destructor is called for derived classes
    virtual ~Account() {
        cout << "Account closed for " << ownerName << endl;
    }

    // ========================================================================
    // TASK 3: OPERATOR OVERLOADING
    // ========================================================================
    // Operators are special functions that define how operators (+, -, ==, etc.)
    // work with our custom class

    // OPERATOR + (Addition)
    // Combines two accounts: Account acc3 = acc1 + acc2;
    // Returns a NEW Account with same owner name and summed balances
    Account operator+(const Account& other) const {
        // 'const Account& other' means we receive the other account by reference
        // (no copying) and promise not to modify it
        return Account(this->ownerName, this->balance + other.balance);
    }

    // OPERATOR - (Subtraction)
    // Returns the DIFFERENCE between two account balances (just a number)
    // Example: double diff = acc1 - acc2;
    double operator-(const Account& other) const {
        return this->balance - other.balance;
    }

    // OPERATOR == (Equality)
    // Checks if two accounts have the same balance
    // Example: if (acc1 == acc2) { ... }
    bool operator==(const Account& other) const {
        return this->balance == other.balance;
    }

    // OPERATOR << (Output Stream)
    // Allows us to print Account objects using cout
    // Example: cout << acc1;
    // Note: Must be a FRIEND function because << is called on cout (not Account)
    friend ostream& operator<<(ostream& out, const Account& acc) {
        // 'ostream& out' is the output stream (like cout)
        // We write to it and return it so we can chain operations
        out << "Owner: " << acc.ownerName << endl;
        out << "Balance: " << acc.balance;
        return out;
    }

    // OPERATOR >> (Input Stream)
    // Allows us to read Account data using cin
    // Example: cin >> acc1;
    // Note: Also a FRIEND function because >> is called on cin (not Account)
    friend istream& operator>>(istream& in, Account& acc) {
        // 'istream& in' is the input stream (like cin)
        // We read from it without printing prompts (as per requirements)
        in >> acc.ownerName >> acc.balance;
        return in;
    }
};

// ============================================================================
// TASK 2: DERIVED CLASS - SAVINGS ACCOUNT
// ============================================================================
// This class INHERITS from Account (it gets all Account's members and methods)
// ": public Account" means public inheritance - public members stay public

class SavingsAccount : public Account {
private:
    // Additional attribute specific to SavingsAccount
    double interestRate;

public:
    // CONSTRUCTOR
    // We must initialize the BASE CLASS (Account) using its constructor
    // Then initialize our additional member (interestRate)
    SavingsAccount(string name, double bal, double rate) 
        : Account(name, bal), interestRate(rate) {
        // Account(name, bal) calls the parent constructor
        // interestRate(rate) initializes our additional member
    }

    // OVERRIDE display()
    // This replaces the Account's display() with a custom version
    // We add the interest rate information
    void display() const override {
        // 'override' keyword is optional but good practice
        // It tells the compiler we're intentionally replacing a virtual function
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    // DESTRUCTOR
    // Automatically called when SavingsAccount is destroyed
    // The base class destructor (Account's) will be called automatically after
    ~SavingsAccount() {
        cout << "Savings account closed" << endl;
    }
};

// ============================================================================
// TASK 2: DERIVED CLASS - CHECKING ACCOUNT
// ============================================================================
// Similar to SavingsAccount but with a transaction fee

class CheckingAccount : public Account {
private:
    // Additional attribute specific to CheckingAccount
    double transactionFee;

public:
    // CONSTRUCTOR
    // Initializes base class and the transaction fee
    CheckingAccount(string name, double bal, double fee) 
        : Account(name, bal), transactionFee(fee) {
    }

    // OVERRIDE display()
    // Custom display that includes transaction fee
    void display() const override {
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction Fee: " << transactionFee << endl;
    }

    // DESTRUCTOR
    ~CheckingAccount() {
        cout << "Checking account closed" << endl;
    }
};

#endif // ACCOUNT_H

// ============================================================================
// SUMMARY OF KEY C++ CONCEPTS USED:
// ============================================================================
//
// 1. INHERITANCE
//    - SavingsAccount and CheckingAccount inherit from Account
//    - They get all Account's members and can add their own
//    - Uses "public" inheritance to maintain access levels
//
// 2. ENCAPSULATION
//    - private: Only accessible within the class
//    - protected: Accessible within class and derived classes
//    - public: Accessible from anywhere
//
// 3. POLYMORPHISM
//    - virtual functions allow derived classes to override behavior
//    - virtual destructor ensures proper cleanup of derived classes
//
// 4. OPERATOR OVERLOADING
//    - Defines custom behavior for operators (+, -, ==, <<, >>)
//    - Makes our class objects behave like built-in types
//    - Friend functions access private members for stream operators
//
// 5. CONST CORRECTNESS
//    - "const" after function means it doesn't modify the object
//    - "const&" parameters avoid copying and prevent modification
//
// 6. CONSTRUCTOR INITIALIZATION LISTS
//    - ": member(value)" syntax initializes members efficiently
//    - Required for calling base class constructors
//
// ============================================================================
