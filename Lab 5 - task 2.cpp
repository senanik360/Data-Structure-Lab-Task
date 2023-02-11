#include <iostream>
using namespace std;

class Qu
{
    int const size = 5;
public :
    int queue[5];
    int rear = - 1, front = - 1;
    void enqueue(int);
    void dequeue();
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
        cout<<element<<"  Enqueued successfully."<<endl;
    }
}
void Qu :: dequeue()
{
    if (front == - 1 && rear == -1)
    {
        cout<<"\tQueue Underflow ";
        return ;
    }
    else
    {
        cout<< queue[front] <<"  Dequeued successfully." <<endl;
        front++;;
    }
}
void Qu :: display()
{
    if (front == - 1)
        cout<<"\tQueue is empty"<<endl;
    else
    {
        cout<<"\tQueue elements are : ";
        for (int i = front; i <= rear; i++)
            cout<<queue[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    Qu ob;

    ob.display();

    ob.enqueue(1);
    ob.enqueue(2);
    ob.enqueue(3);
    ob.enqueue(4);
    ob.enqueue(5);

    ob.display();

    ob.enqueue(5);

    ob.dequeue();
    ob.dequeue();

    ob.display();
}
