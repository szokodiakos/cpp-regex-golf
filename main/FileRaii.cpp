#include "FileRaii.h"
#include <stdexcept>

FileRaii::FileRaii(std::string name) {
    this->file = fopen(name.c_str(), "r"); // we only need read-only access
    if (this->file == nullptr) {
        throw std::bad_alloc();
    }
}

FileRaii::~FileRaii() {
    if (this->file != nullptr) {
        fclose(this->file);
    }
    this->file = nullptr;
}

FileRaii::operator FILE* () const {
    return file;
}