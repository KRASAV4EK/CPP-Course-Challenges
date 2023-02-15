#include <iostream>
#include "Movies.h"
#include "termcolor/termcolor.hpp"

void display_menu();
void display_question();

char get_command();
void action_choose(string command, Movies &movies);

void add_movie(Movies &movies);
void increment_watched(Movies &movies, string name);

int main()
{
    Movies my_movies;

    display_menu();
    display_question();

    string command;
    vector<int> array = {};

    while (true)
    {
        command = get_command();
        action_choose(command, my_movies);
    }

    return 0;
}

void display_menu()
{
    cout << "\nP - Show my collection"
         << "\nA - Add the film"
         << "\nM - Display the menu"
         << "\nQ - Quit\n";
}

void display_question()
{
    cout << "\nEnter your choice: ";
}

char get_command()
{
    char command;
    cin >> command;
    return command;
}

void action_choose(string command, Movies &movies)
{
    switch (command[0])
    {
    case 'P':
    case 'p':
        movies.display();
        break;

    case 'A':
    case 'a':
        add_movie(movies);
        break;

    case 'M':
    case 'm':
        display_menu();
        break;

    case 'Q':
    case 'q':
        cout << "\nGoodbye!\n\n";
        exit(0);

    default:
        cout << termcolor::red << "\nWrong command!\n"
             << termcolor::reset;
        break;
    }

    display_question();
}

void add_movie(Movies &movies)
{
    cin.clear();
    cout << termcolor::yellow << "\nEnter film title: " << termcolor::reset;
    string name;
    getline(cin, name);

    cout << termcolor::yellow << "\nEnter film rating(G, PG, PG-13, R): " << termcolor::reset;
    string rating;
    getline(cin, rating);

    cout << termcolor::yellow << "\nEnter number you have watched this film: " << termcolor::reset;
    unsigned watched;
    while (!(cin >> watched))
    {
        cout << termcolor::red << "\nError! Enter a number: " << termcolor::reset;
        cin.clear();
        cin.ignore(123, '\n');
    }

    if (movies.add_movie(name, rating, watched))
        cout << termcolor::green << endl
             << '"' << name << "\" was added!\n"
             << termcolor::reset;
    else
        cout << termcolor::red << endl
             << '"' << name << "\" already exists!\n"
             << termcolor::reset;
}

void increment_watched(Movies &movies, string name)
{
}