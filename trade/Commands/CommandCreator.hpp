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
    inline static std::map<std::string, std::pair<std::string, std::string>> availableShortNameCommands = {
        {"help", {"list all available commands", "👨🏾‍💻"}},
        {"help <CMD>", {"output help for the specified command", "⁉️"}},
        {"prod", {"list available products", "👨🏾‍💻"}},
        {"min", {"find minimum bid or ask for product in current time step", "📉"}},
        {"max", {"find maximum bid or ask for product in current time step", "📈"}},
        {"avg", {"compute average ask or bid for the sent product over the sent number of time steps.", "🗺️"}},
        {"predict", {"predict max or min ask or bid for the sent product for the next time step", "🪄"}},
        {"time", {"state current time in dataset, i.e. which timeframe are we looking at", "⏳"}},
        {"step", {"move to next time step", "⏭️"}},
        {"pre-step", {"move to previous time step..🆕✨", "⏮️"}},
        {"summary", {"a summary of the higitest/loweset products..🆕✨", "📝"}}
        
    };
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
