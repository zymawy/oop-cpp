//
//  MerkelMain.cpp
//  trade
//
//  Created by hamza ironside on 10/12/22.
//

#include "Advisorbot.hpp"
#include <iostream>
#include "OrderBookEntry.hpp"
#include "Reader.hpp"
#include <fstream>
#include <string>
#include "UserInputProcessor.hpp"

Advisorbot::Advisorbot() {
//    commandCreator.setOrderBook(orderBook);
}

void Advisorbot::init() {
    
    UserInputProcessor::print("Please enter a command, or help for a list of commands");
    currentTime = orderBook.getEarliestTime();
    while (true) {
        try {
            
            std::string input;
            
            input = inputProcesser.getInput();
            commandCreator.isVaildCommand(input);
            commandCreator.setOrderBook(orderBook);
            // todo:: if have time enhonce
            if (input == "step") {
                goToNextTimeFrame();
            }
  
            commandCreator.setCurrentTime(currentTime);
            commandCreator.runCommand(input);
        } catch (const std::exception& e) {
   
            UserInputProcessor::print(e.what());

        }
    }
}


void Advisorbot::printMarketStats() {
    
    for(std::string const& product : orderBook.getKnownProducts()) {
        std::cout << "Product: " << product << std::endl;
        std::vector<OrderBookEntry> enteries = orderBook.getOrders(OrderBookType::ask, product, currentTime);
        
        std::cout << "Asks seen of " << product  << " seen " << enteries.size() << " times" << std::endl;
        
        std::cout << "High Price Asks  of " << product  << " " << OrderBook::getHighPrice(enteries) << std::endl;
        
        std::cout << "Low Price Asks of " << product  << " " << OrderBook::getLowPrice(enteries) << std::endl;
    }
//    std::cout << "Market Looks Good" << std::endl;
}

void Advisorbot::enterAsk() {
    
    std::cout << "Make and offer - enter the amount: product, price, amount, eg ETH/BTC," << std::endl;
    std::string input;
    
    std::getline(std::cin, input);
    
    
    std::vector<std::string> tokens = Reader::tokenise(input,',');
    
    if (tokens.size() != 3) {
        std::cout << "Bad Input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obs = Reader::stringTpOrderBookEntry(
                                                                tokens[1],
                                                                tokens[2],
                                                                currentTime,
                                                                tokens[0],
                                                                OrderBookType::ask);
            
            if (wallet.canOrder(obs)) {
                
                std::cout << "Wool! 😀";
                orderBook.insrtOrder(obs);
            } else {
                    std::cout << "No Money!";
            }
        } catch (const std::exception& e) {
            std::cout << "Bad Input! " << input << std::endl;
        }
    }
    
    std::cout << "Your Enter : " << input << std::endl;
}

void Advisorbot::enterBid() {
    
    std::cout << "Make and offer - enter the amount: product, price, amount, eg ETH/BTC," << std::endl;
    std::string input;
    
    std::getline(std::cin, input);
    
    
    std::vector<std::string> tokens = Reader::tokenise(input,',');
    
    if (tokens.size() != 3) {
        std::cout << "Bad Input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obs = Reader::stringTpOrderBookEntry(
                                                                tokens[1],
                                                                tokens[2],
                                                                currentTime,
                                                                tokens[0],
                                                                OrderBookType::bid);
            
            if (wallet.canOrder(obs)) {
                
                std::cout << "Wool! 😀";
                orderBook.insrtOrder(obs);
            } else {
                    std::cout << "No Money!";
            }
        } catch (const std::exception& e) {
            std::cout << "Bad Input! " << input << std::endl;
        }
    }
    
    std::cout << "Your Enter : " << input << std::endl;
}

void Advisorbot::printWallet() {
    
//    std::cout << "Your Wallet is Has : " << orders.size() << " Of Enteries!" << std::endl;
//    unsigned int bids = 0;
//    unsigned int asks = 0;
//
//    for(OrderBookEntry& order : orders) {
//        if (order.orderType == OrderBookType::ask) {
//            asks++;
//        } else if (order.orderType == OrderBookType::bid) {
//            bids++;
//        }
//    }
//
    
    std::cout << "OrderBooks asks: " << wallet.toString() << std::endl;
}


void Advisorbot::goToNextTimeFrame() {
    
    currentTime = orderBook.getNextTime(currentTime);
}
