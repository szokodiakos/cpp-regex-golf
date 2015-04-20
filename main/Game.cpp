#include <iostream>
#include "Game.h"
#include "Util.h"
#include "Level.h"
#include "RegexTester.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levelNames = Level::getLevelNames();
    this->results = std::map<std::string, std::string>();
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
        this->currentLevel->print(results);
        std::cout << "\nScore for last guess: " << this->score << " points." << std::endl;
        std::cout << "Enter guess: ";
    } else {
        std::cout << "Select level:" << std::endl;
        for (unsigned int i = 0; i < this->levelNames.size(); ++i) {
            std::cout << "  (" << i + 1 << ") " << levelNames[i] << std::endl;
        }
        std::cout << "\nLevel choice: ";
    }
}

int Game::evaluateGuess(std::string guess) {
    int score = 0;
    this->results.clear();

    // -1 pts for every character
    score -= guess.length();

    // +10 pts for every 'should' word match
    for (auto word: this->currentLevel->getShouldMatch()) {
        auto longestMatch = RegexTester::test(word, guess);

        // add some additional info to the result
        std::string resultInfo;
        if (longestMatch != nullptr) {
            resultInfo = "[ OK ] (" + *longestMatch + ")";
            score += 10;
        } else {
            resultInfo = "[    ]";
        }
        this->results[word] = resultInfo;
    }

    // -10 pts for every 'shouldNot' word match
    for (auto word: this->currentLevel->getShouldNotMatch()) {
        auto longestMatch = RegexTester::test(word, guess);

        // add some additional info to the result
        std::string resultInfo;
        if (longestMatch != nullptr) {
            resultInfo = "[FAIL] (" + *longestMatch + ")";
            score -= 10;
        } else {
            resultInfo = "[    ]";
        }
        this->results[word] = resultInfo;
    }
    return score;
}

bool Game::isLevelLoaded() {
    return (this->currentLevel != nullptr);
}
