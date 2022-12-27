//
//  PredictCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once
#ifndef PredictCommand_hpp
#define PredictCommand_hpp

#include <stdio.h>
#include "BaseCommand.hpp"

class PredictCommand : public BaseCommand {
public:
//    This is the constructor for the PredictCommand class. It is calling the constructor for the BaseCommand class.
    PredictCommand() : BaseCommand(6, "predict",
                                   "predict max or min ask or bid for the sent product for the next time step",
                                   "🪄") {};

//    This is a function that is gathering the transactions from the order book.
    std::map <OrderBookType, std::map<std::string, double>> gatherTransactions();

//    This function is calculating the smooth average of the transactions.
    double calculateSmoothAverage(const OrderBookType &type, const std::string &product, const int &timeframes,
                                  const std::string time);

private:
    virtual void run();
};

#endif /* PredictCommand_hpp */
