//
//  Wallet.hpp
//  trade
//
//  Created by hamza ironside on 10/15/22.
//

#ifndef Wallet_hpp
#define Wallet_hpp
#include <string>
#include <map>

#include <stdio.h>
#include "OrderBookEntry.hpp"
class Wallet {
public:
    Wallet();
    void insertCurrency(std::string type, double amount);
    bool removeCurrency(std::string type, double amount);
    bool hasCurrency(std::string type, double amount);
    bool canOrder(OrderBookEntry order);
    std::string toString();
    
private:
    std::map<std::string, double> currencies;
};
#endif /* Wallet_hpp */
