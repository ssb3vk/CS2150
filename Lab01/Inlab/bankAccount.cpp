//Sidhardh Burre, ssb3vk@virginia.edu, 2/11/2021, bankAccount.cpp

#include <iostream>
using namespace std;

#include "bankAccount.h"

//Constructors and destructors-no return types

//default constructor that will be called when a program creates a bankAccount object. This constructor should set the bankAccount balance to $0.00
bankAccount::bankAccount() {
  balance = 0.00;
}

//constructor that will be called when a program creates a bankAccount object with an initial balance
bankAccount::bankAccount(double amount){
  balance = amount;
}

//empty implementation, destructor
bankAccount::~bankAccount(){}

double bankAccount::withdraw(double amount) {//protect against negative withdraws?, nvm harness addresses negatives 
  if (balance - amount < 0){//do we need this->balance? 
    return balance;
  } else {
    balance = balance - amount;
    return balance;
  }

}

double bankAccount::deposit(double amount) {
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance() {
  return balance;
}

