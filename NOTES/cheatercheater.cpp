#include <iostream>

#include "MovieTree.hpp"

using namespace std;



MovieTree::MovieTree(){

    root = NULL;

}



MovieTree::~MovieTree(){

    DeleteAll(root);

}



void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){

    //get the first letter of the title and set as the letter variable to be used to create tree

    char letter = title[0];

    //create a new movie node with all the info to be added to it's correct linked list

    MovieNodeLL* newMovie = new MovieNodeLL(ranking, title, releaseYear, quantity);

    //create a BST node with the new letter

    MovieNodeBST* newIndex = new MovieNodeBST(letter);



    //if the BST is empty, set the new BST and lined list nodes as root and head respectively

    if (root == NULL){

        root = newIndex;

        root->head = newMovie;

        root->head->next = NULL;

        return;

    }





    MovieNodeBST* parent = NULL;

    MovieNodeBST* tmp = root;



    //go through and find the correct position for the new BST node

    while(tmp != NULL){

        parent = tmp;

        if(newIndex->letter < tmp->letter){

            tmp = tmp->leftChild;

        }

       else if(newIndex->letter == tmp->letter){

            newIndex = tmp;

            break;

        }

        else{

            tmp = tmp->rightChild;

        }

    }



    // if the newIndex was not set equal to the tmp, we need to deal with the newIndex node as a new node in the BST

    if (newIndex != tmp){



        if (newIndex->letter < parent->letter){

            parent->leftChild = newIndex;

            newIndex->parent = parent;



        }



        else if (newIndex->letter > parent->letter){

            parent->rightChild = newIndex;

            newIndex->parent = parent;



        }

    }



    //check to see if the index has no movie yet (is a new BST node) and if so, add newMovie node to head of LL associated with this index(letter)

    if (newIndex->head == NULL){

        newIndex->head = newMovie;

        newIndex->head->next = NULL;



    }



        //if there is already node(s) in the LL associated with the index, then add the newMovie to the LL alphabetically

    else{

        int i = 1;

        MovieNodeLL* current = newIndex->head;

        while(current!=NULL){

           while(current->title[i] == newMovie->title[i]){

                i++;

                //we have made it to the end of the node, it is shorter than the newMovie

                //check the next node

                if(i == current->title.length()){

                    //check if curren->next if null before continueing

                    if(current->next == NULL){

                        //set the newMovie as the tail

                        current->next = newMovie;

                        newMovie->next = NULL;

                        i =1;

                        return;



                    }

                    else{

                        current = current->next;

                        i = 1;

                    }

                }



                    //if the newMovie is shorter than the existing movie, it should go ahead in the List

                else if(i == newMovie->title.length()){

                    //if the current Node is the head, handle this case

                    if(current == newIndex->head){

                        newMovie->next = newIndex->head;

                        newIndex->head = newMovie;

                        return;

                    }



                    else{

                        MovieNodeLL* previous = NULL;

                        MovieNodeLL* temp = newIndex->head;

                        //find the node before the current node to find where the newMovie is being put behind

                        while(temp != current){

                            previous = temp;

                            temp = temp->next;

                        }

                        newMovie->next = current;

                        previous->next = newMovie;

                        return;

                    }

                }



           }

             if(current->title[i] < newMovie->title[i]){

                //check if current->next if null before continueing

                if(current->next == NULL){

                    //set the newMovie as the tail

                    current->next = newMovie;

                    newMovie->next = NULL;

                    i =1;

                    return;



                }

                else{

                    current = current->next;

                    i = 1;

                }

            }



                //if the newMovie is ahead of the previous alphabetically, position it accordingly

            else if(current->title[i] > newMovie->title[i]){

                if(current == newIndex->head){

                    newMovie->next = newIndex->head;

                    newIndex->head = newMovie;

                    return;

                }



                else{

                    MovieNodeLL* previous = NULL;

                    MovieNodeLL* temp = newIndex->head;

                    while(temp != current){

                        previous = temp;

                        temp = temp->next;

                    }

                    newMovie->next = current;

                    previous->next = newMovie;

                    return;

                }

            }

        }



    }

    return;

}



