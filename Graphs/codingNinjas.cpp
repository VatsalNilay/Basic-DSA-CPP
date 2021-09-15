/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int validPoint(int x, int y, int r, int c)
{
    return (x >= 0 && x < r && y >= 0 && y < c);
}

bool dfs(vector<vector<char>> &board, int r, int c, vector<vector<bool>> &visited, string word, int sx, int sy, int currIndex)
{
    if(currIndex == 11)
        return true;

    visited[sx][sy] = true;
    bool found = false;

    int dxdy[8][2] = {{-1,-1},
                      {1,1},
                      {0,1},
                      {1,0},
                      {-1,1},
                      {1,-1},
                      {-1,0},
                      {0,-1}}; 

    for(int i = 0; i < 8; i++)
    {
        int newX = sx + dxdy[i][0];
        int newY = sy + dxdy[i][1];

        if(validPoint(newX,newY,r,c) && board[newX][newY] == word[currIndex] && !visited[newX][newY])
            found = found | dfs(board, r, c, visited, word, newX, newY, currIndex + 1);
    }

    visited[sx][sy] = false;
    return found;
}

bool hasPath(vector<vector<char>> &board, int r, int c)
{
    vector<vector<bool>> visited(r, vector<bool>(c,false)); //creating adjacency matrix
    bool foundPath = false;
    string word = "CODINGNINJA";  //total 11 letters

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 'C')
            {
                foundPath = dfs(board, r, c, visited, word, i, j, 1);
                if(foundPath)
                    return foundPath;
            }
        }
    }
    return foundPath;
}
int main()
{
    int r,c;
    cin >> r >> c;

    vector<vector<char>> board(r,vector<char>(c));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> board[i][j];
    }

    cout << (hasPath(board,r,c)? 1 : 0);
}