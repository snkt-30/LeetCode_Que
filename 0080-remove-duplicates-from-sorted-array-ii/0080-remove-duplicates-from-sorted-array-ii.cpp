class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        
        
        int l=0,r=0;
        
        int n=a.size();
        
        while(r<n)
        {
            if(a[l]==a[r])
            {
               if(r-l+1>2)
               {
                   a[r]=INT_MIN;
               }
            }
            else
            {
                l=r;
            }
            r++;
        }
        
        l=0,r=0;
        
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        
        cout<<" next ";
        
        while(r<n)
        {
            if(a[l]==INT_MIN)
            {
                if(a[r]!=INT_MIN)
                {
                    swap(a[l],a[r]);
                    l++;
                }
            }
            else
            {
                l++;
            }
            r++;
        }
             for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        
        cout<<endl;
        
        return (l);
        
    }
};