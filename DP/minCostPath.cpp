/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/

#include<iostream>
#include<climits>
using namespace std;

//revursive
int minCostPath(int **arr, int r, int c, int six, int siy)
{
    if(six == r - 1 && siy == c - 1)
        return arr[six][siy];

    if(six >= r || siy >= c)
        return INT_MAX;
    else
    {
        int x = minCostPath(arr, r, c, six+1, siy);
        int y = minCostPath(arr, r, c, six+1, siy + 1);
        int z = minCostPath(arr, r, c, six , siy + 1);

        return min(x, min(y, z)) + arr[six][siy];
    }
}
int minCostPath(int **arr, int r, int c)
{
    return minCostPath(arr,r,c,0,0);    
}

//memoization
int minCost_mem(int **arr, int r, int c, int six, int siy, int **ans)
{
    if(six == r - 1 || siy == c - 1)
        return arr[six][siy];

    if(ans[six][siy] != -1)
        return ans[six][siy];

    if(six >= r || siy >= c)
        return INT_MAX;
    
    int x = minCostPath(arr, r, c, six+1, siy);
    int y = minCostPath(arr, r, c, six+1, siy + 1);
    int z = minCostPath(arr, r, c, six , siy + 1);
    
    int a = min(x, min(y, z)) + arr[six][siy]; 
    ans[six][siy] = a;
    return a;
}
int minCost_mem(int **arr, int r, int c)
{
    //total unique calls will be r*c
    int **ans = new int*[r];  
    for(int i = 0; i < r; i++)
        ans[i] = new int[c];

    for (int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            ans[i][j] = -1;
    }
    return minCost_mem(arr, r, c, 0, 0, ans);
}
//dp
int minCost_dp(int **arr, int r, int c)
{
    // int **ans;

    int **ans = new int*[r];
    for(int i = 0; i < r; i++)
        ans[i] = new int[c];
    
    ans[r - 1][c - 1] = arr[r - 1][c - 1];
//last row...from n - 2 to 0
    for(int i = c - 2; i >= 0; i--)
        ans[r - 1][i] = ans[r - 1][i + 1] + arr[r - 1][i];

//last column...from bottom to top
    for(int i = r - 2; i >= 0; i--)
        ans[i][c - 1] = ans[i + 1][c - 1] + arr[i][c - 1];


    for(int i = r - 2; i >= 0; i--)
    {
        for(int j = c - 2; j >= 0; j--)
            ans[i][j] = arr[i][j] + min(ans[i+1][j],min(ans[i][j+1], ans[i +1][j + 1]));
    }
    return ans[0][0];
}
int main()
{
    int **arr, r, c;
    cin >> r >> c;

    arr = new int*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];
    }

    cout << minCostPath(arr,r,c) << endl;
    cout << minCost_mem(arr,r,c) << endl;
    cout << minCost_dp(arr,r,c) << endl;
}