#include <iostream>
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"
#include "Hash.cpp"

using namespace std;

Tree::Tree()
{
    root = NULL;

}

Tree::~Tree()
{
    DeleteAll(root);


}

/* Used to delete all nodes in the tree */
void Tree::DeleteAll(MovieNode * node)
{
    // clean to the left
    if (node->leftChild != NULL)
        DeleteAll(node->leftChild);
    // clean to the right
    if (node->rightChild != NULL)
        DeleteAll(node->rightChild);
    // delete this node
    delete node;

    return;
}



/* Helper for the printMovieInventory recursive function */
void Tree::printMovieInventory()
{


    printMovieInventory(root);

    return;
}

/* Prints the inventory(in order traversal) */
void Tree::printMovieInventory(MovieNode * node)
{

    // Left Node
    if(node->leftChild!=NULL)
        printMovieInventory(node->leftChild);

    // Value
    cout<< node->title << ":" << node->year << endl << "IMDB Rating: "<<node->imdb<<endl<<"stock: "<<node->quantity<<endl;


    // Right Node
    if(node->rightChild!=NULL)
		printMovieInventory(node->rightChild);


    return;
}



void Tree::addMovieNode(int imdb, std::string title, int yearear, int quantity)
{

    MovieNode * newMovie = new MovieNode(ranking,title,year,quantity);
    MovieNode * x = root;
    MovieNode * y = NULL;

    // Do we have an empty tree?
    if (root == NULL)
        root = newMovie;

    // If the tree is not empty
    else
    {

        // Get to the end of the tree, where we need to add this node.
        while (x != NULL)
        {

            y = x;
            if(newMovie->title.compare(x->title) < 0)
                x = x->leftChild;
            else
                x = x->rightChild;

        }

        // set the parent of this node to be the previous node.
        newMovie->parent = y;

        // Determine which child to this previous node we are at.
        if (newMovie->title.compare(y->title) < 0)
            y->leftChild = newMovie;
        else
            y->rightChild = newMovie;
    }

    return;

}

/* used to find movie information, provides info or says movie can't be found */
void Tree::findMovie(std::string title)
{

    // Find the movie
    MovieNode * foundMovie = searchMovieTree(root,title);
    if (foundMovie != NULL)
    {
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->imdb << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
    }
    else
        cout << "Movie not found." << endl;

    return;
}

MovieNode* Tree::searchMovieTree(MovieNode * node, std::string title)
{

    // If the node is NULL, we just return. Failed to find node.
    if (node == NULL)
        return NULL;
    // Return this node if it is the one we are searching for
    else if (node->title == title)
        return node;

    // Else return the correct recursive call.
    else
    {
        if(title.compare(node->title) < 0)
            return searchMovieTree(node->leftChild,title);

        else
            return searchMovieTree(node->rightChild,title);
    }
}

void Tree::rentMovie(std::string title)
{


    int stockOutput = 0;

    MovieNode * foundMovie = searchMovieTree(root,title,travLog);

    // If the movie exists.
    if (foundMovie != NULL)
    {
        // If it's in stock.
        if (foundMovie->quantity > 0)
        {
            cout << "Movie has been rented." << endl;
            foundMovie->quantity--;
            stockOutput = foundMovie->quantity;



            //change this to print information
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << foundMovie->ranking << endl;
            cout << "Title:" << foundMovie->title << endl;
            cout << "Year:" << foundMovie->year << endl;
            cout << "Quantity:" << foundMovie->quantity << endl;
            // If the stock is 0 delete the movie
            if (foundMovie->quantity == 0)
                deleteMovieNode(foundMovie->title);

        }
        // If it's not in stock.
        else
            cout << "Movie out of stock." << endl;

    }
    // If it doesn't exist.
    else
        cout << "Movie not found." << endl;

}

void Tree::deleteMovieNode(std::string title)
{

    MovieNode * foundMovie = searchMovieTree(root,title);

    // If the movie exists
    if (foundMovie != NULL)
    {
        // If it has no children
        if (foundMovie->leftChild == NULL && foundMovie->rightChild == NULL)
        {
            // If this node is the left child, set the parents left child to NULL
            if (foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = NULL;
            // Else, this node is the right child, set that to NULL
            else
                foundMovie->parent->rightChild = NULL;
            // Delete the node
            delete foundMovie;

        }
        // If it only has a left child
        else if (foundMovie->rightChild == NULL)
        {
            if (foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = foundMovie->leftChild;
            else
                 foundMovie->parent->rightChild = foundMovie->leftChild;

            delete foundMovie;

        }
        // If it only has a right child
        else if (foundMovie->leftChild == NULL)
        {
            if (foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = foundMovie->rightChild;
            else
                 foundMovie->parent->rightChild = foundMovie->rightChild;

            delete foundMovie;
        }

        // Node has two children, we need the smallest node from the right child
        else
        {
            // Start on the right sub-tree
            MovieNode * replacementNode = foundMovie->rightChild;

            // search for the smallest left child
            while (replacementNode->leftChild != NULL)
            {
                replacementNode = replacementNode->leftChild;
            }

            // Swap in all the info from the replacement to this node we are "deleting"
            foundMovie->title = replacementNode->title;
            foundMovie->quantity = replacementNode->quantity;
            foundMovie->ranking = replacementNode->imdb;
            foundMovie->year = replacementNode->year;


            // If the replacement node has a right child, update the parent
            if (replacementNode->rightChild != NULL)
                replacementNode->rightChild->parent = replacementNode->parent;

            // If the replacement node is a left child
            if (replacementNode->parent->leftChild == replacementNode)
                replacementNode->parent->leftChild = replacementNode->rightChild;
            // If it is a right child
            else
                replacementNode->parent->rightChild = replacementNode->rightChild;

            // Delete the node
            delete replacementNode;
        }

       
    }
    // If it doesn't exist
    else
        cout << "Movie not found." << endl;



};
void Tree::UpdateFile(){


ofstream myfile ("OrganizedMoves.txt");

    updateMovieInventory(root);
    myfile.close();

    return;
};

/* Prints the inventory(in order traversal) */
void Tree::updateMovieInventory(MovieNode * node)
{

    // Left Node
    if(node->leftChild!=NULL)
        updateMovieInventory(node->leftChild);

    // Value
    myfile<<node->imdb<<","<<node->title<< ","<< node->year  <<","<<node->quantity<< endl;


    // Right Node
    if(node->rightChild!=NULL)
		updateMovieInventory(node->rightChild);


    return;
}


	};
	
	void Tree::convertTable(){
		converter(root);
		
		return;
		};

void Tree::converter(MovieNode * node){
	Hash y;
    // Left Node
    if(node->leftChild!=NULL)
        updateMovieInventory(node->leftChild);

    // Value
    y.insertMovie(node->imdb,node->title, node->year,node->quantity);


    // Right Node
    if(node->rightChild!=NULL)
		updateMovieInventory(node->rightChild);


    return;
};
