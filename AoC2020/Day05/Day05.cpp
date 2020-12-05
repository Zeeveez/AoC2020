#include "Day05.h"
#include "../Helpers/Helpers.h"

namespace Day05 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day05Input.txt");

    std::set<int> GetSeatIDs(std::vector<std::string> input) {
        std::set<int> seatIDs = {};
        for (auto& boardpass : input) {
            int row = (boardpass[0] == 'F' ? 0 : 64)
                + (boardpass[1] == 'F' ? 0 : 32)
                + (boardpass[2] == 'F' ? 0 : 16)
                + (boardpass[3] == 'F' ? 0 : 8)
                + (boardpass[4] == 'F' ? 0 : 4)
                + (boardpass[5] == 'F' ? 0 : 2)
                + (boardpass[6] == 'F' ? 0 : 1);
            int col = (boardpass[7] == 'L' ? 0 : 4)
                + (boardpass[8] == 'L' ? 0 : 2)
                + (boardpass[9] == 'L' ? 0 : 1);
            int ID = row * 8 + col;
            seatIDs.insert(ID);
        }
        return seatIDs;
    }

    int A(std::vector<std::string> input) {
        return *(GetSeatIDs(input)).rbegin();
    }

    int B(std::vector<std::string> input) {
        int currentID = A(input);
        auto seatIDs = GetSeatIDs(input);
        while (seatIDs.count(currentID)) {
            currentID--;
        }
        return currentID;
    }
}