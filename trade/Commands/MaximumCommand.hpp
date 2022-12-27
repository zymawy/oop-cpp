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

class MaximumCommand : public BaseCommand {
public:
//    This is the constructor for the MaximumCommand class. It is calling the constructor for the BaseCommand class.
    MaximumCommand() : BaseCommand(4, "max", " find maximum bid or ask for product in current time step", "📈") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};

#endif /* MaximumCommand_hpp */
