#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
// you may include more libraries as needed

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
        //cout << "here" << endl;
        rank = stoi(rank1);

        getline(inMovies, name1, ',');
        name = name1;
        //cout << "here2" << endl;
        getline(inMovies, year1, ',');
        year = stoi(year1);
        //cout << "here3" << endl;
        getline(inMovies, rate1, '\n');
        rate = stof(rate1);
        //cout << "here4" << endl;

        mt.addMovieNode(rank, name, year, rate);
    }
  }
  string option="";
  while(option != "5")
  {
    displayMenu();
    getline(cin, option);
    switch(stoi(option))
    {
      case 1:
      {
        string enterTitle;
        cout << "Enter title:" << endl;
        getline(cin, enterTitle);
        mt.findMovie(enterTitle);
        break;
      }
      case 2:
      {
        string userRate;
        string minYear;
        cout << "Enter minimum rating:" << endl;
        getline(cin, userRate);
        cout << "Enter minimum year:" << endl;
        getline(cin, minYear);
        mt.queryMovies(stof(userRate), stoi(minYear));
        break;
      }
      case 3:
      {
        mt.printMovieInventory();
        break;
      }
      case 4:
      {
        mt.averageRating();
        break;
      }
      case 5:
      {
        cout << "Goodbye!" << endl;
      }
    }
  }

}


void displayMenu()
{
  cout << "======Main Menu======" << endl;
  cout << "1. Find a movie" << endl;
  cout << "2. Query movies" << endl;
  cout << "3. Print the inventory" << endl;
  cout << "4. Average Rating of movies" << endl;
  cout << "5. Quit" << endl;
}
