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

class AverageCommand : public BaseCommand {
public:
//    This is the constructor for the AverageCommand class. It is calling the constructor for the BaseCommand class.
    AverageCommand() : BaseCommand(5, "avg",
                                   "predict max or min ask or bid for the sent product for the next time step",
                                   "🗺️") {}

private:
//    A virtual function that is being overridden.
    virtual void run();
};

#endif /* AverageCommand_hpp */
