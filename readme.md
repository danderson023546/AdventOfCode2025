# Advent of Code 2025

Repository to store/share AoC 2025 challenge solutions.

## Day 1

Basic solution for the day 1 challenge.

### Part 1

1. Read file in line-by-line.
2. Substring each line to get the numbers after the first character.
3. Convert substrings to integers.
4. Store the integers in a list, positive if starting with 'R', negative if starting with 'L'.
5. Loop through all numbers, adding to the starting position % 100.
6. Count number of times 0 is the result after addition.

### Part 2

1. Read similarly as part 1.
2. Instead of adding the entire number, track the number of additions that must be done based on the numbers read in.
3. Perform additions as increments, checking to see each time if 0 is the result.
4. Count the number of times 0 is the result after any addition.
