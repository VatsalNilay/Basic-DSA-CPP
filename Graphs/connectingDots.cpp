/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called 
adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
*/
#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &board, int r, int c, char currColour, int x, int y, int fromX, int fromY, vector<vector<bool>> &used, bool &found)
{
    if(x < 0 || x >= r || y < 0 || y >= c)
        return;
    if(board[x][y] != currColour) //is raaste se to cylce ni ban paega
        return;
    if(used[x][y]) //cycle complete
    {
        found = true;
        return;
    }
    used[x][y] = true;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for(int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX == fromX && nextY == fromY)
            continue;
        dfs(board, r, c, currColour, nextX, nextY, x, y, used, found );
    }    
}

bool hasCycle(vector<vector<char>> &board, int r, int c)
{
    vector<vector<bool>> used(r,vector<bool>(c,false));
    bool findCycle = false;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(!used[i][j])
                dfs(board, r, c, board[i][j], i, j, -1, -1, used, findCycle);
        }
    }
    return findCycle;
}

int main()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> board(r,(vector<char>(c)));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cin >> board[i][j];
    }

    cout << (hasCycle(board,r,c)? "true" : "false");
}