cmake_minimum_required(VERSION 4.0)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(Day1 Day1/SafeCodeFinder.cpp)

add_executable(Day2_Part1 Day2/GiftShopPart1.cpp)
add_executable(Day2_Part2 Day2/GiftShopPart2.cpp)

add_executable(Day3_Part1 Day3/LobbyPart1.cpp)
add_executable(Day3_Part2 Day3/LobbyPart2.cpp)

add_executable(Day4_Part1 Day4/PrintingDepartmentPart1.cpp)
add_executable(Day4_Part2 Day4/PrintingDepartmentPart2.cpp)
