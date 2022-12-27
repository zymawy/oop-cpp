//
//  MaximumCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "MaximumCommand.hpp"
#include "UserInputProcessor.hpp"

void MaximumCommand::run() {
    auto arguments = UserInputProcessor::explode(commandName, ' ');

    if (arguments.size() < 3) {
        throw std::runtime_error(std::string("arguments missing product ex..[BTC/ETH], type ex..[ask,bid]"));
    }


    std::string product = arguments[1];
    std::string type = arguments[2];


    if ((type != "bid" && type != "ask")) {

        throw std::runtime_error(
                std::string("argument missing/invalid type, it should be ether ask or bid you entered [" + type + "]"));
    }


    if (!orderBook.isProductExists(product)) {

        throw std::runtime_error(std::string("not supported product, please type `prod` for known product"));
    }

    std::vector <OrderBookEntry> entries = orderBook.getOrders(OrderBookEntry::convertType(type), product, currentTime);

    double maxPrice = orderBook.getHighPrice(entries, product, OrderBookEntry::convertType(type));

    UserInputProcessor::info("The max ask for " + product + " is " + std::to_string(maxPrice), icon);

}