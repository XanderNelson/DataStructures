#include <iostream>
#include <iomanip>
#include <fstream>

#include "HashTable.hpp"
using namespace std;


HashTable stopWordsTable(50);

unsigned int getHash2(string word)
{
    unsigned long hash = 5381;
    int c;
    int length = word.length();

    for (int i = 0; i < length; ++i) {
        c = (int) word[i];
        hash = ((hash << 5) + hash) + c;
    }
    hash %= 50;
    return hash;
}
void getStopWords(char *ignoreWordFileName, HashTable &stopWordsTable)
{
  string line;
  ifstream inIgnore;
  inIgnore.open(ignoreWordFileName);


  if(inIgnore.fail())
  {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }
  else
  {
    while(inIgnore >> line)
    {
      stopWordsTable.addWord(line);
   }
  }
}


bool isStopWord(string word, HashTable &stopWordsTable)
{
  for(int i = 0; i <= 50; i++)
  {
    if(stopWordsTable.isInTable(word) == true)
    {
      return true;
    }
  }
  return false;
}

HashTable::HashTable(int hashTableSize)
{
  this->hashTableSize = hashTableSize;
  numItems = 0;
  numCollisions = 0;
  hashTable = new wordItem *[hashTableSize];
  for(int i = 0; i < hashTableSize; i++)
  {
    hashTable[i] = nullptr;
  }
}

HashTable::~HashTable()
{
  for(int i = 0; i < hashTableSize; i++)
  {
    wordItem *temp = hashTable[i];
    while(temp != nullptr)
    {
      wordItem *current = temp;
      temp = temp->next;
      delete current;
    }
  }
  delete[] hashTable;
}

void HashTable::addWord(string word)
{
      numItems++;
      int index = getHash(word);
      wordItem *nWord = new wordItem;
      nWord->word = word;
      nWord->count = 1;

      if(hashTable[index] == nullptr)
      {
        hashTable[index] = nWord;
        hashTable[index]->next = nullptr;
        return;
      }
      else
      {
        numCollisions++;
        wordItem *current = hashTable[index];
        wordItem *temp = nullptr;
        while(current != nullptr)
        {
          if(current == nWord)
          {
            current->count = current->count + 1;
          }
          temp = current;
          current = current->next;
        }
        temp->next = nWord;
        temp->next->next = nullptr;
        return;
      }

}




bool HashTable::isInTable(string word)
{
  if(searchTable(word) == nullptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void HashTable::incrementCount(string word)
{
  wordItem *temp = searchTable(word);
  temp->count = temp->count + 1;
  return;
}

void HashTable::printTopN(int n)
{
  wordItem *topwords[n+1];
  int current = 0;

  for(int i = 0; i<hashTableSize; i++)
  {
    wordItem *temp = hashTable[i];
    while(temp != nullptr)
    {
      topwords[current] = temp;
      current++;
      for(int j = (current-1); j > 0; j--)
      {
        if(topwords[j]->count > topwords[j-1]->count)
        {
          wordItem *temp2 = topwords[j-1];
          topwords[j-1] = topwords[j];
          topwords[j] = temp2;
        }
        else
        {
          break;
        }
      }
      if(current > n)
      {
        current = n;
      }
      temp = temp->next;
    }
  }
  for(int c = 0; c < n; c++)
  {
    cout << fixed << setprecision(4) << (float)topwords[c]->count/getTotalNumWords() << " - " << topwords[c]->word << endl;
  }
}

int HashTable::getNumCollisions()
{
  return numCollisions;
}

int HashTable::getNumItems()
{
  return numItems;
}

int HashTable::getTotalNumWords()
{

  int titties = 0;
   for(int i = 0; i < hashTableSize; i++)
   {
     wordItem *temp = hashTable[i];
     while(temp != nullptr)
     {
       titties = titties + temp->count;
       temp = temp->next;
     }
   }
   return titties;
}

unsigned int HashTable::getHash(string word)
{
    unsigned int hashValue = 5381;
    int length = word.length();
    for (int i=0;i<length;i++)
    {
        hashValue=((hashValue<<5)+hashValue) + word[i];
    }

    hashValue %= hashTableSize;
    return hashValue;
}

wordItem* HashTable::searchTable(string word)
{
  int index = getHash(word);
  wordItem *temp = hashTable[index];
  while(temp != nullptr)
  {
    if(temp->word == word)
    {
      return temp;
    }
    temp = temp->next;
  }
  return nullptr;
}
