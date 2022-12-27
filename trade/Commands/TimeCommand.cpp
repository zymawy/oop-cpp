//
//  TimeCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "TimeCommand.hpp"
#include "UserInputProcessor.hpp"

void TimeCommand::run() {

    UserInputProcessor::info(currentTime, icon);
}