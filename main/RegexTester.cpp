#include "RegexTester.h"
#include <iostream>

RegexTester::RegexTester() {
}

RegexTester::~RegexTester() {
}

std::shared_ptr<std::string> RegexTester::test(std::string string, std::string regex) {
    std::shared_ptr<std::string> stringPtr;
    std::smatch matchResult;
    std::regex_match(string, matchResult, std::regex(regex));

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
