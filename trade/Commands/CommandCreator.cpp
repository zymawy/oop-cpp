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
#include "SummaryCommand.hpp"
#include "PreviousStepCommand.hpp"
#include "UserInputProcessor.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

CommandCreator::CommandCreator() {

    /**
     Let's push our commands. in order to use each individual command in its own command class, and let's
     It is our Advisorbot that determines and routes the user to the appropriate command class that serves the user's request.
     */
    commands.emplace_back(std::make_unique<HelpCommand>());
    commands.emplace_back(std::make_unique<ProductCommand>());
    commands.emplace_back(std::make_unique<MinimumCommand>());
    commands.emplace_back(std::make_unique<MaximumCommand>());
    commands.emplace_back(std::make_unique<AverageCommand>());
    commands.emplace_back(std::make_unique<PredictCommand>());
    commands.emplace_back(std::make_unique<TimeCommand>());
    commands.emplace_back(std::make_unique<StepCommand>());
    commands.emplace_back(std::make_unique<PreviousStepCommand>()); // own command
    commands.emplace_back(std::make_unique<SummaryCommand>()); // own command
}


void CommandCreator::runCommand(std::string commandName) {

    std::string oddCommand = commandName;

    // let's handle any command has different signature ...
    if (checkCommandValidate(oddCommand) != "") {
        // validate our commands and make sure we
        // support that command... 
        oddCommand = checkCommandValidate(oddCommand);
    }

    // let's find the desire command
    // and get going and run it!
    for (auto const &command: commands) {
        if (command->getName() == oddCommand) {
            command->setOrderBook(orderBook);
            command->setCurrentTime(currentTime);
            command->setCommandName(commandName);
            command->run();
        }
    }
}

void CommandCreator::setOrderBook(OrderBook &mOrderBook) {
    orderBook = mOrderBook;
}


void CommandCreator::setCurrentTime(std::string mCurrentTime) {
    currentTime = mCurrentTime;
}


std::string CommandCreator::checkCommandValidate(std::string command) {

    if ((
            command.rfind("min", 0) == 0
            ||
            command.rfind("avg", 0) == 0
            ||
            command.rfind("help", 0) == 0
            ||
            command.rfind("max", 0) == 0
            ||
            command.rfind("predict", 0) == 0
            ||
            command.rfind("high", 0) == 0)
            ) {

        auto argments = UserInputProcessor::explode(command, ' ');

        return argments[0];

    } else return "";
}


bool CommandCreator::isValidCommand(std::string command) {

    for (int i = 0; i < commands.size(); ++i) {
        if (
                commands[i]->getName() == command
                || checkCommandValidate(command) != ""
                ) {
            return true;
        }
    }

    UserInputProcessor::debug(checkCommandValidate(command));

    throw std::runtime_error(std::string("please provider a valid command name type help for more information"));

    return false;
};


std::string CommandCreator::findCommand(std::string commadName, std::string type) {

    std::map <std::string, std::string> mappedProducts;
    for (auto const &command: commands) {
        if (command->getName() == commadName) {
            if (type == "description") {
                return command->getDescription();
            }
        }
    }

    throw std::runtime_error(std::string("please provider current input!"));
}
