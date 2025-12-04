#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

int main()
{
    std::ifstream file("../Day4/Resources/day4.txt");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::string> paper_roll_grid;

    // Read each line, store the string in a list of strings.
    while (std::getline(file, line))
    {
        paper_roll_grid.push_back(line);
    }

    for (auto const &line : paper_roll_grid)
    {
        std::cout << line << std::endl;
    }

    std::cout << "\nLoaded " << paper_roll_grid.size() << " lines.\n" << std::endl;

    int total_valid_rolls = 0;
    int const adjacent_offsets[3] = {-1, 0, 1};

    for (int line_index = 0; line_index < paper_roll_grid.size(); line_index++)
    {
        // Grab the current line, as well as the previous and next if available. If they are not available (e.g., edge cases), create empty lines of the same length.
        std::string previous_line = "";
        auto &current_line = paper_roll_grid[line_index];
        std::string next_line = "";

        if (line_index > 0)
        {
            previous_line = paper_roll_grid[line_index - 1];
        }
        else
        {
            previous_line.resize(current_line.size(), '.');
        }

        if (line_index < paper_roll_grid.size() - 1)
        {
            next_line = paper_roll_grid[line_index + 1];
        }
        else
        {
            next_line.resize(current_line.size(), '.');
        }

        for (int char_index = 0; char_index < current_line.size(); char_index++)
        {
            // Track the number of adjacent rolls.
            int adjacent_roll_count = 0;

            if (current_line[char_index] == '@')
            {
                // First, check on the current line.
                for (int offset : adjacent_offsets)
                {
                    // If the offset is within the bounds on the line
                    if (char_index + offset >= 0 && char_index + offset < current_line.size())
                    {
                        if (current_line[char_index + offset] == '@')
                        {
                            if (offset != 0) // Exclude self
                            {
                                adjacent_roll_count++;
                            }
                        }
                    }
                }

                // Now check the previous line.
                for (int offset : adjacent_offsets)
                {
                    // If the offset is within the bounds on the line
                    if (char_index + offset >= 0 && char_index + offset < previous_line.size())
                    {
                        if (previous_line[char_index + offset] == '@')
                        {
                            adjacent_roll_count++;
                        }
                    }
                }

                // Now check the next line.
                for (int offset : adjacent_offsets)
                {
                    // If the offset is within the bounds on the line
                    if (char_index + offset >= 0 && char_index + offset < next_line.size())
                    {
                        if (next_line[char_index + offset] == '@')
                        {
                            adjacent_roll_count++;
                        }
                    }
                }

                if (adjacent_roll_count < 4U)
                {
                    total_valid_rolls++;
                }
            }
        }
    }

    for (auto const &line : paper_roll_grid)
    {
        std::cout << line << std::endl;
    }

    std::cout << "Total valid rolls: " << total_valid_rolls << std::endl;

    return 0;
}
