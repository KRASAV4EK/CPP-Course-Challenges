#include "Movie.h"

Movie::Movie(string new_name, string new_rating, int new_watched)
    : name{new_name}, rating{new_rating}, watched{new_watched} {}

// get title from class
string Movie::get_name() const {return name;}
// get rating from class
string Movie::get_rating() const {return rating;}
// get watched from class
int Movie::get_watched() const {return watched;}

void Movie::set_name(string new_name) {name = new_name;}
void Movie::set_rating(string new_rating) {rating = new_rating;}
void Movie::set_watched(int new_watched) {watched = new_watched;}

// get title from input
string get_title() 
{
    cin.clear();
    cin.ignore(123, '\n');
    cout << termcolor::yellow << "\nEnter film title: " << termcolor::reset;
    string name;
    getline(cin, name);
    return name;
}

// get rating from input
string get_rating() 
{
    cout << termcolor::yellow << "\nEnter film rating(G, PG, PG-13, R): " << termcolor::reset;
    string rating;
    while (!(cin >> rating) || (rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R" &&
                                rating != "g" && rating != "pg" && rating != "pg-13" && rating != "r"))
    {
        cout << termcolor::red << "\nError! Enter G or PG, or PG-13, or R: " << termcolor::reset;
        cin.clear();
        cin.ignore(123, '\n');
    }
    transform(rating.begin(), rating.end(), rating.begin(), ::toupper);
    return rating;
}

// get watched from input
int get_watched() 
{
    // get watched number
    cout << termcolor::yellow << "\nEnter number you have watched this film: " << termcolor::reset;
    int watched;
    while (!(cin >> watched) || watched < 0)
    {
        cout << termcolor::red << "\nError! Enter a positive number: " << termcolor::reset;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return watched;
}
