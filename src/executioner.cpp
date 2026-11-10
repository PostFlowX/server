#include "executioner.hpp"

int executioner::start() {
    alive = true;
    aliveMessage();

    return 0;
}

//TestMessage
void executioner::aliveMessage() {
    std::cout << "EXEC: I am Alive!!" << std::endl;
    std::cout << alive << std::endl;
}