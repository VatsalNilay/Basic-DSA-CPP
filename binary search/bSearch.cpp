#include<iostream>
using namespace std;
int binarySearch(int *arr, int n, int x)
{
    bool asc = arr[0] < arr[n -1];
    int mid, si = 0, ei = n -1;
    
    if(asc)
    {
        cout << "Ascending" << endl;
        while(si <= ei)
        {
            mid = si + (ei - si)/2;
            if(arr[mid] == x)
                return mid;
            else if(arr[mid] > x)
                ei = mid - 1;
            else 
                si = mid + 1;
        }
    }
    else
    {
        cout << "Descending" << endl;
        while(si <= ei)
        {
            mid = si + (ei - si)/2;
            if(arr[mid] == x)
                    return mid;
            else if(arr[mid] < x)
                ei = mid - 1;
            else 
                si = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int size, x;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "Enter the key: ";
    cin >> x;

    cout << binarySearch(arr,size, x) << endl;
    delete []arr;
}