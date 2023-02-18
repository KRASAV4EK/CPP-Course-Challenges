#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include "Movie.h"

class Movies
{
public:
    vector<Movie> movies;
    void display();
    bool add_movie(string new_name, string new_rating, int new_watched);
    int get_size() {return movies.size();}

    // Class Constructors
    Movies(){};
    ~Movies(){};
};

void add_movie(Movies &movies);

void display_watched(Movies &movies);
void display_rating(Movies &movies);
void display_films_w_rating(Movies &movies);

int get_position(Movies &movies);

#endif //_MOVIES_H_