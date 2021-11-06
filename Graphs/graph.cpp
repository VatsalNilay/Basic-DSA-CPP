#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edge, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;

    for(int i = 0; i < n; i++)
    {
        if(edge[sv][i] && !visited[i])
            printDFS(edge,n,i,visited);
    }
    
}

void printBFS(int **edge, int n, int sv, bool *visited)
{
    queue<int>pv;
    pv.push(sv);
    visited[sv] = true;

    while(!pv.empty())
    {
        int front = pv.front();
        pv.pop();
        cout << front << " ";
        for(int i = 0; i < n; i++)
        {
            if(edge[front][i] && !visited[i])
            {
                pv.push(i);
                visited[i] = true;
            }
        }
    }
}


void dfs(int **edge, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            printDFS(edge,n,i,visited);
    }
    cout << endl;
    delete [] visited;
}

void bfs(int **edge, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            printBFS(edge,n,i,visited);
    }
    delete [] visited;
    cout << endl;
}

int main()
{
    int n, e; //n is num of vertices...e is no of edges
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) //adjecency matrix
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f, s; //determines which two nodes have an edge bw them
        cin >> f >> s;
        edges[f][s] = edges[s][f] = 1;
    }
    
    cout << "DFS" << endl;
    dfs(edges,n);
    cout << "BFS" << endl;
    bfs(edges,n);
    
}

// 8 7 
// 0 1
// 0 2
// 1 3
// 1 4
// 2 3
// 7 5 
// 5 6