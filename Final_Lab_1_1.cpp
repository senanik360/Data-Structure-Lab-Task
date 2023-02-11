#include<iostream>
using namespace std;
int main ()
{
    int arr[7]= {12,13,14,15,16,17,18},first,last,middle,num;
    first = 0;
    last = sizeof(arr)/sizeof(arr[0]);
    middle = (first+last)/2;
    cout<<"Enter a number for search : ";
    cin>>num;
    while(first <= last)
    {
        if(arr[middle]<num)
        {
            first = middle+1;
        }
        else if(arr[middle]==num)
        {
            cout<<"\tGot it. It is found at index : "<<middle;
            break;
        }
        else
        {
            last = middle-1;
            middle = (first+last)/2;
        }
    }
    if(first>last)
    {
        cout<<"\tNumber is not found.";
    }
    cout<<endl;
}
