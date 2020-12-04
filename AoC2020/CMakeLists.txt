# CMakeList.txt : CMake project for AoC2020, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (AoC2020 "AoC2020.cpp" "AoC2020.h" "Helpers/Helpers.cpp" "Helpers/Helpers.h" "Day1/Day1.cpp" "Day1/Day1.h" "Day2/Day2.cpp" "Day2/Day2.h" "Day3/Day3.cpp" "Day3/Day3.h" "Day4/Day4.cpp" "Day4/Day4.h")
set_property(TARGET AoC2020 PROPERTY CXX_STANDARD 17)
set_property(TARGET AoC2020 PROPERTY CXX_STANDARD_REQUIRED ON)

# Copy needed files
configure_file("Day1/Day1Input.txt" "" COPYONLY)
configure_file("Day2/Day2Input.txt" "" COPYONLY)
configure_file("Day3/Day3Input.txt" "" COPYONLY)
configure_file("Day4/Day4Input.txt" "" COPYONLY)
# TODO: Add tests and install targets if needed.
