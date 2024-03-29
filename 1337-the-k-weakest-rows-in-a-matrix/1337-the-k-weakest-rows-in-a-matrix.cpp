class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
       int n=mat.size();
        int m=mat[0].size();
        
        // int ans=0;
        
      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    cnt++;
            }
            
            pq.push(make_pair(cnt,i));
        }
        
        vector<int>ans;
      while(k--)
      {
          ans.push_back(pq.top().second);
          pq.pop();
      }
        return ans;
    }
};