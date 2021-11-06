/*
  1. At every index, sort all the elements to its left.
  2.    
  3. 
*/

#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{


}

int main()
{
    int n;
    cin >>  n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    insertionSort(arr,n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete []arr;
}