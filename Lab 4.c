#include<iostream>
using namespace std;
const int size=5;
class stacks
{
    int stack[size];
    int top;
public:
    stacks()
    {
        top=-1;
    }
    int push(int);
    int pop();
    void display();
};
int stacks :: push(int element)
{
    if(top==(size-1))
    {
        cout<<"Overflow."<<endl;
        return 0;
    }
    else
    {
        stack[++top]=element;
    }
    return 1;
}

int stacks::pop()
{
    int temp=0;
    if(top==-1)
    {
        cout<<"Underflow. "<<endl;
    }
    else
    {
        temp=stack[top--];
    }
    return temp;
}
void stacks::display()
{
    for(int i=top; i>=0; i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

main()
{

    stacks b;
    b.push(12);
    b.push(15);
    b.pop();
    b.display();

}
