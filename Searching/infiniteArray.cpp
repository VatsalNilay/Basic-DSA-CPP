//infinite array means we do not need the size...
//the apparoach should be reverse binary search
//https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
#include<iostream>
using namespace std;

int B_search(int *arr, int x)
{
    int si = 0, ei = 1;
    
    while(arr[ei] < x) //array is large enough, so no out of bound checking
    {
        int tstart = si + 1;
        ei = ei + (ei - si + 1)*2;
        si = tstart;
    }

    while (si <= ei)
    {
        int mid = si + (ei - si)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return -1;
}
int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    cout << B_search(arr, target) << endl;
    delete[] arr;
}