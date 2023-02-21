class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        
        int n=a.size();

        if(n==1)
          return a[0];

        int lo=0, hi=n-1;

        while(lo<=hi)
        {
            int mid=(lo+hi)/2;

            if(mid&1)
            {
                if(a[mid]==a[mid-1])
                  lo=mid+1;
                else if(a[mid]==a[mid+1])
                   hi=mid-1; 
            }
            else
            {
                if(mid==n-1)
                  return a[mid];

                if(mid==0 and a[mid]!=a[mid+1])
                  return a[mid];

                if(a[mid]==a[mid+1])
                  lo=mid+1;
                else if(a[mid]==a[mid-1])
                  hi=mid-1;
                else
                   return a[mid];
            }
        }
        return 0;

    }
};