//
//  TimeCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once
#ifndef TimeCommand_hpp
#define TimeCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"

class TimeCommand: public BaseCommand {
public:
    TimeCommand(): BaseCommand(7, "time", "state current time in dataset, i.e. which timeframe are we looking at") {}
    
private:
    virtual void init();
    virtual void run();
};
#endif /* TimeCommand_hpp */
