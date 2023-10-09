class Solution {
public:
 vector<int> searchRange(vector<int>& nums, int target) {
     
        int right = nums.size()-1;
        int left = 0;
        vector<int> res(2, -1);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums.at(mid) < target) {
                left = mid + 1;
                if (left < nums.size() && nums.at(left)==target) {
                    res.at(0) = left;
                }
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            } else {
                right = mid - 1;
                res.at(0) = left;
            }
        }
        
        right = nums.size()-1;
        left = 0;        
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums.at(mid) < target) {
                left = mid + 1;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            } else {                
                left = mid + 1;
                res.at(1) = left - 1;
            }
        }
        
        return res;
    }
};