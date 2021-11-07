//https://leetcode.com/problems/find-peak-element/
//similar

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int si = 0, ei = nums.size() - 1;

    while(si < ei)
    {
        int mid = si + (ei - si)/2;
        if(nums[mid] > nums[mid + 1])//dec aprt
            ei = mid;
        else //inc part
            si = mid + 1;
    }
    return si;
}
// int findPeakElement(vector<int> &v1)
// {
    // int si = 0, ei = v1.size() - 1;
    // int ans = 0;

    // while(si <= ei)
    // {
    //     int mid = si + (ei - si)/2;
    //     // cout << mid << endl;
    //     int possAns = mid;
    //     if(v1[mid] > v1[mid + 1]) //we are in decreasing part of the array
    //     {
    //         if(v1[ans] < v1[possAns])
    //             ans = possAns;
    //         ei = mid - 1;
    //         // cout << 100 << v1[ans] << " " << ans << endl;
    //     }
    //     else //inc part of the array
    //     {
    //         if(v1[ans] <  v1[possAns])
    //             ans = possAns;
    //         // cout << 200 << v1[ans] << " " << ans << endl;
    //         si = possAns + 1;
    //     }
    // }
    return ans;
// }
int main()
{
    vector<int>v1;
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        v1.push_back(val);
    }

    cout << findPeakElement(v1) << endl;
}
