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

class MinimumCommand: public BaseCommand {
public:
    MinimumCommand(): BaseCommand(3, "min", "find minimum bid or ask for product in current time step", "📉") {}
    
private:
    virtual void init();
    virtual void run();
};

#endif /* MinimumCommand_hpp */
