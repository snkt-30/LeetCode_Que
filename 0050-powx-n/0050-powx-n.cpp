class Solution {
public:
    double myPow(double x, int p) {
        double ans=1.0;
        
        bool isNeg=false;
        
        long long n=p;
        if(n<0)
        {
            n=n*(-1);
            isNeg=true;
        }
        
        while(n)
        {
            if(n&1)
            {
                ans=ans*x;
            }
            x=x*x;
            (n>>=1);
        }
        if(isNeg)
        {
            ans=double(1.0)/double(ans);
        }
        return ans;
    }
};