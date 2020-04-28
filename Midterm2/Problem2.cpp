#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
//#include <math>
#include <vector>
using namespace std;
#include "heaps.hpp"

Heap::Heap(int heapSize)
{
  this->heapSize = heapSize;
  currentSize = 0;
  heap = new float[heapSize];
}

Heap::~Heap()
{
  delete []heap;
}

void Heap::printHeap()
{
  int iter = 0;
  while(iter < currentSize)
  {
    cout<<heap[iter]<<" ";
    iter = iter + 1;
  }
  cout<<endl;
}
bool Heap::isFull()
{
  if(currentSize == heapSize)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void Heap::addToHeap(float value)
{
  if(isFull())
  {
    cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
    return;
  }

  else
  {
    currentSize++;
    int i = currentSize-1;
    heap[i] = value;
    repairUpward(i);
  }
}

float Heap::peekValue()
{
  return heap[0];
}

int Heap::parent(int nodeIndex)
{
  return ((nodeIndex-1)/2);
}


int Heap::leftChild(int nodeIndex)
{
  return ((2*nodeIndex) + 1);
}

int Heap::rightChild(int index)
{
  return ((2*index) + 2);
}

void Heap::repairUpward(int nodeIndex)
{
  if(nodeIndex != 0 && heap[parent(nodeIndex) > heap[nodeIndex]])
  {
    swap(heap[nodeIndex], heap[parent(nodeIndex)]);
    repairUpward(parent(nodeIndex));
  }
  else
  {
      return;
  }
}

void Heap::repairDownward(int nodeIndex)
{
  int left = leftChild(nodeIndex);
  int right = rightChild(nodeIndex);
  int min = nodeIndex;

  if(left <= currentSize && heap[left] < heap[nodeIndex])
  {
    min = left;
  }
  if(right <= currentSize && heap[right] < heap[min])
  {
    min = right;
  }
  if(min != nodeIndex)
  {
    swap(heap[nodeIndex], heap[min]);
    repairDownward(min);
  }
}
float Heap::removeFromHeap()
{


    currentSize--;
    heap[0] = heap[currentSize];
    repairDownward(0);
    return heap[0];
}
float *Heap::heapSort(float arr[])
{\
  float *arr2 = arr;
  int i = 0;
  int j = i+1;
  while(i != heapSize)
  {
    float left = leftChild(arr[i]);
    float right = rightChild(arr[i]);

    if(arr2[i] > left)
    {
      swap(arr2[i], left);
      // arr2[i] = arr2[j];
      // arr[j] = arr2[i];
    }
    else if(arr2[i] > right)
    {
      swap(arr2[i], right);
      // arr2[i] = arr2[j];
      // arr[j] = arr2[i];
    }
    i++;
    j++;
  }
  for(int r = 0; r < heapSize; r++)
  {
    cout << arr2[r] << " ";
  }

  return 0;
}

int main()
{
  Heap heap(8);

  float arr[8] = {1.1, 4, 2, 6.5, 5, 10, 55, 31.5};
  for(int i = 0; i < 8; i++)\
  {
    heap.addToHeap(arr[i]);
  }

  cout<<"***********Elements in the heap are **********"<<endl;
  heap.printHeap();
  cout << "After heap sort: " << endl;
  heap.heapSort(arr);

  Heap heap2(5);
  float arrt[5] = {8, 4, 3, 5.6, 1.7};
  for(int j = 0; j < 5; j++)\
  {
    heap2.addToHeap(arrt[j]);
  }
  cout << endl;
  cout<<"***********Elements in the heap are **********"<<endl;
  heap2.printHeap();
  cout << "After heap sort: " << endl;
  heap2.heapSort(arrt);
  cout<<endl;

}
