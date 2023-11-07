#include <iostream>
using namespace std;

void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[largest])
    {
        largest = left;
    }

    if (right < n && A[right] > A[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}


void insert(int A[], int &n, int key)
{
    n = n + 1;
    int i = n - 1;
    A[i] = key;

    while (i >= 1 && A[i / 2] < A[i])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

int deleted(int A[], int &n)
{
    int max_ele = A[0];
    swap(A[0], A[n - 1]);
    n--;
    heapify(A, n, 0);
    return max_ele;
}


void heap_sort(int A[], int n)
{
    while (n > 1)
    {
        swap(A[0], A[n - 1]);
        n--;
        heapify(A, n, 0);
    }
}

int main()
{
    int A[100]; 
    int n = 0;   

    insert(A, n, 12);
    insert(A, n, 11);
    insert(A, n, 13);
    insert(A, n, 5);
    insert(A, n, 6);
    insert(A, n, 7);

    cout << "After inserting elements:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }

    cout << endl;
    cout << "After heapifying:" << endl;
    for (int i = 0; i < n/2; ++i)
    {
        heapify(A,n,i);
    }
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }

    heap_sort(A, n);
    cout << endl;
    cout << "The elements after heap sort are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}