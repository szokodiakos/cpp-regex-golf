#ifndef REGEXTESTER_H
#define REGEXTESTER_H

#include <regex>
#include <string>

class RegexTester {
public:
    RegexTester();
    ~RegexTester();
    static std::shared_ptr<std::string> test(std::string, std::string);
};

#endif // REGEXTESTER_H
