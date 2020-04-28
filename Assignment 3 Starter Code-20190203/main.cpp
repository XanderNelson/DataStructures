/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;




void displayMenu();

int main(int argc, char* argv[])
{
  CountryNetwork opt;
  string option;
  while(option != "8")
  {

  displayMenu();
  getline(cin, option);
  switch(stoi(option))
  {
  case 1:
  {
    opt.loadDefaultSetup();
    opt.printPath();
    break;
  }
  case 2:
  {
    opt.printPath();
    //displayMenu();
    break;
  }
  case 3:
  {
    string message;
    string country;
    cout << "Enter name of the country to receive the message:" << endl;
    getline(cin, country);
    cout << "Enter the message to send:" << endl;
    cout << endl;
    getline(cin, message);
    opt.transmitMsg(country, message);
    break;
    //displayMenu();
  }
  case 4:
  {
      string prev;
      string insertC;
      cout << "Enter a new country name:" << endl;
      getline(cin, insertC);
      cout << "Enter the previous country name (or First):" << endl;
      getline(cin, prev);

     while(opt.searchNetwork(prev) == NULL && prev != "First" && prev != "first")
      {
        cout << "INVALID country...Please enter a VALID previous country name:" << endl;
        getline(cin, prev);
        //break;
      }
      if(prev == "First" || prev == "first")
      {
        opt.insertCountry(NULL, insertC);
        opt.printPath();
      }
      if(opt.searchNetwork(prev) != NULL)
      {
        opt.insertCountry(opt.searchNetwork(prev), insertC);
        opt.printPath();
      }
      //displayMenu();
      break;
  }
  case 5:
  {
    string cName;
    cout << "Enter a country name:" << endl;
    getline(cin, cName);
    opt.deleteCountry(cName);
    opt.printPath();
    break;
  }
  case 6:
  {
    opt.reverseEntireNetwork();
    opt.printPath();
    //displayMenu();
    break;
  }
  case 7:
  {
    opt.deleteEntireNetwork();
    //displayMenu();
    break;
  }
  case 8:
  {
    cout << "Quitting... cleaning up path: " << endl;

    opt.printPath();
    if(opt.isEmpty()==false)
    {
    opt.deleteEntireNetwork();
    if(opt.isEmpty() == true)
    {
      cout << "Path cleaned" << endl;
    }
    else
    {
      cout << "Error: Path NOT cleaned" << endl;
    }
    }
    else
    {
        cout << "Path cleaned" << endl;
    }
    cout << "Goodbye!" << endl;
    break;
  }
   }
  }
}

