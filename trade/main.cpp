//
//  main.cpp
//  trade
//
//  Created by hamza ironside on 10/11/22.
//

#include <iostream>
#include "OrderBookEntry.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include "MerkelMain.hpp"
#include "Reader.hpp"
#include "Wallet.hpp"
int main(int argc, const char * argv[]) {
    
//    MerkelMain app{};
//    app.init();
    Wallet wallat;
    
    wallat.insertCurrency("BTC", 2);
    std::cout << "Wallaet Has BTC " << wallat.hasCurrency("BTC", 4);
    return 0;
}
