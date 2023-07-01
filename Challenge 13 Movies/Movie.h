#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "termcolor/termcolor.hpp"

using namespace std;

string get_title();
string get_rating();
int get_watched();

class Movie
{
private:
    string name;
    string rating; // G PG PG-13 R
    int watched = 1;

public:
    string get_name() const;
    string get_rating() const;
    int get_watched() const;

    void set_name(string new_name);
    void set_rating(string new_rating);
    void set_watched(int new_watched);

    // Class Constructors
    Movie(string new_name, string new_rating, int new_watched);
    ~Movie(){};
};

#endif //_MOVIE_H_