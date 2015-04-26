#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "Hash.h"

using namespace std;

void Hash::hasher()
{/*
    for (int j = 0;j <tableSize; j++){
    HashTable[j] = new movie;
        HashTable[j] -> title = "empty";
        HashTable[j] -> year = "empty";
        HashTable[j] -> next = NULL;
	}
*/

};

//Inserts movie into hashtable
void Hash::insertMovie(int imdb, string title, string year,int quantity){

int index = hashSum(title);
if (HashTable[index] == NULL)
    {
		HashTable[index]->imdb = imdb;
        HashTable[index]->title = title;
        HashTable[index]->year = year;
        HashTable[index]->quantity = quantity;
        HashTable[index]->next = NULL;
    }else{
    movie* Ptr = HashTable[index];
    movie* n = new movie;
    n->imdb = imdb;
    n->title = title;
    n->year = year;
    n->quantity = quantity;
    n->next = NULL;
    while(Ptr->next != NULL)
    {
      Ptr = Ptr->next;
    }
    Ptr->next = n;
}
};

Deletes movie from a hashTable
void Hash::DelMovie(string title)
{
    movie* Ptr = HashTable[hashSum(title)];


            for (int j = 0; j< numItems(hashSum(title));j++)
            {
                if(j==0 && Ptr->title == title)
            {
				if(Ptr->next == NULL){
					cout<< "No Movie Found"<< endl;
					break;
				}
              //  Ptr->title = "empty";
              //  Ptr->year = "empty";
                delete[Ptr];
                break;
            }
            if(Ptr->title == title){
				Ptr->next = Ptr->next->next;
			}else{
				Ptr = Ptr->next;
			}
				
            
            }

};

//counts numberof items in chain
int Hash::numItems(int index)
{
    int count = 0;

    if (HashTable[index]->title == "empty")
    {
        return count;
    }else{
    count++;
    movie* Ptr = HashTable[index];
    while(Ptr->next != NULL)
    {
        count++;
        Ptr = Ptr->next;
    }

    }
    return count;

};

//Hash sum algorithm for indexing
int Hash::hashSum(string x/*, int s*/)
{

int sum = 0;
for (unsigned int i = 0; i<x.length(); i++){
    sum = sum + x[i];
    }
sum = sum % tableSize/*s*/;
return sum;
};

//searches for movie within hash table
void Hash::FindMovie(string title)
{

    movie* Ptr = HashTable[hashSum(title)];


            for (int j = 0; j< numItems(hashSum(title));j++)
            {
                if(Ptr->title == title)
            {
                cout << hashSum(title) << ":" << Ptr->title << ":" << Ptr->year << endl;
            }else{
            Ptr = Ptr->next;
            }
        }



};

//Prints table
void Hash::PrintTable(int index)
{
movie* Ptr = HashTable[index];

        while(Ptr !=NULL)
        {
            cout<< Ptr->title << ":" << Ptr->year << endl << "IMDB Rating: "<<Ptr->imdb<<endl<<"stock: "<<Ptr->quantity<<endl<<endl;
            Ptr = Ptr->next;
		}
		
 
};

//Converts table into a bst

void Hash::convertTable(vector<int> *v){
	for(int i = 0;i < v.size(); i++){
	
movie* Ptr = HashTable[v[i]];

        while(Ptr !=NULL)
        {
            movieList.push_back(Ptr);
            Ptr = Ptr->next;
		}
		for (int j = 0; j <movieList.size();j++){
			movie* newMovie = new movie(Ptr->imdb, Ptr->title, Ptr->year, Ptr->quantity);
			movie * x = root;
		movie * y = NULL;

    if (root == NULL)
        root = newMovie;


    else
    {

        while (x != NULL)
        {
 
            y = x;
            if(newMovie->title.compare(x->title) < 0)
                x = x->Lchild;
            else
                x = x->Rchild;

        }


        newMovie->parent = y;

        if (newMovie->title.compare(y->title) < 0)
            y->Lchild = newMovie;
        else
            y->Rchild = newMovie;
    }

	}
}
	};

