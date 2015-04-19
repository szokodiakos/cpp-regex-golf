#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <memory>
#include "FileHandler.h"
#include "JSONLevelParser.h"

class Level {
    std::shared_ptr<std::vector<std::string>> shouldMatch;
    std::shared_ptr<std::vector<std::string>> shouldNotMatch;
public:
    constexpr static auto LEVELS_DIR = "../levels";
    Level();
    template <typename LevelParser = JSONLevelParser>
    Level(std::string);
    ~Level();
    void print();
    static std::vector<std::string> getLevelNames();
    static int getLevelCount();
    static std::shared_ptr<Level> load(std::string);
};

#endif // LEVEL_H
