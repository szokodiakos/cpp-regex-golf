#include "RegexTester.h"
#include <iostream>

RegexTester::RegexTester() {
}

RegexTester::~RegexTester() {
}

std::shared_ptr<std::string> RegexTester::test(std::string const& string, std::string const& regex) {
    std::shared_ptr<std::string> stringPtr;
    std::smatch matchResult;
    try {
        std::regex pattern(regex);
        std::regex_match(string, matchResult, pattern);
    } catch (std::regex_error& e) {
        throw "Invalid regex pattern";
    }

    // if match found, gather the longest match, then return it
    for (unsigned int i = 0; i < matchResult.size(); ++i) {
        if (stringPtr == nullptr) {
            stringPtr = std::make_shared<std::string>(matchResult[i]);
        } else {
            if (static_cast<unsigned int>(stringPtr->length()) < matchResult[i].length()) {
                stringPtr = std::make_shared<std::string>(matchResult[i]);
            }
        }
    }
    return stringPtr;
}
