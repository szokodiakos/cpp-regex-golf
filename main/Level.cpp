#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>
#include "FileHandler.h"
#include "Level.h"

Level::Level() {
}

template <typename LevelParser>
Level::Level(std::string const& content) {
    LevelParser::parse(content, this->shouldMatch, this->shouldNotMatch);
}

Level::Level(Level && other) {
    this->shouldMatch = std::move(other.shouldMatch);
    this->shouldNotMatch = std::move(other.shouldNotMatch);
}


Level& Level::operator=(Level rhs) {
    std::swap(this->shouldMatch, rhs.shouldMatch);
    std::swap(this->shouldNotMatch, rhs.shouldNotMatch);
    return *this;
}

Level::~Level() {
}

void Level::print(std::map<std::string, std::string> const& results) {
    std::cout << "Should match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldMatch.size(); ++i) {
        std::string result;
        try {
            result = results.at(this->shouldMatch[i]);
        } catch (std::out_of_range &e) {
            result = "";
        }

        // augment level item with guess results
        std::cout << " * " << this->shouldMatch[i] << " " << result << std::endl;
    }

    std::cout << "\nShould not match: " << std::endl;
    for (unsigned int i = 0; i < this->shouldNotMatch.size(); ++i) {
        std::string result;
        try {
            result = results.at(this->shouldNotMatch[i]);
        } catch (std::out_of_range &e) {
            result = "";
        }

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

Level Level::load(std::string const& fileName) {
    std::string filePath = std::string(Level::LEVELS_DIR) + "/" + fileName;
    std::string content = FileHandler::getFileContent(filePath);
    return Level(content);
}

const std::vector<std::string>& Level::getShouldMatch() const {
    return shouldMatch;
}
const std::vector<std::string>& Level::getShouldNotMatch() const {
    return shouldNotMatch;
}
