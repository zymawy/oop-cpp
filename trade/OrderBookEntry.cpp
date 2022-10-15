//
//  OrderBookEntry.cpp
//  trade
//
//  Created by hamza ironside on 10/12/22.
//

#include "OrderBookEntry.hpp"


OrderBookEntry::OrderBookEntry(
               double price,
               double amount,
               std::string timestamp,
               std::string product,
               OrderBookType orderType)
{
    this->price = price;
    this->amount = amount;
    this->timestamp = timestamp;
    this->product = product;
    this->orderType = orderType;
}


OrderBookType OrderBookEntry::convertType(std::string type) {
    
    if (type == "ask") {
        return OrderBookType::ask;
    } else if (type == "bid") {
        return OrderBookType::bid;
    }
    
    return OrderBookType::unkown;
}



bool OrderBookEntry::compareByTimestamp(OrderBookEntry& orderOne, OrderBookEntry& orderTow) {
    
    return orderOne.timestamp < orderTow.timestamp;
}


bool OrderBookEntry::compareByPriceAsc(OrderBookEntry& orderOne, OrderBookEntry& orderTow)
{
return orderOne.price < orderTow.price;
}
bool OrderBookEntry::compareByPriceDesc(OrderBookEntry& orderOne, OrderBookEntry& orderTow)
{
return orderOne.price > orderTow.price;
}
