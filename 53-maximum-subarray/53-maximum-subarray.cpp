class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int mx=INT_MIN;
       int currsum=0;
       for(int i=0;i<nums.size();i++)
       {
           currsum+=nums[i];
             mx=max(currsum,mx);
           if(currsum<0)
           {
               currsum=0;
           }
       }
       return mx;
        
    }
};