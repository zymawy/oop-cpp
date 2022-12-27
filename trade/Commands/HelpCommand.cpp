//
//  HelpCommand.cpp
//  trade
//
//  Created by hamza ironside on 12/2/22.
//

#include "HelpCommand.hpp"
#include "UserInputProcessor.hpp"
#include "CommandCreator.hpp"
#include <algorithm>

void HelpCommand::run() {
    auto arguments = UserInputProcessor::explode(commandName, ' ');

    // let's handle the simple help command...
    if (arguments.size() == 1) {
        UserInputProcessor::print("📊 The available commands are :");

        for (auto &command: CommandCreator::availableShortNameCommands) {
            // let' quickly format our lists for better understanding
            // and a convenient way to show the description...
            std::string paddingSpaces = "               ";

            paddingSpaces = UserInputProcessor::repeat((paddingSpaces.length() - command.first.length()) & INT_MAX,
                                                       " ");

            UserInputProcessor::info(
                    command.first + paddingSpaces + command.second.first, command.second.second);
        }
    } else if (arguments.size() == 2) {
        // here we're going to handle the help <CMD>
        // so we can show the info for the selected command...

        std::string cmd = arguments[1];
        std::vector <std::string> checkCommands;

        // let's get the shortname of the commands that available :)...

        for (auto &command: CommandCreator::availableShortNameCommands) {
            checkCommands.push_back(command.first);
        }

        // lets lookup if the second argument is actually a supported cmd in our advisor bot...
        // otherwise, let's throw in error to show the user that the provided cmd is not supported!
        if (!count(checkCommands.begin(), checkCommands.end(), cmd)) {

            throw std::runtime_error(std::string("not supported command, please type `help` for supported commands"));
        }


        for (auto const &commend: CommandCreator::availableShortNameCommands) {

            if (commend.first == cmd) {
                UserInputProcessor::info(commend.second.first, commend.second.second);
            }
        }


    } else {

        throw std::runtime_error(std::string("please provider current input!"));
    }

}