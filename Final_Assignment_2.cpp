#include<iostream>
using namespace std;
class heap
{
public:
    void heapify(int [], int, int );
    void build(int [], int );
};
void heap :: heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap :: build(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Array representation of Heap is :  ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main ()
{
    int n;
    cout<<"Please enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Please enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    heap h;
    h.build(arr, n);
}

