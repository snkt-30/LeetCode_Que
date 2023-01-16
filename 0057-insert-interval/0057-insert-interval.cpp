class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nin) {
        
        
        in.push_back(nin);
        
        sort(in.begin(),in.end());
        
        
        vector<vector<int>>res;
        
        
        
        
        auto temp=in[0];
        
        for(auto x:in)
        {
            int pr_end=temp[1];
            int curr_st=x[0];
            
            if(curr_st<=pr_end)
            {
                //merge
                temp[1]=max(pr_end,x[1]);
            }
            else
            {
                res.push_back(temp);
                temp=x;
            }
        }
        
        res.push_back(temp);
        return res;
        
    }
};