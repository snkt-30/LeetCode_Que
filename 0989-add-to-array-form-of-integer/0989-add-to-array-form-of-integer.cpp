class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        
        
        int n=nums.size()-1;
        
        int carry=0;
        
        vector<int>ans;
        for(int i=n;i>=0;i--)
        {
            int rem=k%10;
            k/=10;
            
            int digit=nums[i]+rem+carry;
            
            carry=digit/10;
            
            ans.push_back(digit%10);
        }
        
        while(k)
        {
            int rem=k%10;
            k/=10;
            
            int digit=rem+carry;
            
            carry=digit/10;
            
            ans.push_back(digit%10);
        }
        
       while(carry)
       {
           int rem=carry%10;
           ans.push_back(rem);
           carry/=10;
       }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
            
    }
};