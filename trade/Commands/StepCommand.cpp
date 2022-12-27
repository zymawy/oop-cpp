//
//  StepCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "StepCommand.hpp"
#include "UserInputProcessor.hpp"

void StepCommand::run() {

    UserInputProcessor::info("now at " + currentTime, icon);
}
