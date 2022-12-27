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


class PreviousStepCommand: public BaseCommand {
public:
    PreviousStepCommand(): BaseCommand(10, "pre-step", "move to previous time step", "⏭️") {}
    
private:
    virtual void init();
    virtual void run();
};

#endif /* PreviousStepCommand_hpp */
