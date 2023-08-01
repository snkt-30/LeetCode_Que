class Solution {
    
    vector<vector<int>>res;
    void helper(int ind,vector<int>&ds,int k,int n)
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
        
        helper(ind+1,ds,k,n);
        
        ds.pop_back();
        
        helper(ind+1,ds,k,n);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>ds;
        
        helper(1,ds,k,n);
        
        return res;
    }
};