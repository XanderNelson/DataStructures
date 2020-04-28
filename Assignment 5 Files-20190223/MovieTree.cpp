#include "MovieTree.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;


MovieTree::MovieTree()
{
  root = nullptr;
}

void destructor(MovieNode *root);
MovieTree::~MovieTree()
{
  destructor(root);
}

void destructor(MovieNode *root)
{
  if(root == nullptr)
  {
    return;
  }
  if(root->leftChild != nullptr)
  {
    destructor(root->leftChild);
  }
  if(root->rightChild != nullptr)
  {
    destructor(root->rightChild);
  }
  delete root;
}



MovieNode *MovieTree::search(string title)
{
  MovieNode *temp = root;
  while(temp != nullptr)
  {
    if(title.compare(temp->title) < 0)
    {
      temp = temp->leftChild;
    }
    else if(title.compare(temp->title) > 0)
    {
      temp = temp->rightChild;
    }
    else
    {
      break;
    }
  }
  return temp;
}

void inOrderFunc(MovieNode *top)
{
 if(top != nullptr)
 {
   inOrderFunc(top->leftChild);
   cout << "Movie: " << top->title << " " << top->rating << endl;
   inOrderFunc(top->rightChild);
}
}
void MovieTree::printMovieInventory()
{
  inOrderFunc(root);
}


void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{

  MovieNode *prev = nullptr;
  MovieNode *temp = root;
  MovieNode *newMovie = new MovieNode(ranking, title, year, rating);

  prev = temp;
  while(temp != nullptr)
  {
  prev = temp;
    if(title.compare(temp->title) < 0)
    {
      temp = temp->leftChild;
    }
    else
    {
      temp = temp->rightChild;
    }
  }
  if(prev == nullptr)
  {
    root = newMovie;
  }
  else if(title.compare(prev->title) < 0)
  {
    prev->leftChild = newMovie;
    newMovie->parent = prev;
  }
  else
  {
    prev->rightChild = newMovie;
    newMovie->parent = prev;
  }
}


void MovieTree::findMovie(string title)
{
  MovieNode *temp = root;
  while(temp!=nullptr)
  {
    if(temp->title == title)
    {
      cout << "Movie Info:" << endl;
      cout << "==================" << endl;
      cout << "Ranking:" << temp->ranking << endl;
      cout << "Title :" << temp->title << endl;
      cout << "Year :" << temp->year << endl;
      cout << "rating :" << temp->rating << endl;
      break;
    }
    else if(title.compare(temp->title) < 0)
    {
      temp = temp->leftChild;
    }
    else if(title.compare(temp->title) > 0)
    {
      temp = temp->rightChild;
    }
  }
  if(temp == nullptr)
  {
    cout << "Movie not found." << endl;
  }
}

void preOrderFunc(MovieNode *top, float rate, int year1)
{
  if(top!=nullptr)
  {
    if(top->rating >= rate && top->year > year1)
    {
      cout << top->title << "(" << top->year << ") " << top->rating << endl;
    }
    preOrderFunc(top->leftChild, rate, year1);
    preOrderFunc(top->rightChild, rate, year1);
  }
}


void MovieTree::queryMovies(float rating, int year)
{
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  preOrderFunc(root, rating, year);
}

float sum(MovieNode *root, float &count);

void average(MovieNode *root)
{
  float finalAvg = 0.0;
  float count = 0;
  float total = sum(root, count);
  finalAvg = total/count;
    cout << "Average rating:" << finalAvg << endl;
}

float sum(MovieNode *root, float& count)
{
  count++;
  float total = root->rating;
  if(root->leftChild != nullptr)
  {
    total = total + sum(root->leftChild, count);
  }
  if(root->rightChild != nullptr)
  {
    total = total + sum(root->rightChild, count);
  }
  return total;
}

void MovieTree::averageRating()
{
    if(root == nullptr)
    {
        cout << "Average rating:0" << endl;
    }
    else
    {
        average(root);
    }
}
