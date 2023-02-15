#include "Movie.h"

Movie::Movie(string new_name, string new_rating, int new_watched)
{
    set_name(new_name);
    set_rating(new_rating);
    set_watched(new_watched);
}

string Movie::get_name() const {return name;}
string Movie::get_rating() const {return rating;}
int Movie::get_watched() const {return watched;}

void Movie::set_name(string new_name) {name = new_name;}
void Movie::set_rating(string new_rating) {rating = new_rating;}
void Movie::set_watched(int new_watched) {watched = new_watched;}

