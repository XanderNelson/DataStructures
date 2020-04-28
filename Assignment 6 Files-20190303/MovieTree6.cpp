#include "MovieTree.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

MovieTree::MovieTree()
{
  root = nullptr;
}

void deleteTree(TreeNode *root);



MovieTree::~MovieTree()
{
    deleteTree(root);
}

void inOrderFunc(TreeNode *top)
{
 if(top != nullptr)
 {
   LLMovieNode *temp = top->head;
   inOrderFunc(top->leftChild);
   cout << "Movies starting with letter: " << top->titleChar << endl;
   while(temp!=nullptr)
   {
     cout << " >> " << temp->title << " " << temp->rating << endl;
     temp = temp->next;
   }
   inOrderFunc(top->rightChild);
 }
}

void MovieTree::printMovieInventory()
{
  inOrderFunc(root);
}


void deleteTree(TreeNode *root)
{
  if(root == nullptr)
  {
    delete root;
    return;
  }
  if(root->leftChild != nullptr)
  {
    deleteTree(root->leftChild);
  }
  if(root->rightChild != nullptr)
  {
    deleteTree(root->rightChild);
  }
  LLMovieNode *here = root->head;
  LLMovieNode *temp;

  while(here != nullptr)
  {
    temp = here -> next;
    delete root -> head;
    root -> head = temp;
    here = root -> head;
  }
  root->head = nullptr;
  delete root->head;
  delete root;
  return;
}


TreeNode *searchTree(TreeNode *root, string title);

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  LLMovieNode *LLnode = new LLMovieNode(ranking, title, year, rating);

  if(searchTree(root, LLnode->title) == nullptr)
  {
    TreeNode *Tnode = new TreeNode;
    Tnode->titleChar = title[0];

    if(root == nullptr)
    {
      root = Tnode;
      root->head = LLnode;
      root->head->next = nullptr;
      return;
    }

    TreeNode *temp = root;
    TreeNode *parent = nullptr;

    while(temp != nullptr)
    {
      parent = temp;
      if(Tnode->titleChar < temp->titleChar)
      {
        temp = temp->leftChild;
      }
      else if(Tnode -> titleChar > temp -> titleChar)
      {
        temp = temp->rightChild;
      }
      else
      {
        Tnode = temp;
        //break;
      }
    }
    if(Tnode != temp)
    {
      if(Tnode->titleChar < parent->titleChar)
      {
        parent->leftChild = Tnode;
        Tnode->parent = parent;
        Tnode -> head = LLnode;
      }
      else
      {
        parent->rightChild = Tnode;
        Tnode->parent = parent;
        Tnode -> head = LLnode;
      }
    }
  }


  else
  {
    TreeNode *Tnode = searchTree(root, LLnode->title);
    if(Tnode -> head == nullptr)
    {
      Tnode->head = LLnode;
      Tnode->head->next = nullptr;
    }
    else
    {
      LLMovieNode *temp1 = Tnode->head;
      LLMovieNode *prev = temp1;

      if(temp1->title.compare(LLnode->title) > 0)
      {

        LLnode->next = Tnode->head;
        Tnode->head = LLnode;
      }
      else
      {
        while(temp1 != nullptr)
        {
          if(temp1->title.compare(LLnode->title) <= 0)
          {
            if(temp1->next == nullptr)
            {
                temp1->next = LLnode;
                LLnode-> next = nullptr;
                return;
            }
              prev = temp1;
              temp1 = temp1->next;
          }
          else
          {
            prev->next = LLnode;
            LLnode->next = temp1;
            return;
          }
        }
      }
    }
  }
}




TreeNode *searchTree(TreeNode *root, string title)
{
  char firstLetter = title[0];
  if(root == nullptr)
  {
    return root;
  }
  else if(root->titleChar == firstLetter)
  {
    return root;
  }
  else if(root->titleChar > firstLetter)
  {
    return searchTree(root->leftChild, title);
  }
  else
  {
    return searchTree(root->rightChild, title);
  }
}

LLMovieNode *searchLinked(LLMovieNode *head, string title)
{
  if(head == nullptr)
  {
    return head;
  }
  else if(head->title == title)
  {
    return head;
  }
  else
  {
    return searchLinked(head->next, title);
  }
}

TreeNode *getMin(TreeNode *n)
{
	while(n->leftChild != nullptr)
	{
		n = n->leftChild;
	}
	return n;
}


