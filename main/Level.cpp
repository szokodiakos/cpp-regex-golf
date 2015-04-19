#include "Level.h"

Level::Level() {
}

Level::~Level() {
}

std::vector<std::string> Level::getLevelNames() {
    return FileHandler::getFileNames(LEVELS_DIR);
}
