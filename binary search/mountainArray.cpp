//https://leetcode.com/problems/find-in-mountain-array/
//Binary search in mountain array

#include<iostream>
#include<vector>
using namespace std;
class MountainArray 
{
    vector<int> v1;
    int size;

    public:
       MountainArray()
       {
            size = 0;
       }

      void push(int val)
      {
          v1.push_back(val);
          size++;
      }
      void pop()
      {
          v1.pop();
          size--;
      }
      int length()
      {
          return size;
      }
      int get(int index)
      {
          if(index > size - 1)
            return -1;
          return v1[index];
      }
};

int findInMountainArray(int target, MountainArray &m)
{
    int si = 0, ei = m.length() - 1, mid;

    while(si < ei)
    {
        mid = si + (ei - si)/2;
        if(m.get(mid) > m.get(mid + 1))
            ei = mid;
        else
            si = mid + 1;
    }
    mid = si;
    si = 0, ei = mid;

    while (si <= ei)
    {
        int temp = si + (ei - si)/2;
        if(m.get(temp) == target)
            return temp;
        else if(m.get(temp) > target)
            ei = temp - 1;
        else
            si = temp + 1;
    }
    si = mid + 1, ei = m.length() - 1;
    while (si <= ei)
    {
        int temp = si + (ei - si)/2;
        if(m.get(temp) == target)
            return temp;
        else if(m.get(temp) < target)
            ei = temp - 1;
        else
            si = temp + 1;
    }
    return -1;
}
int main()
{
    MountainArray m;
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        m.push(val);
    }
    int target;
    cin >> target;

    cout << findInMountainArray(taeget, m) << endl;
}
