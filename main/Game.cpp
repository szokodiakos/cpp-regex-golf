#include <iostream>
#include "Game.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levels = std::make_shared<std::vector<std::string>>(Level::getLevelNames());
}

Game::~Game() {
}

void Game::guess(std::string) {
}

void Game::print() {
    std::cout << "RegexGolf++11" << std::endl;
}
