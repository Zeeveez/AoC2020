#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include <fstream>

namespace Helpers {
    template<typename T>
    std::vector<T> ReadAllLines(std::string path) {
        std::string line;
        std::vector<T> lines;
        std::ifstream f(path);
        while (std::getline(f, line)) {
            if constexpr (std::is_same<T, std::string>::value) {
                lines.push_back(line);
            } else if constexpr (std::is_same<T, int>::value) {
                lines.push_back(std::stoi(line));
            }
        }
        f.close();
        return lines;
    }
}

#endif