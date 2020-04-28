#include <iostream>

#include <string>



using namespace std;



struct Node

{

  int number;

  Node *next = nullptr;

  Node()

  {



  }

  Node(int k)

  {

    number = k;

  }

};



Node *deleteNegatives(Node *head);



int main()

{

  Node *n1 = new Node(-2);

  Node *n2 = new Node(3);

  n1->next = n2;

  Node *n3 = new Node(-2);

  n2->next = n3;

  Node *n4 = new Node(-4);

  n3->next = n4;

  Node *n5 = new Node(2);

  n4->next = n5;

  Node *n6 = new Node(2);

  n5->next = n6;



  for(Node *temp3 = n1; temp3 != 0; temp3 = temp3->next)

  {

    cout << temp3->number << endl;

  }



  cout << deleteNegatives(n1) << endl;

}



Node *deleteNegatives(Node *head)

{

  Node *temp = head;

  while(head->number < 0)

  {

    cout << "deleting: " << temp->number << endl;

    temp = temp->next;

    head = temp;

    delete temp;

  }

  Node *temp2 = head->next;

  Node *prev = head;



  while(temp2 != nullptr)

  {

    if(temp2->number <0)

    {

      prev->next = temp2->next;

      temp2=prev->next;

      cout << "deleting " << prev->number<< endl;



    }

    else

    {

      temp2 = temp2->next;

      prev = prev->next;

    }

  }



  Node *temp4 = head;

  while(temp4 != nullptr)

  {

    cout << temp4->number << endl;

    temp4 = temp4->next;

  }

  return head;

}
