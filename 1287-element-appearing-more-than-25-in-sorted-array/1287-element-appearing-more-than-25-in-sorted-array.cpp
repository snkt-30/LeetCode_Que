class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        
        int cnt=0,ans=0;
        
        for(auto x:arr)
        {
            mp[x]++;
            
            if(mp[x]>cnt)
            {
                cnt=mp[x];
                ans=x;
            }
        }
        
        return ans;
    }
};