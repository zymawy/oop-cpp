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
#include <string>

OrderBook::OrderBook() {}


OrderBook::OrderBook(const std::string &filename) {
    UserInputProcessor::print("Loading data set tight...");
    Reader reader{};

    orders = reader.read(filename);
    products = getKnownProducts();
}


std::unordered_set <std::string> OrderBook::getKnownProducts() {
    std::unordered_set <std::string> products;
    for (auto const &[timestamp, orderVec]: orders) {
        for (OrderBookEntry order: orderVec) {
            products.insert(order.product);
        }
    }
    return products;
}


std::vector <OrderBookEntry> OrderBook::getOrders(const OrderBookType &type,
                                                  const std::string &product,
                                                  const std::string &timestamp) {
    std::vector <OrderBookEntry> matchedOrders{};
    if (orders.find(timestamp) != orders.end()) {
        for (const OrderBookEntry &order: orders.at(timestamp)) {
            if (order.orderType == type &&
                order.product == product) {
                matchedOrders.push_back(order);
            }
        }
    }
    return matchedOrders;
}


double OrderBook::getLowPrice(const std::vector <OrderBookEntry> &orders, const std::string &product,
                              const OrderBookType &type) {
    double min{orders[0].price};
    for (const OrderBookEntry &order: orders) {
        if (order.price < min && order.product == product && order.orderType == type) {
            min = order.price;
        }
    }
    return min;
}


double OrderBook::getHighPrice(const std::vector <OrderBookEntry> &orders, const std::string &product,
                               const OrderBookType &type) {
    double max{orders[0].price};

    for (const OrderBookEntry &order: orders) {
        if (order.price > max && order.product == product && order.orderType == type) {
            max = order.price;
        }
    }
    return max;
}


std::string OrderBook::getEarliestTime() {
    return orders.begin()->first;
}


std::string OrderBook::getNextTime(const std::string &timestamp) {
    if (orders.find(timestamp) != orders.end()) {
        return std::next(orders.find(timestamp), 1)->first;
    } else {
        return orders.begin()->first;
    }
}


void OrderBook::insertOrder(const OrderBookEntry &order) {
    orders.at(order.timestamp)
            .push_back(order);
}


std::vector <OrderBookEntry> OrderBook::matchAsksToBids(const std::string &product, const std::string &timestamp) {

    // ask
    std::vector <OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);

    // bids
    std::vector <OrderBookEntry> bids = getOrders(OrderBookType::ask, product, timestamp);
    // salces
    std::vector <OrderBookEntry> sales;

    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);

    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    for (OrderBookEntry &ask: asks) {

        for (OrderBookEntry &bid: bids) {
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

    bool productExists = false;

    for (auto const &kProduct: products) {
        if (kProduct == product) {
            productExists = true;
        };
    }

    return productExists;

}

std::string OrderBook::getPreviousTime(const std::string &timestamp) {
    if (orders.find(timestamp) != orders.begin()) {
        return std::prev(orders.find(timestamp), 1)->first;
    } else {
        return orders.begin()->first;
    }
}
