#include <iostream>
using namespace std;

#include "binaryST.h"

BinaryST::BinaryST()
{
	root = nullptr;
}

// Insert new node
void BinaryST::insert( int newValue )
{
	//create a pointer to keep track of previous node
	Node *prev = nullptr;
	//pointer for traversing tree. start with root
	Node *temp = root;
	//create a new node and pointer for it
	Node *n = new Node;
	//set all pointers inside n to null. write new value to key
	n->parent = nullptr;
	n->leftChild = nullptr;
	n->rightChild = nullptr;
	n->key = newValue;
	//loop until we find first enmpty spot in the tree
	//if the tree is empty, root is null and the loop will not execute
	while(temp != nullptr)
	{
		//set prev to temp to keep track of last node
		prev = temp;
		//check which way to go
		if(n->key < temp->key)
		{
			temp = temp->leftChild;
		}
		else //if n key is greater than or equal to
		{
			temp = temp->rightChild;
		}
		//at this point the parent has been found
	}
	if(prev == nullptr)
	{
		root = n;
	}
	else if(n->key < prev->key)
	{
		prev->leftChild = n;
		n->parent = prev;
	}
	else
	{
		prev->rightChild = n;
		n->parent = prev;
	}
}

void BinaryST::disp( string Order )
{
	if(Order == "Pre-order")
	{
		dispPreOrd(root);
	}
	else if(Order == "In-order")
	{
		dispInOrd(root);
	}
}

void BinaryST::dispPreOrd( Node *n )
{

}

void BinaryST::dispInOrd( Node *n )
{
	if(n->leftChild != nullptr)
	{
		dispInOrd(n->leftChild);
	}
	cout << n->key << endl;
	if(n->rightChild != nullptr)
	{
		dispInOrd(n->rightChild);
	}
}

Node* BinaryST::search( int value )
{
	return searchRecur(root, value);
}

Node* BinaryST::searchRecur( Node *n , int searchKey )
{
	if(n != nullptr)
	{
		cout << "Node visted: " << n->key << endl;
		if(n->key == searchKey)
		{
			return n;
		}
		else if(n->key > searchKey)
		{
			return searchRecur(n->leftChild, searchKey);
		}
		else
		{
			return searchRecur(n->rightChild, searchKey);
		}
	}
	else
	{
		return nullptr;
	}
}

Node* BinaryST::findMin()
{
	return getMin(root);
}

Node* BinaryST::getMin( Node *n )
{
	while(n->leftChild != nullptr)
	{

		n = n->leftChild;
	}
	return n;

}


void BinaryST::deleteNode( int value )
{
	Node *n = search(value);
	//non-root case
	if(n!=root)
	{
		//I) the leaf case (n is a leaf node)
		if(n->leftChild == nullptr && n->rightChild == nullptr)
		{
			//go up to the parent node and update the correct child pointer
			//check n's relationship to its parents
			//is n the left child?
			if(n==n->parent->leftChild)
			{
				n->parent->leftChild = nullptr;
			}
			//otherwise must be the right child
			else
			{
				n->parent->rightChild = nullptr;
			}
		}
		//II) the two children case
		else if(n->leftChild != nullptr && n->rightChild != nullptr)
		{
			//find the min of the right sub tree to replace the deleted node
			Node *min = getMin(n->rightChild);
			//if min is the right child of n
			if(min == n->rightChild)
			{
				//make parent point to the min
				//check if node is left child
				if(n == n->parent->leftChild)
				{
					n->parent->leftChild = min;
				}
				else
				{
					n->parent->rightChild = min;
				}
				//make min point to the parent
				min->parent = n->parent;
				//make min poiunt to n's old child
				min->leftChild = n->leftChild;
				//make old LC point to min
				min->leftChild->parent = min;
			}
			//when there is a whole sub tree
			//meaning its somewhere in that subtree
			else
			{
				//min's old right child takes mins spot
				min->parent ->leftChild = min->rightChild;
				//new node needs to point back up to mins former parent
				if(min->rightChild != nullptr)
				{
					min->rightChild->parent = min->parent;
				}
				//now insert min into n's old Spotless
				//check if node is LC
				if(n==n->parent->leftChild)
				{
					n->parent->leftChild = min;
				}
				else
				{
					n->parent->rightChild = min;
				}
				min->parent = n-> parent;
				min->leftChild = n->leftChild;
				min->leftChild->parent = min;
				min->rightChild = n->rightChild;
				min->rightChild->parent = min;
			}
		}
		//III) the one child case
		else
		{
			// 1) the one child is a left child
			if(n->leftChild != nullptr)
			{
				n->leftChild->parent = n->parent;
				//check if node is left child
				if(n == n->parent->leftChild)
				{
					n->parent->leftChild = n->leftChild;
				}
				//otherwise it is the right chld
				else
				{
					n->parent->rightChild = n->leftChild;
				}
			}
			// 2) the one child is the right child
			else
			{
				n->rightChild -> parent = n->parent;
				//check if node is left child
				if(n == n->parent->leftChild)
				{
					n->parent->leftChild = n->rightChild;
				}
				//otherwise it is the right chld
				else
				{
					n->parent->rightChild = n->rightChild;
				}
			}
		}

	}
	//root case
	else
	{

	}
	delete n;
}















