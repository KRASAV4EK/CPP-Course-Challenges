// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::fstream input_file {"Challenge 19 IO and Streams/Challenge_4/romeoandjuliet.txt", std::ios::in};
    std::fstream output_file {"Challenge 19 IO and Streams/Challenge_4/out.txt", std::ios::out};
    if (!input_file || !output_file) {
        std::cerr << "Input file was not found! Terminating..." << std::endl;
        return 1;
    }

    std::string temp {};
    int str_counter {1};

    while (getline(input_file, temp)) {
        output_file << std::setw(8) << std::left << str_counter++ << temp << std::endl;
    }

    input_file.close();
    output_file.close();

    std::cout << std::endl << "Copy completed successfully!" << std::endl;
    
    return 0;
}

