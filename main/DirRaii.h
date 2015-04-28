#ifndef DIRRAII_H
#define DIRRAII_H

#include <string>
#include <dirent.h>

/**
 * @class DirRaii
 * @file DirRaii.h
 * @brief RAII wrapper for the C DIR structure.
 */
class DirRaii {

    /**
     * @brief Pointer to the guarded C structure.
     */
    DIR* dir;

public:

    /**
     * @brief Constructor using a directory path.
     * @param path Path to the directory.
     */
    DirRaii(std::string path);

    /**
     * @brief Destructor
     */
    ~DirRaii();

    /**
     * @brief Converting operator to C DIR structure pointer.
     */
    operator DIR* () const;

    DirRaii(DirRaii const &) = delete;
    DirRaii(DirRaii &&) = delete;
    DirRaii& operator=(DirRaii) = delete;
};

#endif // DIRRAII_H
