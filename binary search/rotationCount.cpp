//https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

int countRotated(vector<int> &arr)
{
    int si = 0, ei= arr.size() - 1, mid;
    while(si <= ei)
    {
        mid = si + (ei - si)/2;

        if(mid < ei && arr[mid] > arr[mid + 1])
            return mid + 1;
        
        if(mid > si && arr[mid] < arr[mid - 1])
            return mid;

        if(arr[si] > arr[mid])
            ei = mid - 1;
        else
            si = mid + 1;
    }
    return 0;
}

int main()
{
    vector<int> v1;
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int data;
        cin >> data;
        v1.push_back(data);
    }

    cout << countRotated(v1) << endl;
}