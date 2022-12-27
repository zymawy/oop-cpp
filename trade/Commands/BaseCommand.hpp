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

struct BaseCommand
{
public:
    // A virtual destructor.
    virtual ~BaseCommand(){};
    /*A default constructor.*/
    BaseCommand(){};
   /*A getter function for the name variable. */
    const std::string &getName() const { return name; };
    /*This is a getter function for the id variable.*/
    int getId() const { return id; };
    // This is a getter function for the description variable.
    const std::string &getDescription() const { return description; };
    // This is a virtual function that is used to initialize the command.
    virtual void init();
    //This is a virtual function that is used to initialize the command.
    virtual void run();
//    Creating an instance of the OrderBook class.
    OrderBook orderBook;
//    A variable that is used to store the name of the command.
    std::string commandName;
//    This is a variable that is used to store the current time.
    std::string currentTime;
//    This is a setter function that is used to set the orderBook variable.
    void setOrderBook(OrderBook &orderBook);
//    This is a setter function that is used to set the commandName variable.
    void setCommandName(std::string commandName);
//    This is a setter function that is used to set the currentTime variable.
    void setCurrentTime(std::string time);
    // Let only derived classes create base instances.
    BaseCommand(int id,
                const std::string &name,
                const std::string &description,
                const std::string &icon)
        : id(id), name(name), description(description), icon(icon)
    {}
    int id = 0;
    std::string name = "Base Command";
    std::string description = "Base Command";
    std::string icon = "🪄";
};

#endif /* BaseCommand_hpp */
