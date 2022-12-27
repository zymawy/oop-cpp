//
//  OrderBook.hpp
//  trade
//
//  Created by hamza ironside on 10/14/22.
//

#pragma once
#ifndef OrderBook_hpp
#define OrderBook_hpp
#include "Reader.hpp"
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <unordered_set>

class OrderBook {
    
public:
    /** Constructor */
    OrderBook();
    OrderBook(const std::string& filename);

    /** Retrieve a subset of orders based on specified filter criteria */
    std::vector<OrderBookEntry> getOrders(const OrderBookType& type,
                                          const std::string& product,
                                          const std::string& timestamp);
    /** Get the highest price in a given set of orders */
    static double getHighPrice(const std::vector<OrderBookEntry>& orders, const std::string& product, const OrderBookType& type);
    /** Get the lowest price in a given set of orders */
    static double getLowPrice(const std::vector<OrderBookEntry>& orders, const std::string& product, const OrderBookType& type);
    /** Insert an order into the order book */
    void insertOrder(const OrderBookEntry& order);
    /** Run the matching engine to match asks to bids and create sales  */
    std::vector<OrderBookEntry> matchAsksToBids(const std::string& product, const std::string& timestamp);
    /** Contains the actual order book as a map */
    std::map<std::string, std::vector<OrderBookEntry>> orders;
    /** Contains the products identified in the order book */
    std::unordered_set<std::string> products;
    /** Get the next timeframe in the order book */
    std::string getNextTime(const std::string& timestamp);
    /** Get the previous timeframe in the order book */
    std::string getPreviousTime(const std::string& timestamp);
    std::string getEarliestTime();
    /** Get a list of products seen in the order book */
    std::unordered_set<std::string> getKnownProducts();
    bool isProductExists(std::string product);
};
#endif /* OrderBook_hpp */
