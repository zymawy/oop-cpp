//
//  OrderBookEntry.hpp
//  trade
//
//  Created by hamza ironside on 10/12/22.
//
#pragma once
#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <stdio.h>
#include <string>
enum class OrderBookType{bid, ask, unkown, sale};

class OrderBookEntry {
public:
    OrderBookEntry(
                   double price,
                   double amount,
                   std::string timestamp,
                   std::string product,
                   OrderBookType orderType,
                   std::string username = "system"
                   );
    
    static OrderBookType convertType(std::string type);
    static bool compareByTimestamp(OrderBookEntry& orderOne, OrderBookEntry& orderTwo);
    static bool compareByPriceAsc(OrderBookEntry& orderOne, OrderBookEntry& orderTwo);
    static bool compareByPriceDesc(OrderBookEntry& orderOne, OrderBookEntry& orderTwo);
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    std::string username;
    
};
#endif /* OrderBookEntry_hpp */
