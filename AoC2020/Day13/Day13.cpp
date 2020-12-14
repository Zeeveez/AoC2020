#include "Day13.h"
#include "../Helpers/Helpers.h"

#include <regex>
#include <climits>

namespace Day13 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day13Input.txt");

    std::pair<int, std::vector<int>> ParseBuses(std::vector<std::string> input) {
        long long earliestDeparture = std::stoll(input[0]);
        std::vector<int> buses = {};
        std::regex parseRegex("([x\\d]+)");
        std::sregex_iterator iter(input[1].begin(), input[1].end(), parseRegex);
        std::sregex_iterator end;

        while (iter != end) {
            std::string bus = (*iter)[1];
            if (bus == "x") {
                buses.push_back(-1);
            } else {
                buses.push_back(std::stoi(bus));
            }
            iter++;
        }
        return { earliestDeparture, buses };
    }

    long long A(std::vector<std::string> input) {
        auto [earliestDeparture, buses] = ParseBuses(input);

        long long min = LLONG_MAX;
        int minBus = -1;
        for (auto& bus : buses) {
            if (bus != -1) {
                int earliest = (earliestDeparture / bus + 1) * bus;
                if (earliest < min) {
                    min = earliest;
                    minBus = bus;
                }
            }
        }
        return minBus * (min - earliestDeparture);
    }

    bool CheckBusTimes(std::vector<int>& buses, long long depNumber) {
        long long depTime = buses[0] * depNumber;
        for (int i = 1; i < buses.size(); i++) {
            if (buses[i] != -1) {
                if ((depTime + i) % buses[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    long long B(std::vector<std::string> input) {
        auto [earliestDeparture, buses] = ParseBuses(input);
        long long i = 100000000000000 / buses[0];
        do {
            i++;
        } while (!CheckBusTimes(buses, i));
        return i * buses[0];
    }
}