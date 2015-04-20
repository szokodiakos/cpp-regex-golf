#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include "FileHandler.h"
#include "JSONLevelParser.h"

class Level {
    std::vector<std::string> shouldMatch;
    std::vector<std::string> shouldNotMatch;
public:
    constexpr static auto LEVELS_DIR = "../levels";
    Level();
    template <typename LevelParser = JSONLevelParser>
    Level(std::string);
    ~Level();
    void print(std::map<std::string, std::string>);
    static std::vector<std::string> getLevelNames();
    static int getLevelCount();
    static Level load(std::string);
    const std::vector<std::string>& getShouldMatch() const;
    const std::vector<std::string>& getShouldNotMatch() const;
};

#endif // LEVEL_H
