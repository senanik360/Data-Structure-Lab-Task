#include <bits/stdc++.h>
using namespace std;
class billsearch
{
public:
    void insertionSort(int[],int);
    void binarySearch(int[],int,int);
};
void billsearch :: insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void billsearch :: binarySearch(int arr[], int n,int src)
{
    int left = 0;
    int right = n-1;
    int count=0, sum=0,m;
    while(left <= right)
    {
        int mid = (left+right) / 2;
        if(arr[mid] < src)
        {
            left = mid+1;
        }
        else if(arr[mid] > src)
        {
            right = mid-1;
        }
        else if(arr[mid] == src)
        {
            cout<<"Total number of transaction : \n  1.More than BDT "<<src<<". \n\t2.Less than BDT "<<src<<".\n";
            cin>>m;
            if(m==1)
            {
                for(int i=arr[mid+1]; i<=arr[n-1]; i++)
                {
                    sum+=i;
                    count++;
                }
                cout<<"Total payment of the orders whose bills are more than BDT "<<arr[mid]<<" is "<<count<<endl;
                cout<<"Sum of total bills : "<<sum;
            }
            else if(m==2)
            {
                for(int i=arr[mid-1]; i>=arr[0]; i--)
                {
                    sum+=i;
                    count++;
                }
                cout<<"Total payment of the orders whose bills are less than BDT "<<arr[mid]<<" is "<<count<<endl;
                cout<<"Sum of total bills : "<<sum;
            }

            break;
        }
    }
}
int main()
{
    billsearch b;
    int n;
    cout<<"How many bills do you want to insert? "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter your bills: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    int src;
    b.insertionSort(arr, n);
    cout<<"Enter a bill to search"<<endl;
    cin>>src;
    b.binarySearch(arr,n,src);
}
