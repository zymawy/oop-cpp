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

//This is a struct that is used to create a base class for the commands.
struct BaseCommand {
public:
    // A virtual destructor.
    virtual ~BaseCommand() {};

    /*A default constructor.*/
    BaseCommand() {};

    /*A getter function for the name variable. */
    const std::string &getName() const { return name; };

    /*This is a getter function for the id variable.*/
    int getId() const { return id; };

    // This is a getter function for the description variable.
    const std::string &getDescription() const { return description; };

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

    // This is a constructor that is used to initialize the variables of the BaseCommand class.
    // Let only derived classes create base instances.
    BaseCommand(int id,
                const std::string &name,
                const std::string &description,
                const std::string &icon)
            : id(id), name(name), description(description), icon(icon) {}

//    A default value for the id variable.
    int id = 0;
//    This is a default value for the name variable.
    std::string name = "Base Command";
//    This is a default value for the description variable.
    std::string description = "Base Command";
//    This is a default value for the icon variable.
    std::string icon = "🪄";
};

#endif /* BaseCommand_hpp */
