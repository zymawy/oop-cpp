//
//  HelpCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once
#ifndef HelpCommand_hpp
#define HelpCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"
#include <vector>

class HelpCommand: public BaseCommand {
public:
    HelpCommand(): BaseCommand(1, "help", "output help for the specified command") {};
    std::vector<std::string> commandLists = {
        "💉 help", "🪡 help <cmd>", "👨🏾‍💻 product", "📉 min", "📈 max", "🗺️ avg", "🪄 predict", "⏳ time", "⏭️ step"};
    virtual void init();
    virtual void run();
private:
    std::string getCommandsList();
     
};

#endif /* HelpCommand_hpp */
