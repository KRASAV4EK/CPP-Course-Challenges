#include <iostream>
#include <string>
#include "termcolor/termcolor.hpp"

using namespace std;

void get_text(string *p_text);
void print_pyramid(string text);

int main()
{
    string text{};

    get_text(&text);

    print_pyramid(text);

    return 0;
}

void get_text(string *p_text)
{
    cout << "\nProgram make letter pyramid from input text\n"
         << termcolor::yellow
         << "\nEnter some text: " << termcolor::reset;

    getline(cin, (*p_text));

    cout << endl;
}

void print_pyramid(string text)
{
    size_t space_lenght{text.length()};
    unsigned let_counter{1};

    for (unsigned string = 0; string < text.length(); string++)
    {
        for (unsigned space = 0; space != space_lenght; space++)
            cout << ' ';

        space_lenght -= 1;

        for (unsigned letter = 0; letter < let_counter; letter++)
            cout << text[letter];

        for (int letter = let_counter - 2; letter != -1; letter--)
            cout << text[letter];

        let_counter += 1;

        cout << endl;
    }
    cout << endl;
}
