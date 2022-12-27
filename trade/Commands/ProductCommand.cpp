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
    for (auto &productName: orderBook.products) {
        UserInputProcessor::info(productName, icon);
    }
}