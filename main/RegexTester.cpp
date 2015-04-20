#include "RegexTester.h"
#include <iostream>

RegexTester::RegexTester() {
}

RegexTester::~RegexTester() {
}

bool RegexTester::test() {
    if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
        std::cout << "string literal matched\n";
    return true;
}
