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
    Advisorbot();
    void init();
    
private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void goToNextTimeFrame();
    int getUserOption();
    void processUserOption(std::string option);
    std::string currentTime;
//    OrderBook orderBook{"test.csv"};
    OrderBook orderBook{"data/mid_trem_20200601.csv"};
    // let's create or command create to
    // init the commands ...
    CommandCreator commandCreator{};
    UserInputProcessor inputProcesser{};
    
    Wallet wallet;
    
    std::vector<OrderBookEntry> orders;
};
#endif /* MerkelMain_hpp */
