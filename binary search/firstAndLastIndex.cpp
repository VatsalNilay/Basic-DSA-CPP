//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> range(vector<int> &v1, int x)
{
    vector<int> ans;
    if(x > v1[v1.size() - 1] || x < v1[0])
        return ans;

    int si = 0, ei = v1.size() -1;
    int mid;
    int start = INT_MAX, end = INT_MIN;
    //for si
    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        if(v1[mid] == x)
        {
            if(mid < start)
            {
                start = mid;
                ei = mid - 1;
            }
        }
        else if(v1[mid] > x)
            ei = mid - 1;
        else 
            si = mid + 1;
    }
    //for ei
    si = 0, ei = v1.size() -1;
    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        if(v1[mid] == x)
        {
            if(mid > end)
            {
                end = mid;
                si = mid + 1;
            }            
        }
        else if(v1[mid] > x)
            ei = mid - 1;
        else 
            si = mid + 1;
    }
    if(start != INT_MAX)
    {
        ans.push_back(start);
        ans.push_back(end);
    }
    else
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}

int main()
{
    vector<int> v1;
    int i = 0, size, data;
    cin >> size;

    while(i < size)
    {
        cin >> data;
        v1.push_back(data);
        i++;
    }
    int target;
    cin >> target;

   makepair* ans = range(v1, target);

   cout << ans -> si << " " << ans -> ei << endl; 
    // delete makepair;
}