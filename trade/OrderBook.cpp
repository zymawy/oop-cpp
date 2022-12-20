//
//  OrderBook.cpp
//  trade
//
//  Created by hamza ironside on 10/14/22.
//

#include "OrderBook.hpp"
#include "Reader.hpp"
#include <map>
#include "OrderBookEntry.hpp"
#include "UserInputProcessor.hpp"

OrderBook::OrderBook() {
    
}

OrderBook::OrderBook(std::string filename) {
    orders = Reader::read(filename);
}

std::vector<std::string> OrderBook::getKnownProducts() {
    std::vector<std::string> prodcuts;
    std::map<std::string, bool> mappedProducts;
    for(OrderBookEntry& order : orders) {
        mappedProducts[order.product] = true;
    }
    
    for(auto const& e : mappedProducts) {
        prodcuts.push_back(e.first);
    }
    
    return prodcuts;
    
}



std::string OrderBook::getAllKnownProducts() {
  
    std::string lists;
    std::vector<std::string> knownProducts = getKnownProducts();
    
    for (auto const& product : knownProducts) {
        // let's check, and avoid adding comma in first or last command name...
        std::string withComma = ", ";
        lists = lists.append(withComma + product);
     }
    
    return lists;
};


std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp) {
    std::vector<OrderBookEntry> foundOrders;
    
    for (OrderBookEntry& order : orders) {
        if (order.orderType == type && order.product == product && order.timestamp == timestamp) {
            foundOrders.push_back(order);
        }
    }
    
    return foundOrders;
};

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{

    double min = orders[0].price;

    for (OrderBookEntry& order : orders) {
        if (order.price < min) {
            min = order.price;
        }
    }
    return min;
}


double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    
    double max = orders[0].price;
    
    for (OrderBookEntry& order : orders) {
        if (order.price > max) {
            max = order.price;
        }
    }
    return max;
}


std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}



std::string OrderBook::getNextTime(std::string timestamp) {
    
    std::string nextTimestamp = "";
    for(OrderBookEntry& order : orders) {
        if (order.timestamp > timestamp) {
            nextTimestamp = order.timestamp;
        }
    }
    
    if (nextTimestamp == "") {
        nextTimestamp = orders[0].timestamp;
    }
    
    
    return nextTimestamp;
};


void OrderBook::insrtOrder(OrderBookEntry& order) {
    
    orders.push_back(order);
    
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}


std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp) {
    
    // ask
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);
    
    // bids
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::ask, product, timestamp);
    // salces
    std::vector<OrderBookEntry> sales;
    
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);
    
    for (OrderBookEntry& ask : asks) {
        
        for (OrderBookEntry& bid : bids) {
            if (bid.price >= ask.price) {
                
                OrderBookEntry sale{
                    ask.price,
                    0,
                    timestamp,
                    product,
                    OrderBookType::sale};
                
                // 1
                if (bid.amount == ask.amount) {
                    
                    sale.amount = ask.amount;
                    
                    sales.push_back(sale);
                    
                    bid.amount = 0;
                    
                    break;
                }
                
                // 2
                if (bid.amount > ask.amount) {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    
                    bid.amount = bid.amount - ask.amount;
                    
                    break;;
                }
                
                // 3
                if (bid.amount < ask.amount) {
                    sale.amount = bid.amount;
                    
                    sales.push_back(sale);
                    
                    ask.amount = ask.amount - bid.amount;
                    
                    bid.amount = 0;
                    
                    continue;
                }
                
            }
        } // second first
            
    } // first for
    
    return sales;
}


bool OrderBook::isProductExists(std::string product) {
    
    std::vector<std::string> knownProducts = getKnownProducts();
    bool productExists = false;
    
    for(auto const& kProduct : knownProducts) {
        if (kProduct == product) {
            productExists = true;
        };
    }
    
    return productExists;
    
}

double OrderBook::getLowPriceFor(std::string product, std::string type, std::string timestamp) {
    
    std::vector<OrderBookEntry> foundOrders = getOrders(OrderBookEntry::convertType(type), product, timestamp);

    return OrderBook::getLowPrice(foundOrders);
}

double OrderBook::getHighPriceFor(std::string product, std::string type, std::string timestamp) {
    
    std::vector<OrderBookEntry> foundOrders = getOrders(OrderBookEntry::convertType(type), product, timestamp);

    return OrderBook::getHighPrice(foundOrders);
}
