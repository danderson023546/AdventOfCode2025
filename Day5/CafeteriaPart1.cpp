#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

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
    std::vector<long long> ingredients;

    // Read ID ranges until blank line
    while (std::getline(file, line) && !line.empty())
    {
        long long first, second;
        char dash;
        std::istringstream iss(line);
        iss >> first >> dash >> second;
        ranges.emplace_back(first, second);
    }

    // Read ingredients
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            ingredients.push_back(std::stoll(line));
        }
    }

    long long fresh_ingredients = 0;
    for (auto const &ingredient : ingredients)
    {
        // Check to see if the ingredient is in a range.
        for (auto const &range : ranges)
        {
            if (ingredient >= range.first && ingredient <= range.second)
            {
                // Break if we find a match, don't double count;
                fresh_ingredients++;
                break;
            }
        }
    }

    std::cout << fresh_ingredients << std::endl;

    return 0;
}
