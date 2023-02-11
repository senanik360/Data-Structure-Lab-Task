#include <iostream>
using namespace std;
int heap_size=1000,n,in,del;

void heapify(int arr[],int i,int n)
{    int lc,rc,li;
    lc=2*i+1;
    rc=2*i+2;

    if(lc<n && arr[lc]>arr[i])
    {
        li=lc;
    }
    else
        li=i;
    if(rc<n && arr[rc]>arr[li])
        li=rc;
    if(li!=i)
    {
        swap(arr[i],arr[li]);
        heapify(arr,li,n);
    }
}
void build_max_heap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}

void printHeap(int arr[],int n){
    	for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter tree size : ";
    cin>>n;
	int a[heap_size];
	cout<<"\nEnter tree data \n";
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    build_max_heap(a,n);
    cout<<"\nThe Max heap data are : \n";
	printHeap(a,n);

    return 0;
}


