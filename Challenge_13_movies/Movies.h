#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include "Movie.h"

class Movies
{
private:
    vector<Movie> movies;

public:
    void display();
    bool add_movie(string new_name, string new_rating, int new_watched);

    // Class Constructors
    Movies(){};
    ~Movies(){};
};

#endif //_MOVIES_H_