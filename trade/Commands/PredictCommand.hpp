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

class PredictCommand: public BaseCommand {
public:
    PredictCommand(): BaseCommand(6, "predict", "predict max or min ask or bid for the sent product for the next time step", "🪄") {};
    std::map<OrderBookType, std::map<std::string, double>> getherTranctions();
    double calculateSmoothAverage(const OrderBookType &type, const std::string &product, const int &timeframes, const std::string time);
private:
    virtual void init();
    virtual void run();
};
#endif /* PredictCommand_hpp */
