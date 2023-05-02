class Solution {
public:
    int arraySign(vector<int>& a) {
        
        int neg=0,zero=0;
        
        int n=a.size();
        
        
        for(int i=0;i<n;i++)
        {
            if(a[i]<0)
            {
                neg++;
            }
            
            if(a[i]==0)
            {
                zero++;
            }
        }
        
        if(zero>=1)
        {
            return 0;
        }
        
        if(neg%2==1)
        {
            return -1;
        }
          
        return 1;
    }
};