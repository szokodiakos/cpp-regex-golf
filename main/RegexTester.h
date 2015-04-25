#ifndef REGEXTESTER_H
#define REGEXTESTER_H

#include <regex>
#include <string>

namespace RegexTester {

/**
 * @brief Tests a given string against a given regex pattern.
 * @param string The string which will be tested.
 * @param regex The regex pattern which will be used in testing.
 * @return A smartpointer to a string which holds the longest part of the word
 * which matches the pattern.
 */
std::shared_ptr<std::string> test(std::string const& string, std::string const& regex);
}

#endif // REGEXTESTER_H
