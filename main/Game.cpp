#include <iostream>
#include "Game.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levels = std::make_shared<std::vector<std::string>>(Level::getLevelNames());
}

Game::~Game() {
}

void Game::input(std::string input) {
    if (this->isLevelLoaded()) {

    } else {

    }
}

void Game::print() {
    std::cout << "RegexGolf++11" << std::endl;
    if (this->isLevelLoaded()) {
        this->currentLevel->print();
    } else {
        std::cout << "Select level:" << std::endl;
        for (unsigned int i = 0; i < this->levels->size(); i++) {
            std::cout << "  (" << i + 1 << ") " << (*levels)[i] << std::endl;
        }
        std::cout << "Level choice: ";
    }
}

bool Game::isLevelLoaded() {
    return (this->currentLevel != nullptr);
}
