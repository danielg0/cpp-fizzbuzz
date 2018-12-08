// main.cpp - A simple fizzbuzz implementation in C++
// Copyright (C) 2018  Daniel G.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <map>
#include <string>
#include <iostream>

// Text to add to a string if n is a factor
const std::map<int, std::string> STRINGS {
    {3, "Fizz"},
    {5, "Buzz"}
};

int main(int argc, char const *argv[]) {
    // Get number to count to
    std::string input;
    if(argc == 1) {
        // Get from cin
        std::cout << "Enter Number To Count To: ";
        std::getline(std::cin, input);
    }
    else {
        // Get from command-line arg
        input = argv[1];
    }

    // Attempt to convert to int
    int N;
    try {
        N = stoi(input);
    }
    catch(const std::invalid_argument& e) {
        // Non-numerical value entered
        std::cout << "ERROR: '" << input << "' is not a valid number\n";
        return 1;
    }

    // Loop over i from {1..N}
    for(int i = 1; i <= N; ++i) {
        std::string output {""};

        // Loop through all defined strings
        for(auto j : STRINGS) {
            if(i % j.first == 0) {
                output += j.second;
            }
        }

        // Catch numbers with no divisors
        if(output == "") {
            output = std::to_string(i);
        }

        std::cout << output << "\n";
    }

    return 0;
}
