//
//  CommandCreator.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once

#ifndef CommandCreator_hpp
#define CommandCreator_hpp

#include <stdio.h>
#include <vector>
#include "BaseCommand.hpp"
#include "OrderBook.hpp"
#include <map>

class CommandCreator {
public:
    CommandCreator();
    OrderBook orderBook;
    std::string currentTime;
    void setOrderBook(OrderBook& orderBook);
    void setCurrentTime(std::string currentTime);
    std::string findCommand(std::string commadName, std::string type);
    void runCommand(std::string commandName);
    bool isVaildCommand(std::string command);
    std::string checkCommandVaildate(std::string command);
    std::vector<std::unique_ptr<BaseCommand>> commands;
private:

protected:
};

#endif /* CommandCreator_hpp */
