#ifndef DAY03_H
#define DAY03_H

#include <vector>
#include <string>

namespace Day03 {
    extern std::vector<std::string> input;

    std::vector<std::vector<bool>> ParseInput(std::vector<std::string> input);

    long long A(std::vector<std::string> input, int xSlope = 3, int ySlope = 1);
    long long B(std::vector<std::string> input);
}

#endif