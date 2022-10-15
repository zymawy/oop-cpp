//
//  Wallet.cpp
//  trade
//
//  Created by hamza ironside on 10/15/22.
//

#include "Wallet.hpp"
#include "Reader.hpp"

Wallet::Wallet() {
    
};

void Wallet::insertCurrency(std::string type, double amount) {
    
    double balance;
    if (amount < 0) {
        throw std::exception{};
    }
    
    if (currencies.count(type) == 0) {
        balance = 0;
    } else {
        balance = currencies[type];
    }
    
    balance += amount;
    
    currencies[type] = balance;
}
bool Wallet::hasCurrency(std::string type, double amount) {
    
    if (currencies.count(type) == 0)
        return false;
    else
        return currencies[type] <= amount;
};

std::string Wallet::toString() {
    
    std::string s;
    for (std::pair<std::string, double> pair : currencies) {
        std::string currency = pair.first;
        double amount = pair.second;
        
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return "ON Link";
}



bool Wallet::removeCurrency(std::string type, double amount) {
    if (amount < 0) {
        return false;
    }
    
    if (currencies.count(type) == 0) {
        return false;
    } else {
        if (hasCurrency(type,amount)) {
            currencies[type] -= amount;
            return true;
        } else {
            return false;
        }
    }
}



bool Wallet::canOrder(OrderBookEntry order) {
    std::vector<std::string> currs = Reader::tokenise(order.product, '/');
    
    if (order.orderType == OrderBookType::ask) {
        double amount = order.amount;
        std::string currency = currs[0];
        return hasCurrency(currency, amount);
    }
    
    if (order.orderType == OrderBookType::bid) {
        double amount = order.amount * order.price;
        std::string currency = currs[1];
        return hasCurrency(currency, amount);
    }
    
    return false;
};
