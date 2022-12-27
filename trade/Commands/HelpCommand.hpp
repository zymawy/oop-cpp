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

class HelpCommand : public BaseCommand {
public:
//    This is the constructor for the HelpCommand class. It is calling the constructor for the BaseCommand class.
    HelpCommand() : BaseCommand(1, "help", "output help for the specified command", "🙋🏾‍♂️") {};

//    This is a virtual function that is being used to override the run function in the BaseCommand class.
    virtual void run();
};

#endif /* HelpCommand_hpp */
