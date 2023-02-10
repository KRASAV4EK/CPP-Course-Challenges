#include <iostream>
#include <string>
#include <vector>
#include "termcolor/termcolor.hpp"

using namespace std;

void get_array(int *(&p_array), unsigned &size);
void create_third_array(int *(&p_array1), unsigned &size1, int *(&p_array2), 
                        unsigned &size2, int *(&p_array3));
void display_info(int *(&p_array1), unsigned &size1, int *(&p_array2), 
                  unsigned &size2, int *(&p_array3));

int main()
{
    cout << termcolor::bright_cyan << "\nProgram makes from 2 arrays 1 array with some attributes\n"
         << termcolor::reset;

    cout << termcolor::yellow << "\nEnter size of first array: " << termcolor::reset;
    int *p_array1 = nullptr;
    unsigned size_1;
    get_array(p_array1, size_1); // create & fill first array

    cout << termcolor::yellow << "\nEnter size of second array: " << termcolor::reset;
    int *p_array2 = nullptr;
    unsigned size_2;
    get_array(p_array2, size_2); // create & fill second array

    // create third array from two previous
    int *p_array3 = nullptr;
    create_third_array(p_array1, size_1, p_array2, size_2, p_array3);

    display_info(p_array1, size_1, p_array2, size_2, p_array3);

    return 0;
}

// create array with given size and fill with given numbers
void get_array(int *(&p_array), unsigned &size)
{
    // get size of the array
    while (!(cin >> size) || size <= 0)
    {
        cout << termcolor::red << "\nError! Enter a positive number: " << termcolor::reset;
        cin.clear();
        cin.ignore(123, '\n');
    }

    // create the array
    p_array = new int [size];
    if (p_array)
        cout << termcolor::green << "\nArray with size " << size 
             << " was successfully created!\n" << termcolor::reset;
    else
    {
        cout << termcolor::red << "\nError! Array wasn't created! Exit..." << termcolor::reset;
        exit(1);
    }

    // fill array with input numbers
    for (unsigned i = 0; i < size; i++)
    {
        cout << termcolor::yellow << "\nEnter " << i + 1 << " element of array: " 
             << termcolor::reset;
        
        while (!(cin >> p_array[i]))
        {
            cout << termcolor::red << "\nError! Enter a number: " << termcolor::reset;
            cin.clear();
            cin.ignore(123, '\n');
        }
    }

    cout << termcolor::green << "\nArray with size " << size 
         << " was successfully filled!\n" << termcolor::reset;
}

// create third array from two given 
void create_third_array(int *(&p_array1), unsigned &size1, int *(&p_array2), 
                        unsigned &size2, int *(&p_array3))
{
    p_array3 = new int [size1 * size2];

    if (p_array3)
        cout << termcolor::green << "\nThird array with size " << size1 * size2 
             << " was successfully created!\n" << termcolor::reset;
    else
    {
        cout << termcolor::red << "\nError! Array wasn't created! Exit..." << termcolor::reset;
        exit(1);
    }

    unsigned counter3 = 0;

    // fill third array with multiplication each element of second array 
    // and each element of first array
    for (unsigned count_2  = 0; count_2 < size2; count_2++)
    {
        for (unsigned count_1  = 0; count_1 < size1; count_1++)
        {
            p_array3[counter3] = p_array1[count_1] * p_array2[count_2];
            counter3 += 1;
        }
    }
}

// display all needable information
void display_info(int *(&p_array1), unsigned &size1, int *(&p_array2), 
                  unsigned &size2, int *(&p_array3))
{
    cout << "\nFirst array: [ ";
    for (unsigned i = 0; i < size1; i++)
        cout << p_array1[i] << ' ';
    cout << "]\n";

    cout << "\nSecond array: [ ";
    for (unsigned i = 0; i < size2; i++)
        cout << p_array2[i] << ' ';
    cout << "]\n";

    cout << "\nResult: [ ";
    for (unsigned i = 0; i < size1 * size2; i++)
        cout << p_array3[i] << ' ';
    cout << "]\n";
}
