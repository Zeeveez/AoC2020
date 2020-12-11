#include "Day11.h"
#include "../Helpers/Helpers.h"

#include <iostream>
#include <map>

namespace Day11 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day11Input.txt");

    std::vector<std::vector<Seat>> InputToSeats(std::vector<std::string> input) {
        std::vector<std::vector<Seat>> seats = {};
        for (auto& row : input) {
            seats.push_back({});
            for (auto& seat : row) {
                switch (seat) {
                case '.':
                    seats[seats.size() - 1].push_back(Seat::NONE);
                    break;
                case 'L':
                    seats[seats.size() - 1].push_back(Seat::EMPTY);
                    break;
                }
            }
        }
        return seats;
    }


    int CountNeighboursA(std::vector<std::vector<Seat>>& seats, int x, int y) {
        int taken = 0;
        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                if (x + dx > -1 && x + dx < seats.size() && y + dy > -1 && y + dy < seats[x + dx].size() && !(dx == 0 && dy == 0)) {
                    if (seats[x + dx][y + dy] == Seat::TAKEN) {
                        taken++;
                    }
                }
            }
        }
        return taken;
    }

    int CountNeighboursB(std::vector<std::vector<Seat>>& seats, int x, int y) {
        std::map<int, std::pair<int, int>> dirs = {
            { 0, { 1, 0 } },
            { 1, { 1, 1 } },
            { 2, { 0, 1 } },
            { 3, { -1, 1 } },
            { 4, { -1, 0 } },
            { 5, { -1, -1 } },
            { 6, { 0, -1 } },
            { 7, { 1, -1 } }
        };
        int taken = 0;
        for (int dir = 0; dir < 8; dir++) {
            int dx = 0;
            int dy = 0;
            do {
                dx += dirs[dir].first;
                dy += dirs[dir].second;
            } while (x + dx > -1 && x + dx < seats.size() && y + dy > -1 && y + dy < seats[x + dx].size() && seats[x + dx][y + dy] == Seat::NONE);

            if (x + dx > -1 && x + dx < seats.size() && y + dy > -1 && y + dy < seats[x + dx].size() && seats[x + dx][y + dy] == Seat::TAKEN) {
                taken++;
            }
        }
        return taken;
    }

    std::pair<std::vector<std::vector<Seat>>, bool> IterateSeats(std::vector<std::vector<Seat>> seats, int maxTaken, std::function<int(std::vector<std::vector<Seat>>&, int, int)> countMethod) {
        std::vector<std::vector<Seat>> newSeats = seats;
        for (int x = 0; x < seats.size(); x++) {
            for (int y = 0; y < seats[x].size(); y++) {
                if (seats[x][y] != Seat::NONE) {
                    int taken = countMethod(seats, x, y);
                    if (taken == 0) {
                        newSeats[x][y] = Seat::TAKEN;
                    } else if (taken >= maxTaken) {
                        newSeats[x][y] = Seat::EMPTY;
                    }
                }
            }
        }

        for (int x = 0; x < seats.size(); x++) {
            for (int y = 0; y < seats[x].size(); y++) {
                if (seats[x][y] != newSeats[x][y]) {
                    return { newSeats, false };
                }
            }
        }
        return { newSeats, true };
    }

    long long Run(std::vector<std::string> input, int maxTaken, std::function<int(std::vector<std::vector<Seat>>&, int, int)> countMethod) {
        auto seats = InputToSeats(input);
        bool stable = false;
        while (!stable) {
            auto [newSeats, newStable] = IterateSeats(seats, maxTaken, countMethod);
            seats = std::move(newSeats);
            stable = newStable;
        }

        long long taken = 0;
        for (auto& row : seats) {
            for (auto& seat : row) {
                if (seat == Seat::TAKEN) { taken++; }
            }
        }
        return taken;
    }

    long long A(std::vector<std::string> input) {
        return Run(input, 4, CountNeighboursA);
    }

    long long B(std::vector<std::string> input) {
        return Run(input, 5, CountNeighboursB);
    }
}