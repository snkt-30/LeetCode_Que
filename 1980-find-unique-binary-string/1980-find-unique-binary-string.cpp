class Solution {
    
    string ans="";
    
    void helper(unordered_map<string, bool>&mp,string temp,int n)
    {
        if(temp.length()==n)
        {
            if(mp.find(temp)==mp.end())
            {
                ans=temp;
            }
            return;
        }
        
        helper(mp,temp+"0",n);
        
        helper(mp,temp+"1",n);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        
        unordered_map<string,bool>mp;
        
        int n=nums[0].length();
        
        for(auto x:nums)
        {
            mp[x]=true;
        }
        
        
        helper(mp,"",n);
        return ans;
    }
};