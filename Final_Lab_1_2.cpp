#include<iostream>
using namespace std;
main ()
{
    int arr[]= {11,14,17,15,16,13,18,19,12,20}, target, match;
    int N = sizeof(arr)/sizeof(arr[0]);
    for(target = 1; target<N; target++)
    {
        int t = arr[target];
        for(int j = 0; j<target; j++)
        {
            if (arr[j]>t)
            {
                match = j;
                for(int i=target-1; i>=match; i--)
                {
                    arr[i+1]=arr[i];
                }
            }
            arr[match]=t;
        }
    }

    for(int i=0; i<N; i++)
    {
        cout<<arr[i]<<" ";
    }
}
