#include <iostream>
#include "Movies.h"
#include "termcolor/termcolor.hpp"

void Movies::display()
{
    if (movies.size() == 0)
        cout << termcolor::red << "\nYour collection is empty!\n" << termcolor::reset;
    else
    {
        cout << endl;
        for (Movie mov : movies)
            cout << mov.get_name() << ' ';

        cout << endl;
    }
}

bool Movies::add_movie(string new_name, string new_rating, int new_watched)
{
    for (Movie mov : movies)
        if (mov.get_name() == new_name)
            return false;
    
    Movie new_movie(new_name, new_rating, new_watched);
    movies.push_back(new_movie);
    return true;
}