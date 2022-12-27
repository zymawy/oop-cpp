//
//  PredictCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "PredictCommand.hpp"
#include "UserInputProcessor.hpp"

void PredictCommand::run() {
    // Let's parse the input ... and get the arguments
    auto argments = UserInputProcessor::explode(commandName, ' ');
    
    
    // let's check if we have lass the 4 arguments
    // we will return in favor of early return consapt!
    if (argments.size() < 4) {
        throw std::runtime_error(
                                 std::string("arguments missing product ex..[max/min], ex..[BTC/ETH], type ex..[ask/bid]"));
    }
    
    
    std::string maxOrMin =argments[1];
    std::string product =argments[2];
    std::string type = argments[3];
    
    // Let's get started and validate user inputs
    if ((type != "bid" && type != "ask")) {

throw std::runtime_error(
     std::string("argument missing/invalid type, it should be ether ask or bid you entered [" + type + "]")
         );
    }
    
    if ((maxOrMin != "min" && maxOrMin != "max")) {

throw std::runtime_error(
     std::string("argument missing/invalid maxOrMin, it should be ether min or max you entered [" + maxOrMin + "]")
         );
    }
    
    
    if (! orderBook.isProductExists(product)) {
        
        throw std::runtime_error(std::string("not supported product, please type `prod` for knowen product"));
    }
    
    std::map<std::string, double> bidOrAsksAvg{getherTranctions().at(OrderBookEntry::convertType(type))};
    std::string availableSuggestionProductsName;
    // let's get going and see if we have product in
    // this current time with curret entry type ...
    for (auto& e: bidOrAsksAvg) {
        if (! UserInputProcessor::is_number( e.first )) {
            availableSuggestionProductsName =  availableSuggestionProductsName + (availableSuggestionProductsName.length() ? "," : "") + e.first;
        }
    }
    
    double predictAvg;

    /**
     The map is mapped with the product, so let's try to get it out
     Occasionally, no results are obtained due to a lack of information
     Transactions/orders have been processed and meet the 10 timestamps
     Additionally, we are using try here and recommending some products that are available
     Transactions/orders with a current timestamp to help the user
     */
    try {
        predictAvg = bidOrAsksAvg.at(product);
    } catch (const std::exception &e) {
        
        
        std::string errorMessage = "There is not enough data to predict the future based on the current timestamp: " + currentTime + " and current product " + product;
        if (availableSuggestionProductsName.length()) {
            errorMessage = "There is not enough data to predict \n we suggest try those products " + availableSuggestionProductsName;
        }
        
        throw std::runtime_error(std::string(errorMessage));

    }
    
        UserInputProcessor::print(
                                  " The average " + product + " " + type + " price over the last 10 timesteps was "
                                  + std::to_string(predictAvg)
                                  );
}

void PredictCommand::init() {
}

std::map<OrderBookType, std::map<std::string, double>> PredictCommand::getherTranctions() {
    
    std::map<OrderBookType, std::map<std::string, double>> predictions;
    std::map<std::string, double> bids{};
    std::map<std::string, double> asks{};
    std::string currentPreTime = currentTime;

    for (const std::string &product : orderBook.products) {
        try {
            std::vector<OrderBookEntry> orders = orderBook.orders.at(currentPreTime);
            if (orderBook.orders.find(currentPreTime) != orderBook.orders.begin() && orders.size() > 0) {
                
                if (calculateSmoothAverage(OrderBookType::ask, product, 10, currentPreTime) < orderBook.getLowPrice(orders, product, OrderBookType::ask)) {
                    asks.emplace(product, orderBook.getLowPrice(orders, product, OrderBookType::ask));
                }
                if (calculateSmoothAverage(OrderBookType::bid, product, 10, currentPreTime) > orderBook.getHighPrice(orders, product, OrderBookType::bid)) {
                    bids.emplace(product, orderBook.getHighPrice(orders, product, OrderBookType::bid));
                }
                
            }
                

        }
        catch (const std::exception &e) {
            
            UserInputProcessor::exception(e.what());
            
            continue;
        }
    }
    // let's append
    predictions.emplace(OrderBookType::bid, bids);
    predictions.emplace(OrderBookType::ask, asks);
    
    return predictions;
}

double PredictCommand::calculateSmoothAverage(const OrderBookType &type, const std::string &product, const int &timeframes, const std::string time) {
    int conclusions{0};
    double sumConclusions{0};
    std::string timeframe{time};
    while (orderBook.orders.find(timeframe) != orderBook.orders.begin() && conclusions < timeframes) {
        std::vector<OrderBookEntry> orders{orderBook.getOrders(type, product, timeframe)};
        if (orders.size() > 0) {
            timeframe = orderBook.getPreviousTime(timeframe);
            ++conclusions;
            sumConclusions += orders.back().price;
        } else {
            
            timeframe = orderBook.getPreviousTime(timeframe);
        }
    }
    return sumConclusions/timeframes;
}
