#define mp make_pair
#define pb push_back


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        
        int n=g.size();
        
        int src=0;
        int des=n-1;
        
        queue<pair<int,vector<int>>> bfs;
        
        vector<vector<int>> res;
        
        vector<int>temp={src};
        
        bfs.push(mp(src,temp));
        
        while(!bfs.empty())
        {
            int node=bfs.front().first;
            
            vector<int>temp=bfs.front().second;
            
            bfs.pop();
            
            for(auto x:g[node])
            {
                temp.pb(x);
                
                if(x==des)
                {
                    res.push_back(temp);
                }
                
                bfs.push(mp(x,temp));
                temp.pop_back();
            }
        }
        
        return res;
        
    }
};