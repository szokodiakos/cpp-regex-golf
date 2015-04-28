#include <iostream>
#include <algorithm>
#include "Game.h"
#include "Util.h"
#include "Level.h"
#include "RegexTester.h"

Game::Game() {
    this->score = 0;
    this->currentLevel = nullptr;
    this->levelNames = Level::getLevelNames();
    this->results = std::map<std::string, std::string>();
    this->validGuess = true;
}

Game::~Game() {
}

void Game::input(std::string const& input) {
    std::string info;
    if (this->isLevelLoaded()) {
        this->validGuess = true;
        try {
            this->score = this->evaluateGuess(input);
        } catch (...) {
            this->validGuess = false;
        }
    } else {
        if (Util::isNumber(input)) {
            int levelId = std::stoi(input);
            if (levelId <= Level::getLevelCount()) {
                std::string name = Level::getLevelNames()[levelId - 1];
                try {
                    std::shared_ptr<Level> levelPtr = std::make_shared<Level>(Level::load(name));
                    this->currentLevel = levelPtr;
                } catch (std::string info) {
                    this->currentLevel = nullptr;
                    std::cerr << " *** Error: Could not parse level file, reason: " << info <<  " *** " << std::endl;
                }
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
    std::cout << Util::separator << std::endl;
    if (this->isLevelLoaded()) {
        this->currentLevel->print(results);
        if (this->validGuess) {
            std::cout << "\nScore for last guess: " << this->score << " points." << std::endl;
        } else {
            std::cout << "\n *** Error: Invalid guess, please try again. ***" << std::endl;
        }
        std::cout << "Enter guess: ";
    } else {
        std::cout << "Select level:" << std::endl;
        for (unsigned int i = 0; i < this->levelNames.size(); ++i) {
            std::cout << "  (" << i + 1 << ") " << levelNames[i] << std::endl;
        }
        std::cout << "\nLevel choice: ";
    }
}

int Game::evaluateGuess(std::string const& guess) {
    bool shouldMatch;
    int score = 0;
    this->results.clear();

    // -1 pts for every character
    score -= guess.length();

    auto testWord = [&guess, &score, this, &shouldMatch](std::string const& word) {

        // run actual test
        auto longestMatch = RegexTester::test(word, guess);

        // add some additional info to the result
        std::string resultInfo;
        if (longestMatch != nullptr) {
            std::string label = shouldMatch ? "[ OK ]" : "[FAIL]";
            resultInfo = label + " (" + *longestMatch + ")";

            int scoreDiff = shouldMatch ? 10 : -10;
            score += scoreDiff;
        } else {
            std::string label = shouldMatch ? "[FAIL]" : "[ OK ]";
            resultInfo = label;
        }
        this->results[word] = resultInfo;
    };

    // +10 pts for every 'should' word match
    shouldMatch = true;
    std::for_each(this->currentLevel->getShouldMatch().begin(),
                  this->currentLevel->getShouldMatch().end(),
                  testWord);

    // -10 pts for every 'shouldNot' word match
    shouldMatch = false;
    std::for_each(this->currentLevel->getShouldNotMatch().begin(),
                  this->currentLevel->getShouldNotMatch().end(),
                  testWord);

    return score;
}

bool Game::isLevelLoaded() {
    return (this->currentLevel != nullptr);
}
