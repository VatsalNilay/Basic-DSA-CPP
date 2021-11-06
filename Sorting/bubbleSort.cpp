/*
  1. Basically backside sorting, meaning at first pass, the largest element is at its place
  2. Best case(sorted in ascending order) -> O(N), worst case(sorted in descending order) -> O(N^2), avg case
  3. If in an entire pass, no swaping takes place, then array is sorted
  4. Stable sorting algo -> When 2 or more values are the same, final array order is same for the equal elements
*/


#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int *arr, int n)
{
    bool ifSwap;
    for(int i = 0; i < n; i++)
    {
        ifSwap = false;
        for(int j = 1; j < n-i; j++) //bcoz at cmpletion of ith pass, the ith element from last is sorted
        {
            if(arr[j] < arr[j - 1])
            {
                ifSwap = true;   
                swap(arr[j],arr[j-1]);
            }
        }
        if(ifSwap == false)  
            return;
    }
}


int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    bubble_sort(arr,size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}