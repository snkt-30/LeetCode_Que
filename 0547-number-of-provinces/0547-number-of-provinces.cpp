#define eb emplace_back

class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n=mat.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    adj[i].eb(j);
                    adj[j].eb(i);
                }
            }
        }
        
        vector<int>vis(n);
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                queue<int> bfs;
                bfs.push(i);
                vis[i]=1;
                
                cnt++;
                
                while(!bfs.empty())
                {
                    int sz=bfs.size();
                    for(int ele=0;ele<sz;ele++)
                    {
                        int node=bfs.front();
                        bfs.pop();
                        
                        for(auto x:adj[node])
                        {
                            if(!vis[x]){
                                vis[x]=1;
                                bfs.push(x);
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};