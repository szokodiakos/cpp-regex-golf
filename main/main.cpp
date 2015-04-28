#include <iostream>
#include <string>
#include "Game.h"

// memory leak checking
int reserved = 0;
int silentAllocation = true;

void * operator new(size_t size) {
    if(size > 1024*1024) throw std::bad_alloc();
    void *res = malloc(size);
    if(res == nullptr) throw std::bad_alloc();
    if (!silentAllocation) {
        std::cout << "~~~ allocated " << size << " bytes at " << res << std::endl;
    }
    reserved ++;
    return res;
}

void operator delete(void *p) noexcept {
    free(p);
    if (!silentAllocation) {
        std::cout << "~~~ freed memory at " << p << std::endl;
    }
    reserved--;
}

void * operator new[](size_t size) {
    if(size > 1024*1024) throw std::bad_alloc();
    void *res = malloc(size);
    if(res == nullptr) throw std::bad_alloc();
    if (!silentAllocation) {
        std::cout << "~~~ allocated " << size << " bytes at " << res << std::endl;
    }
    reserved ++;
    return res;
}

void operator delete[](void *p) noexcept {
    free(p);
    if (!silentAllocation) {
        std::cout << "~~~ freed memory at " << p << std::endl;
    }
    reserved--;
}

void check() {
    if (!silentAllocation) {
        std::cout << "~~~ Reserved: " << reserved << std::endl;
    }
}

int main(int argc, char **argv) {
    atexit(check);

    // lambda - why not?!
    []() {
        std::cout << R"(  ____                         ____       _  __ )" << std::endl;
        std::cout << R"( |  _ \ ___  __ _  _____  __  / ___| ___ | |/ _|)" << std::endl;
        std::cout << R"( | |_) / _ \/ _` |/ _ \ \/ / | |  _ / _ \| | |_ )" << std::endl;
        std::cout << R"( |  _ <  __/ (_| |  __/>  <  | |_| | (_) | |  _|)" << std::endl;
        std::cout << R"( |_| \_\___|\__, |\___/_/\_\  \____|\___/|_|_|  )" << std::endl;
        std::cout << R"(            |___/              powered by C++11 )" << std::endl;
    }();

    Game game;
    std::string input;
    game.print();
    while (getline(std::cin, input)) {
        if (input == "*q") {
            break;
        }
        game.input(input);
        game.print();
    }
    return 0;
}
