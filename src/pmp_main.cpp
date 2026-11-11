#include "pmp.hpp"

#include <iostream>
#include <sys/wait.h>

int pmp::start() {
    alive = true;
    aliveMessage();

    return containerloop();
}

void pmp::aliveMessage()
{
    std::cout << "PMP: I am Alive!! | Set alive: " << alive << std::endl;
}

int pmp::containerloop()
{
    while (true)
    {
        // Placeholer

        sleep(1);
    }
    return 0;
}