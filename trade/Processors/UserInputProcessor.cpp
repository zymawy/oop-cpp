//
//  UserInputProcessor.cpp
//  trade
//
//  Created by hamza ironside on 12/16/22.
//

#include "UserInputProcessor.hpp"

#include <iostream>
#include <sstream>
#include <vector>


UserInputProcessor::UserInputProcessor() {}

std::string UserInputProcessor::getInput() {
    std::string line;
    std::getline(std::cin, line);
    return line;

}

void UserInputProcessor::print(std::string taxt, std::string by) {
    std::cout << by << taxt << std::endl;
}


void UserInputProcessor::debug(std::string taxt) {
    print(taxt, "debug🐛> ");
}

void UserInputProcessor::info(std::string taxt, std::string icon) {
//    std::cout.width(50);

    print(taxt, "advisorbot" + icon + "> ");
}


void UserInputProcessor::exception(std::string taxt) {
    print(taxt, "exception🚨> ");
}

std::vector <std::string> UserInputProcessor::explode(std::string const &s, char delim) {
    std::vector <std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);) {
        // let's clear any spaces
        std::string::iterator end_pos = std::remove(token.begin(), token.end(), ' ');
        token.erase(end_pos, token.end());

        result.push_back(std::move(token));
    }

    return result;
}


std::string UserInputProcessor::repeat(int n, std::string repeat) {

    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << repeat;


    return os.str();
}

bool UserInputProcessor::is_number(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}
