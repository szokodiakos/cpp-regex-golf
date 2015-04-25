#ifndef UTIL_H
#define UTIL_H

#include <string>

namespace Util {

/**
 * @brief Separator for game UI printing.
 */
constexpr auto separator = "\n---------";

/**
 * @brief Determines whether the string parameter is a number.
 * @param str The parameter to be tested.
 * @return True if the string is a number, else false.
 */
bool isNumber(std::string const& str);
}

#endif // UTIL_H
