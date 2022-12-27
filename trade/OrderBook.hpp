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
//    A constructor.
    OrderBook();

    OrderBook(const std::string &filename);

//    This function is used to retrieve a subset of orders based on specified filter criteria.
    std::vector <OrderBookEntry> getOrders(const OrderBookType &type,
                                           const std::string &product,
                                           const std::string &timestamp);

//    This function is used to get the highest price in a given set of orders.
    static double
    getHighPrice(const std::vector <OrderBookEntry> &orders, const std::string &product, const OrderBookType &type);

//    This function is used to get the lowest price in a given set of orders.
    static double
    getLowPrice(const std::vector <OrderBookEntry> &orders, const std::string &product, const OrderBookType &type);

//    This function is used to insert an order into the order book.
    void insertOrder(const OrderBookEntry &order);

//    This function is used to match asks to bids and create sales.
    std::vector <OrderBookEntry> matchAsksToBids(const std::string &product, const std::string &timestamp);

//    This is a map of vectors of OrderBookEntry objects. The key is a string, which is the timestamp of the order. The value is a vector of OrderBookEntry objects.
    std::map <std::string, std::vector<OrderBookEntry>> orders;

//    A set of products that are seen in the order book.
    std::unordered_set <std::string> products;

//    This function is used to get the next timestamp in the order book.
    std::string getNextTime(const std::string &timestamp);

//    This function is used to get the previous timestamp in the order book.
    std::string getPreviousTime(const std::string &timestamp);

//    This function is used to get the earliest timestamp in the order book.
    std::string getEarliestTime();

//    This function is used to get the set of products that are seen in the order book.
    std::unordered_set <std::string> getKnownProducts();

//    This function is used to check if a product exists in the order book.
    bool isProductExists(std::string product);
};

#endif /* OrderBook_hpp */
