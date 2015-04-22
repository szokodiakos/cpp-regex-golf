#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>

class FileHandler {
public:
    FileHandler();
    ~FileHandler();
    static std::vector<std::string> getFileNames(std::string const&);
    static std::string getFileContent(std::string const&);
};

#endif // FILEHANDLER_H
