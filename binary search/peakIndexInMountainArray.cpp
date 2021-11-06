//https://leetcode.com/problems/peak-index-in-a-mountain-array/
//finding the index of max in bitonic array, i.e. first it will increase and then it will decrease

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int peakIndexInMountainArray(vector<int> &v1)
{
    int si = 0, ei = v1.size() - 1;
    int ans = 0;

    while(si <= ei)
    {
        int mid = si + (ei - si)/2;
        // cout << mid << endl;
        int possAns = mid;
        if(v1[mid] > v1[mid + 1]) //we are in decreasing part of the array
        {
            if(v1[ans] < v1[possAns])
                ans = possAns;
            ei = mid - 1;
            // cout << 100 << v1[ans] << " " << ans << endl;
        }
        else //inc part of the array
        {
            if(v1[ans] <  v1[possAns])
                ans = possAns;
            // cout << 200 << v1[ans] << " " << ans << endl;
            si = possAns + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v1;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        v1.push_back(val);
    }

    cout << peakIndexInMountainArray(v1) << endl;
}