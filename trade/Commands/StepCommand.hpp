//
//  StepCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once
#ifndef StepCommand_hpp
#define StepCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"

class StepCommand : public BaseCommand {
public:
//    This is the constructor for the class. It is calling the constructor for the base class.
    StepCommand() : BaseCommand(8, "step", "move to next time step", "⏭️") {}

private:
//    This is a virtual function. It is a function that is declared in a base class and is then redefined by a derived class.
    virtual void run();
};

#endif /* StepCommand_hpp */
