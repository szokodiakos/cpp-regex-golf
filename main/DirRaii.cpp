#include "DirRaii.h"
#include <stdexcept>

DirRaii::DirRaii(std::string path) {
    this->dir = opendir(path.c_str());
    if (this->dir == nullptr) {
        throw std::bad_alloc();
    }
}

DirRaii::~DirRaii() {
    if (this->dir != nullptr) {
        closedir(this->dir);
    }
    this->dir = nullptr;
}

DirRaii::operator DIR* () const {
    return dir;
}
