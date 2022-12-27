//
//  HighestAndLowestCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/23/22.
//
#pragma once

#ifndef HighestAndLowestCommand_hpp
#define HighestAndLowestCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"


class SummaryCommand : public BaseCommand {
public:
    //    This is the constructor for the SummaryCommand class. It is calling the constructor for the BaseCommand class.
    SummaryCommand() : BaseCommand(9, "summary", "a summary of the highest/lowest products.. ", "📝") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};


#endif /* HighestAndLowestCommand_hpp */
