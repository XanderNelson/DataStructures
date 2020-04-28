// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);
    node *temp = table[index];
    while(temp!=nullptr)
    {
      if(temp->key == key)
      {
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
    //TODO: Search the list at that specific index and return the node if found
}

//TODO Complete this function
//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        node *newW = new node;
        newW->key = key;
        newW->next = NULL;

        if(table[index] == nullptr)
        {
          table[index] = newW;
        }
        else
        {
          node *curr = table[index];
          node *temp = nullptr;
          while(curr != nullptr)
          {
            temp = curr;
            curr = curr->next;
          }
          temp->next = newW;
        }
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
    return true;
}

//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        node *temp = table[i];
      // for(temp = table[i]; temp != nullptr; temp = temp->next)
        while(temp != nullptr)
        {
          cout << i <<"|| "<< temp->key << endl;
          temp=temp->next;
        }
    }
    return;
 }

bool HashTable::findThreeSum()
{
  //arr[] = hashTable;
  for(int i = 0; i < tableSize; i++)
  {
    node *temp = hashTable[i];
    for(int j = 0; j < tableSize; j++)
    {
      node *temp2 = hashTable[j];
      node *temp3 = hashTable[j];
      while(temp3 != nullptr)
      {
        if((temp->data + temp2->data + temp3->data) == 0)
        {
          return true;
        }
        temp3 = temp3->next;
      }
    }
  }
  return false;
}
