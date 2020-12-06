#include "Helpers.h"

namespace Helpers {
    std::vector<std::vector<std::string>> SeparateDatasets(std::vector<std::string> input) {
        std::vector<std::vector<std::string>> dataSets = {};
        std::vector<std::string> dataSet = {};
        for (auto& line : input) {
            if (line.length() == 0) {
                dataSets.push_back(dataSet);
                dataSet = {};
            } else {
                dataSet.push_back(line);
            }
        }
        if (dataSet.size() != 0) {
            dataSets.push_back(dataSet);
        }
        return dataSets;
    }
}