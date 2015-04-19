#include <iostream>
#include "Game.h"
#include "Util.h"
#include "Level.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levels = std::make_shared<std::vector<std::string>>(Level::getLevelNames());
}

Game::~Game() {
}

void Game::input(std::string input) {
    std::string info;
    if (this->isLevelLoaded()) {
    } else {
        if (Util::isNumber(input)) {
            int levelId = std::stoi(input);
            if (levelId <= Level::getLevelCount()) {
                std::string name = Level::getLevelNames()[levelId - 1];
                info = " *** Loading level '" + name + "'... ***";
                this->currentLevel = Level::load(name);
            } else {
                info = " *** Error: Invalid level id, try again. ***";
            }
        } else {
            info = " *** Error: Level is must be numeric. ***";
        }
    }
    if (info.length() > 0) {
        std::cout << info << std::endl;
    }
}

void Game::print() {
    std::cout << "-----" << std::endl;
    if (this->isLevelLoaded()) {
        this->currentLevel->print();
    } else {
        std::cout << "Select level:" << std::endl;
        for (unsigned int i = 0; i < this->levels->size(); ++i) {
            std::cout << "  (" << i + 1 << ") " << (*levels)[i] << std::endl;
        }
        std::cout << "Level choice: ";
    }
}

bool Game::isLevelLoaded() {
    return (this->currentLevel != nullptr);
}
