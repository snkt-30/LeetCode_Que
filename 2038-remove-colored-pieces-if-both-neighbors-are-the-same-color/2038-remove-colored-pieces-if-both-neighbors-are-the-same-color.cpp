class Solution {
public:
    bool winnerOfGame(string s) {
        
        
        int a_cnt=0;
        int b_cnt=0;
        
        int n=s.length();
        
        if(n<=2)
        {
            return false;
        }
        
        int l=0,r=0;
        
        while(r<n)
        {
            char ch=s[r];
            
            if(s[r]=='A')
            {
                while(r<n and s[r]=='A')
                {
                    r++;
                }
               int cnt=(r-l-2);
                
                if(cnt>=1)
                {
                    a_cnt+=cnt;
                }
                l=r;
            }
            else
            {
                
                // l=r;
                
                while(r<n and s[r]=='B')
                {
                    r++;
                }
               int cnt=(r-l-2);
                
                if(cnt>=1)
                {
                    b_cnt+=cnt;
                }
                l=r;
            }
        }
        
        cout<<a_cnt<<" "<<b_cnt<<endl;
        
        if(a_cnt>b_cnt)
        {
            return true;
        }
        
        return false;
    }
};