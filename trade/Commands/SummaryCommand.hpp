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


class SummaryCommand: public BaseCommand {
public:
    SummaryCommand(): BaseCommand(9, "summary", "a summary of the higitest/loweset products.. ", "📝") {}
    
private:
    virtual void init();
    virtual void run();
};


#endif /* HighestAndLowestCommand_hpp */
