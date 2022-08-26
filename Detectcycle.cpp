#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<int> parent[N];

//  detech cycle using dfs techniquie
bool  isCycledfs(int vertex, int par)
{
    if (vis[vertex])
    {
        return true;
    }

    if (!vis[vertex])
    {
        vis[vertex] = true;
        for (auto x : g[vertex])
        {
            if (x != par)
            {
                if (vis[x])
                {
                    return true;
                }
                if (!vis[x] and iscycledfs(x, vertex))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// detect cycle using bfs technique

bool isCyclebfs(int node,vector<int> adj[],vector<bool>&vis)
{
    queue<pair<int,int>> bfs;
    vis[node]=1;

    bfs.push({node,-1});

    while(!bfs.empty())
    {
        int node=bfs.front().first;
        int par=bfs.front().second;

        bfs.pop();

        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                vis[x]=true;
                bfs.push({x,node});
            }
            else if(par!=x) //if visited node is not equal to parent of node then surely there is cycle
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool>vis(n+1,false);
    bool isloopexit = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        if (isCyclebfs(i,g,vis))
        {
            isloopexit = true;
            break;
        }
    }
    cout << isloopexit << endl;
}