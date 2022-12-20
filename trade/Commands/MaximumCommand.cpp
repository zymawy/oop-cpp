//
//  MaximumCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "MaximumCommand.hpp"
#include "UserInputProcessor.hpp"

void MaximumCommand::run() {
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
    
    
    double minPrice = orderBook.getLowPriceFor(product,type,currentTime);
    
    
    UserInputProcessor::print("The max ask for "+ product + " is " + std::to_string(minPrice));
    
}

void MaximumCommand::init() {
}
