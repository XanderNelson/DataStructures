enqueue-always add at tail
dequeue- remove the element- fifo

implementations-
  simple linear
  circular array

circular array
  -allow for both the head and tail to shift when enqueueing and dequeueing

EX

const int MAXSIZE = 5;

class QueArrCir
{
  private:
    int head, tail, queSize;
    string a[MAXSIZE];
  public:
    QueArrCir();
    bool isEmpty();
    bool isFull();
    void enque(string newItem);
    string deque();
};


QueArrCir::QueArrCir()
{
  head = 0;
  tail = 0;
  queSize = 0;
}

bool QueArrCir::isEmpty()
{
  if(queSize == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool QueArrCir::isFull()
{
  if(queSize == MAXSIZE)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void QueArrCir::enque(string newItem)
{
  if(!isFull)
  {
    a[tail] = newItem;
    queSize++;

    if(tail == MAXSIZE-1)
    {
      tail = 0;
    }
    else
    {
      tail++;
    }
  }
  else
  {
    cout << "Queue is full" << endl;
  }
}

string QueArrCir::deque()
{
  string output;

  if(!isEmpty)
  {
    output= a[head];
    queSize--;
    if(head == MAXSIZE-1)
    {
      head = 0;
    }
    else
    {
      head++;
    }
  }
  else
  {
    cout << "Queue empty. returning empty string" << endl;
    output = "";
  }
}

TREES
---------------------------------------------------------------

-Each node has parent
-topmost node is called the root
-each node hsa a key that identifies it
-each node has exactly two children
-if one of the children is non-existent, child is null
-if both children are null, then the node is called a leaf
-self-similarity: a tree is composed of smaller subtrees

Binary search tree (BST)
-special case of binary tree
-ordered structure
-great for being searched
-Rules
  -left child always has smaller key value than the right child

e.g.

  {4,2,3,6,0,9,5}
  {
                    4
               2         6
             0   3      5  9
  }


-for any node in the tree, all nodes in the left subtree
  (of that node) are less than that node value
-all nodes in the right sub-tree are greater than or equal
  to the node value

assume the perfect tree

worst case number of operations: height

As a function of N
N=2^(h+1)-1
h=log2(N+1)-1
O(log2(N))



struct node{
  int key;

  Node *parent;
  Node *LL;//left child
  Node *RL;//right child
};

BST ADT
 private:
   root;
   searchRecursive(node, value);
 public:
    init();
    search(value);
    insert(value);
    disp();//?
    delete(value);
    deleteTree();//destructor


  insert()
  {
    given an existing tree, insert a node w/ key=3;
    1)create new node
      (n) and assign key (3)
    2) Two pointers that well need for traversal
        temp = root;
        prev = null;
    3)Drill down to find next available empty spot
        while(temp!=null)
        {
          prev = temp;
          //check which way to traverse
          if(n(new node)->key < temp->key)
          {
            temp = temp-> leftChild
          }
          else//>=
          {
            temp = temp->rightChild
          }
        }
        //found where to put new node
  }
