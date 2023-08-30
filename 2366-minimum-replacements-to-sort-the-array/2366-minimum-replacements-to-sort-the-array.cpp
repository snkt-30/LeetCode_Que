class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans=0;
        
        int n=nums.size();
        
        int prev=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            int noOfDeletion=nums[i]/prev;
            
            if(nums[i]%prev!=0)
            {
                noOfDeletion++;
            }
            
            if(nums[i]%prev!=0)
            {
                prev=nums[i]/noOfDeletion;
            }
            
            ans+=noOfDeletion-1;
        }
        
        return ans;
    }
};