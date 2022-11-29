class NumArray {
public:
    int prefix[10010];
    NumArray(vector<int>& nums) {
        int n=nums.size();
        prefix[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {

        int add=0;

        if(left>0)
        {
          add=prefix[left]-prefix[left-1];

        }
        else
           add=prefix[0];
        
        int ans=prefix[right]-prefix[left]+add;

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */