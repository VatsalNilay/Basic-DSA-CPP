/*
    isBadVersion is an api which returns true if num is bad otherwise true;
*/
#include<iostream>
using namespace std;

int firstBadVersion(int n) 
{
    int si = 0, ei = n, mid;
    
    while(si <= ei)
    {
        mid = si + (ei - si)/2;
        bool curr = isBadVersion(mid);
        
        if(!curr)
        {
            if(mid < n)
            {
                if(!isBadVersion(mid + 1))
                    si = mid + 1;
                else
                    return mid + 1;
            }
            else
                return mid;
        }
        else
            ei = mid - 1;
    }
    return mid + 1;
}

int main()
{
    int n;
    cin >> n;

    cout << firstBadVersion(n) << endl;
}