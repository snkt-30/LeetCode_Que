class Solution {
    
    void helper(int ind,vector<int>&ds,int k,int n,vector<vector<int>>&res)
    {
        
       if(ind>n)
       {
           if(ds.size()==k)
           {
               res.push_back(ds);
           }
           return;
       }
        
        ds.push_back(ind);
        
        helper(ind+1,ds,k,n,res);
        
        ds.pop_back();
        
        helper(ind+1,ds,k,n,res);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>ds;
            vector<vector<int>>res;
        helper(1,ds,k,n,res);
        
        return res;
    }
};