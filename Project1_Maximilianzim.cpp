
//Maximilian Zim
//Assignment 9

#include <iostream>
#include <fstream>  //allows istream/ostream
#include <string>
#include <stdlib.h>
#include <vector>
#include "Hash.cpp"
#include "Tree.cpp"

using namespace std;

int main(){

isHash = true;
int input;
void displayMenu();
vector<int> indList;
Hash h;
Tree t;
//int imdb, quantity;
 string imdb, title, year, quantity;
 bool quit = false;
 t.tree();
 h.hasher();
 bool jaked = true;
 	string fileName;
    while(quit != true)
    {
		jaked =true;
        displayMenu();
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input)
        {
			case 1:
		
			cout << "Enter File Name<< endl;
			cin << fileName;
				ifstream in_stream;
					
						in_stream.open(fileName);
						if (!in_stream)
						{
							cout << "Could not open file\n";
								return;
							}


					while (!in_stream.eof())
					{
					title ="";
					getline(in_stream, imdb, ',');
					getline(in_stream, title, ',');
					getline(in_stream, year, ',');
				getline(in_stream, quantity); // "\n" is the default delimiter
				if (title != "")
					{
					h.insertMovie(stoi(imdb), title, year, stoi(quantity));
					}
					}

				
				break;
             case 2:
				cout << "Enter title:" << endl;
                getline(cin,title);
                cout << "Enter imdb rating:" << endl;
                getline(cin,imdb);
                cout << "Enter year:" << endl;
                getline(cin, year);
                cout << "Enter quantity:" << endl;
                getline(cin, quantity);
                if (isHash == true){
                h.insertMovie(imdb, title, year, quantity);
                for (unsigned int i =0;i<indList.size();i++){
					if(h.hashSum(title) == indList[i]){
						jaked = false;}
					}
					if (jaked ==true){
             indList.push_back(h.hashSum(title));
		 }
	 }else{
		 t.addMovieNode(imdb,title, year, quantity);
		 }
                break;

            case 3:
                cout << "Enter title:" << endl;
                getline(cin,title);
                if (isHash == true){
                h.DelMovie(title);
                
			}else{
				t.deleteMovieNode(title);
				}
				break;
            // Find a movie

            case 4:
                cout << "Enter title:" << endl;
                getline(cin,title);
                if (isHash == true){
                h.FindMovie(title);
			}else{
				t.findMovie(title);
			}
                break;
                
			case 5:
			if (isHash == true){
                h.convertTable(indList);
                isHash = false;
			}else{
				t.convertTable();
			}
                cout << "Table converted"<< endl;
                break;

            case 6:
            if (isHash == true){
				for (unsigned int i = 0;i<indList.size();i++){
				cout <<i;
                h.PrintTable(indList[i]);
			}else{
				t->printMovieInventory();
				}
			}
			break;
			
			case 7:
			if (isHash == true){
				for (unsigned int i = 0;i<indList.size();i++){
				cout <<i;
                h.UpdateFiler(indList[i]);
			}else{
				t.UpdateFile();
				}
			}

			break;
            // Quit
            case 8:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
}


void displayMenu()
{
    cout << "======Main Menu=====" << endl;
    cout << "1. Read in a movie file" << endl;
    cout << "2. Insert movie" << endl;
    cout << "3. Delete movie" << endl;
    cout << "4. Find movie" << endl;
    cout << "5. Convert to a Search Tree" << endl;
    cout << "6. Print table contents" << endl;
    cout << "7. Export updated file" << endl;
    cout << "8. Quit" << endl;

 return;
}
