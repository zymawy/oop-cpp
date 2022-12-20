//
//  ProductCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "ProductCommand.hpp"
#include "UserInputProcessor.hpp"
#include "vector"

void ProductCommand::run() {
    std::vector<std::string> argments = UserInputProcessor::explode(orderBook.getAllKnownProducts().erase(0, 2), ',');
    
    for (auto & argment: argments) {
        UserInputProcessor::print(argment);
    }
}

void ProductCommand::init() {
}
