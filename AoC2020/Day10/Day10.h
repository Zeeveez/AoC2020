#ifndef DAY10_H
#define DAY10_H

#include <vector>

namespace Day10 {
    extern std::vector<long long> input;
    extern std::vector<long long> tribonacciSequence;

    std::vector<std::vector<long long>> GroupDatasets(std::vector<long long> input);
    std::vector<long long> GroupsToSolutions(std::vector<std::vector<long long>> dataSets);

    long long A(std::vector<long long> input);
    long long B(std::vector<long long> input);
}

#endif