MovieNodeBST* MovieTree::searchBST(MovieNodeBST* node, string title){

   char letter = title[0];

    if(node == NULL){

        return node;

    }



    else if (node->letter == letter){

        return node;

    }



    else if(node->letter > letter){

        return searchBST(node->leftChild, title);

    }

    else

        return searchBST(node->rightChild, title);



}



MovieNodeLL* MovieTree::searchLL(MovieNodeLL* node, string title){

    if(node == NULL){

        return node;

    }



    else if(node->title == title){

        return node;

    }



    else

        return searchLL(node->next, title);

}



void MovieTree::findMovie(string title){

    MovieNodeBST* index = searchBST(root, title);

    if (index == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }



    MovieNodeLL* movie = searchLL(index->head, title);



    if (movie == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }



    else

        cout << "Movie Info:" << endl;

    cout << "===========" << endl;

    cout << "Ranking:" << movie->ranking << endl;

    cout << "Title:" << movie->title << endl;

    cout << "Year:" << movie->year << endl;

    cout << "Quantity:" << movie->quantity << endl;



    return ;

}



MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST* node){

    MovieNodeBST* x = node;

    while(x->leftChild!=NULL){

        x = x->leftChild;

    }

    return x;

}





void MovieTree::deleteMovieNode(string title){

    //find the location of the node with the movie to delete

    MovieNodeBST* index = searchBST(root, title);

    if (index == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }

    //find the movie

    MovieNodeLL* delMovie = searchLL(index->head, title);



    if (delMovie == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }



        //check if the movie being deleted is the only node in the list, we need to delete the BST node as well

    else if ((delMovie == index->head) && (index->head->next==NULL)){



        index->head = NULL;

        delete(delMovie);

       if((index->leftChild == NULL) && (index->rightChild == NULL)){

            if (index->parent== NULL){

                delete(index);

                return;

            }

            else if(index->parent->leftChild==index){

                index->parent->leftChild = NULL;

                delete(index);

                return;

            }

            else if(index->parent->rightChild == index){

                index->parent->rightChild = NULL;

                delete(index);

                return;

            }





        }



            //check if index has right or left subchildren, handle these cases respectively

        else if (index->leftChild == NULL){

            index->rightChild->parent = index->parent;

            if (index->parent == NULL){

                root = index->rightChild;

                delete(index);

                return;

            }



            else if(index->parent->leftChild == index){

                index->parent->leftChild = index->rightChild;

                delete(index);

                return;

            }

            else if (index->parent->rightChild == index){

                index->parent->rightChild = index->rightChild;

                delete(index);

                return;

            }

        }



        else if(index->rightChild == NULL){

            if (index->parent == NULL){

                root = index->leftChild;

                delete(index);

                return;

            }

            else if(index->parent->leftChild == index){

                index->parent->leftChild = index->leftChild;

                delete(index);

                return;

            }

            else if (index->parent->rightChild == index){

                index->parent->rightChild = index->leftChild;

                delete(index);

                return;

            }





        }



        else{



           MovieNodeBST* min = treeMinimum(index->rightChild);



            if(min == index->rightChild){

                min->leftChild = index->leftChild;

                index->leftChild->parent = min;



                if(index->parent == NULL){

                    //index->leftChild->parent = NULL;

                    root = min;

                    delete(index);

                    return;

                }





                else if(index==index->parent->leftChild){



                    min->parent = index->parent;

                    index->parent->leftChild = min;

                    delete(index);

                    return;

                }



                else if (index==index->parent->rightChild){



                    min->parent = index->parent;

                    index->parent->rightChild = min;

                    delete(index);

                    return;

                }



            }



            else{



                min->parent->leftChild = min->rightChild;



                min->rightChild->parent = min->parent;



                min->leftChild = index->leftChild;



                min->rightChild = index->rightChild;



                min->leftChild->parent = min;

                min->rightChild->parent = min;



                if(index->parent == NULL){

                    //index->leftChild->parent = NULL;

                    root = min;

                    delete(index);

                    return;

                }

                else if(index->parent->leftChild == index){



                    min->parent = index->parent;

                    index->parent->leftChild = min;

                    delete(index);

                    return;

                }



                else if (index->parent->rightChild == index){



                    min->parent = index->parent;

                    index->parent->rightChild = min;

                    delete(index);

                    return;

                }





            }

        }

    }



    else{



        if(index->head == delMovie){



            index->head = delMovie->next;



            delete(delMovie);

            return;

        }

        MovieNodeLL* previous = NULL;

        MovieNodeLL* tmp = index->head;

        while(tmp != delMovie){

            previous = tmp;

            tmp = previous->next;

        }



        previous->next = delMovie->next;

        delete(delMovie);

        return;

    }

    return;

}



