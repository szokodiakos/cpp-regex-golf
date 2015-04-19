#include <iostream>
#include <string>
#include "Game.h"

int main(int argc, char **argv) {
    Game game;
    std::string guess;
    game.print();
    while (getline(std::cin, guess)) {
        game.guess(guess);
        game.print();
    }
    return 0;
}
