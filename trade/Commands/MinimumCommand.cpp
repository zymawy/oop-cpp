//
//  MinimumCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "MinimumCommand.hpp"
#include "UserInputProcessor.hpp"

void MinimumCommand::run() {
    
    auto argments = UserInputProcessor::explode(commandName, ' ');
    
    
    if (argments.size() < 3) {
        throw std::runtime_error(std::string("arguments missing product ex..[BTC/ETH], type ex..[ask,bid]"));
    }
    
    
    std::string product =argments[1];
    std::string type =argments[2];
    
    
    if ((type != "bid" && type != "ask")) {

            throw std::runtime_error(std::string("argument missing/invalid type, it should be ether ask or bid you entered [" + type + "]"));
    }
    
    if (! orderBook.isProductExists(product)) {
        
        throw std::runtime_error(std::string("not supported product, please type `prod` for knowen product"));
    }
    
    
    UserInputProcessor::debug("current time is" + currentTime);
    double minPrice = orderBook.getLowPriceFor(product,type, currentTime);
    
    
    UserInputProcessor::print("The min ask for "+ product + " is " + std::to_string(minPrice));
}

void MinimumCommand::init() {
    
}
