#ifndef DAY11_H
#define DAY11_H

#include <vector>
#include <string>
#include <functional>

namespace Day11 {
    extern std::vector<std::string> input;

    enum class Seat {
        NONE,
        EMPTY,
        TAKEN
    };

    std::vector<std::vector<Seat>> InputToSeats(std::vector<std::string> input);
    std::pair<std::vector<std::vector<Seat>>, bool> IterateSeats(std::vector<std::vector<Seat>> seats, int maxTaken, std::function<int(std::vector<std::vector<Seat>>&, int, int)> countMethod);
    int CountNeighboursA(std::vector<std::vector<Seat>>& seats, int x, int y);
    int CountNeighboursB(std::vector<std::vector<Seat>>& seats, int x, int y);

    long long Run(std::vector<std::string> input, int maxTaken, std::function<int(std::vector<std::vector<Seat>>&, int, int)> countMethod);
    long long A(std::vector<std::string> input);
    long long B(std::vector<std::string> input);
}

#endif