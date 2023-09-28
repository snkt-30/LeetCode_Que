class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int odd=0,even=0;
        
        while(odd<nums.size())
        {
            if(!(nums[odd]&1))
            {
                swap(nums[odd],nums[even]);
                odd++;
                even++;
            }
            else
            {
                  odd++;
            }
        }
        
//         for(auto x:nums)
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
        
        return nums;
        
        
    }
};