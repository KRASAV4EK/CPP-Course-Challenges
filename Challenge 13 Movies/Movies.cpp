#include "Movies.h"

// display all films from the collection
void Movies::display()
{
    if (movies.size() == 0)
        cout << termcolor::red << "\nYour collection is empty!\n"
             << termcolor::reset;
    else
    {
        cout << "\nYou have watched:\n";
        for (Movie mov : movies)
        {
            cout << mov.get_watched() << " times \"" << mov.get_name() 
                 << "\"  with rating \"" << mov.get_rating() << "\"" << endl;
        }
    }
}

// add film to the class
bool Movies::add_movie(string new_name, string new_rating, int new_watched)
{
    for (Movie mov : movies)
        if (mov.get_name() == new_name)
            return false;

    Movie new_movie(new_name, new_rating, new_watched);
    movies.push_back(new_movie);
    return true;
}

// add film to hte collection
void add_movie(Movies &movies)
{
    string title = get_title();

    string rating = get_rating();

    int watched = get_watched();

    // check if film already exists in list
    if (movies.add_movie(title, rating, watched))
        cout << termcolor::green << endl
             << '"' << title << "\" was added!\n"
             << termcolor::reset;
    else
        cout << termcolor::red << endl
             << '"' << title << "\" already exists!\n"
             << termcolor::reset;
}

// display watched number from certain film
void display_watched(Movies &movies)
{
    string title = get_title();
    bool flag = false;

    for (Movie mov : movies.movies)
    {
        if (mov.get_name() == title)
        {
            cout << "\nYou have watched \"" << mov.get_name() << "\" " 
                 << mov.get_watched() << " times\n";
            flag = true;
        }
    }

    if (!flag)
        cout << termcolor::red << "\nFilm \"" << title 
             << "\" was not found!\n" << termcolor::reset;

}

// display rating from certain
void display_rating(Movies &movies)
{
    int position = get_position(movies);

    if (position >= 0)
        cout << "\nFilm \"" << movies.movies.at(position).get_name()
             << "\" has rating \"" << movies.movies.at(position).get_rating() << "\"\n"; 

    else
        cout << termcolor::red << "\nFilm \"" << movies.movies.at(position).get_name() 
             << "\" was not found!\n" << termcolor::reset;

}

// display all films with certain rating
void    display_films_w_rating(Movies &movies)
{
    string rating = get_rating();
    bool flag = false;

    for (Movie mov : movies.movies)
    {
        if (mov.get_rating() == rating)
        {
            if (!flag)
                cout << "\nFilms from your collection with rating \"" << rating << "\":\n";

            cout << "\"" << mov.get_name() << "\"\n"; 
            flag = true;
        }
    }

    if (!flag)
        cout << termcolor::red << "\nFilms with rating \"" << rating
             << "\" were not found!\n" << termcolor::reset;
}

// get position in the vector from the title
int get_position(Movies &movies)
{
    int position = 0;

    string title = get_title();

    for (Movie mov : movies.movies)
    {
        if (mov.get_name() == title)
            return position;

        position += 1;
    }

    return -1;
}
