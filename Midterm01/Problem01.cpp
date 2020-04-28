#include <iostream>
#include <string>

using namespace std;

struct Node
{
  int number;
  Node* next = nullptr;
  Node()
  {

  }
  Node(int k)
  {
    number = k;
  }
};

int sumEvens(Node *head);

int main()
{
  Node *n1 = nullptr;
  cout << "Empty test: " << sumEvens(n1) << endl;

  n1 = new Node(2);
  Node *n2 = new Node(3);
  n1->next = n2;
  Node *n3 = new Node(4);
  n2->next = n3;
  Node *n4 = new Node(2);
  n3->next = n4;
  Node *n5 = new Node(3);
  n4->next = n5;
  Node *n6 = new Node(6);
  n5->next = n6;

  cout << "Test list: 2, 3, 4, 2, 3, 6 = "<< sumEvens(n1) << endl;

  Node *n_1 = new Node(1);
  Node *n_2 = new Node(3);
  n_1->next = n_2;
  Node *n_3 = new Node(5);
  n_2->next = n_3;
  Node *n_4 = new Node(7);
  n_3->next = n_4;
  Node *n_5 = new Node(3);
  n_4->next = n_5;
  Node *n_6 = new Node(3);
  n_5->next = n_6;

  cout << "Test list: 1, 3, 5, 7, 3, 3 = "<< sumEvens(n_1) << endl;

  Node *n__1 = new Node(2);
  Node *n__2 = new Node(4);
  n__1->next = n__2;
  Node *n__3 = new Node(6);
  n__2->next = n__3;
  Node *n__4 = new Node(8);
  n__3->next = n__4;
  Node *n__5 = new Node(2);
  n__4->next = n__5;

  cout << "Test list: 1, 3, 5, 7, 3, 3 = "<< sumEvens(n__1) << endl;
}

int sumEvens(Node *head)
{
  Node *temp = head;
  int count = 0;
  if(!head)
  {
    return 0;
  }
  else
  {
    while(temp != nullptr)\
    {
      if(temp->number%2 == 0)
      {
        count = count + temp->number;
      }
      temp = temp->next;
    }
    return count;
  }
}
