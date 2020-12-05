#ifndef DAY05_H
#define DAY05_H

#include <vector>
#include <string>
#include <set>

namespace Day05 {
    extern std::vector<std::string> input;

    std::set<int> GetSeatIDs(std::vector<std::string> input);

    int A(std::vector<std::string> input);
    int B(std::vector<std::string> input);
}

#endif