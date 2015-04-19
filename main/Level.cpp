#include <iostream>
#include "FileHandler.h"
#include "Level.h"

Level::Level() {
}

Level::~Level() {
}

void Level::print() {
    std::cout << "Level." << std::endl;
}

std::vector<std::string> Level::getLevelNames() {
    return FileHandler::getFileNames(LEVELS_DIR);
}

int Level::getLevelCount() {
    return Level::getLevelNames().size();
}

std::shared_ptr<Level> Level::load(std::string path) {
    std::string content = FileHandler::getFileContent(path);
}
