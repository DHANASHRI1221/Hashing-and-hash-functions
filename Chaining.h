#ifndef CHAINING_H
#define CHAINING_H

#include "BaseClass.h"
#include <iostream>
#include <vector>


class Chaining : public BaseClass {
public:
    Chaining();

   
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;

    
private:
   int sizev;
   int sort1(std::vector<int> &vect,int l,int k );
    
  void sort2(std::vector<int> &vect,int l,int k );

     
   
    
    // Other data members and functions specific to Chaining
};

#endif // CHAINING_H
