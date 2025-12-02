#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

struct ProductIdRange
{
    long long LowerID = 0;
    long long UpperID = 0;
};

int main()
{
    std::ifstream file("../Day2/Resources/day2_part1.txt");
    std::vector<ProductIdRange> product_ranges;
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // Read the entire large line.
    while (std::getline(file, line))
    {
        std::stringstream line_stream(line);
        std::string range_string;

        // Reach each comma-separated range.
        while (std::getline(line_stream, range_string, ','))
        {
            // Find the dash position, dependent on size of the numbers.
            uint64_t const dash_pos = range_string.find('-');

            if (dash_pos != std::string::npos)
            {
                // Extract the lower and upper bounds as substrings.
                std::string lower_str = range_string.substr(0, dash_pos);
                std::string upper_str = range_string.substr(dash_pos + 1);

                // Convert the substrings to integers and create the range entry.
                ProductIdRange range = { std::stoll(lower_str), std::stoll(upper_str) };
                product_ranges.push_back(range);
            }
        }
    }

    long long invalid_sum = 0;

    // Check every range pair.
    for (ProductIdRange const &range : product_ranges )
    {
        // In each pair, iterate over every possible number combination
        for (long long id = range.LowerID; id <= range.UpperID; id++)
        {
            // Convert back into a string. (Yes I realize I am probably wasting a load of time.)
            std::string const number_string = std::to_string(id);

            // If the current string is not an even number, it's impossible to have a repeating set of digits. Skip.
            // This also makes my divide below need no rounding. :)
            if (number_string.size() % 2 != 0)
            {
                continue;
            }

            // Try all pattern lengths from 1 to half the string length.
            for (int pattern_length = 1; (pattern_length <= number_string.size() / 2); pattern_length++)
            {
                std::string const &pattern = number_string.substr(0, pattern_length);
                std::string const &remainder = number_string.substr(pattern_length);

                // If they match, it's invalid.
                if (pattern == remainder)
                {
                    invalid_sum += id;
                }
            }
        }
    }

    std::cout << "Invalid sum: " << invalid_sum << std::endl;

    return 0;
}
