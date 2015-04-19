#ifndef DIRRAII_H
#define DIRRAII_H

#include <string>
#include <dirent.h>

class DirRaii {
    DIR* dir;
public:
    DirRaii(std::string);
    ~DirRaii();
    DirRaii(DirRaii const &) = delete;
    DirRaii& operator=(DirRaii const &) = delete;
    operator DIR* () const;
};

#endif // DIRRAII_H
