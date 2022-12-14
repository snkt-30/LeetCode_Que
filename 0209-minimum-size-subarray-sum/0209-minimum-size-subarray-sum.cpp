class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
   /*  
     time Complexity : O(N)
    int len = 100001;

	int st_ind = 0, end_ind = 0;

	int sum = 0;

	while (end_ind < nums.size())
	{
		sum += nums[end_ind];

		if (sum < target)
			end_ind++;
		else if (sum >= target)
		{
			while (sum >= target and st_ind <= end_ind)
			{
				int curr = end_ind - st_ind + 1;
				if (len > curr)
				{
					len = curr;
				}
				sum -= nums[st_ind];
				st_ind++;
			}
			end_ind++;
		}
	}

	return len == 100001 ? 0 : len;
    
    */
        
  // Time Complexity O(log(N))
        
        int n=nums.size();
        
        vector<int> v(n+1,0);
        
        int len=INT_MAX;
        
        for(int i=1;i<=n;i++)
        {
            v[i]=v[i-1]+nums[i-1];
        }
        
        for(int i=n;i>=0 and v[i]>=s;i--)
        {
            int ind=upper_bound(v.begin(),v.end(),v[i]-s)-v.begin();
            len=min(len,i-ind+1);
            
        }
        
        return len==INT_MAX?0:len;
    }
};