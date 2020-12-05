#ifndef DAY5_H
#define DAY5_H

#include <vector>
#include <string>
#include <set>

namespace Day5 {
    extern std::vector<std::string> input;

    std::set<int> GetSeatIDs(std::vector<std::string> input);

    int A(std::vector<std::string> input);
    int B(std::vector<std::string> input);
}

#endif