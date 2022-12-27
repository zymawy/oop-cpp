//
//  BaseCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "BaseCommand.hpp"

void BaseCommand::run() {}

void BaseCommand::setOrderBook(OrderBook &mOrderBook) {
    orderBook = mOrderBook;
}


void BaseCommand::setCurrentTime(std::string time) {
    currentTime = time;
}


void BaseCommand::setCommandName(std::string name) {
    commandName = name;
}
