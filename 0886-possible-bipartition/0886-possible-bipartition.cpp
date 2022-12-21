class Solution {
	public:
		bool possibleBipartition(int n, vector<vector<int>>& d) {

			vector<int>adj[n + 1];

			for (auto vi : d)
			{
				int u = vi[0];
				int v = vi[1];
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
            
			vector<int>vis(n + 1, -1);

			for (int i = 1; i <= n; i++) {

				if (vis[i] == -1)
				{
					queue<int> bfs;

					bfs.push(i);
					vis[i] = 0;
					while (!bfs.empty())
					{
						auto node = bfs.front();
						bfs.pop();

						for (auto tr : adj[node])
						{
							if (vis[tr] == -1)
							{
								vis[tr] =!vis[node];
								bfs.push(tr);
							}
							else
							{
								if (vis[tr] == vis[node])return false;
							}
						}
					}
				}
			}
            
			return true;


		}
	};