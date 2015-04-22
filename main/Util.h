#ifndef UTIL_H
#define UTIL_H

#include <string>

class Util {
public:
    Util();
    ~Util();
    static bool isNumber(std::string const&);
    static std::string separator();
};

#endif // UTIL_H
