#include <iostream>
#include "Game.h"
#include "Util.h"
#include "Level.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levels = Level::getLevelNames();
}

Game::~Game() {
}

void Game::input(std::string input) {
    std::string info;
    if (this->isLevelLoaded()) {
        this->score = this->evaluateGuess(input);
    } else {
        if (Util::isNumber(input)) {
            int levelId = std::stoi(input);
            if (levelId <= Level::getLevelCount()) {
                std::string name = Level::getLevelNames()[levelId - 1];
                this->currentLevel = std::make_shared<Level>(Level::load(name));
            } else {
                info = " *** Error: Invalid level id, try again. ***";
            }
        } else {
            info = " *** Error: Level id must be numeric. ***";
        }
    }
    if (info.length() > 0) {
        std::cout << info << std::endl;
    }
}

void Game::print() {
    std::cout << Util::separator() << std::endl;
    if (this->isLevelLoaded()) {
        this->currentLevel->print();
        std::cout << "\nScore so far: " << this->score << std::endl;
        std::cout << "Enter guess: ";
    } else {
        std::cout << "Select level:" << std::endl;
        for (unsigned int i = 0; i < this->levels.size(); ++i) {
            std::cout << "  (" << i + 1 << ") " << levels[i] << std::endl;
        }
        std::cout << "\nLevel choice: ";
    }
}

int Game::evaluateGuess(std::string guess) {
    int score = 0;

    // -1 pts for every character
    score -= guess.length();

    // +10 pts for every should word

    // -10 pts for every shouldNot word

    return score;
}

bool Game::isLevelLoaded() {
    return (this->currentLevel != nullptr);
}
