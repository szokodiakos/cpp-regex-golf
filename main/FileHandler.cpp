#include <iostream>
#include <memory>
#include <cstring>
#include <dirent.h>
#include "FileHandler.h"

FileHandler::FileHandler() {
}

FileHandler::~FileHandler() {
}

std::vector<std::string> FileHandler::getFileNames(std::string directory) {
    std::shared_ptr<DIR> dir(opendir(directory.c_str()));
    std::vector<std::string> files;
    if (dir != nullptr) {
        while (auto ep = readdir(dir.get())) {
            auto fileName = ep->d_name;
            if ((std::strcmp(fileName, ".") != 0) && (std::strcmp(fileName, "..") != 0)) {
                files.push_back(fileName);
            }
        }
    }
    return files;
}
