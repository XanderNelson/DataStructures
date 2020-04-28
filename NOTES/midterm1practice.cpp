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

bool lengthIsEven(Node *head)
{
  Node* temp;
  temp = head;
  int count = 0;
  if(!head)
  {
    return true;
  }
  else
    {
    while(temp != nullptr)
    {
      temp = temp->next;
      count++;
    }
    if(count%2 == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
string isEven(Node *head)
{
  if(lengthIsEven(head) == true)
  {
    return "False";
  }
  else
  {
    return "True";
  }
}

int main()
{
  Node *n1 = nullptr;
  cout << "Empty test: " << isEven(n1) << endl;

  n1 = new Node(1);
  Node *n2 = new Node(1);
  n1->next = n2;
  Node *n3 = new Node(1);
  n2->next = n3;
  Node *n4 = new Node(1);
  n3->next = n4;
  Node *n5 = new Node(1);
  n4->next = n5;
  Node *n6 = new Node(1);
  n5->next = n6;

  cout << "Test 1: " << isEven(n1) << endl;

  Node *n7 = new Node(1);
  n6->next = n7;

  cout << "Test 1: " << isEven(n1) << endl;
}
