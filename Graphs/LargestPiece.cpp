/*
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &board, int n, int currX, int currY, int &count)
{
    count++;
    board[currX][currY] = 0;

    if(currX + 1 < n && board[currX + 1][currY] == 1)
        dfs(board, n, currX + 1, currY, count);

    if(currY + 1 < n && board[currX][currY + 1] == 1)
        dfs(board, n, currX , currY + 1, count);

    if(currX - 1 >= 0 && board[currX - 1][currY] == 1)
        dfs(board, n, currX - 1, currY, count);

    if(currY - 1 >= 0 && board[currX ][currY - 1] == 1)
        dfs(board, n, currX , currY - 1, count);
}
int largestPiece(vector<vector<int>> &board, int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int ans2 = 0;
            if(board[i][j] == 1)
                dfs(board, n, i, j, ans2);
            ans = max(ans, ans2);
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n,vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    cout << largestPiece(board, n) << endl;
}