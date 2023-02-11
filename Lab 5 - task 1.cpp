#include<iostream>
using namespace std;
class stacknode
{
public :
    int data;
    stacknode *next;
};
class stack
{
    stacknode *top;
public:
    stack();
    void push(int);
    int pop();
    void display();
};
stack :: stack()
{
    top=NULL;
}
void stack :: push(int element)
{
    if(top==NULL)
    {

        top = new stacknode;
        top->data=element;
        top -> next=NULL;
        cout<<element<<" pushed "<<endl;
    }
    else
    {
        stacknode *temp = new stacknode;
        temp ->data=element;
        temp->next=top;
        top=temp;
        cout<<element<<" pushed "<<endl;
    }
}
int stack :: pop()
{
    if(top==NULL)
    {
        cout<<"\tStack is empty "<<endl;
        return 0;
    }
    stacknode* temp = top;
    int e1=temp->data;
    top = top->next;
    delete temp;
    return e1;
}
void stack :: display()
{
    stacknode *current;
    current = top;
    cout<<"\tElements in the stack are : "<<endl;
    while (current !=NULL)
    {
        cout<<current->data<<" ";
        current = current ->next;
    }
    cout<<endl;
}
int main ()
{
    stack s;
    s.pop();
    s.push(12);
    s.push(15);
    s.push(20);
    s.display();
    s.pop();
    s.display();

}
