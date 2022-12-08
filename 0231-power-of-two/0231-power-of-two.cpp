class Solution {
public:
    bool isPowerOfTwo(int  n) {
                      
        if(n<0)return false;
        
        if(n==0)return false;
        
          int x=__builtin_popcount(n);
        
        return x==1;
    }
};