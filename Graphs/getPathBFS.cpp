/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2:

*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#define pb push_back
using namespace std;

vector<int>* getPath_bfs(bool **edge, int n, int n1, int n2)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    unordered_map<int, int> m;
    queue<int>pg;

    pg.push(n1);
    visited[n1] = true;
    bool pathfind = false;
    while(!pg.empty() && !pathfind)
    {
        int front = pg.front();
        pg.pop();    
        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && edge[front][i])
            {
                pg.push(i);
                m[i] = front;
                visited[i] = true;
                if(i == n2)
                {
                    pathfind = true;
                    break;
                }
            }
        }
    }
    delete [] visited;
    if(!pathfind)
        return NULL;

    vector<int> * output = new vector<int>();
    int current = n2;
    output -> pb(current);
    // cout << 213123 << endl;
    while(current != n1)
    {
        current = m[current];
        output -> pb(current);
    }
    // cout << 99 << endl;
    return output;
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
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> *path = getPath_bfs(edge,n,n1,n2);
    // cout << 213 << endl;
    if(path)
    {
        for(auto i : *path)
            cout << i << " ";

        delete path;
        cout << endl;
    }

    for(int i = 0; i < n; i++)
        delete [] edge[i];
    delete [] edge;
}