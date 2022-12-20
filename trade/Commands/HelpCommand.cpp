//
//  HelpCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "HelpCommand.hpp"
#include "UserInputProcessor.hpp"
#include "CommandCreator.hpp"

void HelpCommand::run() {
    auto argments = UserInputProcessor::explode(commandName, ' ');
  
    if (argments.size() == 1) {
        UserInputProcessor::print("📊 The available commands are :");
        for (auto & command: commandLists) {
            UserInputProcessor::print(command);
        }
    } else if (argments.size() == 2) {
        std::vector<std::string> ans = {
            "product", "min", "max", "avg", "predict", "time", "step"};

        std::string cmd = argments[1];
        
        if (! count(ans.begin(), ans.end(), cmd)) {
            
            throw std::runtime_error(std::string("not supported command, please type `help` for supported commands"));
        }
        
        std::map<std::string, std::string> availableCommands;

        availableCommands.insert(std::make_pair("product", "list available products"));
        availableCommands.insert(std::make_pair("min", " find minimum bid or ask for product in current time step"));
        availableCommands.insert(std::make_pair("max", "find maximum bid or ask for product in current time step"));
        availableCommands.insert(std::make_pair("avg", "compute average ask or bid for the sent product over the sent number of time steps."));
        availableCommands.insert(std::make_pair("predict", "Purpose: predict max or min ask or bid for the sent product for the next time step"));
        availableCommands.insert(std::make_pair("time", "state current time in dataset, i.e. which timeframe are we looking at"));
        availableCommands.insert(std::make_pair("step", "move to next time step"));

        for(auto const& e : availableCommands) {
            if (e.first == cmd) {
                UserInputProcessor::print(e.second);
            }
        }

        
    } else {
        
        throw std::runtime_error(std::string("please provider currect input!"));
    }

}


void HelpCommand::init() {
}
