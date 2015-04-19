#include <iostream>
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

std::shared_ptr<Level> load(std::string path) {
    FileHandler::getFile(path);
}
