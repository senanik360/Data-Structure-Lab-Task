#include<iostream>
using namespace std;
class bnode
{
public:
    int info;
    bnode *left, *right;
};
class bst
{
public :
    bnode *root;
    bst
    {
        root=NULL;
    }
    void creat (int);
    void insertAll(int a[], int aSize);
    void traverse ();
    void pre_order (bnode *root);
    void inorder(bnode *root);
    void post_order(bnode *root);
};
void bst :: create (int element)
{
    if (root==NULL)
    {
        root = new bnode;
        root->info = element;
        root->left=root->right=NULL;
        return;
    }
    bnode *temp, *r;
    temp = new bnode;
    temp -> info=element;
    temp -> left = temp->right=NULL;
     r = root;
     while(t!=NULL){
        if(element < r->info){

        }
     }
}

