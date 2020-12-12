#include "Day12.h"
#include "../Helpers/Helpers.h"

#include <iostream>
#include <unordered_map>
#include <regex>
#include <functional>

namespace Day12 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day12Input.txt");

    long long A(std::vector<std::string> input) {
        long long x = 0;
        long long y = 0;
        int bearing = 0;
        std::unordered_map<int, std::pair<int, int>> dirs = {
            { 0, { 1, 0 } },
            { 90, { 0, 1 } },
            { 180, { -1, 0 } },
            { 270, { 0, -1 } },
            { (int)('N'), { 0, -1 } },
            { (int)('E'), { 1, 0 } },
            { (int)('S'), { 0, 1 } },
            { (int)('W'), { -1, 0 } }
        };

        std::regex parseRegex("([NESWLRF])(\\d+)");
        for (auto& ins : input) {
            std::sregex_iterator iter(ins.begin(), ins.end(), parseRegex);
            char dir = (*iter)[1].str()[0];
            int val = std::stoi((*iter)[2]);
            switch (dir) {
            case 'N': case 'S': case 'E': case 'W':
                x += dirs[(int)dir].first * val;
                y += dirs[(int)dir].second * val;
                break;
            case 'F':
                x += dirs[bearing].first * val;
                y += dirs[bearing].second * val;
                break;
            case 'L':
                val = 360 - val;
                [[fallthrough]];
            case 'R':
                bearing = (bearing + val) % 360;
                break;
            }
        }
        return std::abs(x) + std::abs(y);
    }

    long long B(std::vector<std::string> input) {
        long long x = 0;
        long long y = 0;
        long long wpx = 10;
        long long wpy = -1;
        std::unordered_map<char, std::pair<int, int>> dirs = {
            { 'N', { 0, -1 } },
            { 'E', { 1, 0 } },
            { 'S', { 0, 1 } },
            { 'W', { -1, 0 } }
        };
        std::unordered_map<int, std::function<std::pair<int, int>(int, int)>> rots = {
            { 0, [](int x, int y) -> std::pair<int,int> { return { x, y }; } },
            { 90, [](int x, int y) -> std::pair<int,int> { return { -y, x }; } },
            { 180, [](int x, int y) -> std::pair<int,int> { return { -x, -y }; } },
            { 270, [](int x, int y) -> std::pair<int,int> { return { y, -x }; } }
        };

        std::regex parseRegex("([NESWLRF])(\\d+)");
        for (auto& ins : input) {
            std::sregex_iterator iter(ins.begin(), ins.end(), parseRegex);
            char dir = (*iter)[1].str()[0];
            int val = std::stoi((*iter)[2]);
            switch (dir) {
            case 'N': case 'S': case 'E': case 'W':
                wpx += dirs[dir].first * val;
                wpy += dirs[dir].second * val;
                break;
            case 'F':
                x += wpx * val;
                y += wpy * val;
                break;
            case 'L':
                val = 360 - val;
                [[fallthrough]];
            case 'R':
                auto [nx, ny] = rots[val](wpx, wpy);
                wpx = nx;
                wpy = ny;
                break;
            }
        }

        return std::abs(x) + std::abs(y);
    }
}