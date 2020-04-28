#include "MovieTree.hpp"
#include "MovieTree6.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void displayMenu();

int main(int argc, char* argv[])
{
  MovieTree mt;

  ifstream inMovies;
  ifstream inMovies2;

  inMovies.open(argv[1]);
  inMovies2.open(argv[1]);

  string line;

  string rank1 = "";
  string name1 = "";
  string year1 = "";
  string rate1 = "";
  int rank = 0;
  string name = "";
  int year = 0;
  float rate = 0.0;

    int countLines=0;
    if(inMovies2.is_open())
    {
        while(getline(inMovies2, line))
        {
            countLines++;
        }
    }

  if(inMovies.is_open())
  {
    for(int i =0; i < countLines; i++)
    {
        getline(inMovies, rank1, ',');

        rank = stoi(rank1);

        getline(inMovies, name1, ',');
        name = name1;

        getline(inMovies, year1, ',');
        year = stoi(year1);

        getline(inMovies, rate1, '\n');
        rate = stof(rate1);


        mt.addMovie(rank, name, year, rate);
    }
  }
  string option="";
  while(option != "3")
  {
    displayMenu();
    getline(cin, option);
    switch(stoi(option))
    {
      case 1:
      {
        mt.printMovieInventory();
        break;
      }
      case 2:
      {
        string movietit;
        cout << "Enter a movie title:" << endl;
        getline(cin, movietit);
        mt.deleteMovie(movietit);
        break;
      }
      case 3:
      {
        cout << "Goodbye!" << endl;
      }
    }
  }
}

void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Print the inventory" << endl;
  cout << "2. Delete a movie" << endl;
  cout << "3. Quit" << endl;
}
