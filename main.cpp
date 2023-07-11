#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

struct tree
{
    int num;
    tree* left = nullptr;
    tree* right = nullptr;
};

tree* findPlace (tree* (&root), int number)
{
    if (number < root->num)
    {
        if (root->left)
        {
            findPlace(root->left, number);
        }
        else
        {
            root->left = new tree;
            return root->left;
        }
    }
    else if (number > root->num)
    {
        if (root->right)
        {
            findPlace(root->right, number);
        }
        else
        {
            root->right = new tree;
            return root->right;
        }
    }
    else
        return root;
}

int depthCalc (tree *root)
{
    if (!(root))
        return 0;
    if ((root->left == nullptr) && (root->right == nullptr))
        return 1;
    if (!(root->left))
        return depthCalc(root->right) + 1;
    if (!(root->right))
        return depthCalc(root->left) + 1;
    if (depthCalc(root->left) >= depthCalc(root->right))
        return depthCalc(depthCalc(root->left) + 1;
    else if (depthCalc(root->left) < depthCalc(root->right))
        return depthCalc(depthCalc(root->right) + 1;
}

void avlTree (tree* (&root))
{
    int weight = 0;
    int height = depthCalc(root);
    if (weight > 1)
    {

    }
}

void pushNum (tree* (&root), int number, bool firstFlag)
{
    tree* rootBackup = nullptr;
    tree* leaf = nullptr;
    if (firstFlag == false)
    {
        rootBackup = root;
        leaf = findPlace (root, number);
    }
    leaf->num = number;
    firstFlag = false;
    avlTree (root);
}

void readFile (tree* (&root))
{
    ifstream readNum ("input.txt");
    node* leaf = tree;
    if (readNum.is_open())
    {
        while (readNum.eof() == false)
        {
            readNum >> number;
            pushNum (leaf, number);
        }
        readNum.close();
    }
    else
    {
        cout << "Error: Can't read input file!" << endl;
        assert (readNum.is_open() == true);
    }
}

int main()
{
    tree* root = new tree;
    readFile(root);
    return 0;
}
