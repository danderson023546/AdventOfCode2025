#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream file("../Day1/Resources/day1.txt");
    std::vector<int> numbers;
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            char direction = line[0];
            std::string number_str = line.substr(1, line.size() - 1);
            int number = std::stoi(number_str);

            if (direction == 'L')
            {
                numbers.push_back(-number);
            }
            else if (direction == 'R')
            {
                numbers.push_back(number);
            }
        }
    }

    file.close();

    int position = 50;
    int answer = 0;
    for (int number : numbers)
    {
        int adjustments = std::abs(number);
        int adjustment = (number > 0) ? 1 : -1;

        while (adjustments > 0)
        {
            if (((position += adjustment) % 100) == 0)
            {
                answer++;
            }

            adjustments--;
        }
    }

    std::cout << "Answer: " << answer << std::endl;

    return 0;
}
