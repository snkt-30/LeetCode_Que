class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        
//         vector<int>pos(101,0);
        
//         pos[1]=0;
//         int inc=1;
        
//         for(int i=2;i<=100;i++)
//         {
//             pos[i]=pos[i-1]+inc;
//             inc++;
//         }
        
        map<int,int>mp;
        
        for(auto x:nums)
        {
            mp[x]++;
        }
        
        int ans=0;
        
        for(auto x:mp)
        {
            int n=x.second;
            
            ans+=(n*(n-1))/2;
        }
        
        return ans;
        

    }
};