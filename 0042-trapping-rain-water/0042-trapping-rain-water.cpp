class Solution {
public:
    int trap(vector<int>& h) {
        
        int leftmax=0,rightmax=0,left=0,right=h.size()-1;
        
        long long ans=0;
        
        while(left<right)
        {
            if(h[left]<=h[right])
            {
                if(h[left]>leftmax)
                {
                    leftmax=h[left];
                }
                else
                {
                    ans+=leftmax-h[left];
                }
                left++;
            }
            else
            {
                if(h[right]>rightmax)
                {
                    rightmax=h[right];
                }
                else
                {
                    ans+=rightmax-h[right];
                }
                right--;
            }
        }
        return ans;
        
    }
};