void MovieTree::deleteMovie(string title)
{
  TreeNode *Tsearch = searchTree(root, title);


  if(Tsearch == root)
  {
   LLMovieNode *LLsearch = searchLinked(Tsearch->head, title);

      if(Tsearch->head == LLsearch)
            {
              Tsearch->head = LLsearch->next;
              delete LLsearch;
              //Tsearch->head = nullptr;

              return;
            }
            else
            {
                LLMovieNode *prev = nullptr;
                LLMovieNode *temp = Tsearch->head;
                while(temp != LLsearch)
                {
                  prev = temp;
                  temp = prev -> next;
                }
                prev->next = LLsearch->next;
                delete(LLsearch);
                return;
            }
        //delete root->head;
        delete root;
  }
  else
  {
      if(Tsearch == nullptr)
      {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
      }
      LLMovieNode *LLsearch = searchLinked(Tsearch->head, title);
      if(LLsearch == nullptr)
      {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
      }
      else if(Tsearch->head->next == nullptr)
      {
        Tsearch->head = nullptr;
        delete LLsearch;

        if((Tsearch->leftChild == NULL) && (Tsearch->rightChild == NULL))
        {
          if(Tsearch->parent == nullptr)
          {
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->leftChild == Tsearch)
          {
            Tsearch->parent->leftChild = nullptr;
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->rightChild == Tsearch)
          {
            Tsearch->parent->rightChild = nullptr;
            delete Tsearch;
            return;
          }
        }
        else if(Tsearch->leftChild == nullptr)
        {
          Tsearch->rightChild->parent = Tsearch->parent;
          if(Tsearch->parent == nullptr)
          {
            root = Tsearch->rightChild;
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->leftChild == Tsearch)
          {
            Tsearch->parent->leftChild = Tsearch->rightChild;
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->rightChild == Tsearch)
          {
            Tsearch->parent->rightChild = Tsearch->rightChild;
            delete Tsearch;
            return;
          }
        }
        else if(Tsearch->rightChild == nullptr)
        {
          if(Tsearch->parent == nullptr)
          {
            root = Tsearch->leftChild;
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->leftChild == Tsearch)
          {
            Tsearch->parent->leftChild = Tsearch->leftChild;
            delete Tsearch;
            return;
          }
          else if(Tsearch->parent->rightChild == Tsearch)
          {
            Tsearch->parent->rightChild = Tsearch->leftChild;
            delete Tsearch;
            return;
          }
        }
        else
        {
          TreeNode *min = getMin(Tsearch->rightChild);

          if(min == Tsearch->rightChild)
          {
            min->leftChild = Tsearch->leftChild;
            Tsearch->leftChild->parent = min;
            if(Tsearch->parent == nullptr)
            {
              root = min;
              delete Tsearch;
              return;
            }
            else if(Tsearch == Tsearch->parent->leftChild)
            {
              min->parent = Tsearch->parent;
              Tsearch->parent->leftChild = min;
              delete Tsearch;
              return;
            }
            else if(Tsearch == Tsearch->parent->rightChild)
            {
              min->parent = Tsearch->parent;
              Tsearch->parent->rightChild = min;
              delete Tsearch;
              return;
            }
          }
          else
          {
            min->parent->leftChild = min->rightChild;
            min->rightChild->parent = min->parent;
            min->leftChild = Tsearch->leftChild;
            min->rightChild = Tsearch->rightChild;
            min->leftChild->parent = min;
            min->rightChild->parent = min;
            if(Tsearch->parent == NULL){

                root = min;
                delete(Tsearch);
                return;
            }
            else if(Tsearch->parent->leftChild == Tsearch){
                min->parent = Tsearch->parent;
                Tsearch->parent->leftChild = min;
                delete(Tsearch);
                return;
            }
            else if (Tsearch->parent->rightChild == Tsearch){
                min->parent = Tsearch->parent;
                Tsearch->parent->rightChild = min;
                delete(Tsearch);
                return;
            }
          }
        }
      }
      else
      {
            if(Tsearch->head == LLsearch)
            {
              Tsearch->head = LLsearch->next;
              delete LLsearch;
              return;
            }
            else
            {
                LLMovieNode *prev = nullptr;
                LLMovieNode *temp = Tsearch->head;
                while(temp != LLsearch)
                {
                  prev = temp;
                  temp = prev -> next;
                }
                prev->next = LLsearch->next;
                delete(LLsearch);
                return;
            }
      }
    }
 }
