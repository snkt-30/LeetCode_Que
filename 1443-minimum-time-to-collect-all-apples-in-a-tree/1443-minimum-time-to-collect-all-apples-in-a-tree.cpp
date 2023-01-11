
class Solution {
public:
     vector<int> adj[100005];
    vector<bool> fruit;
    
    
    pair<int,int> dfs(int node, int par){
        pair<int,int> v={0,fruit[node]};
        for(auto it: adj[node]){
            if(it!=par){
                auto x = dfs(it,node);
                v.first+=(2+x.first)*x.second;
                v.second|=x.second;
            }
        }
        return v;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       
       for(int i=0;i<edges.size();i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);

       }
        fruit=hasApple;
        return dfs(0,0).first;
    }
};
