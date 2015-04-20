#include <iostream>
#include <string>
#include "FileHandler.h"
#include "Level.h"

Level::Level() {
}

template <typename LevelParser>
Level::Level(std::string content) {
    try {
        LevelParser::parse(content, this->shouldMatch, this->shouldNotMatch);
    } catch (std::string info) {
        std::cerr << " *** Error: Could not parse level file, reason: " << info <<  " *** " << std::endl;
    }
}

Level::~Level() {
}

void Level::print(std::map<std::string, std::string> results) {
    std::cout << "Should match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldMatch.size(); ++i) {
        auto result = results[this->shouldMatch[i]];

        // augment level item with guess results
        std::cout << " * " << this->shouldMatch[i] << " " << result << std::endl;
    }

    std::cout << "\nShould not match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldNotMatch.size(); ++i) {
        auto result = results[this->shouldNotMatch[i]];

        // augment level item with guess results
        std::cout << " * " << this->shouldNotMatch[i] << " " << result << std::endl;
    }
}

std::vector<std::string> Level::getLevelNames() {
    return FileHandler::getFileNames(LEVELS_DIR);
}

int Level::getLevelCount() {
    return Level::getLevelNames().size();
}

Level Level::load(std::string path) {
    std::string content = FileHandler::getFileContent(path);
    return Level(content);
}

const std::vector<std::string>& Level::getShouldMatch() const {
    return shouldMatch;
}
const std::vector<std::string>& Level::getShouldNotMatch() const {
    return shouldNotMatch;
}
