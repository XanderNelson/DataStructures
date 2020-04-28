#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "PRIORITYQUEUE.hpp"
using namespace std;

PriorityQueue::PriorityQueue(int queueSize)\
{
  maxQueueSize = queueSize;
  currentQueueSize = 0;
  priorityQueue = new GroupNode [queueSize];
}

PriorityQueue::~PriorityQueue()
{
  delete[] priorityQueue;
}


void PriorityQueue::enqueue (std::string _groupName, int _groupSize, int _cookingTime)
{
  if(isFull())
  {
    cout << "Heap full, cannot enqueue" << endl;
  }
  else
  {
    currentQueueSize++;
    int i = currentQueueSize-1;
    priorityQueue[i].groupName = _groupName;
    priorityQueue[i].groupSize = _groupSize;
    priorityQueue[i].cookingTime = _cookingTime;
    repairUpward(i);
  }
}

void PriorityQueue::dequeue()
{
  if(isEmpty())
  {
    cout << "Heap empty, cannot dequeue" << endl;
  }
  else
  {
    currentQueueSize--;
    priorityQueue[0] = priorityQueue[currentQueueSize];
    repairDownward(0);
  }
}

GroupNode PriorityQueue::peek()
{
  if(isEmpty())
  {
    cout << "Heap empty, nothing to peek" << endl;
    return priorityQueue[0];
  }
  else
  {
    return priorityQueue[0];
  }
}

bool PriorityQueue::isFull()
{
  if(currentQueueSize == maxQueueSize)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool PriorityQueue::isEmpty()
{
  if(currentQueueSize == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void PriorityQueue::repairUpward(int nodeIndex)
{
  if(nodeIndex != 0 && priorityQueue[(nodeIndex-1)/2].groupSize > priorityQueue[nodeIndex].groupSize)
  {
    swap(priorityQueue[nodeIndex], priorityQueue[(nodeIndex-1)/2]);
    repairUpward((nodeIndex-1)/2);
  }
  else if(nodeIndex != 0 && priorityQueue[(nodeIndex-1)/2].groupSize == priorityQueue[nodeIndex].groupSize)
  {
      if(nodeIndex != 0 && priorityQueue[(nodeIndex-1)/2].cookingTime > priorityQueue[nodeIndex].cookingTime)
      {
        swap(priorityQueue[nodeIndex], priorityQueue[(nodeIndex-1)/2]);
        repairUpward((nodeIndex-1)/2);
      }
      else
      {
          return;
      }
  }
  else
  {
      return;
  }
}

void PriorityQueue::repairDownward(int nodeIndex)
{
  int left = (2*nodeIndex+1);
  int right = (2*nodeIndex+2);
  int min = nodeIndex;

  if(left <= currentQueueSize && priorityQueue[left].groupSize < priorityQueue[nodeIndex].groupSize)
  {
    min = left;
  }

  if(right <= currentQueueSize && priorityQueue[right].groupSize < priorityQueue[min].groupSize)
  {
    min = right;
  }
  if(left <= currentQueueSize && priorityQueue[left].groupSize == priorityQueue[nodeIndex].groupSize)
  {
      if(priorityQueue[left].cookingTime < priorityQueue[min].cookingTime)
      {
          min = left;
      }
  }
  if(right <= currentQueueSize && priorityQueue[right].groupSize == priorityQueue[min].groupSize)
  {
    if(priorityQueue[right].cookingTime < priorityQueue[min].cookingTime)
    {
        min = right;
    }
  }
  if(min != nodeIndex)
  {
    swap(priorityQueue[nodeIndex], priorityQueue[min]);
    repairDownward(min);
  }
}
