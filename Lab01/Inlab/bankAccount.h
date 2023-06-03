//Sidhardh Burre, ssb3vk@virginia.edu, 2/11/2021, bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {//currently 0 implementations despite the instructions saying so
  //gonna test and implement if needed
 public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();

 private:
  double balance;

};

#endif
