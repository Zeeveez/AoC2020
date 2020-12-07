#include "Day07.h"
#include "../Helpers/Helpers.h"

#include <regex>
#include <algorithm>

namespace Day07 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day07Input.txt");

    std::map<std::string, std::vector<std::tuple<std::string, int>>> ParseBags(std::vector<std::string> input) {
        std::map<std::string, std::vector<std::tuple<std::string, int>>> data = {};
        std::regex parseRegex("(\\d+)? ?([a-z ]+) bags?");

        for (auto& bag : input) {
            std::sregex_iterator iter(bag.begin(), bag.end(), parseRegex);
            std::sregex_iterator end;
            std::smatch matches;

            std::string bag = (*iter++)[2];
            data.insert({ bag, {} });
            while (iter != end) {
                data[bag].push_back({ (*iter)[2], std::stoi((*iter)[1]) });
                iter++;
            }
        }

        return data;
    }

    int A(std::vector<std::string> input) {
        auto bags = ParseBags(input);
        std::vector<std::string> containsGold = { };

        for (auto& bag : bags) {
            for (auto& subbag : bag.second) {
                if (std::get<0>(subbag) == "shiny gold") {
                    containsGold.push_back(bag.first);
                }
            }
        }

        bool changed = true;
        while (changed) {
            changed = false;
            for (auto& bag : bags) {
                for (auto& subbag : bag.second) {
                    if (std::count(containsGold.begin(), containsGold.end(), std::get<0>(subbag))) {
                        if (!std::count(containsGold.begin(), containsGold.end(), bag.first)) {
                            containsGold.push_back(bag.first);
                            changed = true;
                        }
                    }
                }
            }
        }
        return containsGold.size();
    }

    int B(std::vector<std::string> input) {
        auto bags = ParseBags(input);
        std::vector<std::tuple<std::string, int>> carriedBags = { { "shiny gold", 1 } };
        std::vector<std::tuple<std::string, int>> newBags = {};

        int totalBags = 0;
        while (carriedBags.size()) {
            for (auto& bag : carriedBags) {
                std::string bagColor = std::get<0>(bag);
                int bagCount = std::get<1>(bag);
                if (bags.find(bagColor) != bags.end()) {
                    for (auto& subbag : bags[bagColor]) {
                        std::string subBagColor = std::get<0>(subbag);
                        int subBagCount = std::get<1>(subbag);
                        newBags.push_back({ subBagColor, subBagCount * bagCount });
                        totalBags += subBagCount * bagCount;
                    }
                }
            }
            carriedBags = newBags;
            newBags = {};
        }
        return totalBags;
    }
}