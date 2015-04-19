#ifndef FILERAII_H
#define FILERAII_H

#include <string>
#include <cstdio>

class FileRaii {
    FILE* file;
public:
    FileRaii(std::string);
    ~FileRaii();
    FileRaii(FileRaii const &) = delete;
    FileRaii& operator=(FileRaii const &) = delete;
    operator FILE* () const;
};

#endif // FILERAII_H
