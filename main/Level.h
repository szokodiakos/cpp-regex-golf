#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "FileHandler.h"

class Level {
    constexpr static auto LEVELS_DIR = "levels";
public:
    Level();
    ~Level();
    static std::vector<std::string> getLevelNames();
};

#endif // LEVEL_H
