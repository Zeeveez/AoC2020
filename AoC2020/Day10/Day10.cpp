#include "Day10.h"
#include "../Helpers/Helpers.h"

#include <algorithm>
#include <numeric>

namespace Day10 {
    std::vector<long long> input = Helpers::ReadAllLines<long long>("./Day10Input.txt");
    std::vector<long long> tribonacciSequence = { 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504 };

    long long A(std::vector<long long> input) {
        input.push_back(0);
        std::sort(input.begin(), input.end());
        input.push_back(input[input.size() - 1] + 3);
        long long joltDiff1 = 0;
        long long joltDiff3 = 0;
        for (size_t i = 1; i < input.size(); i++) {
            if (input[i] - input[i - 1] == 1) {
                joltDiff1++;
            } else if (input[i] - input[i - 1] == 3) {
                joltDiff3++;
            }
        }
        return joltDiff1 * joltDiff3;
    }

    std::vector<std::vector<long long>> GroupDatasets(std::vector<long long> input) {
        std::sort(input.begin(), input.end());
        std::vector<std::vector<long long>> data = { { input[0] } };
        for (size_t i = 0; i < input.size() - 1; i++) {
            if (input[i + 1] - input[i] == 3) {
                data.push_back({});
            }
            data[data.size() - 1].push_back(input[i + 1]);
        }
        return data;
    }

    std::vector<long long> GroupsToSolutions(std::vector<std::vector<long long>> dataSets) {
        std::vector<long long> solutions = {};
        for (auto& dataSet : dataSets) {
            solutions.push_back(tribonacciSequence[dataSet.size()]);
        }
        return solutions;
    }

    long long B(std::vector<long long> input) {
        input.push_back(0);
        std::sort(input.begin(), input.end());
        input.push_back(input[input.size() - 1] + 3);
        auto data = GroupDatasets(input);
        auto solutions = GroupsToSolutions(data);
        return std::accumulate(solutions.begin(), solutions.end(), (long long)1, std::multiplies<long long>());
    }
}