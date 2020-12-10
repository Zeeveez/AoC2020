#include "Day09.h"
#include "../Helpers/Helpers.h"

#include <deque>
#include <algorithm>
#include <climits>

namespace Day09 {
    std::vector<long long> input = Helpers::ReadAllLines<long long>("./Day09Input.txt");

    long long A(std::vector<long long> input, int preambleLength) {
        std::deque<long long> preamble = {};
        for (int i = 0; i < preambleLength; i++) {
            preamble.push_back(input[i]);
        }

        for (int i = preambleLength; i < input.size(); i++) {
            bool good = false;
            for (int j = 0; j < preambleLength && !good; j++) {
                for (int k = 0; k < preambleLength && !good; k++) {
                    if (j != k) {
                        if (preamble[j] + preamble[k] == input[i]) {
                            good = true;
                        }
                    }
                }
            }
            if (good) {
                preamble.push_back(input[i]);
                preamble.pop_front();
            } else {
                return input[i];
            }
        }
        return -1;
    }

    long long B(std::vector<long long> input) {
        long long target = A(input);
        for (int i = 0; i < input.size(); i++) {
            long long sum = 0;
            long long min = LLONG_MAX;
            long long max = LLONG_MIN;

            for (int j = i; j < input.size(); j++) {
                sum += input[j];
                if (sum > target) {
                    break;
                }
                min = std::min(input[j], min);
                max = std::max(input[j], max);
                if (sum == target) {
                    return min + max;
                }
            }
        }
        return -1;
    }
}