#include "Day06.h"
#include "../Helpers/Helpers.h"

#include <algorithm>
#include <numeric>

namespace Day06 {
    std::vector<std::vector<std::string>> input = Helpers::SeparateDatasets(Helpers::ReadAllLines<std::string>("./Day06Input.txt"));

    int A(std::vector<std::vector<std::string>> input) {
        int yes = 0;
        for (auto& dataSet : input) {
            std::string group = std::accumulate(dataSet.begin(), dataSet.end(), std::string(""));
            for (auto& c : "abcdefghijklmnopqrstuvwxyz") {
                if (group.find(c) != std::string::npos) {
                    yes++;
                }
            }
        }
        return yes;
    }

    int B(std::vector<std::vector<std::string>> input) {
        int yes = 0;
        for (auto& dataSet : input) {
            std::string group = std::accumulate(dataSet.begin(), dataSet.end(), std::string(""));
            for (auto& c : "abcdefghijklmnopqrstuvwxyz") {
                if (std::count(group.begin(), group.end(), c) == dataSet.size()) {
                    yes++;
                }
            }
        }
        return yes;
    }
}