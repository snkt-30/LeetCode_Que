//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU{
    
    public:
    vector<int>parent,sizes;
    
    DSU(int n)
    {
        sizes.resize(n+1,1);
        
        parent.resize(n+1);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find_par(int node)
    {
        if(node==parent[node])return node;
        
        return parent[node]=find_par(parent[node]);
    }
    
    void Union_size(int a,int b)
    {
        int ul_a=find_par(a);
        int ul_b=find_par(b);
        
        if(ul_a==ul_b)return ;
        else
        {
            if(sizes[ul_a]<sizes[ul_b])
            {
                swap(ul_a,ul_b);
            }
            parent[ul_b]=ul_a;
            sizes[ul_a]+=sizes[ul_b];
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        DSU ds(n);
        
       int cnt_ed=0;
       
       for(auto x:edge)
       {
           int a=x[0];
           int b=x[1];
           
           if(ds.find_par(a)==ds.find_par(b))
           {
               cnt_ed++;
           }
           else
           {
                ds.Union_size(a,b);
           }
       }
       
       int cnt=0;
       for(int i=0;i<n;i++)
       {
           if(ds.parent[i]==i)
              cnt++;
       }
       
       int ans=cnt-1;
       
       if(cnt_ed>=ans)return ans;
       
       return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends