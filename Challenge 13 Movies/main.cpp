#include "Movies.h"

void display_menu();
void display_question();

char get_command();
void action_choose(string command, Movies &movies_list);

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
         << "\nA - Add the film\n"
         << "\nR - Change rating of the film "
         << "\nT - Change title of the film "
         << "\nW - Change watched number of the film \n"
         << "\nZ - Display watched number from film's title"
         << "\nX - Display rating from film's title"
         << "\nC - Display films with certain rating\n"
         << "\nD - Delete my collection"
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

void action_choose(string command, Movies &movies_list)
{
    switch (command[0])
    {
    case 'P': // show collection
    case 'p':
        movies_list.display();
        break;

    case 'A': // add the film
    case 'a':
        add_movie(movies_list);
        break;

    case 'R': // change rating
    case 'r':
        movies_list.movies.at(get_position(movies_list)).set_rating(get_rating());
        cout << termcolor::green << "\nRating was changed!\n" << termcolor::reset;
        break;

    case 'T': // change title
    case 't':
        movies_list.movies.at(get_position(movies_list)).set_name(get_title());
        cout << termcolor::green << "\nTitle was changed!\n" << termcolor::reset;
        break;

    case 'W': // change watched
    case 'w':
        movies_list.movies.at(get_position(movies_list)).set_watched(get_watched());
        cout << termcolor::green << "\nNumber was changed!\n" << termcolor::reset;
        break;

    case 'Z': // display watched
    case 'z':
        display_watched(movies_list);
        break;

    case 'X': // display rating
    case 'x':
        display_rating(movies_list);
        break;

    case 'C': // display films with certain rating
    case 'c':
        display_films_w_rating(movies_list);
        break;

    case 'D': // delete collection
    case 'd':
        cout << termcolor::green << "\nCollection was successfully deleted!\n" << termcolor::reset;
        movies_list.movies.clear();
        break;

    case 'M': // display menu
    case 'm':
        display_menu();
        break;

    case 'Q': // quit
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