void MovieTree::rentMovie(string title){

    MovieNodeBST* index = searchBST(root, title);

    if (index == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }



    MovieNodeLL* movie = searchLL(index->head, title);



    if (movie == NULL){

        cout << "Movie Not Found." << endl;

        return;

    }



    else

        cout << "Movie has been rented." << endl;

    cout << "Movie Info:" << endl;

    cout << "===========" << endl;

    cout << "Ranking:" << movie->ranking << endl;

    cout << "Title:" << movie->title << endl;

    cout << "Year:" << movie->year << endl;

    movie->quantity--;

    cout << "Quantity:" << movie->quantity << endl;





    if (movie->quantity == 0)

        deleteMovieNode(movie->title);



    return ;

}



void MovieTree::countMovieNodes(MovieNodeBST *node, int *c){

    if (root == NULL){

        return;

    }

    //go through in post order and count all movies for each node

    if(node->leftChild!=NULL){

        countMovieNodes(node->leftChild, c);

    }

    if(node->rightChild!=NULL){

        countMovieNodes(node->rightChild, c);

    }

    //go through each LL for each node and count up the movies

    MovieNodeLL* current = node->head;

    while(current!=NULL){

        *c+=1;

        //cout << *c <<". "<< current->title << endl;

        current= current->next;

    }





    return;

}



int MovieTree::countMovieNodes(){

    int count = 0;

    int* counter = &count;

    countMovieNodes(root, counter);

    return *counter;

}



void MovieTree::printMovieInventory(MovieNodeBST * node){

    if(root == NULL){

        return;

    }
    //in order traversal through movie tree

    if(node->leftChild != NULL){

        printMovieInventory(node->leftChild);
    }

    MovieNodeLL* current = node->head;

    while(current!=NULL){

        cout << "Movie: " << current->title << " " << current->quantity<< endl;

        //cout << *c <<". "<< current->title << endl;

        current= current->next;

    }

    if(node->rightChild!=NULL){

        printMovieInventory(node->rightChild);

    }



    return;

}



void MovieTree::printMovieInventory(){

    printMovieInventory(root);

    return;

}



void MovieTree::DeleteAll(MovieNodeBST* node){

    if (root == NULL){

        return;

    }

    //go through in post order and count all movies for each node

    if(node->leftChild!=NULL){

        DeleteAll(node->leftChild);

    }

    if(node->rightChild!=NULL){

        DeleteAll(node->rightChild);

    }

    //go through each LL for each node and count up the movies

    MovieNodeLL* current = node->head;

    MovieNodeLL* temp;

    while(current!=NULL){

        temp = node->head->next;

        cout << "Deleting: " << node->head->title << endl;

        delete node->head;

        node->head = temp;

        current = node->head;

    }

    node->head = NULL;

    delete node;

    return;

}
