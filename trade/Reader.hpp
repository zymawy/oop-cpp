//
//  Reader.hpp
//  trade
//
//  Created by hamza ironside on 10/14/22.
//

#ifndef Reader_hpp
#define Reader_hpp

#include <stdio.h>
#include <istream>
#include <vector>
#include "OrderBookEntry.hpp"
class Reader {
public:
    Reader();
    
    static std::vector<OrderBookEntry> read(std::string file);
    static std::vector<std::string> tokenise(std::string line, char separator);
    static OrderBookEntry stringTpOrderBookEntry(
                                                 std::string price,
                                                 std::string amount,
                                                 std::string timestamp,
                                                 std::string product,
                                                 OrderBookType orderBookType
                                                 );

private:
    static OrderBookEntry stringTpOrderBookEntry(std::vector<std::string> strings);
};

#endif /* Reader_hpp */
