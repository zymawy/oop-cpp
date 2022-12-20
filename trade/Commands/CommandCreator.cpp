//
//  CommandCreator.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "CommandCreator.hpp"
#include "BaseCommand.hpp"
#include "HelpCommand.hpp"
#include "ProductCommand.hpp"
#include "MinimumCommand.hpp"
#include "MaximumCommand.hpp"
#include "AverageCommand.hpp"
#include "PredictCommand.hpp"
#include "TimeCommand.hpp"
#include "StepCommand.hpp"
#include "UserInputProcessor.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

CommandCreator::CommandCreator() {
    
    // lett's push our commands...
    commands.emplace_back(std::make_unique<HelpCommand>());
    commands.emplace_back(std::make_unique<ProductCommand>());
    commands.emplace_back(std::make_unique<MinimumCommand>());
    commands.emplace_back(std::make_unique<MaximumCommand>());
    commands.emplace_back(std::make_unique<AverageCommand>());
    commands.emplace_back(std::make_unique<PredictCommand>());
    commands.emplace_back(std::make_unique<TimeCommand>());
    commands.emplace_back(std::make_unique<StepCommand>());
}


void CommandCreator::runCommand(std::string commandName) {
 
    std::string oddCommand = commandName;
    // let's handle any command has differnct signiture ...
    if (checkCommandVaildate(oddCommand) != "") {
        oddCommand = checkCommandVaildate(oddCommand);
    }

    for (auto  const& command : commands) {
        if (command->getName() == oddCommand) {
            command->setOrderBook(orderBook);
            command->setCurrentTime(currentTime);
            command->setCommandName(commandName);
            command->run();
        }
     }
}

void CommandCreator::setOrderBook(OrderBook& mOrderBook) {
    orderBook = mOrderBook;
}


void CommandCreator::setCurrentTime(std::string mCurrentTime) {
    currentTime = mCurrentTime;
}


std::string CommandCreator::checkCommandVaildate(std::string command) {
    
     if((
               command.rfind("min", 0) == 0
               ||
               command.rfind("avg", 0) == 0
               ||
               command.rfind("help", 0) == 0
               ||
               command.rfind("max", 0) == 0) )
            {
                  
                  auto argments = UserInputProcessor::explode(command, ' ');
                  
                  return argments[0];
                  
              }  else return "";
}


bool CommandCreator::isVaildCommand(std::string command) {
    
    for (int i = 0; i < commands.size(); ++i) {
        if (
            commands[i]->getName() == command
            || checkCommandVaildate(command) != ""
            ) {
            return true;
        }
   }
    
    throw std::runtime_error(std::string("please provider a vaild command name type help for more inforamtion"));

    return false;
};


std::string CommandCreator::findCommand(std::string commadName, std::string type) {
  
    std::vector<std::string> prodcuts;
    
    std::map<std::string, std::string> mappedProducts;
    for(auto const& command : commands) {
        if(command->getName() == commadName) {
            if (type == "description") {
                return command->getDescription();
            }
        }
    }
    
    throw std::runtime_error(std::string("please provider currect input!"));
}
