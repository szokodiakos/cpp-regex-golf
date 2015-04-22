#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>
#include <cstring>
#include "FileHandler.h"
#include "DirRaii.h"
#include "Level.h"

FileHandler::FileHandler() {
}

FileHandler::~FileHandler() {
}

std::vector<std::string> FileHandler::getFileNames(std::string const& path) {
    DirRaii dir(path);
    std::vector<std::string> files;
    if (dir != nullptr) {
        while (auto ep = readdir(dir)) {
            auto fileName = ep->d_name;
            if ((std::strcmp(fileName, ".") != 0) && (std::strcmp(fileName, "..") != 0)) {
                files.push_back(fileName);
            }
        }
    }
    return files;
}

std::string FileHandler::getFileContent(std::string const& fileName) {
    std::stringstream stringStream;
    std::ifstream fileStream;
    std::string filePath = std::string(Level::LEVELS_DIR) + "/" + fileName;
    fileStream.open(filePath);
    if (fileStream.is_open()) {
        while (fileStream.peek() != EOF) {
            stringStream << (char) fileStream.get();
        }
        fileStream.close();
    } else {
        std::cerr << " *** Error: Could not open file. ***" << std::endl;
    }
    std::string content = stringStream.str();
    return content;
}
