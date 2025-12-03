#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::string find_max_joltage(std::vector<int> const &bank, int const num_batteries)
{
    std::string result;
    int current_index = 0;
    int n = bank.size();

    for (int picked = 0; picked < num_batteries; picked++)
    {
        // Determine how far we're going to search based on the available batteries left to pick.
        // We can be greedy and look at more options if there's more available entries to search before
        // having to take the rest of the batteries.
        int remaining_after = num_batteries - picked - 1;
        int search_end = n - remaining_after - 1;

        // Find the maximum digit in the valid range
        int max_digit = -1;
        int max_pos = current_index;

        // Iterate over the valid range. If num_batteries is close to the bank size, this will often be a loop of 1
        for (int i = current_index; i <= search_end; i++)
        {
            if (bank[i] > max_digit)
            {
                max_digit = bank[i];
                max_pos = i;
            }
        }

        // Append the max digit to result
        result += std::to_string(max_digit);
        current_index = max_pos + 1;
    }

    return result;
}

int main()
{
    std::ifstream file("../Day3/Resources/day3.txt");
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> battery_banks;

    // Read each line, store the numbers each in their own vector
    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::vector<int> bank;
        for (char const &c : line)
        {
            bank.push_back(c - '0');
        }
        battery_banks.push_back(bank);
    }

    long long total_sum = 0;

    // For each bank, find the maximum 12-digit joltage
    for (auto const &bank : battery_banks)
    {
        std::string joltage_str = find_max_joltage(bank, 12);
        long long joltage = std::stoll(joltage_str);

        std::cout << "Bank joltage: " << joltage_str << std::endl;
        total_sum += joltage;
    }

    std::cout << "\nTotal output joltage: " << total_sum << std::endl;

    return 0;
}
