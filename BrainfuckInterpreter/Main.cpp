#include "Interpreter.h"
#include "Commands.h"

int main(int argc, char** argv) {
    Interpreter& i = Interpreter::getInstance();
    std::string commands;
    while (true) {
        std::cin >> commands;
        i.interpret(commands.begin(), commands.end());
    }
}