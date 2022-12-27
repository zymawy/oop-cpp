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

Advisorbot::Advisorbot() {}

void Advisorbot::init() {

    UserInputProcessor::print("Please enter a command, or help for a list of commands");
    currentTime = orderBook.getEarliestTime();

    // let's run our application
    while (true) {
        try {

            std::string input;

            input = inputProcessor.getInput();
            commandCreator.isValidCommand(input);
            commandCreator.setOrderBook(orderBook);
            // todo:: if have time enhance
            if (input == "step") {
                goToNextTimeFrame();
            }

            commandCreator.setCurrentTime(currentTime);

            commandCreator.runCommand(input);
        } catch (const std::exception &e) {

            UserInputProcessor::exception(e.what());

        }
    }


}


void Advisorbot::enterAsk() {

    std::cout << "Make and offer - enter the amount: product, price, amount, eg ETH/BTC," << std::endl;
    std::string input;

    std::getline(std::cin, input);


    std::vector <std::string> tokens = Reader::tokenise(input, ',');

    if (tokens.size() != 3) {
        std::cout << "Bad Input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obs = Reader::stringsToOrderBookEntry(
                    tokens[1],
                    tokens[2],
                    currentTime,
                    tokens[0],
                    OrderBookType::ask);

            if (wallet.canOrder(obs)) {

                std::cout << "Wool! 😀";
                orderBook.insertOrder(obs);
            } else {
                std::cout << "No Money!";
            }
        } catch (const std::exception &e) {
            std::cout << "Bad Input! " << input << std::endl;
        }
    }

    std::cout << "Your Enter : " << input << std::endl;
}

void Advisorbot::enterBid() {

    std::cout << "Make and offer - enter the amount: product, price, amount, eg ETH/BTC," << std::endl;
    std::string input;

    std::getline(std::cin, input);


    std::vector <std::string> tokens = Reader::tokenise(input, ',');

    if (tokens.size() != 3) {
        std::cout << "Bad Input! " << input << std::endl;
    } else {
        try {
            OrderBookEntry obs = Reader::stringsToOrderBookEntry(
                    tokens[1],
                    tokens[2],
                    currentTime,
                    tokens[0],
                    OrderBookType::bid);

            if (wallet.canOrder(obs)) {

                std::cout << "Wool! 😀";
                orderBook.insertOrder(obs);
            } else {
                std::cout << "No Money!";
            }
        } catch (const std::exception &e) {
            std::cout << "Bad Input! " << input << std::endl;
        }
    }

    std::cout << "Your Enter : " << input << std::endl;
}


void Advisorbot::goToNextTimeFrame() {

    currentTime = orderBook.getNextTime(currentTime);
}
