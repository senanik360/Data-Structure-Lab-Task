#include<iostream>
using namespace std;
const int size = 100000;
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
};
int stacks :: push(int element)
{
    string t;
    if(top==(size-1))
    {
        cout<<"Can Overflow."<<endl;
        return 0;
    }
    else
    {
        cout<<"Press any key for insert Chips to the Can.";
        cin>>t;
        stack[++top]=element;
        cout<<"\n  "<<element<<" chips inserted"<<endl;
    }
    return 1;
}

class Qu
{
public :
    int queue[size];
    int rear = - 1, front = - 1, count;
    void enqueue(int);
    int dequeue();
    void display();
};
void Qu :: enqueue(int element)
{
    if (rear == size - 1)
        cout<<"\Conveyor Belt Overflow"<<endl;
    else
    {
        if (front == - 1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        cout<<"\n\t-- "<<element<<" Can full --\n"<<endl;
    }
}
int Qu :: dequeue()
{
    if (front == - 1 && rear == -1)
    {
        cout<<"\tConveyor Belt Underflow ";
        return -1;
    }
    else
    {
        int val = queue[front];
        front++;
        if(val==0)
        {
            cout<<"-- There is no Can on the Conveyor belt --\n";
        }
        else
        {
            cout<<"\n -- "<<val<<" No. Can Removed from Conveyor belt. --\n";
            return val;
        }
    }
}
void Qu :: display()
{
    count = 0;
    if (front == - 1)
        cout<<"\tConveyor Belt is empty"<<endl;
    else
    {
        for (int i = front; i <= rear; i++)
        {
            count++;
        }
        cout<<" -- "<<count<<" Cans left in the Conveyor belt. --\n";
    }
}

int main()
{
    int scount, qcount,n,count;
    stacks s;
    Qu q;
    qcount=0;
    do
    {
        qcount++;
        scount=0;
        do
        {
            scount++;
            s.push(scount);
        }
        while(scount<10);
        q.enqueue(qcount);
    }
    while(qcount<6);
    if (qcount>=6)
    {
        cout<<"-- Conveyor belt is full with Can. --"<<endl;
    }
    cout<<endl;

    do
    {
        cout<<"\nDo you want to Remove any can from conveyor belt ?\n\t1.Yes  2.No\n";
        cin>>n;
        count = 0;
        if(n==1)
        {
            q.dequeue();
            count++;
        }
        else
        {
            q.display();
        }
    }
    while(count!=0);
}


