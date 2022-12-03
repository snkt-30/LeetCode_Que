class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
          int n = patience.size();
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> dis(n, -1);
        dis[0] = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child: adj[node]){
                if(dis[child] == -1){
                    dis[child] = dis[node] + 1;
                    q.push(child);
                }
            }
        }
        
        
        int res = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            
            // cout<<dis[i]<<" ";
            // WHEN REACHED BEFORE THE PATIENCE HAS OVER
            ans = 2*dis[i];
            
            // WHEN NO PATIENCE IS LEFT INDEED
            if(2*dis[i] > patience[i]){
                
                if(2*dis[i] % patience[i] == 0){
                    ans = 4*dis[i] - patience[i];
                    cout<<4*dis[i]<<" "<<patience[i]<<endl;
                }else{
                    ans = 4*dis[i] - (2*dis[i])%patience[i];
                    
                    cout<<4*dis[i]<<" "<<(2*dis[i])%patience[i]<<endl;
                }
            }
            res = max(res, ans);
        }   
        return res+1;
    }
};