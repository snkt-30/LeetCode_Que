class Solution {
public:
    bool isSameAfterReversals(int num) {
        
        int r1=0;
        
        if(num==0)
            return true;
        int cnt=0;
        while(num)
        {
            r1=r1*10+(num%10);
            
            num/=10;
            cnt++;
        }
        
        int r1_=floor(log10(r1)+1);
        
        if(r1_ == cnt)
            return true;
        return false;
        
    }
};