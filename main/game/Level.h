#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <memory>
#include "../io/FileHandler.h"

class Level {
    constexpr static auto LEVELS_DIR = "../levels";
public:
    Level();
    ~Level();
    void print();
    static std::vector<std::string> getLevelNames();
    static int getLevelCount();
    static std::shared_ptr<Level> load(std::string);
};

#endif // LEVEL_H
