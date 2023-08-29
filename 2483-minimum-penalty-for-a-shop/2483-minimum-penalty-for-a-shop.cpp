class Solution {
public:
    int bestClosingTime(string a) {
        
        
       int n=a.length();
        
        
        if(n==1)
        {
            if(a[0]=='N')
            {
                return 0;
            }
            
            return 1;
        }
        vector<int>suf(n,0),pre(n,0);
        
        if(a[n-1]=='Y')
        {
            suf[n-1]=1;
        }
        else
        {
            suf[n-1]=0;
        }
        
        if(a[0]=='Y')
        {
            pre[0]=1;
        }
        else
        {
            pre[0]=0;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]=='Y')
            {
                suf[i]=1+suf[i+1];
            }
            else
            {
                suf[i]=suf[i+1];
            }
        }
        // cout<<pre[0]<<" ";
        for(int i=1;i<n;i++)
        {
            if(a[i]=='Y')
            {
                pre[i]=1+pre[i-1];
            }
            else
            {
                pre[i]=pre[i-1];
            }
            // cout<<pre[i]<<" ";
        }
        // cout<<endl;
        // cout<<suf[0]<<" "<<pre[n-1]<<endl;
        int mn=1e7;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            
            if(i==0)
            {
                cnt+=suf[i+1];
                
                
                if(a[0]=='Y')
                {
                    cnt+=1;
                }
                
                // cout<<cnt<<" "<<i<<endl;
            }
            else if(i==n-1)
            {
                cnt+=(n-1)-pre[i-1];
                
                if(a[i]=='Y')
                {
                    cnt+=1;
                }
                // cout<<cnt<<" "<<i<<endl;
            }
            else
            {
                int p=pre[i-1];
                int s=suf[i+1];
                
                
                cnt+=(i)-pre[i-1];
                cnt+=suf[i+1];
                
                if(a[i]=='Y')
                {
                    cnt+=1;
                }
                // cout<<cnt<<" "<<i<<endl;
            }
            
           if(mn>cnt)
           {
               ans=i;
               mn=cnt;
           }
        }
        
        if(n-pre[n-1] < mn)
        {
            ans=n;
        }
        
        
        return ans;
    }
};