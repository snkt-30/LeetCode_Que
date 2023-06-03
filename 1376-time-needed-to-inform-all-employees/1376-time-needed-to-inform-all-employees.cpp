
#define mk make_pair
class Solution
{
    public:
        int numOfMinutes(int n, int headID, vector<int> &m, vector<int> &it)
        {

            vector<int> g[n];

            int hd = headID;

            for (int i = 0; i < n; i++)
            {
                if(i!=hd)
                {
                    g[m[i]].push_back(i);
                }
            }

            vector<bool> vis(n, false);

            int ans = 0;

            queue<pair<int, int>> bfs;

            bfs.push(mk(hd, 0));

            while (!bfs.empty())
            {
                int node = bfs.front().first;
                int tm = bfs.front().second;
                vis[node] = true;

                ans = max(ans, tm);
                bfs.pop();

                for (auto x: g[node])
                {
                    if (!vis[x])
                    {
                        bfs.push(mk(x, tm + it[node]));
                    }
                }
            }
            return ans;
        }
};