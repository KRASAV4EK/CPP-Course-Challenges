#include <iostream>
#include <vector>
#include "termcolor/termcolor.hpp"
#include <string>

using namespace std;

void display_menu();
void display_question();

char get_command();
void action_choose(string command, vector<int> *array);

void numbers_print(vector<int> *array);
void numbers_add(vector<int> *array);
void numbers_mean(vector<int> *array);
void numbers_smallest(vector<int> *array);
void numbers_largest(vector<int> *array);

void numbers_search(vector<int> *array);
void clear_list(vector<int> *array);

int main()
{
  display_menu();
  display_question();

  string command;
  vector<int> array = {};

  while (true)
  {
    command = get_command();
    action_choose(command, &array);
  }
}

void display_menu()
{
  cout << "\nP - Print numbers"
       << "\nA - Add a number"
       << "\nM - Display mean of the numbers"
       << "\nS - Display the smallest number"
       << "\nL - Display the largest number"
       << "\nF - Search a number in the list, displays number of times it occurs"
       << "\nD - Delete all numbers"
       << "\nZ - Display the menu"
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

void action_choose(string command, vector<int> *array)
{
  switch (command[0])
  {
  case 'P':
  case 'p':
    numbers_print(array);
    break;

  case 'A':
  case 'a':
    numbers_add(array);
    break;

  case 'M':
  case 'm':
    numbers_mean(array);
    break;

  case 'S':
  case 's':
    numbers_smallest(array);
    break;

  case 'L':
  case 'l':
    numbers_largest(array);
    break;

  case 'F':
  case 'f':
    numbers_search(array);
    break;

  case 'D':
  case 'd':
    clear_list(array);
    break;

  case 'Z':
  case 'z':
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

void numbers_print(vector<int> *array)
{
  if ((*array).size() == 0)
    cout << termcolor::red << "\n[] - the list is empty\n"
         << termcolor::reset;

  else
  {
    cout << termcolor::green << "\n[ ";
    for (int number : (*array))
      cout << number << " ";
    cout << "]\n"
         << termcolor::reset;
  }
}

void numbers_add(vector<int> *array)
{
  int new_number;
  bool in_list = false;

  cout << termcolor::yellow << "\nEnter a number: " << termcolor::reset;
  while (!(cin >> new_number))
  {
    cout << termcolor::red << "\nError! Enter a number: " << termcolor::reset;
    cin.clear();
    cin.ignore(123, '\n');
  }

  for (int number : (*array))
  {
    if (new_number == number)
    {
      cout << termcolor::red << "\nError! Number was already added!\n"
           << termcolor::reset;
      numbers_add(array);
      in_list = true;
    }
  }
  if (!in_list)
  {
    (*array).push_back(new_number);
    cout << endl
         << termcolor::green << new_number << " was added succesfully!\n"
         << termcolor::reset;
  }
}

void numbers_mean(vector<int> *array)
{
  if ((*array).size() == 0)
    cout << termcolor::red << "\nUnable to calculate the mean - no data\n"
         << termcolor::reset;

  else
  {
    int sum = 0;
    for (int number : (*array))
      sum += number;
    double mean = double(sum) / (*array).size();
    cout << "Mean is: " << mean << endl;
  }
}

void numbers_smallest(vector<int> *array)
{
  if ((*array).size() == 0)
    cout << termcolor::red << "\nUnable to detemine the smallest number - list is empty\n"
         << termcolor::reset;

  else
  {
    int result = (*array)[0];
    for (int number : (*array))
      if (number < result)
        result = number;
    cout << termcolor::green << "\nThe smallest number is " << result
         << termcolor::reset << endl;
  }
}

void numbers_largest(vector<int> *array)
{
  if ((*array).size() == 0)
    cout << termcolor::red << "\nUnable to detemine the largest number - list is empty\n"
         << termcolor::reset;

  else
  {
    int result = (*array)[0];
    for (int number : (*array))
      if (number > result)
        result = number;
    cout << termcolor::green << "\nThe largest number is " << result
         << termcolor::reset << endl;
  }
}

void numbers_search(vector<int> *array)
{
  unsigned counter = 0;
  int n;

  cout << termcolor::yellow << "\nEnter the number, which you want to find: "
       << termcolor::reset;
  while (!(cin >> n))
  {
    cout << termcolor::red << "\nError! Enter a number: " << termcolor::reset;
    cin.clear();
    cin.ignore(123, '\n');
  }

  for (int number : (*array))
  {
    if (n == number)
      counter += 1;
  }

  if (counter == 0)
    cout << termcolor::red << "Can't find " << n << " in list\n"
         << termcolor::reset;

  else
    cout << termcolor::green << "\nNumber " << n << " occurs in list "
         << counter << " times\n"
         << termcolor::reset;
}

void clear_list(vector<int> *array)
{
  (*array).clear();
  cout << termcolor::green << "\nList was deleted successfully\n"
       << termcolor::reset;
}
