class Solution
{

    private:

        bool dfs(vector<int> adj[], int node, int par, int col, vector<int> &ans, vector<int> vis)
        {

            vis[node] = 1;
            ans[node] = col;

            for (auto child: adj[node])
            {
                if (!vis[child])
                {
                    for (int i = 1; i <= 4; i++)
                    {
                        if (dfs(adj, child, node, i, ans, vis) == true)
                        {
                            break;
                        }
                        else
                            continue;
                    }
                }
                else
                {

                    if (ans[child] == ans[node])
                        return false;
                }
            }

            return true;
        }
    public:
        vector<int> gardenNoAdj(int n, vector<vector < int>> &paths)
        {
            vector<int> ans(n + 1, 0);

            vector<int> adj[n + 1];

            for (auto x: paths)
            {
                int u = x[0];
                int v = x[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

           vector<int>color(n+1,0);
            
            for(int i=1;i<=n;i++)
            {
                if(color[i]==0)
                {
                    queue<int> bfs;
                    color[i]=1;
                    bfs.push(i);
                    
                    while(!bfs.empty())
                    {
                        int node=bfs.front();
                        bfs.pop();
                        
                        for(auto child:adj[node])
                        {
                            if(color[child]==0 or color[child]==color[node])
                            {
                                color[child]=color[node]+1;
                                bfs.push(child);
                            }
                            
                            if(color[child]>4)
                                color[child]=color[child]%4;
                        }
                    }
                }
            }
            
            vector<int>res;
            
            for(int i=1;i<=n;i++)
            {
                res.push_back(color[i]);
            }
            return res;
        }
};