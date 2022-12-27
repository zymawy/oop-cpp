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

class StepCommand: public BaseCommand {
public:
    StepCommand(): BaseCommand(8, "step", "move to next time step", "⏭️") {}
    
private:
    virtual void init();
    virtual void run();
};
#endif /* StepCommand_hpp */
