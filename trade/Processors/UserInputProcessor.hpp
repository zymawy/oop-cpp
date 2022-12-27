//
//  UserInputProcessor.hpp
//  trade
//
//  Created by hamza ironside on 12/16/22.
//

#ifndef UserInputProcessor_hpp
#define UserInputProcessor_hpp

#include <stdio.h>
#include <fstream>
#include <string>

class UserInputProcessor {
public:
//    A constructor.
    UserInputProcessor();

//    Getting the user input.
    std::string getInput();

//    A function that prints out the string that is passed to it.
    static void print(std::string test, std::string by = "advisorbot👨🏾‍💻> ");

//    A function that prints out the string that is passed to it.
    static void debug(std::string input);

//    A function that prints out the string that is passed to it.
    static void info(std::string input, std::string icon = "💁🏾‍♂️");

//    Printing out the string that is passed to it.
    static void exception(std::string input);

//    A function that takes a string and a character and returns a vector of strings.
    static std::vector <std::string> explode(std::string const &s, char delim);

//    A function that takes a string and a character and returns a vector of strings.
    static std::string repeat(int n, std::string repeat);

//    Checking if the string is a number.
    static bool is_number(const std::string &s);

};

#endif /* UserInputProcessor_hpp */
