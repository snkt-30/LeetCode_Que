class Solution
{

    bool dfs(vector<vector < int>> &graph, vector< int > &vis, vector< int > &vis_path, vector< int > &check, int node)
    {
        vis[node] = 1;
        vis_path[node] = 1;

        for (auto child: graph[node])
        {
            if (!vis[child])
            {
                if (dfs(graph, vis, vis_path, check, child) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else
            {
                if (vis_path[child])
                {
                    check[node] = 0;
                    return true;
                }
            }
        }

        check[node] = 1;
        vis_path[node] = 0;
        return false;
    }
    public:
        vector<int> eventualSafeNodes(vector<vector < int>> &graph)
        {

            int n = graph.size();

            vector<int> vis(n, 0);
            vector<int> vis_path(n, 0);
            vector<int> check(n, 0);

            vector<int> safe_node;

            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    dfs(graph, vis, vis_path, check, i);
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (check[i] == 1)
                    safe_node.push_back(i);
            }

            return safe_node;
        }
};