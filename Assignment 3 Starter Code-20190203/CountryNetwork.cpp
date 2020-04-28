/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
  head = nullptr;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if(head == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
 void CountryNetwork::insertCountry(Country* previous, string countryName)
 {

   if(previous == NULL)
   {
     Country *temp = new Country;
     temp->name = countryName;
     temp->next = head;
     head=temp;
     temp = nullptr;
     cout << "adding: " << countryName << " (HEAD)" << endl;
   }
   else
   {
     Country *last = previous;
       if(last == nullptr)
       {
        cout << "Country not found" << endl;
      }

      else
      {
        Country *temp = new Country;
        temp -> name = countryName;
        temp -> next = previous->next;
        previous->next = temp;
        temp = nullptr;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
      }
     }
   }


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
 void CountryNetwork::deleteCountry(string countryName)
 {
     if(searchNetwork(countryName) != nullptr)
     {
       Country *temp = head;
       if(temp->name == countryName)
       {
           head->name = head->next->name;
           temp = head->next;
           head->next = head->next->next;
       }
       else
       {
       while(temp->next != nullptr && temp->next->name != countryName)
       {
         temp = temp -> next;
       }
       temp -> next = temp -> next -> next;
       }
     }
     else
     {
     cout << "Country does not exist." << endl;
     }
 }


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
 void CountryNetwork::loadDefaultSetup()
 {

   deleteEntireNetwork();
   insertCountry(head, "United States");
   insertCountry(head, "Canada");
   insertCountry(head->next, "Brazil");
   insertCountry(head->next->next, "India");
   insertCountry(head->next->next->next, "China");
   insertCountry(head->next->next->next->next, "Australia");
 }


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
 Country* CountryNetwork::searchNetwork(string countryName)
 {
   Country *returnNode = nullptr;
   Country *temp = head;

   bool found = false;
   while(!found && temp != nullptr)
   {
     if(temp->name == countryName)
     {
       found = true;
       returnNode = temp;
     }
     else
     {
       temp = temp->next;
     }
   }
   return returnNode;
 }


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
 void CountryNetwork::deleteEntireNetwork()
 {
   Country* current = head;
   Country* temp;
   while(current != NULL)
   {
     temp = current;
     current = current->next;
     cout << "deleting: " << temp->name << endl;
     free(temp);
   }
   cout << "Deleted network" << endl;
   head = nullptr;
 }


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
 void CountryNetwork::transmitMsg(string receiver, string msg)
 {
   Country *temp = head;
   if(isEmpty() == true)
   {
     cout <<  "Empty list" << endl;
     exit(0);
   }
   else
   {
     head->message = msg;
     head->numberMessages = head->numberMessages + 1;
     cout << head->name << " [# messages received: " << head->numberMessages << "] received: " << head->message << endl;

   while(temp->name != receiver)
   {
     temp = temp->next;
     if(temp->next->name == receiver)
     {
         temp->next->message = msg;

     }
     temp->message = msg;
     temp->numberMessages = temp->numberMessages + 1;
     cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
   }
  }
 }


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
  Country *temp = head;
  if(isEmpty() == true)
  {
    cout <<  "nothing in path" << endl;
    exit(0);
  }
  else
  {
    while(temp != nullptr)
    {
      cout << head << " -> ";
      cout << temp << " -> ";
      temp = temp->next;
      // if(temp->next = nullptr)
      // {
      //   cout << temp->next << endl;
      // }
    }
    if(temp->next = nullptr)
    {
      cout << temp->next << endl;
    }
  }
}


/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
 void CountryNetwork::reverseEntireNetwork()
 {
   Country *previous = nullptr;
   Country *current = head;
   Country *temporary;
   while(current != nullptr)
   {
     temporary = current->next;
     current->next = previous;
     previous = current;
     current = temporary;
   }
   head = previous;
 }
