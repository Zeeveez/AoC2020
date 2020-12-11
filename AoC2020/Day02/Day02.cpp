#include "Day02.h"
#include "../Helpers/Helpers.h"

#include <regex>

namespace Day02 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day02Input.txt");

    int A(std::vector<std::string> input) {
        int valid = 0;
        std::regex parseRegex("(\\d+)-(\\d+) ([a-z]): ([a-z]+)");
        for (auto& pw : input) {
            std::sregex_iterator iter(pw.begin(), pw.end(), parseRegex);
            std::sregex_iterator end;
            int minCount = std::stoi((*iter)[1]);
            int maxCount = std::stoi((*iter)[2]);
            char searchChar = (*iter)[3].str()[0];
            std::string password = (*iter)[4];

            int count = 0;
            for (auto& c : password) {
                if (c == searchChar) { count++; }
            }
            if (count >= minCount && count <= maxCount) {
                valid++;
            }
        }
        return valid;
    }

    int B(std::vector<std::string> input) {
        int valid = 0;
        std::regex parseRegex("(\\d+)-(\\d+) ([a-z]): ([a-z]+)");
        for (auto& pw : input) {
            std::sregex_iterator iter(pw.begin(), pw.end(), parseRegex);
            std::sregex_iterator end;
            int firstPos = std::stoi((*iter)[1]);
            int secondPos = std::stoi((*iter)[2]);
            char searchChar = (*iter)[3].str()[0];
            std::string password = (*iter)[4];

            if ((password[firstPos - 1] == searchChar) ^ (password[secondPos - 1] == searchChar)) {
                valid++;
            }
        }
        return valid;
    }
}