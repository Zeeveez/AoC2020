# CMakeList.txt : CMake project for AoC2020, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (AoC2020 "AoC2020.cpp" "AoC2020.h" "Helpers/Helpers.cpp" "Helpers/Helpers.h" "Day01/Day01.cpp" "Day01/Day01.h" "Day02/Day02.cpp" "Day02/Day02.h" "Day03/Day03.cpp" "Day03/Day03.h" "Day04/Day04.cpp" "Day04/Day04.h" "Day05/Day05.cpp" "Day05/Day05.h")
set_property(TARGET AoC2020 PROPERTY CXX_STANDARD 17)
set_property(TARGET AoC2020 PROPERTY CXX_STANDARD_REQUIRED ON)

# Copy needed files
configure_file("Day01/Day01Input.txt" "" COPYONLY)
configure_file("Day02/Day02Input.txt" "" COPYONLY)
configure_file("Day03/Day03Input.txt" "" COPYONLY)
configure_file("Day04/Day04Input.txt" "" COPYONLY)
configure_file("Day05/Day05Input.txt" "" COPYONLY)
# TODO: Add tests and install targets if needed.
