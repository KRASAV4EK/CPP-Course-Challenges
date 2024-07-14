// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>

int main() {
    std::fstream file {"Challenge 19 IO and Streams/Challenge_3/romeoandjuliet.txt", std::ios::in};
    if (!file) {
        std::cerr << "File was not found! Terminating..." << std::endl;
        return 1;
    }

    std::string sub_str{};

    {
        std::cout << "Enter the substring to search for: ";
        std::cin >> sub_str;
        if (sub_str.size() == 0) {
            std::cerr << "Nothing was provided! Terminating..." << std::endl;
            return 2;
        }
    }

    std::string temp{};
    int word_counter {0};
    int found_counter {0};

    while (!file.eof()) {
        file >> temp;

        if (temp.find(sub_str) != std::string::npos) {
            found_counter++;
        }

        word_counter++;
    }

    file.close();

    std::cout << word_counter << " words were searched..." << std::endl;
    std::cout << "The substring '" << sub_str << "' was found " << found_counter << " times." << std::endl;

    return 0;
}

