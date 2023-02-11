
#define mp make_pair
#define pb push_back

class Solution
{

  vector<vector < int>> res;
    vector<int>temp;
    int src=0;
    int dest;
    public:
    
    void dfs(vector<vector<int>>&g,int node=0)
    {
        temp.pb(node);
        
        if(node==dest)
        {
            res.pb(temp);
        }
        else
            for(auto x:g[node])
                dfs(g,x);
        
        temp.pop_back();
        
        
    }
        vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &g)
        {
            int n = g.size();
            
            dest=n-1;
            dfs(g);

            return res;

            /*      
                        queue<pair<int, vector < int>>> bfs;

                        vector<vector < int>> res;

                        vector<int> temp = { src};

                        bfs.push(mp(src, temp));

                        while (!bfs.empty())
                        {
                            int node = bfs.front().first;

                            vector<int> temp = bfs.front().second;

                            bfs.pop();

                            for (auto x: g[node])
                            {
                                temp.pb(x);

                                if (x == des)
                                {
                                    res.push_back(temp);
                                }

                                bfs.push(mp(x, temp));
                                temp.pop_back();
                            }
                        }
                        return res;            
            */

        }
};