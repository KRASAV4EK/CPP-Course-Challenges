// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct Student {
    std::string name;
    std::string answers;
    int points {0};
};

int main() {
    std::fstream file {"Challenge 19 IO and Streams/Challenge_2/responses.txt", std::ios::in};

    if (!file) {
        std::cerr << "File was not found! Terminating..." << std::endl;
        return 1;
    }

    std::vector<Student> students{};
    std::string right_answers{};

    file >> right_answers;
    std::cout << "Right answers: " << right_answers << std::endl;


    Student student{};
    while (!file.eof()) {
        file >> student.name;
        file >> student.answers;
        students.push_back(student);
    }

    int k;
    float avg {0};

    for (auto &human : students) {
        k = 0;
        for (char c : human.answers) {
            if (c == right_answers[k++]) {
                human.points++;
            }
        }
        avg += human.points;
    }

    avg = avg / students.size();

    file.close();

    { // Output window
        std::cout << std::endl << "+";
        for (int i = 0; i < 28; i++) std::cout << "=";
        std::cout << "+" << std::endl;

        std::cout << "|Student" << std::setw(22) << std::right << "Score|" << std::endl;

        std::cout << "|";
        for (int i = 0; i < 28; i++) std::cout << "-";
        std::cout << "|" << std::endl;

        for (Student person : students) {
            std::cout << "|" << std::setw(27) << std::left << person.name << person.points << "|" << std::endl;
        }

        std::cout << "+";
        for (int i = 0; i < 28; i++) std::cout << "=";
        std::cout << "+" << std::endl;

        std::cout << std::endl << "Average score: " << avg << std::endl;
    }

    return 0;
}

