#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    Game();
    ~Game();
    void print();
    void guess(std::string);
};

#endif // GAME_H
