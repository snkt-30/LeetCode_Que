class Solution {
public:
    
    long long cal(vector<int>& nums,vector<int>& cost,long long median)
                   {
                       long long ans=0;
                       
                       for(int i=0;i<nums.size();i++)
                       {
                           ans+=abs(1ll*(nums[i]-median))*(1ll*cost[i]);
                       }
        return ans;
                   }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        vector<pair<int,int>> v;
        
         long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(make_pair(nums[i],cost[i]));
            sum+=1ll*cost[i];
        }
        
        sort(v.begin(),v.end());
        
        long long tot=0,median=0;
        int i=0;
        
        while(tot<(sum+1)/2 and i<nums.size())
        {
            tot+=1ll*v[i].second;
            median=v[i].first;
            i++;
        }
        
        return cal(nums,cost,median);
      
    }
};