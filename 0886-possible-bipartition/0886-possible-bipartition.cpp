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
					queue<pair<int, int>> bfs;

					bfs.push(make_pair(i, 0));
					vis[i] = 0;
					while (!bfs.empty())
					{
						auto x = bfs.front();
						bfs.pop();

						int node = x.first;
						int par_col = x.second;

						for (auto tr : adj[node])
						{
							if (vis[tr] == -1)
							{
								vis[tr] = !par_col;
								bfs.push({tr, vis[tr]});
							}
							else
							{
								if (vis[tr] == par_col)return false;
							}
						}
					}
				}
			}

			// for(int i=1;i<=n;i++)
			// {
			//     cout<<vis[i]<<" "<<i<<endl;
			// }
			// cout<<"n"<<endl;
			return true;


		}
	};