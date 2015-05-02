#ifndef TREE_H
#define TREE_H



struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        imdb = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
        leftChild = NULL;
        rightChild = NULL;
    }

};

class Tree
{
        int opCount;

    public:
        Tree();
        virtual ~Tree();
        void printMovieInventory();
        int countMovieNodes();
        void deleteMovieNode(std::string title);
        void addMovieNode(int imdb, std::string title, int yearear, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);
        void UpdateFile();
        void updateMovieInventory(MovieNode * node);
        void convertTable();


    protected:

    private:
        void DeleteAll(MovieNode * node); //use this for the post-order traversal deletion of the tree
        void printMovieInventory(MovieNode * node);
        int countMovieNodes(MovieNode *node);
        MovieNode* searchMovieTree(MovieNode * node, std::string title);
        MovieNode *root;
        // Count of how many operations we have done.
        //including the json_object in the class makes it global within the class, much easier to work with



};

#endif // TREE_H
