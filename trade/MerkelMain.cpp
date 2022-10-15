//
//  MerkelMain.cpp
//  trade
//
//  Created by hamza ironside on 10/12/22.
//

#include "MerkelMain.hpp"
#include <iostream>
#include "OrderBookEntry.hpp"
#include "Reader.hpp"
#include <fstream>
#include <string>



MerkelMain::MerkelMain() {

}

void MerkelMain::init() {
    int input;
    currentTime = orderBook.getEarliestTime();
    
    wallet.insertCurrency("BTC", 10);
    
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}


void MerkelMain::printMenu() {
    
        std::cout << "1: Print Help" << std::endl;
        
        std::cout << "2: Print Extancge States" << std::endl;
        
        std::cout << "3: Make An Offer " << std::endl;
        
        std::cout << "4: Make A Bid" << std::endl;
        
        std::cout << "5: Print Wallet " << std::endl;
        
        std::cout << "Continue .." << std::endl;
        
        std::cout <<  "==============" << std::endl;
    
    std::cout <<  "Current Time Is : " << currentTime << std::endl;
        
        std::cout << "Type in 1 till 6" << std::endl;
}


void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyze the market and make " << std::endl;
}

void MerkelMain::printMarketStats() {
    
    for(std::string const& product : orderBook.getKnownProducts()) {
        std::cout << "Product: " << product << std::endl;
        std::vector<OrderBookEntry> enteries = orderBook.getOrders(OrderBookType::ask, product, currentTime);
        
        std::cout << "Asks seen of " << product  << " seen " << enteries.size() << " times" << std::endl;
        
        std::cout << "High Price Asks  of " << product  << " " << OrderBook::getHighPrice(enteries) << std::endl;
        
        std::cout << "Low Price Asks of " << product  << " " << OrderBook::getLowPrice(enteries) << std::endl;
    }
//    std::cout << "Market Looks Good" << std::endl;
}

void MerkelMain::enterAsk() {
    
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

void MerkelMain::enterBid() {
    
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

void MerkelMain::printWallet() {
    
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


void MerkelMain::goToNextTimeFrame() {
    
    currentTime = orderBook.getNextTime(currentTime);
    
    std::cout << "Going To Next Time Frame : Current: " << currentTime << std::endl;
}

int MerkelMain::getUserOption() {
    int option;
    std::string line;
    std::cout << "Type Number Withn 1 - 6" << std::endl;
    std::string input;
   std::getline(std::cin, line);
    
    try {
        option = std::stoi(line);
    } catch (const std::exception& e) {
        
    }
    
    std::cout << "You Chose: " << option << std::endl;
    
    return option;
}

void MerkelMain::processUserOption(int option) {
    
    if (option == 0) {
        std::cout << "Invalid Choice, Choose With range of 1 - 6" << std::endl;
    }
    
    if (option == 1) {
        printHelp();
    }
    
    
    if (option == 2) {
        printMarketStats();
    }
    
    
    if (option == 3) {
        enterAsk();
    }
    
    
    if (option == 4) {
        enterBid();
    }
    
    
    if (option == 5) {
        printWallet();
    }
    
    if (option == 6) {
        goToNextTimeFrame();
    }
}
