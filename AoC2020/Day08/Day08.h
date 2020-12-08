#ifndef DAY08_H
#define DAY08_H

#include <vector>
#include <string>

namespace Day08 {
    extern std::vector<std::string> input;

    class CPU {
    private:
        std::vector<int> run;
        std::vector<std::string> instructions;
        long long acc;
        long long ip;
    public:
        CPU(std::vector<std::string> input);
        bool Step();
        bool Looped();
        long long GetAcc();
        bool EditInstruction(long long i);
    };

    long long A(std::vector<std::string> input);
    long long B(std::vector<std::string> input);
}

#endif