#include "Day06.h"
#include "../Helpers/Helpers.h"

#include <algorithm>

namespace Day06 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day06Input.txt");

    std::vector<std::string> GetGroups(std::vector<std::string> input) {
        std::vector<std::string> groups = {};
        std::string group = "";
        for (auto& line : input) {
            if (line.length() == 0) {
                groups.push_back(group);
                group = "";
            } else {
                group += (group.length() ? ";" : "") + line;
            }
        }
        return groups;
    }

    int A(std::vector<std::string> input) {
        auto groups = GetGroups(input);
        int yes = 0;
        for (auto& group : groups) {
            for (auto& c : "abcdefghijklmnopqrstuvwxyz") {
                if (group.find(c) != std::string::npos) {
                    yes++;
                }
            }
        }
        return yes;
    }

    int B(std::vector<std::string> input) {
        auto groups = GetGroups(input);
        int yes = 0;
        for (auto& group : groups) {
            for (auto& c : "abcdefghijklmnopqrstuvwxyz") {
                if (std::count(group.begin(), group.end(), c) == std::count(group.begin(), group.end(), ';') + 1) {
                    yes++;
                }
            }
        }
        return yes;
    }
}