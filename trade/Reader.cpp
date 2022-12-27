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
#include "UserInputProcessor.hpp"
Reader::Reader () {
    
};

std::map<std::string, std::vector<OrderBookEntry>> Reader::read(std::string file)
{
    std::map<std::string, std::vector<OrderBookEntry>> entries;
//    std::ifstream initStreamer{file};
    
    streamer.open(file);
    
    if (streamer.is_open())
    {
        std::string line;
        while (std::getline(streamer, line))
        {
            OrderBookEntry obe{stringsToOrderBookEntry(tokenise(line, ','))};
            entries[obe.timestamp].push_back(obe);
        }
    }
    else
    {
        UserInputProcessor::debug("Problem opening file " + file);
    }

    return entries;
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

OrderBookEntry Reader::stringsToOrderBookEntry(std::vector<std::string> tokens)
{
    double price, amount;
    if (tokens.size() != 5)
    {
        UserInputProcessor::exception("CSVReader::stringsToOrderBookEntry Bad line! ");
        throw std::exception{};
    }

    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception& e)
    {
        
    UserInputProcessor::exception("CSVReader::stringsToOrderBookEntry Bad line! " +  tokens[3] + " : " + tokens[4]);
        throw;
    }

    OrderBookEntry obe{
        price,
        amount,
        tokens[0],
        tokens[1],
        OrderBookEntry::convertType(tokens[2])};

    return obe;
}

OrderBookEntry Reader::stringsToOrderBookEntry(std::string _price,
                                       std::string _amount,
                                       std::string timestamp,
                                       std::string product,
                                       OrderBookType orderType)
{
    double price, amount;
    try
    {
        price = std::stod(_price);
        amount = std::stod(_amount);
    }
    catch (const std::exception& e)
    {
        UserInputProcessor::exception("CSVReader::stringsToOrderBookEntry Bad float! " + _price + " : " + _amount);
        throw;
    }

    OrderBookEntry obe{price,
                       amount,
                       timestamp,
                       product,
                       orderType};
    return obe;
}