/*
 * Purpose: displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Delete Country " << endl;
    cout << " 6. Reverse Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

// main and any other functions from main.cpp go here



// #include "CountryNetwork.hpp"
// #include <iostream>
// #include <cstdlib>
// // add any other includes you need that aren't already included in CountryNetwork.hpp
//
// using namespace std;
//
// // implementation of class functions goes here
// CountryNetwork::CountryNetwork()
// {
//   head = nullptr;
// }
//
//
// /*
//  * Purpose: Check if list is empty
//  * @return true if empty; else false
//  */
// bool CountryNetwork::isEmpty()
// {
//   if(head == nullptr)
//   {
//     return true;
//   }
//   else
//   {
//     return false;
//   }
// }
//
//
// /*
//  * Purpose: Add a new Country to the network
//  *   between the Country *previous and the Country that follows it in the network.
//  * @param previous name of the Country that comes before the new Country
//  * @param countryName name of the new Country
//  * @return none
//  */
//  void CountryNetwork::insertCountry(Country* previous, string countryName)
//  {
//
//    if(previous == NULL)
//    {
//      Country *temp = new Country;
//      temp->name = countryName;
//      temp->next = head;
//      head=temp;
//      temp = nullptr;
//      cout << "adding: " << countryName << " (HEAD)" << endl;
//    }
//    else
//    {
//      Country *last = previous;
//        if(last == nullptr)
//        {
//         cout << "Country not found" << endl;
//       }
//
//       else
//       {
//         Country *temp = new Country;
//         temp -> name = countryName;
//         temp -> next = previous->next;
//         previous->next = temp;
//         temp = nullptr;
//         cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
//       }
//      }
//    }
//
//
// /*
//  * Purpose: delete the country in the network with the specified name.
//  * @param countryName name of the country to delete in the network
//  * @return none
//  */
//  void CountryNetwork::deleteCountry(string countryName)
//  {
//      if(searchNetwork(countryName) != nullptr)
//      {
//        Country *temp = head;
//        if(temp->name == countryName)
//        {
//            head->name = head->next->name;
//            temp = head->next;
//            head->next = head->next->next;
//        }
//        else
//        {
//        while(temp->next != nullptr && temp->next->name != countryName)
//        {
//          temp = temp -> next;
//        }
//        temp -> next = temp -> next -> next;
//        }
//      }
//      else
//      {
//      cout << "Country does not exist." << endl;
//      }
//  }
//
//
// /*
//  * Purpose: populates the network with the predetermined countries
//  * @param none
//  * @return none
//  */
//  void CountryNetwork::loadDefaultSetup()
//  {
//    //deleteEntireNetwork();
//    insertCountry(head, "United States");
//    insertCountry(head, "Canada");
//    insertCountry(head->next, "Brazil");
//    insertCountry(head->next->next, "India");
//    insertCountry(head->next->next->next, "China");
//    insertCountry(head->next->next->next->next, "Australia");
//  }
//
//
// /*
//  * Purpose: Search the network for the specified country and return a pointer to that node
//  * @param countryName name of the country to look for in network
//  * @return pointer to node of countryName, or NULL if not found
//  * @see insertCountry, deletecountry
//  */
//  Country* CountryNetwork::searchNetwork(string countryName)
//  {
//    Country *returnNode = nullptr;
//    Country *temp = head;
//
//    bool found = false;
//    while(!found && temp != nullptr)
//    {
//      if(temp->name == countryName)
//      {
//        found = true;
//        returnNode = temp;
//      }
//      else
//      {
//        temp = temp->next;
//      }
//    }
//    return returnNode;
//  }
//
//
// /*
//  * Purpose: deletes all countries in the network starting at the head country.
//  * @param none
//  * @return none
//  */
//  void CountryNetwork::deleteEntireNetwork()
//  {
//    Country* current = head;
//    Country* temp;
//    while(current != NULL)
//    {
//      temp = current;
//      current = current->next;
//      cout << "deleting: " << temp->name << endl;
//      free(temp);
//    }
//    cout << "Deleted network" << endl;
//    head = nullptr;
//  }
//
//
// /*
//  * Purpose: Transmit a message across the network to the
//  *   receiver. Msg should be stored in each country it arrives
//  *   at, and should increment that country's count.
//  * @param receiver name of the country to receive the message
//  * @param message the message to send to the receiver
//  * @return none
//  */
//  void CountryNetwork::transmitMsg(string receiver, string msg)
//  {
//    Country *temp = head;
//    if(isEmpty() == true)
//    {
//      cout <<  "Empty list" << endl;
//      exit(0);
//    }
//    else
//    {
//      head->message = msg;
//      head->numberMessages = head->numberMessages + 1;
//      cout << head->name << " [# messages received: " << head->numberMessages << "] received: " << head->message << endl;
//
//    while(temp->name != receiver)
//    {
//      temp = temp->next;
//      if(temp->next->name == receiver)
//      {
//          temp->next->message = msg;
//
//      }
//      temp->message = msg;
//      temp->numberMessages = temp->numberMessages + 1;
//      cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
//    }
//   }
//  }
//
//
// /*
//  * Purpose: prints the current list nicely
//  * @param ptr head of list
//  */
// void CountryNetwork::printPath()
// {
//     if(isEmpty()==false)
//     {
//     cout << "== CURRENT PATH =="<< endl;
//     Country *current = head -> next;
//     string message = head -> name;
//     while (current != NULL)
//     {
//         cout<<message<<" -> ";
//         message = current->name;
//         current = current->next;
//     }
//     if (current == NULL)
//     {
//         cout<<message<<" -> ";
//     }
//     cout<<"NULL"<<endl;
//     cout<<"==="<<endl;
//     cout << endl;
//     }
//     else
//     {
//         cout << "== CURRENT PATH =="<< endl;
//         cout << "nothing in path" << endl;
//         cout<<"==="<<endl;
//         cout << endl;
//     }
//
// }
//
//
// /*
//  * Purpose: reverse the entire network t
//  * @param ptr head of list
//  */
//  void CountryNetwork::reverseEntireNetwork()
//  {
//    Country *previous = nullptr;
//    Country *current = head;
//    Country *temporary;
//    while(current != nullptr)
//    {
//      temporary = current->next;
//      current->next = previous;
//      previous = current;
//      current = temporary;
//    }
//    head = previous;
//  }
//
//
//
//
//
//
// void displayMenu();
//
// int main(int argc, char* argv[])
// {
//   CountryNetwork opt;
//   string option;
//   while(option != "8")
//   {
//
//   displayMenu();
//   getline(cin, option);
//   switch(stoi(option))
//   {
//   case 1:
//   {
//     opt.loadDefaultSetup();
//     opt.printPath();
//     break;
//   }
//   case 2:
//   {
//     opt.printPath();
//     //displayMenu();
//     break;
//   }
//   case 3:
//   {
//     string message;
//     string country;
//     cout << "Enter name of the country to receive the message:" << endl;
//     getline(cin, country);
//     cout << "Enter the message to send:" << endl;
//     cout << endl;
//     getline(cin, message);
//     opt.transmitMsg(country, message);
//     break;
//     //displayMenu();
//   }
//   case 4:
//   {
//       string prev;
//       string insertC;
//       cout << "Enter a new country name:" << endl;
//       getline(cin, insertC);
//       cout << "Enter the previous country name (or First):" << endl;
//       getline(cin, prev);
//
//      while(opt.searchNetwork(prev) == NULL && prev != "First" && prev != "first")
//       {
//         cout << "INVALID country...Please enter a VALID previous country name:" << endl;
//         getline(cin, prev);
//         break;
//       }
//       if(prev == "First" || prev == "first")
//       {
//         opt.insertCountry(NULL, insertC);
//         opt.printPath();
//       }
//       else if(opt.searchNetwork(prev) != NULL)
//       {
//         opt.insertCountry(opt.searchNetwork(prev), insertC);
//         opt.printPath();
//       }
//       //displayMenu();
//       break;
//   }
//   case 5:
//   {
//     string cName;
//     cout << "Enter a country name:" << endl;
//     getline(cin, cName);
//     opt.deleteCountry(cName);
//     opt.printPath();
//     //displayMenu();
//     break;
//   }
//   case 6:
//   {
//     opt.reverseEntireNetwork();
//     opt.printPath();
//     //displayMenu();
//     break;
//   }
//   case 7:
//   {
//     opt.deleteEntireNetwork();
//     //displayMenu();
//     break;
//   }
//   case 8:
//   {
//     cout << "Quitting... cleaning up path: " << endl;
//     opt.printPath();
//     opt.deleteEntireNetwork();
//     if(opt.isEmpty() == true)
//     {
//       cout << "Path cleaned" << endl;
//     }
//     else
//     {
//       cout << "Error: Path NOT cleaned" << endl;
//     }
//     cout << "Goodbye!" << endl;
//     break;
//   }
//    }
//   }
// }
//
// /*
//  * Purpose: displays a menu with options
//  */
// void displayMenu()
// {
//     cout << "Select a numerical option:" << endl;
//     cout << "+=====Main Menu=========+" << endl;
//     cout << " 1. Build Network " << endl;
//     cout << " 2. Print Network Path " << endl;
//     cout << " 3. Transmit Message " << endl;
//     cout << " 4. Add Country " << endl;
//     cout << " 5. Delete Country " << endl;
//     cout << " 6. Reverse Network" << endl;
//     cout << " 7. Clear Network " << endl;
//     cout << " 8. Quit " << endl;
//     cout << "+-----------------------+" << endl;
//     cout << "#> ";
// }
