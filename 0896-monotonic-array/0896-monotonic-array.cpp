class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i=0,j=1;
        int n= nums.size();
        bool isMonotonic_inc= true;
        bool isMonotonic_dec= true;
        for(;i<n-1 && j<n; i++)
        {
            if(nums[i] <= nums[j])
            {   if((i== n-2) && (j==n-1)) return true;
                j++;
                continue;
            }
            else
            {
                isMonotonic_inc= false;
                break;
            }
        }

        int k=0,l=1;
        for(; k<n-1 && l<n; k++)
        {

            if(nums[k] >= nums[l])
            {   if((k== n-2) && (l==n-1)) return true;
                l++;
                continue;
            }
            else
            {
                isMonotonic_dec= false;
                break;
            }
        } 
        return isMonotonic_inc || isMonotonic_dec;
    }
};