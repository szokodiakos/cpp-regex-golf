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

void Level::print() {
    std::cout << "Should match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldMatch->size(); ++i) {
        std::cout << " * " << (*this->shouldMatch)[i] << std::endl;
    }

    std::cout << "Should not match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldNotMatch->size(); ++i) {
        std::cout << " * " << (*this->shouldNotMatch)[i] << std::endl;
    }
}

std::vector<std::string> Level::getLevelNames() {
    return FileHandler::getFileNames(LEVELS_DIR);
}

int Level::getLevelCount() {
    return Level::getLevelNames().size();
}

std::shared_ptr<Level> Level::load(std::string path) {
    std::string content = FileHandler::getFileContent(path);
    std::shared_ptr<Level> level = std::make_shared<Level>(Level(content));
    return level;
}
