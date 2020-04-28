#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "PriorityQueue.hpp"


void displayMenu();

int main(int argc, char* argv[])
{
  int queueSSize = stoi(argv[1]);
  PriorityQueue PQ(queueSSize);

  string option = "";
  while(option != "6")
  {
    displayMenu();
    getline(cin, option);
    switch(stoi(option))
    {
      case 1:
      {
        string filename;
        ifstream inData;
        ifstream inData2;
        string line;
        cout << "Enter filename:" << endl;
        getline(cin, filename);

        inData.open(filename);
        inData2.open(filename);

        string name1 = "";
        string size1 = "";
        string time1 = "";

        string name = "";
        int size = 0;
        int time = 0;

        int countLines=0;
        if(inData2.is_open())
        {
            while(getline(inData2, line))
            {
                countLines++;
            }
        }
        if(inData.is_open())
        {
          for(int i = 0; i < countLines; i++)
          {
            if(PQ.isFull())
            {
              cout << "Heap full, cannot enqueue" << endl;
              break;
            }
            getline(inData, name1, ' ');
            name = name1;

            getline(inData, size1, ' ');
            size = stoi(size1);

            getline(inData, time1, '\n');
            time = stoi(time1);

            PQ.enqueue(name, size, time);
          }
        }
        break;
      }
      case 2:
      {
        if(PQ.isFull())
        {
          cout << "Heap full, cannot enqueue" << endl;
          break;
        }
        else
        {
          string n;
          string s;
          string t;
          cout << "Enter Group Name:" << endl;
          getline(cin, n);
          cout << "Enter Group Size:" << endl;
          getline(cin, s);
          cout << "Enter Estimated Cooking Time:" << endl;
          getline(cin, t);

          PQ.enqueue(n, stoi(s), stoi(t));
          break;
        }
      }
      case 3:
      {
        if(PQ.isEmpty())
        {
          cout << "Heap empty, nothing to peek" << endl;
          break;
        }
        else
        {
          cout << "Group Name: " << PQ.peek().groupName << endl;
          cout << "Group Size: " << PQ.peek().groupSize << endl;
          cout << "Group Time: "<< PQ.peek().cookingTime << endl;
          break;
        }
      }
      case 4:
      {
        cout << "Group Name: " << PQ.peek().groupName << " - Total Cook Time for the Group: "<< PQ.peek().cookingTime << endl;
        PQ.dequeue();
        break;
      }
      case 5:
      {
          int ttime = 0;
        if(PQ.isEmpty())
        {
          cout << "Heap empty, cannot dequeue" << endl;
          break;
        }
        else
        {
          while(!PQ.isEmpty())
          {
            ttime = ttime+PQ.peek().cookingTime;
            cout << "Group Name: " << PQ.peek().groupName << "- Total Cook Time for the Group: "<< ttime << endl;
            PQ.dequeue();
          }
          break;
        }
      }
      case 6:
      {
        cout << "Goodbye!" << endl;
      }
    }
  }
}

void displayMenu()
{
  cout << "============Main Menu============" << endl;
  cout << "1. Get group information from file" << endl;
  cout << "2. Add a group to Priority Queue" << endl;
  cout << "3. Show next group in the queue" << endl;
  cout << "4. Serve Next group" << endl;
  cout << "5. Serve Entire Queue" << endl;
  cout << "6. Quit" << endl;
}
