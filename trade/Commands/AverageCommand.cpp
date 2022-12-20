//
//  AverageCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "AverageCommand.hpp"
#include "UserInputProcessor.hpp"

void AverageCommand::run() {
    
    UserInputProcessor::print("Basm allahma");
    auto argments = UserInputProcessor::explode(commandName, ' ');
    
    
    if (argments.size() < 4) {
        throw std::runtime_error(
                                 std::string("arguments missing product ex..[BTC/ETH], type ex..[ask,bid], timestamp ex..[10]"));
    }
    
    
    std::string product =argments[1];
    std::string type =argments[2];
    std::string timestamp = argments[3];
    
    if ((type != "bid" && type != "ask")) {

throw std::runtime_error(
     std::string("argument missing/invalid type, it should be ether ask or bid you entered [" + type + "]")
         );
    }
    
    
    if (! orderBook.isProductExists(product)) {
        
        throw std::runtime_error(std::string("not supported product, please type `prod` for knowen product"));
    }
    
    
    double minPrice = orderBook.getLowPriceFor(product,type);
    
    
    UserInputProcessor::print(
                              "The average "+ product +
                              " " + type +
                              " price over the last "+
                              timestamp +
                              " was " +
                              std::to_string(minPrice)
                              );
    
}

void AverageCommand::init() {
}
