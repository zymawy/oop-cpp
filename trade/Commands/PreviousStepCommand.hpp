//
//  PreviousStepCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/26/22.
//
#pragma once
#ifndef PreviousStepCommand_hpp
#define PreviousStepCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"


class PreviousStepCommand : public BaseCommand {
public:
//    This is the constructor for the PreviousStepCommand class. It is calling the constructor for the BaseCommand class.
    PreviousStepCommand() : BaseCommand(10, "pre-step", "move to previous time step", "⏭️") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};

#endif /* PreviousStepCommand_hpp */
