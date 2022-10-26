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
class MerkelMain {
public:
    MerkelMain();
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
    void processUserOption(int option);
    std::string currentTime;
    OrderBook orderBook{"test.csv"};
    
    Wallet wallet;
    
    std::vector<OrderBookEntry> orders;
};
#endif /* MerkelMain_hpp */
