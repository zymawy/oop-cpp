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
    UserInputProcessor();
    std::string getInput();
    static void print(std::string test, std::string by = "advisorbot> ");
    static void debug(std::string input);
    static std::vector<std::string> explode(std::string const & s, char delim);
    
};
#endif /* UserInputProcessor_hpp */
