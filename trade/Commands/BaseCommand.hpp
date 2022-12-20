//
//  BaseCommand.hpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//
#pragma once
#ifndef BaseCommand_hpp
#define BaseCommand_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "OrderBook.hpp"

struct BaseCommand {
public:
    virtual ~BaseCommand() {};
    BaseCommand() {};
    const std::string& getName() const { return name; };;
    int getId() const { return id; };
    const std::string& getDescription() const { return description; };
    virtual void init();
    virtual void run();
    OrderBook orderBook;
    std::string commandName;
    std::string currentTime;
    void setOrderBook(OrderBook& orderBook);
    void setCommandName(std::string commandName);
    void setCurrentTime(std::string time);
//protected:
    // Let only derived classes create base instances.
    BaseCommand(int id,
                const std::string& name,
                const std::string& description)
        : id(id), name(name), description(description)
    {}
//private:
    int id = 0;
    std::string name = "Base Command";
    std::string description = "Base Command";
    
};

#endif /* BaseCommand_hpp */
