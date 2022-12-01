//
//  Reader.cpp
//  trade
//
//  Created by hamza ironside on 10/14/22.
//

#include "Reader.hpp"
#include <iostream>
#include <fstream>
#include "OrderBookEntry.hpp"

Reader::Reader () {
    
};

std::vector<OrderBookEntry> Reader::read(std::string file) {

    std::vector<OrderBookEntry> enteries;
    
        std::ifstream streamer{file};
        std::string line;
        std::vector<std::string> tokens;
    
    if (streamer.is_open()) {
        while (std::getline(streamer, line)) {
            try {
                OrderBookEntry order = stringTpOrderBookEntry(tokenise(line, ','));
                enteries.push_back(order);
            } catch (const std::exception& e) {
                std::cout << "Reader[read]  bad data '" <<  line << "'"  << std::endl;
            }
        }
    }
    
    std::cout << "Reader::read " << enteries.size() << " enteries" << std::endl;
    
    return enteries;
}


std::vector<std::string> Reader::tokenise(std::string line, char separator) {
    std::vector<std::string> tokens;
    signed long start, end;
    std::string token;
    start = line.find_first_not_of(separator, 0);
    
    do {
        end = line.find_first_of(separator, start);
        if (start == line.length() || start == end) break;
    
        if (end >= 0) token = line.substr(start, end - start);
        
        else token = line.substr(start, line.length() - start);
        
        tokens.push_back(token);
        
        start = end + 1;

    } while(end != std::string::npos);
    
    
    return tokens;
}


OrderBookEntry Reader::stringTpOrderBookEntry(std::vector<std::string> token) {
    
    double price, amount;
    
    if (token.size() != 5) {

        throw std::exception{};
    }

    try {
    price = std::stod(token[3]);
    amount = std::stod(token[4]);
    } catch (std::exception& e) {
    std::cout << "Bad float" << std::endl;
    throw;
    }
        
    
    OrderBookEntry order{price, amount, token[0], token[1], OrderBookEntry::convertType(token[2])};
    
    return order;
}

OrderBookEntry Reader::stringTpOrderBookEntry(
                                             std::string _price,
                                             std::string _amount,
                                             std::string timestamp,
                                             std::string product,
                                             OrderBookType orderBookType
                                             ) {
    
    
    double price, amount;

    try {
    price = std::stod(_price);
    amount = std::stod(_amount);
    } catch (std::exception& e) {
    std::cout << "Bad float" << std::endl;
    throw;
    }
    
    OrderBookEntry order{price, amount, timestamp, product, orderBookType};
    
    return order;
}
