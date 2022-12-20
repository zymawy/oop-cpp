//
//  UserInputProcessor.cpp
//  trade
//
//  Created by hamza ironside on 12/16/22.
//

#include "UserInputProcessor.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>


UserInputProcessor::UserInputProcessor() {
    
}

std::string UserInputProcessor::getInput() {
    std::string line;
    std::getline(std::cin, line);
    return line;

}

void UserInputProcessor::print(std::string test, std::string by) {
    //"\n" <<
    std::cout << by << test << std::endl;
}


void UserInputProcessor::debug(std::string test) {
    print(test, "debug> ");
}

std::vector<std::string> UserInputProcessor::explode(std::string const &s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        // let's clear any spaces
        std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
        token.erase(end_pos, token.end());
        
        result.push_back(std::move(token));
    }

    return result;
}
