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
    std::ifstream file("../Day2/Resources/day2.txt");
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

            // Try all pattern lengths from 1 to half the string length.
            // We need at least 2 repetitions, so pattern can be at most size/2.
            for (int pattern_length = 1; (pattern_length <= number_string.size() / 2); pattern_length++)
            {
                // Check if the string length is divisible by the pattern length.
                if (number_string.size() % pattern_length == 0)
                {
                    std::string const &pattern = number_string.substr(0, pattern_length);
                    bool found_match = true;

                    // For every chunk, check to see if it matches the pattern.
                    for (int i = pattern_length; i < number_string.size(); i += pattern_length)
                    {
                        std::string const &chunk = number_string.substr(i, pattern_length);

                        // This pattern is not a full match. Move on to the next.
                        if (pattern != chunk)
                        {
                            found_match = false;
                            break;
                        }
                    }

                    // If we found a repeating pattern, add to sum and break to avoid double-counting.
                    if (found_match)
                    {
                        invalid_sum += id;
                        break; // Important: avoid counting the same number multiple times
                    }
                }
            }
        }
    }

    std::cout << "Invalid sum: " << invalid_sum << std::endl;

    return 0;
}
