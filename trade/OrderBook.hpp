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

class OrderBook {
    
public:
OrderBook();
/** construct, reading a csv data file */
OrderBook(std::string filename);
    void insrtOrder(OrderBookEntry& order);
    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);
/** return vector of all know products in the dataset*/
std::vector<std::string> getKnownProducts();
std::string getAllKnownProducts();
bool isProductExists(std::string product);
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> getOrders(OrderBookType type,
std::string product,
std::string timestamp);
/** return the price of the highest bid in the sent set */
static double getHighPrice(std::vector<OrderBookEntry>& orders);
/** return the price of the lowest bid in the sent set */
static double getLowPrice(std::vector<OrderBookEntry>& orders);
double getLowPriceFor(std::string product, std::string type, std::string = "2020/03/17 17:01:24.884492");
double getHighPriceFor(std::string product, std::string type, std::string = "2020/03/17 17:01:24.884492");
std::string getEarliestTime();
std::string getNextTime(std::string timestamp);
private:
std::vector<OrderBookEntry> orders;
};
#endif /* OrderBook_hpp */
