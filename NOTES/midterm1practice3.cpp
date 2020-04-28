#include <iostream>
#include <string>

using namespace std;
class arrayStack
{
private:
  int stackSize;
  int length;
  int *arr;
public:
  arrayStack()
  {
    length = 5;
    stackSize = -1;
    arr = new int[length];
  }
  void push(int num);
  void pop();
  void print();
};


void arrayStack::push(int num)
{
  if(stackSize == length-1)
  {
    length = length * 2;
  }
  stackSize++;
  arr[stackSize] = num;
}

void arrayStack::pop()
{
  if(stackSize == (length / 2))
  {
    length = length/2;
  }
  stackSize--;
  //arr[] = arr[stackSize];
}


void arrayStack::print()
{
  for(int i =0; i < stackSize+1; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout <<"Length: " << length << endl;
}

int main()
{
  arrayStack as;
  as.push(1);
  as.push(2);
  as.push(3);
  as.push(4);
  as.push(5);
  as.push(6);
  as.push(7);
  as.push(8);
  as.push(9);
  as.push(10);
  as.push(11);
  as.push(12);

  as.print();

  as.pop();
  as.pop();
  as.pop();
  as.pop();
  as.pop();

  cout << endl;

  as.print();
  //cout << "Array size: " << length << endl;
  //cout << "Stack size: " << stackSize << endl;
}
