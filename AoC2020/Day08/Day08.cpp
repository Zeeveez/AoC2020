#include "Day08.h"
#include "../Helpers/Helpers.h"

#include <regex>

namespace Day08 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day08Input.txt");

    CPU::CPU(std::vector<std::string> input) {
        instructions = input;
        run = {};
        for (auto& ins : instructions) {
            run.push_back(0);
        }
        acc = 0;
        ip = 0;
    }
    bool CPU::Step() {
        std::string ins = instructions[ip];
        run[ip]++;
        std::regex parseRegex("(\\w+)\\s([+-]\\d+)");
        std::sregex_iterator iter(ins.begin(), ins.end(), parseRegex);
        std::string opCode = (*iter)[1];
        long long operand = std::stoi((*iter)[2]);

        if (opCode == "nop") {
            ip++;
        } else if (opCode == "acc") {
            acc += operand;
            ip++;
        } else if (opCode == "jmp") {
            ip += operand;
        }

        return ip == instructions.size();
    }
    bool CPU::Looped() {
        return run[ip] == 1;
    }
    long long CPU::GetAcc() {
        return acc;
    }
    bool CPU::EditInstruction(long long i) {
        if (instructions[i].find("nop") != std::string::npos) {
            instructions[i].replace(0, 3, "jmp");
            return true;
        } else if (instructions[i].find("jmp") != std::string::npos) {
            instructions[i].replace(0, 3, "nop");
            return true;
        }
        return false;
    }

    long long A(std::vector<std::string> input) {
        CPU cpu(input);
        while (!cpu.Looped()) {
            cpu.Step();
        }
        return cpu.GetAcc();
    }

    long long B(std::vector<std::string> input) {
        for (long long i = 0; i < input.size(); i++) {
            CPU cpu(input);
            if (cpu.EditInstruction(i)) {
                while (!cpu.Looped()) {
                    if (cpu.Step()) {
                        return cpu.GetAcc();
                    }
                }
            }
        }
        return -1;
    }
}