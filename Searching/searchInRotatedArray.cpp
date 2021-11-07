//https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& v1, int x) 
{
    int si = 0, ei = v1.size() - 1, mid;
    // int pivot = 0;
    int pivot = -1;
        
        
     while(si <= ei)
    {            
        mid = si + (ei - si)/2;

        if(mid < ei && v1[mid] > v1[mid + 1])
        {
            pivot = mid;
            break;
        }
        if(mid > si && v1[mid] < v1[mid - 1])
        {
            pivot = mid - 1;
            break;
        }

        if(v1[si] >= v1[mid])
            ei = mid - 1;
        else 
            si = mid + 1;
    }
    // cout << pivot << endl;
    if(pivot == -1) //this means that array isn't rotated and we didnt find the pivot element
        si = 0, ei = v1.size() - 1;
    else if(v1[0] > x)
        si = pivot + 1, ei = v1.size() - 1;
    else
        si = 0, ei = pivot;

    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        if(v1[mid] == x)
            return mid;
        else if(v1[mid] > x)
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
    vector<int> v1;

    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        v1.push_back(val);
    }
    int target;
    cin >> target;

    cout << search(v1, target) << endl;
}