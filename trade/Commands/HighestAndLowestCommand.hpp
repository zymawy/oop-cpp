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


class HighestAndLowestCommand: public BaseCommand {
public:
    HighestAndLowestCommand(): BaseCommand(9, "high", "get the higitest products.. ") {}
    
private:
    virtual void init();
    virtual void run();
};


#endif /* HighestAndLowestCommand_hpp */
