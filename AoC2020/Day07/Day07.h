#ifndef DAY07_H
#define DAY07_H

#include <vector>
#include <string>
#include <map>
#include <tuple>

namespace Day07 {
    extern std::vector<std::string> input;

    std::map<std::string, std::vector<std::tuple<std::string, int>>> ParseBags(std::vector<std::string> input);

    int A(std::vector<std::string> input);
    int B(std::vector<std::string> input);
}

#endif