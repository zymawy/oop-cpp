//
//  MaximumCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once

#ifndef MaximumCommand_hpp
#define MaximumCommand_hpp
#include <stdio.h>
#include "BaseCommand.hpp"

class MaximumCommand: public BaseCommand {
public:
    MaximumCommand(): BaseCommand(4, "max", " find maximum bid or ask for product in current time step", "📈") {}
    
private:
    virtual void init();
    virtual void run();
};

#endif /* MaximumCommand_hpp */
