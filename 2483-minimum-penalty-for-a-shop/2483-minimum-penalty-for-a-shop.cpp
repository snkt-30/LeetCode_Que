class Solution {
public:
    int bestClosingTime(string a) {
        
       int n=a.length();   
        
        int alcnt= count(a.begin(),a.end(),'Y');
        
        int y_cnt=0;
        int n_cnt=0;
        
        int mn=1e7;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=alcnt-y_cnt;
            cnt+=n_cnt;
            
            if(a[i]=='Y')
            {
                y_cnt++;
            }
            else
            {
                n_cnt++;
            }
            
            if(mn>cnt)
            {
                mn=cnt;
                ans=i;
            }
        }
        
        if(n_cnt <mn)
        {
            ans=n;
        }
        
        return ans;
        
//         if(n==1)
//         {
//             if(a[0]=='N')
//             {
//                 return 0;
//             }
            
//             return 1;
//         }
//         vector<int>suf(n,0),pre(n,0);
        
//         if(a[n-1]=='Y')
//         {
//             suf[n-1]=1;
//         }
//         else
//         {
//             suf[n-1]=0;
//         }
        
//         if(a[0]=='Y')
//         {
//             pre[0]=1;
//         }
//         else
//         {
//             pre[0]=0;
//         }
        
//         for(int i=n-2;i>=0;i--)
//         {
//             if(a[i]=='Y')
//             {
//                 suf[i]=1+suf[i+1];
//             }
//             else
//             {
//                 suf[i]=suf[i+1];
//             }
//         }
//         for(int i=1;i<n;i++)
//         {
//             if(a[i]=='Y')
//             {
//                 pre[i]=1+pre[i-1];
//             }
//             else
//             {
//                 pre[i]=pre[i-1];
//             }
//         }
//         int mn=1e7;      
//         int ans=0;      
//         for(int i=0;i<n;i++)
//         {
//             int cnt=0;           
//             if(i==0)
//             {
//                 cnt+=suf[i+1];                
//                 if(a[0]=='Y')
//                 {
//                     cnt+=1;
//                 }
//             }
//             else if(i==n-1)
//             {
//                 cnt+=(n-1)-pre[i-1];            
//                 if(a[i]=='Y')
//                 {
//                     cnt+=1;
//                 }
//             }
//             else
//             {
//                 int p=pre[i-1];
//                 int s=suf[i+1];               
//                 cnt+=(i)-pre[i-1];
//                 cnt+=suf[i+1];              
//                 if(a[i]=='Y')
//                 {
//                     cnt+=1;
//                 }
//             }
//            if(mn>cnt)
//            {
//                ans=i;
//                mn=cnt;
//            }
//         }
//         if(n-pre[n-1] < mn)
//         {
//             ans=n;
//         }
        
//         return ans;
    }
};