/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<int> getOneComp(bool **edge, int n, int sv, bool *visited)  //using bfs
{
    vector<int> one;
    queue<int>q;
    q.push(sv);
    // one.push_back(sv);
    visited[sv] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        one.push_back(front);        
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && edge[front][i])
            {
                // one.push_back(i);
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return one;
}

vector<vector<int>> getAllcomp(bool **edge, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    vector<vector<int>> result;   
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            vector<int> one = getOneComp(edge, n, i, visited);
            result.push_back(one);   
        }
    }
    delete []visited;
    return result;
}
int main()
{
    int n, e;
    cin >> n >> e;
    bool **edge = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        edge[i] = new bool[n];
        for(int j = 0; j < n; j++)
            edge[i][j] = false;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        edge[f][s] = edge[s][f] = true;
    }

    vector<vector<int>> connectedComp = getAllcomp(edge,n);

    for(int i = 0; i < connectedComp.size(); i++)
    {
        sort(connectedComp[i].begin(),connectedComp[i].end());
        for(int j = 0; j < connectedComp[i].size(); j++)
            cout << connectedComp[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < n; i++)
        delete [] edge[i];
    delete[] edge;
}