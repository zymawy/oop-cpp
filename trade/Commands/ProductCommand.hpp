//
//  ProductCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once

#ifndef ProductCommand_hpp
#define ProductCommand_hpp

#include <stdio.h>

#include "BaseCommand.hpp"

class ProductCommand: public BaseCommand {
public:
    ProductCommand() : BaseCommand(2, "prod", "list available products") {}
    
private:
    virtual void init();
    virtual void run();
};

#endif /* ProductCommand_hpp */
