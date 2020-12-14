#ifndef DAY13_H
#define DAY13_H

#include <vector>
#include <string>

namespace Day13 {
    extern std::vector<std::string> input;

    std::pair<int, std::vector<int>> ParseBuses(std::vector<std::string> input);
    long long A(std::vector<std::string> input);
    long long B(std::vector<std::string> input);
}

#endif