#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>
#include <set>

int main()
{
    std::ifstream file("../Day5/Resources/day5.txt");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::pair<long long, long long>> ranges;

    // Read ID ranges until blank line
    while (std::getline(file, line) && !line.empty())
    {
        long long first, second;
        char dash;
        std::istringstream iss(line);
        iss >> first >> dash >> second;
        ranges.emplace_back(first, second);
    }

    // Sort the ranges based on where they start.
    std::ranges::sort(ranges);

    std::vector<std::pair<long long, long long>> merged;
    for (auto const &range : ranges)
    {
        if (merged.empty() || range.first > merged.back().second + 1)
        {
            // There is no overlap between the start of this range and the end of the previous, or it's the first
            merged.push_back(range);
        }
        else
        {
            // There is an overlap, so extend the current range based on the larger end.
            merged.back().second = std::max(merged.back().second, range.second);
        }
    }

    // Now just iterate over the merged list and add 'em up.
    long long total = 0;
    for (auto const &range : merged)
    {
        total += range.second - range.first + 1;
    }

    std::cout << total << std::endl;

    return 0;
}
