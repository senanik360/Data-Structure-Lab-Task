/*Infix to Postfix conversion with the algorithm discussed
in Lab without using library stack class.*/

#include<iostream>
using namespace std;
const int size=25;
class stacks
{
    char stack[size];
    int top;
public:

    stacks()
    {
        top=-1;
    }

    int push(char);
    char pop();
    void display();
    void count_elements();
    int isEmpty();
    char topElement();
};


// function to implement the push operation of stack.
int stacks::push(char element)
{
    if(top==(size-1))
    {
        cout<<"overflow, more elements cannot be inserted \n";
        return 0;
    }
    else
    {
        stack [++top] =element;
    }
    return 1;
}


//function to pop the element from the stack
char stacks::pop ()
{
    char temp=0;
    // Examine whether stack is empty or not.
    if (top==-1) // top=-1 indicates the empty state of stack 56
    {
        cout<<"underflow: \n";
    }
    else
    {
        temp=stack [top--];
    }
    return temp;
}
// To examine whether the stack is empty.
int stacks::isEmpty ()
{
    if (top==-1)
        return 1;
    else
        return 0;
}

// Program to display the element(s) of the stack.
void stacks::display ()
{
    for (int i=top; i>=0; i--)
        cout<<stack[i]<<" ";
    cout<<endl;

}

//Return the TOP element
char stacks::topElement()
{
    return stack[top];
}

// QUEUE 89
class Q
{
    int front, rear;
    char queue[size];
public:
    Q( );
    void enqueue(char);
    char dequeue();
    void display();
    //int isEmpty();
};

Q::Q()
{
    front=rear=-1;
}
void Q::enqueue(char element)
{
    if(((rear-front)==(size-1))&&(rear==(size-1)))
    {
        cout<<"overflow element cannot be entered\n";
        return;
    }
    else if(front==-1)
    {
        queue[++rear]=element;
        front=0;
    }
    else if(rear<(size-1))
    {
        queue[++rear]=element;
    }
}

void Q::display()
{
    if(front>=0) //if any item in the queue
        for(int i=front; i<=rear; i++)
            cout<<queue[i]<<" " ;
}

//To know the precedence of an operator 134
int getPrece(char c)
{
    if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
Q convert(string s)
{
    stacks st;
    Q q;
    int i,j,k;
    char c;
    s+=')';
    st.push('(');

    i=0;
    do
    {

        c=s[i]; ///*
        i++;
        //Check whether an element of the string is a character
        if(c>='a' && c<='z'|| c>='A'&& c<='Z')
        {
            q.enqueue(c);
        }
        else // c is an opeartor
        {
            if(c=='(')
                st.push('(');
            else if(c==')')
            {
                while(st.topElement()!='(')
                {
                    q.enqueue(st.topElement());
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(getPrece(c)<=getPrece(st.topElement()))
                {
                    q.enqueue(st.topElement());
                    st.pop();
                }
                st.push(c);
            }
        }
    }
    while(!st.isEmpty());
    return q;
}

main()
{
    Q q2;
    //string exp = "a+b*(c+d-e)+(f+g*h)-i";
    string exp="(A+B/C*(D+C)-F)";
    //string exp="a/b+c-(d*c+b)-g+(f+g))";
    //string exp="a*b/(c-d)+e*f";
    //string exp = "a-b*c";
    q2=convert(exp);
    q2.display();
}
