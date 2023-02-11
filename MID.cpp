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


class Qu
{
public :
    int queue[size];
    int rear = - 1, front = - 1;
    void enqueue(int);
    int dequeue();
    void display();
};
void Qu :: enqueue(int element)
{
    if (rear == size - 1)
        cout<<"\tQueue Overflow"<<endl;
    else
    {
        if (front == - 1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = element;
    }
}
int Qu :: dequeue()
{
    if (front == - 1 && rear == -1)
    {
        cout<<"\tQueue Underflow ";
        return -1;
    }
    else
    {
        int val = queue[front];
        front++;;
        return val;
    }
}
void Qu :: display()
{
    if (front == - 1)
        cout<<"\tQueue is empty"<<endl;
    else
    {
        for (int i = front; i <= rear; i++)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
}

int main()
{

    int num,n;
    cout<<"Enter the length of the series."<<endl;
    cin>>n;

    Qu q;
    stacks st;
    cout<<"Enter numbers for 1st stack."<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        q.enqueue(num);
    }
    cout<<"Enter numbers for 2nd stack."<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        st.push(num);
    }
    cout<<endl;
    int a,b;
    for(int i=0; i<n; i++)
    {
        a = q.dequeue();
        b = st.pop();
        q.enqueue(a+b);
//        cout<<a<<"+"<<b<<"\t";
    }
    q.display();

    cout<<endl;
}


