#include "watchdog.hpp"

#include <iostream>
#include <sys/wait.h>

int watchdog::start() {
    alive = true;
    aliveMessage();

    return containerloop();
}

// TestMessage
void watchdog::aliveMessage() {
    std::cout << "WhaD: I am Alive!! | Set alive: " << alive << std::endl;
}

int watchdog::containerloop() {
    while (true) {
        // Placeholer

        sleep(1);
    }
    return 0;
}