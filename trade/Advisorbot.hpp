//
//  MerkelMain.hpp
//  trade
//
//  Created by hamza ironside on 10/12/22.
//

#pragma once
#ifndef MerkelMain_hpp
#define MerkelMain_hpp

#include <stdio.h>
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
#include "Wallet.hpp"
#include "Commands/CommandCreator.hpp"
#include "Processors/UserInputProcessor.hpp"

class Advisorbot {
public:
//    It's the constructor.
    Advisorbot();

//    It's the constructor.
    void init();

private:
//    It's a function that allows the user to enter an ask.
    void enterAsk();

//    It's a function that allows the user to enter a bid.
    void enterBid();

//    It's going to the next time frame.
    void goToNextTimeFrame();

//    It's the current time.
    std::string currentTime;
    OrderBook orderBook{"data/mid_trem_20200601.csv"};
//    It's creating a new instance of the CommandCreator class.
    CommandCreator commandCreator{};
//    It's creating a new instance of the UserInputProcessor class.
    UserInputProcessor inputProcessor{};

//    It's creating a new instance of the Wallet class.
    Wallet wallet;

    std::vector <OrderBookEntry> orders;
};

#endif /* MerkelMain_hpp */
