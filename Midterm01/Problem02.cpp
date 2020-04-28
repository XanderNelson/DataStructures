#include <iostream>
#include <string>

using namespace std;

struct Node
{
  int number;
  Node* next = nullptr;
  Node ()
  {

  }
  Node(int k)
  {
    number = k;
  }
};

void print(Node *head);

int main()
{
  //Node *n_1 = nullptr;
  Node *n_1 = new Node(1);
  Node *n_2 = new Node(2);
  n_1->next = n_2;
  Node *n_3 = new Node(3);
  n_2->next = n_3;
  Node *n_4 = new Node(4);
  n_3->next = n_4;
  // Node *n_5 = new Node(3);
  // n_4->next = n_5;
  // Node *n_6 = new Node(6);
  // n_5->next = n_6;

  //cout << "Empty test: " << endl;
  Node *temp = n_1;
  Node *lastEven = nullptr;
  Node *lastOdd = nullptr;
  Node *even = nullptr;
  Node *odd = nullptr;
  if(temp == nullptr)
  {
    cout << "List empty!" << endl;
  }
  while(temp != nullptr)
  {
    if(temp->number%2 == 0)
    {
      //lastEven = even;
      if(even == nullptr)
      {
        Node *evenStart = new Node(temp->number);
        even = evenStart;
        lastEven = even;
        cout << "Adding to even start: " << even->number << endl;
      }
      else
      {
        Node *temp2 = new Node(temp->number);
        lastEven = temp2;
        even->next = lastEven;
        cout << "Adding to even: " << temp2->number << endl;
        delete temp2;
      }
      lastEven = lastEven->next;
    }
    else
    {
      if(odd == nullptr)
      {
        Node *oddStart = new Node(temp->number);
        odd = oddStart;
        cout << "Adding to odd start: " << odd->number << endl;
      }
      else
      {
        Node *temp3 = new Node(temp->number);
        odd->next = temp3;
        cout << "Adding to odd: " << temp3->number << endl;
      }


    }
    temp = temp->next;
  }
  print(temp);
  cout << "List of even integers: ";
  print(even);
  cout << endl;
  cout << "List of odd integers: ";
  print(odd);
  cout << endl;
}


void print(Node *head)
{
  Node *printNode = head;
  while(printNode != nullptr)
  {
    cout << printNode->number << ", ";
    printNode = printNode->next;
  }
}
