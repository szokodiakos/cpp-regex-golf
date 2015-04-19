#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
#include <vector>
#include "Level.h"

class Game {
    std::shared_ptr<Level> currentLevel;
    std::shared_ptr<std::vector<std::string>> levels;
    int score;
public:
    Game();
    ~Game();
    void print();
    void input(std::string);
    bool isLevelLoaded();
};

#endif // GAME_H
