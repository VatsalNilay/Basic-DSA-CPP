//out of given 2 strings...find the longest common subsequence
#include<iostream>
#include<string>

using namespace std;
//recursion
int lcs(string s, string t)
{
    // Base Case
    if(s.length() == 0 || t.length() == 0)
        return 0;

    //recursive calls
    if(s[0] == t[0])
        return 1 + lcs(s.substr(1), t.substr(1));
    else
    {
        int a = lcs(s.substr(1),t);
        int b = lcs(s,t.substr(1));
        // int c = lcs(s.substr(1),t.substr(1)); //not necessary because we are anyways making two calls from above
        return max(a,b);
    }
}

//memoization
int lcs_mem(string s, string t, int **arr)
{
    if(s.length() == 0 || t.length() == 0)
        return 0;
    int m = s.length();
    int n = t.length();

    if(arr[m][n] != -1)
        return arr[m][n];

    int ans;
    if(s[0] == t[0])
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), arr);
    else
    {
        int a = lcs_mem(s.substr(1),t, arr);
        int b = lcs_mem(s,t.substr(1),arr);
        // int c = lcs(s.substr(1),t.substr(1)); //not necessary because we are anyways making two calls from above
        ans = max(a,b);
    }
    arr[m][n] = ans;
    return ans;
}
int lcs_mem(string s, string t)
{
    int m = s.length();
    int n = t.length();
//possible length for s 0->m ...total m+1
//possible length for t 0->n...total n+1 
//...hence total different calc will be (m+1)(n+1)

    int **ans = new int*[m + 1];
    for (int i = 0; i < m + 1; i++)
        ans[i] = new int[n + 1];

/*at each co ordinate we will be storing length of lcs for x lengt h for s and y length for t, therfore our ans lies on ans[m+1][n+1]*/ 

    for(int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
            ans[i][j] = -1;
    }
    return lcs_mem(s,t,ans);
}

//dp
int lcs_dp(string s , string t)
{
    int m = s.length();
    int n = t.length();
    int **ans = new int*[m + 1];
    for(int i = 0; i < m + 1; i++)
        ans[i] = new int[n + 1];

//first row
    for(int i = 0; i < n + 1; i++)
        ans[0][i] = 0;
//first column
    for(int i = 0; i < m + 1; i++)
        ans[i][0] = 0;


    for(int i = 1; i < m + 1; i++)
    {
        for(int j = 1; j < n +1; j++)
        {
//i and j denotes the remaining length of s and t
            if(s[m - i] == t[n - j])
                ans[i][j] = 1 + ans[i - 1][j - 1];
            else
                ans[i][j] = max(ans[i -1][j - 1],max(ans[i - 1][j], ans[i][j - 1]));
        }
    }
    return ans[m][n];
}
int main()
{
    string s , p;
    cin >> s >> p;
    cout << lcs(s,p) << endl;
    cout << lcs_mem(s,p) << endl;
    cout << lcs_dp(s,p) << endl;
}