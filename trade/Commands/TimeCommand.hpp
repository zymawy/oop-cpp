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

class TimeCommand : public BaseCommand {
public:
//    This is a constructor for the TimeCommand class. It is calling the BaseCommand constructor with the arguments 7, "time", "state current time in dataset, i.e. which timeframe are we looking at", "⏳".
    TimeCommand() : BaseCommand(7, "time", "state current time in dataset, i.e. which timeframe are we looking at",
                                "⏳") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};

#endif /* TimeCommand_hpp */