//reillys boys code
#include<iostream>

struct Node {
  int key;
  Node* left;
  Node* right;

  Node(int k, Node* l, Node *r) { key = k; left = l; right = r;}
  Node(int k) { key = k; left = right = 0;}
  Node() { key = -1; left = right  = 0;}
};

class BST {
private:
  Node* root;

public:
  BST() {
    // initialize the root to NULL pointer
    root = 0;
  }
  ~BST() {
    // Free the memory used by the BST when you destruct
    recursive_destruct(root);
  }

  Node* search(int k) {
    // search the BST for the value k.
    // It returns the pointer to a node with value $k$ if it exists.
    // OTherwise, it returns 0
    // The helper function search takes a BST and value and searches
    // the BST recursively.
    return search(root, k);
  }

  int size() {
    // Returns the size of th BST
    // It calls the recursive function size that takes a tree and
    // recursively computes its size.
    return size(root);
  }

  void inOrder() {
    inOrder(root);
  }
  void preOrder() {
    preOrder(root);
  }
  void postOrder() {
    postOrder(root);
  }

  Node* getMin() {
    return getMin(root);
  }
  Node* getMax() {
    return getMax(root);
  }

  int getSum() {
    return getSum(root);
  }

  //  void insert(int val){
  // insert(root, val);
  // }

  void insert(int value) {
    Node* tmp = new Node(value);
    Node* curr = root;
    Node* prev;

    if (root == 0) {
      root = tmp;
    }
    else {
      while (curr != 0) {
  	prev = curr;
  	if (value < curr->key) {
  	  curr = curr->left;
  	}
  	else if (value == curr->key) {
  	  return;
  	}
  	else {
  	  curr = curr->right;
  	}
      }
      if (value < prev->key) {
  	prev->left = tmp;
      }

      else {
  	prev->right = tmp;
      }
    }
  }

  void remove(int val)
  {
    remove(root, val);
  }


private:
  /* helper functions */
  void insert(Node* T, int val) {
    // 1. implement this
  }

  void remove(Node* &T, int val)
  {
     if(T == 0)
     {
        return;
     }
     else if
     {
        if(val < T->key)
        {
           remove(t->left, val);
        }
        else if(val > T->key)
        {
           remove(t->right,val);
        }
        else
        {
           if(T->left == 0 && T->right == 0)
           {
             delete(T);
             T == 0;
          }
          else if(T->left != 0 && T->right == 0)
          {
             Node *temp = T;
             T = T->left;
             delete(temp);
          }
          else if(T->left == 0 && T->right != 0)
          {
             Node *temp = T;
             T = T->right;
             delete(temp);
          }
          else
          {
             Node *to_replace = getmin(T->right);
             T->key = to_replace->key;
             remove(T->right, to_replace->key);
          }
        }
     }
     else
     {

     }
  }


  int getSum(Node* T) {
    if (T == 0) return 0;
    else return T->key + getSum(T->left) + getSum(T->right);
  }

  void recursive_destruct(Node* T) {
    if (T == 0) return;
    else {
      recursive_destruct(T->left);
      recursive_destruct(T->right);
      delete T;
    }
  }

  Node* getMin(Node* T) {
    if (T == 0)
    {
      return 0;
    }
    else
    {
      if (T->left == 0)
      { return T;}
      else
      { return getMin(T->left); }
    }
  }

  Node* getMax(Node* T) {
    if (T == 0) {
      return 0;
    }
    else {
      if (T->right == 0) return T;
      else return getMax(T->right);
    }
  }

  void inOrder(Node* T) {
    if (T == 0) {
      return;
    }
    else {
      inOrder(T->left);
      std::cout << T->key << " " ;
      inOrder(T->right);
    }
    return;
  }

    void preOrder(Node* T) {
    if (T == 0) {
      return;
    }
    else {
      std::cout << T->key << " " ;
      preOrder(T->left);
      preOrder(T->right);
    }
    return;
  }

    void postOrder(Node* T) {
    if (T == 0) {
      return;
    }
    else {
      postOrder(T->left);
      postOrder(T->right);
      std::cout << T->key << " " ;
    }
    return;
  }

  int size(Node* T) {
    if (T==0) return 0;
    else return (1+ size(T->left) + size(T->right));
  }

  Node* search(Node* T, int val) {
    if (T == 0 ) {
      // Tree is empty
      return 0;
    }
    else {
      //Tree has got a node and pointers to left and right sub-trees
      if (T->key == val) return T;
      else
	if (val < T->key)
	  return search(T->left, val);
	else
	  return search(T->right, val);
    }
  }
};

int main() {
  BST T;
  int data[10] = {11, 2, 33, 4, 55, 6, 77, -10, 38, 67};

  /* 1. Implement Recursive Insert */
  for (int i = 0; i < 10; i++)   T.insert(data[i]);

  /* 2. Implement recursive "remove" */
  T.remove(11);
   T.remove(33);
   T.remove(6);
   T.remove(4);
   T.inOrder();

}
