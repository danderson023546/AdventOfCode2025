#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>

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

    // Read each line, store the numbers each in their own vector of vectors.
    while (std::getline(file, line))
    {
        std::vector<int> bank;

        // For each char in the line, convert to an int and store in the vector.
        for (char const &c : line)
        {
            bank.push_back(c - '0');
        }

        battery_banks.push_back(bank);
    }

    int total_sum = 0;

    for (auto const bank : battery_banks)
    {
        int current_bank_sum = 0;

        // For every battery in the bank
        for (int i = 0; i < bank.size() - 1; i++)
        {
            // Compare against every other battery
            for (int j = i + 1; j < bank.size(); j++)
            {
                int joltage = bank[i] * 10 + bank[j];
                if (joltage > current_bank_sum)
                {
                    current_bank_sum = joltage;
                }
            }
        }

        total_sum += current_bank_sum;
    }

    std::cout << "Total sum: " << total_sum << std::endl;

    return 0;
}
