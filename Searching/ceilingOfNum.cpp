/*Ceiling of a number 'x' in an array is the smallest number in the 
array equal to or greater than the given number x.
Similarlly floor of a number 'x' is the greatest number equal to or smaller than x
https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/ */

#include<iostream>
using namespace std;

int ceiling(int *arr, int n, int x)
{
    if(x > arr[n-1])
        return -1;
    int mid, si = 0, ei = n -1;
    int start = 7;
    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        if(arr[mid] == x)
        {
            if(mid < start)
				start = mid;
			ei = mid - 1;
        }    
            // return mid;
        else if(arr[mid] > x)
            ei = mid - 1;
        else 
            si = mid + 1;
    }
    
    return si;

}

int floor(int *arr, int n, int x)
{

    if(x < arr[0])
        return -1;
    int mid, si = 0, ei = n -1;
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
    return ei;
}
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    cout << ceiling(arr, size, x) << endl;
    cout << floor(arr, size, x) << endl;
}