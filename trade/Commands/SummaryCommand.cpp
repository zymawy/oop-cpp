//
//  HighestAndLowestCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/23/22.
//

#include "SummaryCommand.hpp"
#include "UserInputProcessor.hpp"

void SummaryCommand::init() {
    
  
}


void SummaryCommand::run() {
    std::vector<std::string> products;
    for (std::string const &p : orderBook.getKnownProducts())
    {
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                   p, currentTime);
        for (OrderBookEntry e : entries)
        {
            products.push_back(e.product);
        }
    }
    
    std::sort(products.begin(), products.end());
    
    
    UserInputProcessor::info("Highest Product : " + products.front(), icon);
    UserInputProcessor::info("Lowest Product : " + products.back(), icon);
}
