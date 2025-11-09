#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {

    protected:
    std::string ownerName;
    double balance;
    public:

    Account(std::string name, double balance): ownerName(name), balance(balance) {}
    double getBalance() {
        return balance;
    };
    virtual void display(){
        std::cout<< "Owner: " << ownerName<< std::endl;
        std::cout<< "Balance: " << balance << std::endl;
    };

    virtual ~Account(){
        std::cout << "Account destroyed for " << ownerName << std::endl;
    };

    Account operator+(const Account& other){
       return Account(this->ownerName, this->balance + other.balance);
    };

     Account operator-(const Account& other){
       return Account(this->ownerName, this->balance -other.balance);
    };
    bool operator==(const Account& other){
        return this->balance == other.balance;
    };

    friend std::ostream& operator<<(std::ostream& out, const Account& acc) {
        out << "Owner: " << acc.ownerName << std::endl;
        out << "Balance: " << acc.balance << std::endl;
        return out;
    };
    friend std::istream& operator>>(std::istream& in, Account& acc){
        in >> acc.ownerName >> acc.balance;
        return in;
    };
   


    



};



class SavingsAccount : public Account {

    private:
    double interestRate;
    public:
    SavingsAccount(std::string name, double balance, double rate): Account(name, balance), interestRate(rate){}
    void display() override {
        Account::display();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;

    };


};

class CheckingAccount : public Account {
    private:
    double transactionFee;
    public:
    CheckingAccount(std::string name, double balance, double fee): Account(name, balance), transactionFee(fee){}

    void display() override {
        Account::display();
        std::cout << "Transaction Fee: " << transactionFee << std::endl;
    };

};






#endif // ACCOUNT_H