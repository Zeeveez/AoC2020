#ifndef DAY4_H
#define DAY4_H

#include <vector>
#include <string>
#include <map>

namespace Day4 {
    extern std::vector<std::string> input;

    std::map<std::string, std::string> ParsePassport(std::string passport);
    std::vector<std::map<std::string, std::string>> ParseAllPassports(std::vector<std::string> input);

    int A(std::vector<std::string> input);
    int B(std::vector<std::string> input);
}

#endif