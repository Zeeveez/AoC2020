#include "Day4.h"
#include "../Helpers/Helpers.h"
#include <map>
#include <regex>

namespace Day4 {
    std::vector<std::string> input = Helpers::ReadAllLines<std::string>("./Day4Input.txt");

    std::map<std::string, std::string> ParsePassport(std::string passport) {
        std::map<std::string, std::string> data = {};
        std::regex parseRegex("(\\w+):(#?\\w+)\\s");

        std::sregex_iterator iter(passport.begin(), passport.end(), parseRegex);
        std::sregex_iterator end;

        std::smatch matches;

        while (iter != end) {
            for (int i = 1; i < iter->size(); i++) {
                data.insert({ (*iter)[1], (*iter)[2] });
            }
            iter++;
        }
        return data;
    }

    std::vector<std::map<std::string, std::string>> ParseAllPassports(std::vector<std::string> input) {
        std::vector<std::string> required = {
            "byr",
            "iyr",
            "eyr",
            "hgt",
            "hcl",
            "ecl",
            "pid"
        };
        std::vector<std::map<std::string, std::string>> passports = {};
        std::string currentPassport;
        for (auto& line : input) {
            currentPassport += " " + line;
            if (line.length() == 0) {
                auto passport = ParsePassport(currentPassport);
                bool valid = true;
                for (auto& requirement : required) {
                    if (passport.count(requirement) == 0) {
                        valid = false;
                        break;
                    }
                }
                if (valid) { passports.push_back(passport); }
                currentPassport = "";
            }
        }
        return passports;
    }

    int A(std::vector<std::string> input) {
        return ParseAllPassports(input).size();
    }

    int B(std::vector<std::string> input) {
        auto passports = ParseAllPassports(input);
        int valid = 0;
        for (auto& passport : passports) {
            int byr = std::stoi(passport["byr"]);
            if (byr < 1920 || byr > 2002) { continue; }
            int iyr = std::stoi(passport["iyr"]);
            if (iyr < 2010 || iyr > 2020) { continue; }
            int eyr = std::stoi(passport["eyr"]);
            if (eyr < 2020 || eyr > 2030) { continue; }

            if (!(std::regex_match(passport["hgt"], std::regex("1[5-8][0-9]cm|19[0-3]cm")) || std::regex_match(passport["hgt"], std::regex("59in|6[0-9]in|7[0-6]in")))) { continue; }
            if (!std::regex_match(passport["ecl"], std::regex("amb|blu|brn|gry|grn|hzl|oth"))) { continue; }
            if (!std::regex_match(passport["hcl"], std::regex("#[0-9a-fA-F]{6}"))) { continue; }
            if (!std::regex_match(passport["pid"], std::regex("[0-9]{9}"))) { continue; }
            valid++;
        }
        return valid;
    }
}