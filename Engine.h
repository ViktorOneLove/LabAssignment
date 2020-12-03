#pragma once
#include "Definitions.h"
#include "ICommand.h"

//Invoker class 
class Engine {

public:

	void register_command(ICommand* command, std::string commandName) {
		commandWithName[commandName] = command;
	}

	int execute(std::string commandName, params_with_name params) {
		auto it = commandWithName.find(commandName);
		if (it != commandWithName.end()) {
			return it->second->execute(params);
		} else {
			return 1;
		}
	}

private:

	std::map<std::string, ICommand*> commandWithName;

};