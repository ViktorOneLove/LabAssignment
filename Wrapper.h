#pragma once
#include "Definitions.h"
#include "ICommand.h"


class Wrapper : public ICommand {

public:


	template<typename Subj, class... Args>
	Wrapper(Subj* subject, int(Subj::* method)(Args...), params_with_name args) {

		if (args.size() != sizeof...(Args)) {
			return;
		}

		for (auto& arg : args) {
			funcArgsOrder.push_back(arg.first);
			defaultFuncArguments.push_back(arg.second);
		}

		func = [this, subject, method](const std::vector<int>& funcArgs) {
			return(callMethod(subject, method, funcArgs, std::make_index_sequence<sizeof...(Args)>{}));
		};
	}


	int execute(params_with_name params) override {
		if (func == NULL)
			return 0;

		if (params.size() != funcArgsOrder.size()) {
			return func(defaultFuncArguments);
		}

		std::vector<int> funcArguments;
		for (auto& argName : funcArgsOrder) {
			auto it = params.find(argName);
			if (it != params.end()) {
				funcArguments.push_back(it->second);
			} else {
				return func(defaultFuncArguments);
			}
		}

		return func(funcArguments);
	}


private:

	std::function<int(const std::vector<int>& funcArgs)> func;

	std::vector<int> defaultFuncArguments;

	std::vector<std::string> funcArgsOrder;

	template<typename Subj, typename Method, size_t... I>
	int callMethod(Subj* subject, Method method, const std::vector<int>& args, std::index_sequence<I...>)
	{
		return((subject->*method)(args[I]...));
	}

};