class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
     vector<long long> prefix;
        prefix.push_back(nums[0]);
        
        
        for(int i=1;i<nums.size();i++){
            prefix.push_back(nums[i]+prefix[i-1]);
        }
        
        int min = INT_MAX;
        int min_index = 0;
        for(int i=0;i<nums.size();i++){
            int diff;
            if(nums.size() - i - 1==0)
                diff = (prefix[i]/(i+1));
            else
            diff = (prefix[i]/(i+1)) - (prefix[nums.size()-1]-prefix[i])/(nums.size() - i - 1);
            
            diff = abs(diff);
            if(diff<min){
                min = diff;
                min_index = i;
            }
        }
        
        return min_index;
        
                       
    }
};