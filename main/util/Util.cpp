#include <cctype>
#include "Util.h"

Util::Util() {
}

Util::~Util() {
}

bool Util::isNumber(std::string str) {
    bool isNumber = true;
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it)) {
            isNumber = false;
        }
    }
    return isNumber;
}
