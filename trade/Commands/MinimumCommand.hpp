//
//  MinimumCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once

#ifndef MinimumCommand_hpp
#define MinimumCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"

class MinimumCommand : public BaseCommand {
public:
//    This is the constructor for the MinimumCommand class. It is calling the constructor for the BaseCommand class.
    MinimumCommand() : BaseCommand(3, "min", "find minimum bid or ask for product in current time step", "📉") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};

#endif /* MinimumCommand_hpp */
