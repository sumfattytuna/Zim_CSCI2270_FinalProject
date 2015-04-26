#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#ifndef HASH_H
#define HASH_H
using namespace std;

class Hash{
private:
    static const int tableSize = 131;

    struct movie{
	int imdb;
    string title;
    string year;
    int quantity;
    movie* next;
    movie* Lchild;
    movie* Rchild;
    movie* Parent;
};
        movie(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        imdb = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        leftChild = NULL;
        rightChild = NULL;
    }
    //}
    ;
   
	 movie *root;
    movie* HashTable[tableSize];
    vector<movie> movielist;
public:
    void hasher();

int hashSum(string x/*, int s*/);
void insertMovie(int imdb, string title, string year, int quantity);
void DelMovie(string title);
void FindMovie(string title);
int numItems(int index);
void PrintTable(int index);
void convertTable(vector<int>* v);
};





#endif  /*HASH_H */
