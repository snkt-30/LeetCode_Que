class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        
        
        int len=0;
        
        int l=0,r=0;
        
        int n=a.size();
        
        int ans=INT_MAX;
        
        int sum=0;
        while(r<n)
        {
            sum+=a[r];
            
            
            if(sum>=t)
            {                
                while(sum>=t and l<n and l<=r)
                {
                    ans=min(ans,r-l+1);
                    sum-=a[l];                    
                    l++;
                }
                
            }
            r++;
        }
        
       return ans==INT_MAX?0:ans;
        
        
    }
};