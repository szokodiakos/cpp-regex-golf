#include <iostream>
#include <string>
#include "Game.h"

int main(int argc, char **argv) {
    std::cout << R"(  ____                         ____       _  __ )" << std::endl;
    std::cout << R"( |  _ \ ___  __ _  _____  __  / ___| ___ | |/ _|)" << std::endl;
    std::cout << R"( | |_) / _ \/ _` |/ _ \ \/ / | |  _ / _ \| | |_ )" << std::endl;
    std::cout << R"( |  _ <  __/ (_| |  __/>  <  | |_| | (_) | |  _|)" << std::endl;
    std::cout << R"( |_| \_\___|\__, |\___/_/\_\  \____|\___/|_|_|  )" << std::endl;
    std::cout << R"(            |___/              powered by C++11 )" << std::endl;
    Game game;
    std::string input;
    game.print();
    while (getline(std::cin, input)) {
        game.input(input);
        game.print();
    }
    return 0;
}
