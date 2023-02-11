#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class list
{
    node *start, *end;
    int node_count;
public:
    list()
    {
        start = NULL;
    }
    void create_end(int);
    void insert(int, int);
    void deletenode(int);
    void display();
};
void list::create_end(int e)
{
    node *current;
    node_count=node_count+1;
    if(start == NULL)
    {

        start = new node;
        start->data=e;
        start->next=NULL;
        end=start;
    }
    else
    {
        current = new node;
        current ->data=e;
        current->next=NULL;
        end->next=current;
        end=current;
    }
}
void list :: insert (int el, int pos)
{
    node *current, *newnode, *prev = NULL;
    if(pos<=node_count+1)
    {
        current = start;
        newnode = new node;
        newnode->data=el;
        newnode->next=NULL;
        int i = 1;
        while(i<pos)
        {
            prev=current;
            current = current->next;
            i++;
        }
        if(prev==NULL)
        {
            newnode->next=start;
            start=newnode;
            node_count=node_count+1;
            return;
        }
        else
        {
            newnode->next=current;
            prev->next=newnode;
            node_count=node_count+1;
        }

    }
    else
    {
        cout<<"Size less than position, Try again - \n";
    }
}
void list::display()
{
    node *current;
    current=start;
    if(start==NULL)
    {
        cout<<"Linked List is null."<<endl;
    }
    else
    {
        cout<<"Linked list : ";
        while(current !=NULL)
        {
            cout<<current->data<<"  ";
            current = current->next;
        }
        cout<<endl;
    }

}
void list::deletenode(int element)
{
    node* current, *prev=NULL;
    int found=0;
    current=start;
    while(current!=NULL)
    {
        if(current->data==element)
        {
            found=1;
            break;
        }
        prev=current;
        current=current->next;
    }
    if(found)
    {
        if(prev==NULL)
        {
            prev=current->next;
            start=prev;
        }
        else
        {
            prev->next=current->next;
        }
        delete current;
    }
    else
    {
        cout<<"Element not in the list"<<endl;
    }
}
main()
{
    list l;
    l.create_end(10);
    l.create_end(20);
    l.create_end(30);
    l.create_end(-1);
    l.display();
    l.insert(40,2);
    l.display();
    l.deletenode(10);
    l.display();

}
