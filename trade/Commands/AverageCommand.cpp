//
//  AverageCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "AverageCommand.hpp"
#include "UserInputProcessor.hpp"
#include <numeric>

void AverageCommand::run() {

    auto arguments = UserInputProcessor::explode(commandName, ' ');

    if (arguments.size() < 4) {
        throw std::runtime_error(
                std::string("arguments missing product ex..[BTC/ETH], type ex..[ask,bid], timestamp ex..[10]"));
    }


    std::string product = arguments[1];
    std::string type = arguments[2];
    std::string timestamp = arguments[3];

    if ((type != "bid" && type != "ask")) {

        throw std::runtime_error(
                std::string("argument missing/invalid type, it should be ether ask or bid you entered [" + type + "]")
        );
    }


    if (!orderBook.isProductExists(product)) {

        throw std::runtime_error(std::string("not supported product, please type `prod` for known product"));
    }

    std::string previousTime = orderBook.getPreviousTime(currentTime);

    std::vector <OrderBookEntry> entries = orderBook.getOrders(OrderBookEntry::convertType(type),
                                                               product, previousTime);

    double average = 0, totalBase = 0, totalProduct = 0;

    for (auto &e: entries) {
        totalBase += e.price * e.amount;
        totalProduct += e.amount;
    }

    average = totalBase / totalProduct;

    UserInputProcessor::info(
            "The average " + product +
            " " + type +
            " price over the last " +
            timestamp +
            " was " +
            std::to_string(average),
            icon
    );

}
