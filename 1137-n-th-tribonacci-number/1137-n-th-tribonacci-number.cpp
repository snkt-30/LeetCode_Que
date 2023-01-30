class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        if(n==1 || n==2)
        {
            return 1;
        }
        
        int prev2=0;
        int prev1=1;
        int prev=1;
        
        for(int i=3;i<=n;i++)
        {
            int curr=prev+prev1+prev2;
            prev2=prev1;
            prev1=prev;
            prev=curr;
        }
        
        return prev;
    }
};