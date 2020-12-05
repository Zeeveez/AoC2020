#include "Day02.h"
#include "../Helpers/Helpers.h"

namespace Day02 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day02Input.txt");

    int A(std::vector<std::string> input) {
        int valid = 0;
        for (auto& pw : input) {
            int step = 0;
            int minCount = 0;
            int maxCount = 0;
            char c = '_';
            int count = 0;
            for (int i = 0; i < pw.length(); i++) {
                if (step == 0) {
                    // Get first number
                    if (pw[i] == '-') {
                        step++;
                    } else {
                        minCount = minCount * 10 + (pw[i] - '0');
                    }
                } else if (step == 1) {
                    // Get second number
                    if (pw[i] == ' ') {
                        step++;
                    } else {
                        maxCount = maxCount * 10 + (pw[i] - '0');
                    }
                } else if (step == 2) {
                    // Get character to search for
                    if (pw[i] == ' ') {
                        step++;
                    } else {
                        c = c == '_' ? pw[i] : c;
                    }
                } else {
                    // Perform password check
                    if (pw[i] == c) {
                        count++;
                    }
                }
            }
            if (count >= minCount && count <= maxCount) {
                valid++;
            }
        }
        return valid;
    }

    int B(std::vector<std::string> input) {
        int valid = 0;
        for (auto& pw : input) {
            int step = 0;
            int firstPos = 0;
            int secondPos = 0;
            char c = '_';
            bool validPass = false;
            int pwStart = 0;
            for (int i = 0; i < pw.length(); i++) {
                if (step == 0) {
                    // Get first number
                    if (pw[i] == '-') {
                        step++;
                    } else {
                        firstPos = firstPos * 10 + (pw[i] - '0');
                    }
                } else if (step == 1) {
                    // Get second number
                    if (pw[i] == ' ') {
                        step++;
                    } else {
                        secondPos = secondPos * 10 + (pw[i] - '0');
                    }
                } else if (step == 2) {
                    // Get character to search for
                    if (pw[i] == ' ') {
                        step++;
                        pwStart = i;
                    } else {
                        c = c == '_' ? pw[i] : c;
                    }
                } else {
                    // Perform password check
                    if (i - pwStart == firstPos || i - pwStart == secondPos) {
                        validPass ^= pw[i] == c;
                    }
                }
            }
            if (validPass) {
                valid++;
            }
        }
        return valid;
    }
}