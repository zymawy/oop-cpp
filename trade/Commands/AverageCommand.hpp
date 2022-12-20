//
//  AverageCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once

#ifndef AverageCommand_hpp
#define AverageCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"

class AverageCommand: public BaseCommand {
public:
    AverageCommand(): BaseCommand(5, "avg", "The average ETH/BTC ask price over the last 10 timesteps was 1.0") {}
    
private:
    virtual void init();
    virtual void run();
};

#endif /* AverageCommand_hpp */
