#ifndef DAY14_H
#define DAY14_H

#include <vector>
#include <string>
#include <map>

namespace Day14 {
    extern std::vector<std::string> input;

    long long ApplyMaskA(std::string mask, long long val);
    std::vector<std::string> GenerateMasksB(std::string mask);
    std::vector<long long> ApplyMaskB(std::string mask, long long rawAddr);
    
    long long A(std::vector<std::string> input);
    long long B(std::vector<std::string> input);
}

#endif