#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include <map>
#include "Level.h"

class Game {
    std::shared_ptr<Level> currentLevel;
    std::vector<std::string> levelNames;
    std::map<std::string, std::string> results;
    int score;
    bool validGuess;
public:
    Game();
    ~Game();
    void print();
    void input(std::string const&);
    bool isLevelLoaded();
    int evaluateGuess(std::string const&);
};

#endif // GAME_H
