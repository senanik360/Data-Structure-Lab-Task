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
public:
    list()
    {
        start = NULL;
    }
    void create_end(int);
    void display();
};
void list::create_end(int e)
{
    node *current;
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
main()
{
    list l;
    l.create_end(10);
    l.create_end(20);
    l.create_end(30);
    l.create_end(-1);
    l.display();
}
