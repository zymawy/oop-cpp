//
//  Reader.hpp
//  trade
//
//  Created by hamza ironside on 10/14/22.
//
#pragma once
#ifndef Reader_hpp
#define Reader_hpp

#include <stdio.h>
#include <istream>
#include <vector>
#include <map>
#include "OrderBookEntry.hpp"
#include <fstream>

class Reader {
public:
    Reader();

//    static std::map<std::string, std::vector<OrderBookEntry>> read(std::string file);
//    A function that takes a string as input and returns a map of strings and vectors of OrderBookEntries.
    std::map <std::string, std::vector<OrderBookEntry>> read(std::string file);

    // A member variable of the class Reader. It is a file streamer.
    std::ifstream streamer;

//    A static function that takes a string and a character as input and returns a vector of strings.
    static std::vector <std::string> tokenise(std::string csvLine, char separator);

//    A static function that takes a vector of strings as input and returns an OrderBookEntry.
    static OrderBookEntry stringsToOrderBookEntry(std::vector <std::string> strings);

//    A function that takes a string and returns an OrderBookEntry.
    static OrderBookEntry stringsToOrderBookEntry(std::string price,
                                                  std::string amount,
                                                  std::string timestamp,
                                                  std::string product,
                                                  OrderBookType OrderBookType);
};

#endif /* Reader_hpp */
