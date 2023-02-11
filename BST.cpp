#include<iostream>
using namespace std;
class bnode
{
public:
    int info ;
    bnode *left, *right;
};
class bst
{
public:
    bnode *root;
    bst()
    {
        root == NULL;
    }
    void create(int);
    void insertAll(int [], int asize);
    void traverse();
    void pre_order(bnode *roote);
    void inorder(bnode *root);
    void post_order(bnode *root);
};
void bst :: traverse ()
{
    //cout<<endl<<"Pre-order : ";
   // pre_order(root);
    //cout<<endl<<"Inorder : ";
    //inorder(root);
    cout<<"Post order : ";
    post_order(root);
}
void bst :: insertAll (int a[], int asize)
{
    for(int i = 0 ; i<asize; i++)
    {
        create(a[i]);
    }
}
void bst :: create (int element)
{
    if(root == NULL)
    {
        root = new bnode;
        root->info=element;
        root->left= root->right=NULL;
        return;
    }
    bnode *temp, *r;
    temp = new bnode;
    temp->info=element;
    temp ->left = temp -> right = NULL;
    r=root;
    while(r!=NULL)
    {
        if(element<r->info)
        {
            if(r->left==NULL)
            {
                r->left = temp;
                break;
            }
            else
            {
                r=r->left;
            }
        }
        else if (element > r->info)
        {
            if(r->right==NULL)
            {
                r->right=temp;
                break;
            }
            else
            {
                r=r->right;
            }
        }
    }
}
void bst :: pre_order(bnode *roote)
{
    if(root!=NULL)
    {
        cout<<roote->left<<" ";
        pre_order(roote->left);
        pre_order(roote->right);
    }
}
void bst :: inorder (bnode *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->info<<" ";
        inorder (root->right);
    }
}
void bst :: post_order(bnode *r)
{
    if(r!=NULL)
    {
        post_order(r->left);
        post_order(r->right);
        cout<<r->info<<" ";
    }
}
main()
{
    bst b;
    int a[]= {35,37,49,65,80,60,40,30,25,27};
    int n = sizeof(a)/sizeof(a[0]);
    b.insertAll(a,n);
    b.traverse ();
}
