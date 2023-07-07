class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        
        int n=s.size();
        
        if(n==1)
            return 1;
        
        if(n==2 and s[0]==s[1])
            return 2;
        
        
        int r=0,l=0;
        
        int t_cnt=0,f_cnt=0,mn=n;
        
        int ans=0;
        while(r<n)
        {
            if(s[r]=='T')
            {
                t_cnt++;
            }
            else
            {
                f_cnt++;
            }
            
            mn=min(t_cnt,f_cnt);
 
                while(mn>k and l<n and l<=r)
                {
                    if(s[l]=='T')
                    {
                        t_cnt--;
                    }
                    else
                    {
                        f_cnt--;
                    }
                    
                    mn=min(t_cnt,f_cnt);
                    l++;
                }
            ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
        
    }
};