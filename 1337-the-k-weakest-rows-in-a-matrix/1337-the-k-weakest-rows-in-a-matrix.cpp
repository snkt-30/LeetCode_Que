class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
       int n=mat.size();
        int m=mat[0].size();
        
        // int ans=0;
        
       vector<pair<int,int>> pq;
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    cnt++;
            }
            
            pq.push_back(make_pair(cnt,i));
        }
        
        sort(pq.begin(),pq.end());
        
        k=n-k;
        while(k--)
        {
            pq.pop_back();
        }
        
        vector<int>ans;
        
        for(auto x:pq)
        {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};