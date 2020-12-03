#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"

/*Активно понадобятся
*  - паттерн Command
*  - паттерн Wrapper
*  - std::function
*  - variadic tempalates
*/





int main() {
    Subject subj;

    Wrapper wrapper(&subj, &Subject::f3, { {"arg1", 0}, {"arg2", 0} });

    Engine engine;

    engine.register_command(&wrapper, "command1");

    std::cout << engine.execute("command1", { {"arg2", 10}, {"arg1", 23} }) << std::endl;

    return 0;
}