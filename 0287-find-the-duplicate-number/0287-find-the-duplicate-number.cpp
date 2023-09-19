class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        
//         long long int bitmask=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             long long int val=(1<<nums[i]);
//             if(bitmask & (1LL<<val))
//             {
//                 return nums[i];
//             }
            
//             bitmask=bitmask | (1<<nums[i]);
//         }
//         return nums[nums.size()-1];
        
        for(int i=0;i<nums.size();i++)
        {
            int idx=abs(nums[i]);
            
            if(nums[idx]<0)
                return idx;
            
            nums[idx]=-nums[idx];
        }
        
        return 0;
    }
};