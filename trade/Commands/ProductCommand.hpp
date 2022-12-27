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

class ProductCommand : public BaseCommand {
public:
//    It's calling the constructor of the base class.
    ProductCommand() : BaseCommand(2, "prod", "list available products", "👨🏾‍💻") {}

private:
//    It's a virtual function.
    virtual void run();
};

#endif /* ProductCommand_hpp */
