/*
 1. Not stable
 2. Best case = Worst case = o(n^2)
 3. Finding the max and placing it at last
*/

#include<iostream>
using namespace std;

void swap(int *arr, int maxI, int lastI)
{
    int temp = arr[maxI];
    arr[maxI] = arr[lastI];
    arr[lastI] = temp;
}

int maxx(int *arr, int last)
{
    int max = 0;
    for (int i = 1; i <= last; i++)
    {
        if(arr[max] < arr[i])
            max = i;
    }
    return max;
}

void selectionSort(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        int last = n - 1 - i;
        int maxIndex = maxx(arr,last);
        swap(arr,maxIndex, last);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    selectionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
}