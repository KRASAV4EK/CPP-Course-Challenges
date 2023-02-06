#include <iostream>
#include <string>
#include <termcolor/termcolor.hpp>

using namespace std;

void get_message(string *p_message, int *p_number);
void transform_message(string *p_message, int *p_number);
void change_letter(string *p_message, int number, char biggest_let,
                   char smallest_let, int i);
void print_message(string *p_message);

int main()
{
    string message{};
    int number{};

    get_message(&message, &number);

    transform_message(&message, &number);

    print_message(&message);

    return 0;
}

void get_message(string *p_message, int *p_number)
{
    cout << termcolor::yellow << "\nEnter your secret message: " << termcolor::reset;

    getline(cin, (*p_message));

    cout << termcolor::yellow << "\nEnter the number, how much letters forward or backward you want to replace letters: " << termcolor::reset;

    while (!(cin >> (*p_number)))
    {
        cout << termcolor::red << "\nError! Enter a number: " << termcolor::reset;
        cin.clear();
        cin.ignore(123, '\n');
    }
}

void transform_message(string *p_message, int *p_number)
{
    for (unsigned i = 0; (*p_message)[i] != '\0'; i++)
    {
        if ((*p_message)[i] >= 'A' && (*p_message)[i] <= 'Z')
        {
            int number = (*p_number) % 26;

            change_letter(p_message, number, 'Z', 'A', i);
        }

        else if ((*p_message)[i] >= 'a' && (*p_message)[i] <= 'z')
        {
            int number = (*p_number) % 26;

            change_letter(p_message, number, 'z', 'a', i);
        }

        else if ((*p_message)[i] >= '0' && (*p_message)[i] <= '9')
        {
            int number = (*p_number) % 10;

            while (number > 10)
                number = (*p_number) % 10;

            change_letter(p_message, number, '9', '0', i);
        }
    }
}

void change_letter(string *p_message, int number, char biggest_let,
                   char smallest_let, int i)
{
    if (number > 0)
    {
        if ((*p_message)[i] + number > biggest_let)
        {
            number = biggest_let - (*p_message)[i];
            (*p_message)[i] = smallest_let + number;
        }
        else
            (*p_message)[i] += number;
    }

    if (number < 0)
    {
        if ((*p_message)[i] + number < smallest_let)
        {
            number = smallest_let - (*p_message)[i];
            (*p_message)[i] = biggest_let + number;
        }
        else
            (*p_message)[i] += number;
    }
}

void print_message(string *p_message)
{
    cout << termcolor::green << "\nYour coded message: "
         << termcolor::reset << (*p_message) << endl
         << endl;
}