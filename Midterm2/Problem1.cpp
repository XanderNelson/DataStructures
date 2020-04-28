#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#include "BST.hpp"
#define COUNT 10

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

BST::~BST(){
     //destroyNode(root);
}

Node* BST::createNode(int data)
{
  Node* newNode = new Node;
  newNode->key = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* BST::addNodeHelper(Node* currNode, int data)
{
  if(currNode == NULL){
      return createNode(data);
  }
  else if(currNode->key < data){
      currNode->right = addNodeHelper(currNode->right,data);
  }
  else if(currNode->key > data){
      currNode->left = addNodeHelper(currNode->left,data);
  }
  return currNode;
}

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

void BST:: printTreeHelper(Node* currNode)
{
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }


void BST::print2DUtilHelper(Node *currNode, int space)
{
    if (currNode == NULL)
        return;

    space += COUNT;

    print2DUtilHelper(currNode->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}


void BST:: printTree(){
     printTreeHelper(root);
}

bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

void BST::addNode(int data)
{
    addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

int BST::sumrangehelp(Node *curr, int min, int max, int sum)
{
  Node *print = curr;
  if(print == NULL)
  {
    return 0;
  }
  if(print->key > min && print->left != NULL)
  {
    sum = sum + print->left->key;
    sumrangehelp(print->left, min, max, sum);
  }
  if(print->key < max && print->right != NULL)
  {
    sum = sum + print->right->key;
    sumrangehelp(print->right, min, max, sum);
  }
  if(print->key == min || print->key == max)
  {
    return sum;
    //sum = sum + print->key;
  }
cout << "sum: " << sum << endl;
return 0;
}
int BST::sumRange(int min, int max)
{
  int sum = max;
  sumrangehelp(root, min, max, sum);
  return 0;
}


int main()
{
  cout<<"Creating tree"<<endl;
  BST tree(5);


  tree.addNode(2); //left child to 5
  tree.addNode(1); //left child to 1
  tree.addNode(4); //right child to 2
  tree.addNode(7); //right child to 5
  tree.addNode(10); //right child of 7
  tree.addNode(8); // left child of 10
  tree.addNode(6); // left child of 7

  cout<<"----------------Intial tree is ---------------"<<endl<<endl;
  tree.print2DUtil(1);
  cout << "The sum of range: 1, 4: " << endl;
  tree.sumRange(1, 4);
  cout << "The sum of range: 4, 6: " << endl;
  tree.sumRange(4, 6);




}
