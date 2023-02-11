#define blue 0
#define red 1
#define mp make_pair

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g ) {
        
        int n=g.size();
        
        vector<int>vis(n,0);
        
        vector<int>color(n,-1);
        
       for(int i=0;i<n;i++)
       {
           if(!vis[i])
           {
                queue<int>bfs;
               
               bfs.push(i);
               color[i]=0;
               while(!bfs.empty())
               {
                  int node=bfs.front();
                                     
                   bfs.pop();
                   
                   for(auto x:g[node])
                   {
                       if(!vis[x])
                       {
                           vis[x]=1;
                           if(color[node]==red)
                           {
                            color[x]=blue;
                           }
                           else
                           {
                               color[x]=red;
                           }
                           bfs.push(x);
                       }
                       else
                       {
                           if(color[node]==color[x])
                               return false;
                       }
                   }
               }
           }
       }

        return true;
        
    }
};