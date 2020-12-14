#include "Day14.h"
#include "../Helpers/Helpers.h"

#include <regex>

namespace Day14 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day14Input.txt");

    long long ApplyMaskA(std::string mask, long long val) {
        int i = mask.length() - 1;
        for (auto& bit : mask) {
            if (bit == '1') {
                val |= 1ll << i;
            } else if (bit == '0') {
                val &= ~(1ll << i);
            }
            i--;
        }
        return val;
    }

    std::vector<std::string> GenerateMasksB(std::string mask) {
        size_t xPos = mask.find('X');
        if (xPos != std::string::npos) {
            std::vector<std::string> masks = {};
            mask[xPos] = '0';
            auto masksWith0 = GenerateMasksB(mask);
            masks.insert(masks.end(), masksWith0.begin(), masksWith0.end());
            mask[xPos] = '1';
            auto masksWith1 = GenerateMasksB(mask);
            masks.insert(masks.end(), masksWith1.begin(), masksWith1.end());
            return masks;
        } else {
            return { mask };
        }
    }

    std::vector<long long> ApplyMaskB(std::string origMask, long long rawAddr) {
        auto masks = GenerateMasksB(origMask);
        std::vector<long long> addresses = {};
        for (auto& mask : masks) {
            long long addr = rawAddr;
            for (int i = 0; i < mask.length(); i++) {
                if (origMask[i] == '1') {
                    addr |= 1ll << (mask.length() - 1 - i);
                } else if (origMask[i] == 'X') {
                    if (mask[i] == '1') {
                        addr |= 1ll << (mask.length() - 1 - i);
                    } else if (mask[i] == '0') {
                        addr &= ~(1ll << (mask.length() - 1 - i));
                    }
                } 
            }
            addresses.push_back(addr);
        }
        return addresses;
    }

    long long A(std::vector<std::string> input) {
        std::map<long long, long long> memory = {};
        std::string mask;
        std::regex maskRegex("mask = ([X\\d]+)");
        std::regex memRegex("mem\\[(\\d+)\\] = ([\\d]+)");
        for (auto& row : input) {
            if (row[1] == 'a') {
                std::sregex_iterator iter(row.begin(), row.end(), maskRegex);
                mask = (*iter)[1];
            } else {
                std::sregex_iterator iter(row.begin(), row.end(), memRegex);
                long long addr = std::stoi((*iter)[1]);
                long long val = std::stoll((*iter)[2]);
                val = ApplyMaskA(mask, val);

                if (memory.count(addr)) {
                    memory[addr] = val;
                } else {
                    memory.insert({ addr, val });
                }
            }
        }

        long long sum = 0;
        for (auto& kvp : memory) {
            sum += kvp.second;
        }
        return sum;
    }

    long long B(std::vector<std::string> input) {
        std::map<long long, long long> memory = {};
        std::string mask;
        std::regex maskRegex("mask = ([X\\d]+)");
        std::regex memRegex("mem\\[(\\d+)\\] = ([\\d]+)");
        for (auto& row : input) {
            if (row[1] == 'a') {
                std::sregex_iterator iter(row.begin(), row.end(), maskRegex);
                mask = (*iter)[1];
            } else {
                std::sregex_iterator iter(row.begin(), row.end(), memRegex);
                long long rawAddr = std::stoi((*iter)[1]);
                long long val = std::stoll((*iter)[2]);
                std::vector<long long> addresses = ApplyMaskB(mask, rawAddr);

                for (auto& addr : addresses) {
                    if (memory.count(addr)) {
                        memory[addr] = val;
                    } else {
                        memory.insert({ addr, val });
                    }
                }
            }
        }

        long long sum = 0;
        for (auto& kvp : memory) {
            sum += kvp.second;
        }
        return sum;
    }
}