#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>

namespace FileHandler {

/**
 * @brief Gets the given path's directory's filenames in a string vector.
 * @param path Path to a directory.
 * @return The file names of the requested directory in a string vector.
 */
std::vector<std::string> getFileNames(std::string const& path);

/**
 * @brief Gets a file's content by file's path.
 * @param path Path of the file (including the file itself).
 * @return Content of the file.
 */
std::string getFileContent(std::string const& path);
};

#endif // FILEHANDLER_H
