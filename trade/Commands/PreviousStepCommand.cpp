//
//  PreviousStepCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/26/22.
//

#include "PreviousStepCommand.hpp"
#include "UserInputProcessor.hpp"


void PreviousStepCommand::run() {
    std::string oldTimeStamp = currentTime;

   std::string currentTimeStamp = orderBook.getPreviousTime(oldTimeStamp);
    
    if (oldTimeStamp == currentTimeStamp) {
        throw std::runtime_error(
                                 std::string("The current timetap is the beginning of the trade"));
    }
    currentTime = currentTimeStamp;
    
    
    UserInputProcessor::info(
                             "old timestamp is : "+ oldTimeStamp +" now at " + currentTime, icon);
}

void PreviousStepCommand::init() {
}
