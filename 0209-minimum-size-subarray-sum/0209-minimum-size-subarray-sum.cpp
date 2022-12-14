class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
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
    }
};