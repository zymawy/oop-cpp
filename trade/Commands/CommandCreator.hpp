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
//    The constructor for the class.
    CommandCreator();

//    A member variable of the class.
    OrderBook orderBook;
//    A member variable of the class.
    std::string currentTime;
//    This is a map of all the commands that are available in the program.
    inline static std::map <std::string, std::pair<std::string, std::string>> availableShortNameCommands = {
            {"help",       {"list all available commands",                                                         "👨🏾‍💻"}},
            {"help <CMD>", {"output help for the specified command",                                               "⁉️"}},
            {"prod",       {"list available products",                                                             "👨🏾‍💻"}},
            {"min",        {"find minimum bid or ask for product in current time step",                            "📉"}},
            {"max",        {"find maximum bid or ask for product in current time step",                            "📈"}},
            {"avg",        {"compute average ask or bid for the sent product over the sent number of time steps.", "🗺️"}},
            {"predict",    {"predict max or min ask or bid for the sent product for the next time step",           "🪄"}},
            {"time",       {"state current time in dataset, i.e. which timeframe are we looking at",               "⏳"}},
            {"step",       {"move to next time step",                                                              "⏭️"}},
            {"pre-step",   {"move to previous time step..🆕✨",                                                     "⏮️"}},
            {"summary",    {"a summary of the highest/lowest products..🆕✨",                                       "📝"}}

    };

//    Setting the orderBook variable to the orderBook that is passed in.
    void setOrderBook(OrderBook &orderBook);

//    Setting the currentTime variable to the currentTime that is passed in.
    void setCurrentTime(std::string currentTime);

//    This function is used to find the command that is passed in.
    std::string findCommand(std::string commandName, std::string type);

//    This function is used to run the command that is passed in.
    void runCommand(std::string commandName);

//    This function is used to check if the command that is passed in is a valid command.
    bool isValidCommand(std::string command);

//    This function is used to check if the command that is passed in is a valid command.
    std::string checkCommandValidate(std::string command);

//    This is a vector of unique pointers to the BaseCommand class.
    std::vector <std::unique_ptr<BaseCommand>> commands;
};

#endif /* CommandCreator_hpp */
