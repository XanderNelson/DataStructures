#include <iostream>
#include "tree.hpp"
using namespace std;
#define COUNT 10


/*
Constructor for a Tree object
*/
Tree::Tree()
{
  this->root = NULL;
}

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void Tree::print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

void Tree::preOrderTraverse(Node *node)
{
  if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left sutree */
    preOrderTraverse(node->left);

    /* now recur on right subtree */
    preOrderTraverse(node->right);
}


/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
            This function deletes all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/
void Tree::deleteTree(Node *node)
{
    if (node == NULL)
    {
      return;
    }
    if(node->left != nullptr)
    {
      deleteTree(node->left);
    }
    if(node->right != nullptr)
    {
      deleteTree(node->right);
    }
    delete node;
    cout<<"\n Deleting node:"<< node->data;
}

/*
***************************************************************************
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                        Implement this function
          This function gives the sum of all the nodes in the tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
***************************************************************************
*/

int sumTotal(Node *temp, int& total)
{
  if(temp == nullptr)
  {
    return total;
  }\
  else
  {
    sumTotal(temp->left, total);
    total = total + temp->data;
    sumTo    tal(temp->right, total);
    return total;
  }
}

int Tree::sumNodes(Node *node)
{
  int total = 0;
  total = sumTotal(root, total);
  return total;
}



/*
 Creates a tree of 7 elements
 */
void Tree::createTree()
{
  Node *root         = new Node(1);
  root->left         = new Node(2);
  root->right        = new Node(3);
  root->left->left   = new Node(4);
  root->left->right  = new Node(5);
  root->right->left  = new Node(6);
  root->right->right = new Node(7);
  this->root = root;
}
